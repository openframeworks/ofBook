# C++ 11

*by [Elliot Woods](http://www.kimchiandchips.com/)*

## Introduction
C++ an old language. It has been around since 1983. It is often seen as archaic, obtuse, and perhaps just plain out of touch by today's standards. Contrary to this, many people believe it offers the best balance of performance and clarity, and many other people use it fot its strong ecosystem of 3rd party libraries, device support and general acceptance. Even new technologies (like CUDA) often use C++ as their language of choice.

Some more modern languages (such as JavaScript and C#) make programs which run in a very different way to C/C++. They use the concept of a 'virtual machine', which is a very different type of computer than the one which crunches electronic signals on a circuit board. The virtual machine receives and processes program instructions like a real machine, but allows for all sorts of ideas which don't directly translate to silicon electronics, such as dynamic typing and reflection. The virtual machine abstracts the constraints of the processor away from the thinking of the programmer.

C/C++ does not have a virtual machine, which (for the time being) often gives it a performance edge over these newer languages. It is quite strict in that the instructions you type deep down have a 1:1 translation with physical processor instructions. This gives the language some inflexibilities, but means that code can be both understood naturally by a human, and clearly translate to machine code.

In this chapter we'll look at some of the new patterns in the C++ language introduced in C++11, which retain this promise whilst offering new ways of writing code.

## `auto`
Perhaps the most used, and simplest new pattern in C++11 is `auto`. You'll love it. And probably won't remember life without it after a day or two. Consider the following...

```cpp
ofRectangle myRectangle = ofGetCurrentViewport();
ofVec2f rectangleCenter = myRectangle.getCenter();
float rectangleCenterX = rectangleCenter.x;
```

In this code block, we are declaring 3 variables:

* `myRectangle`
* `rectangleCenter`
* `rectangleCenterX`

On each line of code we are:

1. Getting a variable on the right hand side. which is of a certain type (`ofRectangle`, `ofVec2f`, `float` respectively)
2. Declaring a new variable which is explicitly typed to match the value on the right
3. Assigning the value to the variable

The type of data on the right and left side of the `=` is the same. Since C++ is strictly typed (e.g. a function which returns `float` will always return `float`), it is impossible for the value on the right hand side to ever be anything different. The compiler __knows__ what data type the right hand side of the code will give, e.g. it knows that on line 1 that on the right hand side of the `=` is an `ofRectangle`. So perhaps if we were to write something like:

```cpp
auto myRectangle = ofGetCurrentViewport();
auto rectangleCenter = myRectangle.getCenter();
auto rectangleCenterX = rectangleCenter.x;
```

Then the compiler can do some of the coding for us. In fact, this is exactly the facility of the `auto` feature. This code block compiles to exactly the same result as the first code block did. The compiler notices what's on the right hand side and substitutes in the correct type wherever it sees `auto`.

#### How this helps
auto is going to save you keystrokes. Imagine the following:

```cpp
//.h
vector<shared_ptr<ofThread> > myVectorOfThreads;
````

```cpp
//.cpp

// the old way
vector<shared_ptr<ofThread>>::iterator firstThreadIterator = this->myVectorOfThreads.begin();

// the new way
auto firstThreadIterator = this->myVectorOfThreads.begin();
```

This makes the code more readable, but also you could take advantage of `auto` in other ways.

For example, when you reuse or copy variables, you can use auto along the way, meaning that you only have to define which type you want to use at the beginning and not everywhere else in your code. For example in the above h file, you might change the `vector` to a `list`, or change `shared_ptr<ofThread>` to `ofThread *`. These changes would perpetuate automatically to wherever an `auto` is being used in the code. Nifty huh?

### Watch out for this

#### `auto` is not a new type

Note that the following doesn't work:

```cpp
auto myRectangle = ofGetCurrentViewport();
myRectangle = "look mum! i'm a string!!"; // compiler error!
```

Remember that `auto` isn't a type itself, it's not a magic container that can take any kind of thing (such as `var` in C# or another dynamic typed language), it is simply a keyword which gets substituted at compile time, you can imagine that the compiler just writes in for you whatever makes sense on that line where it is. In this case, the first line makes sure that `myRectangle` is an `ofRectangle`, and you can't assign a `string` to an `ofRectangle`.

#### You can't use `auto` in function arguments
Since the `auto` must be implicitly defined by the line of code where it is used, and that this decision is made at compile time, it can not be a function argument, let's see what that means..

Imagine that the following was valid: (__NOTE__ : it isn't!)

```cpp
float multiplyBy2(auto number) {
	return number * 2;
}

int firstNumber = 1;
float secondNumber = 2.0f;

cout << multiplyBy2(firstNumber) << endl;
cout << multiplyBy2(secondNumber) << endl;
```

Now if this code were valid, then the first time the function is called, the `auto` would mean `int`, and the second time it would mean `float`. Therefore saying that the text `auto` is simply substituted with an explicit type where it is written doesn't make sense. So basically __you can't use `auto` in function arguments__ (you might want to look into `template` instead, which would automatically generate 2 pieces of code for the 2 different types).

#### You can't use `auto` as a function return type
I'm not sure why, you just can't. It kinda makes sense that you should be able to, but you just can't, I don't make the rules...

### `const` and references
Let's do a `const auto`:

```cpp
ofRectangle rectangle = ofGetCurrentViewport();
//is the same as
auto rectangle = ofGetCurrentViewport();

//and
const ofRectangle rectangle = ofGetCurrentViewport();
//is the same as
const auto rectangle = ofGetCurrentViewport();
```

Next look at `auto &` for when we want reference types.

```cpp
float x = rectangle.x;
//is the same as
auto x = rectangle.x;

//and

float & x = rectangle.x;
//is the same as
auto & x = rectangle.x;
```

### Summary
* Save keystrokes by using `auto` in variable declarations
* `auto` takes the type of the right hand side of the `=` assignment, and replaces the text `auto` with that type at compile time.
* `auto` is not a magic container which can carry any type of data, it simply gets replaced at compile time by whatever is implied in the code
* You can't use `auto` in function arguments, return types and a few other places.
* Use `const auto` for a const type, and `auto &` for a reference type

## `for (thing : things)`
Consider the following common pattern:

```cpp
vector<ofPixels> mySelfies;
/*
take some snaps here and store in mySelfies
*/

//oh dear, my photos are all in portrait
for(int i=0; i<mySelfies.size(); i++) {
	//rotate them from landscape to portrait
	mySelfies[i].rotate90(1);
}

vector<ofxMySpace::Friend> myFriends = myspaceClient.getFriends();

//now let's send them to all my friends
for(int i=0; i<myFriends.size(); i++) {
	if (myFriends[i].isOnline()) {
		for(int i=0; i<mySelfies.size(); i++) {
			myFriends[i].sendImage(mySelfies[i]);
		}
	}
}
```

Well we're forever doing things like `for(int i=0; i<mySelfies.size(); i++) { `, so let's see if we can find a neater way of doing this with `for thing in things` which in C++11 we can write as `for (thing : things)`...

```cpp
vector<ofPixels> mySelfies;
/*
take some lovely snaps
*/

//oh dear, my photos are all in portrait
for(auto & mySelfie : mySelfies) {
	//rotate them from landscape to portrait
	mySelfie.rotate90(1); // (1)
}

auto myFriends = myspaceClient.getFriends();

//now let's send them to all my friends
for(auto & myFriend : myFriends) {
	if (myFriend.isOnline()) {
		for(auto & mySelfie : mySelfies) {
			myFriend.sendImage(mySelfie); // (2)
		}
	}
}
```

Notice that `for(thing : things)` gels so well with `auto`. Also notice that I'm using `auto &` since:

* At `(1)` I want to be able to change the contents of the vector, so I need a reference to the vector item rather than a copy of it.
* At `(2)`, it makes more sense to use a reference rather than a copy because it's computationally cheaper, and means I don't have to allocate new instances of `ofxMySpace::Friend` (which perhaps has many complicated allocations internally which you wouldn't want to repeat by copying the object).

### Summary
* Use `for(auto thing : vectorOfThings)`
* This works with all the STL containers (`vector`, `map`, `list`, `deque`, `set`, etc) and in some more purpose built containers (e.g. `ofxGrayCode::DataSet`)
* Often you'll want to do `for(auto & thing : vectorOfThings)` to use a reference rather than a copy

## override
`override` saves you time not by reducing the amount of typing you do, but by reducing the amount of head-scratching you might do when dealing with `virtual` functions. Imagine the following:

```cpp
class BuildingProjectionMapper {
public:
//...
    virtual void mapTheNeoClassicalColumns();
//...
};

class AutoBuildingProjectionMapper : public BuildingProjectionMapper {
public:
	void mapTheNeoClassicalColums(); // woops, I spelt column incorrectly
};
```
Now if I implement `AutoBuildingProjectionMapper::mapTheNeoClassicalColums`, it may never get called, and I may be wondering why my function calls are all being handled by the base class. The problem is that the compiler never told me that the function that I was trying to override didn't exist. Here comes `override` to the rescue.

```cpp
class AutoBuildingProjectionMapper : public BuildingProjectionMapper {
public:
	void mapTheNeoClassicalColums() override;
};
```

This tells the compiler that I'm intending to override a `virtual` function. In this case, the compiler will tell me that no `virtual` function called `mapTheNeoClassicalColums` exists, and that therefore my `override` is faulty. So following the compiler's complaint I can go in and fix the spelling mistake. Then I can get on with making my Projection Mappening on the town library facade.

This is especially useful when you make changes to your base class, e.g. in oF 0.9.0, many base classes have changed, and by using `override` in addons, addon authors can be hard-notified that their code is now invalid and needs updating.

### Summary
* Use the keyword `override` at the end of function definitions in a derived class' h file when you are intending to override a `virtual` function in the base `class`
* The compiler will warn you if your `override` is invalid, which might just save you a lot of time hunting for errors

## Lambda functions
This one is a little more complex. Rather than making things quicker or safer to write, it adds a new feature to the way you can design your code. As such, we'll introduce the basics of what they do, then make some interesting examples.

Lambda functions are very common in JavaScript, C# and other modern languages, and can be very liberating to use. They can seem more scary than they really are, so I suggest just getting on with some examples to start with. Let's make a simple example:

```cpp
void normalFunction() {
	cout << "Heathcliff, it's me Cathy." << endl;
}

void main() {
	auto lambdaFunction = []() {
		cout << "So cold. Let me into your window." << endl;
	};
	normalFunction();
	lambdaFunction();
}
```

Let's take a guess what happens here:

```
Heathcliff, it's me Cathy.
So cold. Let me into your window.
```

So the lambda function is just like a normal function, but the biggest differences are that:

1. The function is defined within the executable code of another function (in this case `lambdaFunction` is defined inside `main`).
2. The function is now also a variable

That second one is where the lambda function really comes into its own. Because we can pass it around, store it, throw it away, copy it. Let's make a more concrete example of this.

### Passing lambda functions as variables

When we want to pass a lambda function as a variable, we need to introduce a type which can hold that data (since we can't use `auto` in function arguments or when defining members of classes). A common type which can store a lambda function is `std::function<void()>`. I understand that `void()` looks a bit funny at first, but it will make sense when we do a bit more with lambdas later on.

```cpp
class Graphic {
public:
    void draw() {
        whatToDraw();
    }

    std::function<void()> whatToDraw;
};

class ofApp : ofBaseApp {
/*
.. all the usual stuff
*/
protected:
	vector<Graphic> graphicElements;
};
```

```cpp
void ofApp::setup() {
	Graphic circle;
	circle.whatToDraw = []() {
		ofDrawCircle(50,50,20);
	};
	this->graphicElements.push_back(circle);

	Graphic rectangle;
	rectangle.whatToDraw = []() {
		ofRect(50,50,200,200);
	};
	this->graphicElements.push_back(rectangle);
}

void ofApp::draw() {
	for(auto & graphic : this->graphicElements) {
		graphic.draw();
	}
}
```

We could do this by creating classes which inherit from `Graphic` and override the `draw` function (e.g. `CircleGraphic` and `RectangleGraphic`). But instead of defining new classes, we've created 2 instances of Graphic which contain different function definitions by using lambda functions. This is convenient as it's often a pain to make new class definitions when we just want to change a little bit of functionality of a class.

### Arguments, scope and return types
Now how about getting variables in and out of the function? A common pattern with normal functions is using function arguments to get variables into the function, and returning variables to get values out again. Let's see how that works with lambdas.

```cpp
float multiplyByTwoFunction(float x) {
	return x * 2.0f;
}

void test() {
	auto multiplyByTwoLambda = [](float x) {
		return x * 2.0f;
	};

	cout << multiplyByTwoFunction(2.0f) << endl;
	cout << multiplyByTwoLambda(2.0f) << endl;
}
```

This would of course print out:

```
4
4
```

That's great! But we also have to be careful that because this function now has a float return type and a float argument, it is a different type of function to our earlier `lambdaFunction` which took no arguments and returned a string. Note that if we want to pass this function as an argument we'd need to do like:

```cpp
void performActionOnFloat(float & x, std::function<float(float)> action) {
	x = action(x);
}
```

Specifically, the type which can hold a lambda function is:

```cpp
std::function<return type(arguments)>
```

You can use multiple arguments (like you can with normal functions).

### Scope

Finally, we often need to introduce a 'scope' to the lambda function. The scope means what variables from outside the function can be seen inside the function. We define the scope in-between the `[]`s in the lambda function definition, for example:

```cpp
float multiplier = 4.0f;
auto multiplyByOurMultiplier = [multiplier](float x) { // (1)
	return x * multiplier;
}
cout << multiplyByOurMultiplier(2.0f); // prints 8
```

By putting the variable name `multiplier` within the `[]`s of the lambda function definition at `(1)`, we now can use the variable `multiplier` within the function definition. A really handy thing to put there is `[this]` which puts `this` within the scope of the function, i.e. makes all the members of the current class available from within the function.

You can:
* Add multiple variables to the scope, e.g. `[this, multiplier]`
* Add variables as references (rather than copies) to the scope, e.g.: `[&multiplier]`
* Automatically add any variables to the scope which you use inside the function using `[=]` (make a copy of the variable at the function definition) or `[&]` (use a reference to the variable).


### Summary so far

* Lambda functions let you define functions in your code which are stored in variables
* Lambda functions can be passed around between functions, classes, stored variables and `vector`s, etc. Basically, anything you can do with a variable you can do with a lambda function.
* You can return variables from lambda functions and specify arguments for the function
* You can define what is available inside the scope of the function using `[=]`, `[&]`, `[this]`, `[myVariableName]`, `[&myVariableName]`, etc.

### Worker thread example

Now let's go for a more down-deep example of how you might use lambda functions to save you from getting bogged down. In this example we have a class which talks to a camera device. The particular thing about this camera device is that the camera must run in its own thread, and all operations on the camera must run in that thread.

Imagine our ofApp looks like:

```cpp
class ofApp : public ofBaseApp {
	/*
	the usual stuff
	*/

	CameraClass camera;
	ofParameter<float> exposure;
}

class CameraClass : public ofThread {
protected:
	void threadedFunction() override {
		while (this->isCameraRunning()) {
			this->device.getFrame();
			this->pixelsLock.lock();
			this->pixels.setFromExternalPixels(this->device->getData(), 640, 480, 3);
			this->pixelsLock.unlock();
			// (1)
		}
	}

	CameraDriver device;
	ofPixels pixels;
	ofMutex pixelsLock;
}
```

Now if we want a way to set the exposure on the camera from our `ofApp` we need to signal this to the `CameraClass`, and have it set the exposure in the right thread (e.g. at (1) which happens between grabbing frames from the camera).

One way of doing this would be to store some data saying that we needed to change the exposure, and what that new exposure value is. Then at (1) we would need to check for that data and have the code to act on it appropriately. The problem with that is that it's really laborious and introduces lots of special cases (e.g. what if something had to read the gain and then change the exposure accordingly?).

A nice workaround is to use lambda functions for this purpose, e.g. :

```cpp
class CameraClass : public ofThread {
protected:
	void threadedFunction() override {
		while (this->isCameraRunning()) {
			this->device.getFrame();
			this->pixelsLock.lock();
			this->pixels.setFromExternalPixels(this->device->getData(), 640, 480, 3);
			this->pixelsLock.unlock();

			this->actionsLock.lock();
			for(auto & action : this->actions) {
				action(this->device);
			}
			this->actions.clear();
			this->actionsLock.unlock();
		}
	}

	void performInThread(std::function<void(CameraDriver&)> action) {
		this->actionsLock.lock();
		this->actions.push_back(action);
		this->actionsLock.unlock();
	}

	CameraDriver device;
	ofPixels pixels;
	ofMutex pixelsLock;

	vector<std::function<void(CameraDriver&)> > actions;
	ofMutex actionsLock;
}
```

```cpp
//somewhere in ofApp

this->camera->performInThread([this](CameraDriver & device) {
	device.setExposure(this->exposure);
});
```

This will then push the instruction into CameraClass, so that at the right time this function is called within the thread managing the camera, taking the `this->exposure` variable from the `ofApp` and acting on the `CameraDriver` defined in `CameraClass`. All this happens without having to pass lots of variables around, in a really flexible way. To see how this is implemented in ofxMachineVision, check out the `ofxMachineVision::Utils::ActionQueueThread` at https://github.com/elliotwoods/ofxMachineVision/blob/master/src/ofxMachineVision/Utils/ActionQueueThread.cpp .
