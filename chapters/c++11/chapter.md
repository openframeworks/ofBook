# C++ 11

the following needs readability improvements (flow of text)...
i'll take another pass at it soon

## Blah blah
C++ is a pretty old language, it's been around since XXX, and perhaps because of that (but certainly for many other reasons), it is often seen as archaic, obtuse, or perhaps just plain rubbish by today's standards. Contrary to that, many people believe that it is still offers the best balance of performance and clarity on the coding high street, and (in part thanks to the success of Unix and its mates) has an incredibly strong ecosystem of 3rd party libraries, device support and general acceptance, even up to the point where current shader languages and CUDA use C++ as their language of choice.

Some more modern languages (such as JavaScript and C#) make programs which run in a very different way to C/C++. They have a 'virtual machine', which is a very different type of computer than the one which crunches electronic signals on a circuit board. The virtual machine receives and processes program instructions like a real machine, but allows for all sorts of ideas which don't directly translate to silicon electronics, such as dynamic typing and reflection. The virtual machine abstracts the constraints of the processor away from the thinking of the programmer.
 
C/C++ does not have a virtual machine, which (for the time being) often gives it a performance edge over these newer languages. It is quite strict in that ultimately the C code itself (somewhere down the chain) translates 1:1 with processor instructions, the design of the language is inflexible in this way, but clinging to this is the achievement of C++, that code can be both understood naturally by a human, and clearly translate to machine code.

In this chapter we'll look at some of the new patterns in the C++ language introduced in C++11, which retain this promise whilst offering new ways of writing code.

## `auto`
Perhaps the most used, and simplest new pattern in C++11 is `auto`. You'll love it. And probably won't remember life without it after a day or 2. Consider the following...

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

What we may notice, is that the type of data on the right and left side of the `=` is the same. Since C++ is strictly typed (e.g. a function which returns a `float` will always return a `float` no matter what), it is impossible for the value on the right hand side to ever be anything different. The compiler __knows__ what type of value the right hand will give, e.g. it knows that on line 1 that on the right hand side of the `=` is an `ofRectangle`. So perhaps if we were to write something like:

```cpp
auto myRectangle = ofGetCurrentViewport();
auto rectangleCenter = myRectangle.getCenter();
auto rectangleCenterX = rectangleCenter.x;
```

Then the compiler can do some of the coding for us. In fact, thanks to `auto`, we can do this now. This code block compiles to exactly the same result as the first code block did. The compiler notices what's on the right hand side and substitutes in the correct type wherever it sees `auto`.

#### How this helps
Well obviously auto's going to save you keystrokes.  Imagine the following:

```cpp
vector<shared_ptr<ofThread> > myVectorOfThreads;
````

```cpp
// the old way
vector<shared_ptr<ofThread>>::iterator firstThreadIterator = this->myVectorOfThreads.begin();

// the new way
auto firstThreadIterator = this->myVectorOfThreads.begin();
```

Now this makes the code more readable (by decent humans), but also you could take advantage of `auto` in other ways, for example you could make changes things in the h file, and the cpp file code would automatically correct itself. For example in the h you might change the `vector` to a `list`, or change `shared_ptr<ofThread>` to `ofThread *`. These changes would perpetuate automatically to wherever an `auto` is listening out in the code. Nifty huh?

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
I'm not sure why, you just can't. It kinda makes sense that you should be able to, but you just can't, move along :).

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

## for (thing : things)
Consider the following common pattern:

```cpp
vector<ofPixels> mySelfies;
/*
take some sexy snaps
*/

//oh dear, my photos are all in portrait
for(int i=0; i<mySelfies.size(); i++) { 
	//rotate them from landscape to portrait
	mySelfies[i].rotate90(1); 
}

vector<ofxSnapChat::Friend> myFriends = snapChatClient.getFriends();

//now let's send them to all my friends
for(int i=0; i<myFriends.size(); i++) {
	if (myFriends[i].isHot()) {
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
take some sexy snaps
*/

//oh dear, my photos are all in portrait
for(auto & mySelfie : mySelfies) { 
	//rotate them from landscape to portrait
	mySelfie.rotate90(1); // (1)
}

auto myFriends = snapChatClient.getFriends();

//now let's send them to all my friends
for(auto & myFriend : myFriend) { 
	if (myFriend.isHot()) {
		for(auto & mySelfie : mySelfies) {
			myFriend.sendImage(mySelfie); // (2)
		}
	}
}
```

Notice that `for(thing : things)` gels so well with `auto`. Also notice that I'm using `auto &` since:

* At `(1)` I want to be able to change the contents of the vector, so I need a reference to the vector item rather than a copy of it.
* At `(2)`, it makes more sense to use a reference rather than a copy because it's computationally cheaper, and means I don't have to allocate new instances of `ofxSnapChat::Friend` (which I presume is quite a complex object, since it can do things like send images over the internet, and understand societal dispositions of what it means to be attractive).

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
    virtual void mapTheGreekColumns();
//...
};

class AutoBuildingProjectionMapper : public BuildingProjectionMapper {
public:
	void mapTheGreekColums(); // woops, I spelt column incorrectly
};
```
Now if I implement `AutoBuildingProjectionMapper::mapTheGreekColums`, it may never get called, and I may be wondering why my function calls are all being handled by the base class. The problem is that the compiler never told me that the function that I was trying to override didn't exist. Here comes `override` to the rescue.

```cpp
class AutoBuildingProjectionMapper : public BuildingProjectionMapper {
public:
	void mapTheGreekColums() override;
};
```

This tells the compiler that I'm intending to override a `virtual` function. In this case, the compiler will tell me that no `virtual` function called `mapTheGreekColums` exists, and that therefore my `override` is faulty. So following the compiler's complaint I can go in and fix the spelling mistake. Then I can get on with making my Projection Mappening on the town library facade.


### Summary
* Use the keyword `override` at the end of function definitions in a derived class' h file when you are intending to override a `virtual` function in the base `class`
* The compiler will warn you if your `override` is invalid, which might just save you a lot of time hunting for errors

## Lambda functions


### Worker threads
### Callbacks

### Summary
