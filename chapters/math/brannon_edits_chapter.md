# That Math Chapter: From 1D to 4D 

**NOTE: This chapter is formatted with MD and LaTeX. Github won't render it properly. Try [stackedit.io](http://stackedit.io) instead**

## How Artists Approach Math
Math is a curious thing in arts. Many artists reference it directly as inspiration for their work, from Leonardo Da Vinci's _Vitruvian Man_, through Escher's different views of fields of numbers, to the tedious namedrop of "The Golden Ratio" for every concept product made in a design school since the iPhone (if you think that's a neat idea, please read this chapter more than twice).  **[mh: while this is humorous, it's also unfriendly]**

Computers allowed simulation to happen, which means people could draw more than (and faster than) they could think. When Benoît Mandelbrot worked for IBM, his attempt at printing the density map of a self-repeating sequence of complex numbers – something that would have taken forever for a human hand and head – resulted in a scientific measurement being reappropriated for its aesthetic value, in what we now call [Fractal Art](https://en.wikipedia.org/wiki/Fractal_art), a family that also grew to include tree-like structures generated from [L-System](http://en.wikipedia.org/wiki/L-system) grammars and three-dimensional extensions with lovely names such as "Mandelbulb". It's acceptable to call these things _Art_, because the thought that mathematicians had done this deliberately in their work would simply confuse the audience.

Thing is, we know better than all of that. Math is everywhere in Art, just like Art is everywhere in Math. 
When using a brush or pen or chisel, we're taking advantage of the hard work that nature is doing, calculating physics, rendering things perfectly for us, all in real time. ~~Our brains apply direct aesthetic knowledge to a work, and we're done. WYSIWYG.~~ **[mh: these two sentences could be omitted - first one is a bit indirect for saying "we manipulate visuals by hand," and the second, not everyone will know wysiwyg]** In the computer world, none of that is true. Things like L-Systems had to be created for us to use, because our hands can't reach into the computer. If you're doing any bit of digital art, the math is happening somewhere, whether you control it or not. This chapter will try to explain some of the basics of the black arts of graphics programming. I wish I could make this chapter 5 times as long and include the really neat stuff, but that would make this book too heavy to put in a rucksack.

## About this Chapter
A Math chapter for a book about graphics will always miss out on many ideas. In fact, there are entire books covering "math for graphics", mostly consisting of references to other books, focusing on a specific topic (like Linear Algebra, Multivariable Calculus, Differential Geometry, and many other words mysteriously connected to other words). This chapter must therefore be very concise about ideas. All topics here are explained in a friendly way, but please - never fear googling a thing for which you need better examples.

This chapter will be divided into _'numbers of D's'_ : we'll start from one dimension, and slowly explore the possibilities of using scale and change in different dimensions. **[mh: this sentence might be a little unclear for newbies, as in why do I care about scale and change.]** Depending on how you choose to read it, this section contains hundreds of Mathematicians' lifetime research, or in other words, several classes of college math, so it's worth bookmarking.

When bringing math to innocent readers, most programming books will try to explain the idea, not necessarily the exact implementation. This book is no different. This chapter contains detailed breakdowns of concepts, but if you want to find out what's going on under the hood, there's no alternative to reading the source code - in fact, since all the math here is only a few lines long - it's actually _encouraged_ to have a look at the source.

## One Dimension: Using Change

Let's start our journey by looking at the number line. It's a stretch of numbers going to infinity in both the positive and negative direction. Suppose we were ants or microbes, so that we could stand on exactly one value here, and travel to any other value by walking in that direction.
That's pretty much the definition of a _dimension_. It's an infinite collection of values that are all accessible, and any value of it can be described with one number. As you're about to see, these properties are going to enable quite a lot of options.

**//TODO: Draw the number line **

### Interpolation
#### Linear Interpolation: The `ofLerp`
```cpp 
float ofLerp(float start, float stop, float amt)
```

As xkcd once put it, if you've seen a number larger than 7, you're not doing real math.

Those of you that have already done a little time-based or space-based work have probably noticed that you can often describe elements of your work as sitting on a line between two known points. A frame on a timeline is at a known location between 00:00:00 and the runtime of the film, a scrollbar is pointing to a known location between the beginning and the end of a page. That's exactly what `lerp` does.

With the `lerp` function, you can take any two quantities, in our case `start` and `stop`, and find any point between them, using amounts (`amt`) between 0 and 1. To be verbose: 
 $$\text{lerp}\left(a,b,t\right) = t\cdot b+\left(1-t\right)\cdot a$$ 

##### Note: What does _linear_ really mean?
Engineers, Programmers and English Speakers like to think of _linear_ as _anything you can put on a line_. Mathematicians, having to deal with all the conceptual mess the former group of people creates, define it _anything you can put on a line **that begins at (0,0) *_. There's  good reasoning behind that, which we will see in the discussion about Linear Algebra. In the meantime, think of it this way: if our transformation is taking a line that has a value 0 at the point 0 and returning a line with the same property, (thus in the form $f\left(x\right)=ax$), It's _linear_. If it returns a value different from 0 at $x=0$ (in the form $f\left(x\right)=ax + b$), it's _affine_. __[BD: Perhaps explain _affine_]__

##### Exercise: Save NASA's Mars Lander 
In 1999, a masterpiece of engineering was making its final approach to Mars. All instruments were showing that the approach distance matched the speed, and that it's just about to get there and do some science __[BD: This senctence is a bit awkward]__. But instead, it did something rather rude: it crashed into the red planet. An investigation made later by NASA revealed that while designing the lander, one team worked with their test equipment set to _centimetres_, while the other had theirs set to _inches_. **By the way, this is all true.**

Help the NASA teams work together: write a function that converts centimetres to inches. For reference, $1_{\text{in}} = 2.54_{\text{cm}}$. Test your result against three different real-world values.

**Think:**

1. How can we use `lerp` outside the range of 0 and 1?
2. What would it take to write a function that converts inches into centimetres?

#### Affine Mapping: The `ofMap`
```cpp
float ofMap(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp = false)
```


In the last discussion, we saw how by using `lerp`, any value between two points can be _linearly_ addressed as a value between 0 and 1. That's very convenient, and therefore the reason we build most of our arbitrary numerical ranges (`ofFloatColor`, for example) in the domain of 0 and 1. 
However, when dealing with real world problems, programmers run into domains **[mh: if you are going to be specific about the words domain and range, it would be worth an explanation.  it might not hurt to have a sentence or two about what a function is from a mathematical standpoint.  it could be useful for when you talk about more specific functions - like linear and affine mappings.]** of values that they wish to map to other ranges of values, neither of which are confined to 0 and 1. For example, someone trying to convert the temperature in Celsius to Fahrenheit won't be able to use **[mh: missing part of a sentence]** Surely, the way of doing that must involve a `lerp`, but it needs a ~~little help~~ __[BD: "bit more"? Just trying to be a little less abstract.]__:

If we want to use the `lerp` function, we're aiming to get it __[BD: Get what?]__ to the range between 0 and 1. We can do that by knocking `inputMin` off the input `value` so that it starts at 0, then dividing by the size of the domain __[BD: Be specific about what "domain" means]__: $$x=\frac{\text{value}-\text{inputMin}}{\text{inputMax}-\text{inputMin}}$$
Now that we've tamed the input domain to be between 0 and 1, we do the exact opposite to the output: `ofMap(value, inputMin, inputMax, outputMin, outputMax)` $=\frac{\text{value}-\text{inputMin}}{\text{inputMax}-\text{inputMin}}\cdot\left(\text{outputMax}-\text{outputMin}\right)+\text{outputMin}$

**[mh: I'd suggest walking through this some numbers to convert from F to C or vice versa]**

#### Range Utilities
##### Clamping
You'll notice that the previous explanation is missing the `clamp` parameter. This may not matter to us if we're using the `ofMap` function in the range that we defined, but suppose we select a `value` smaller than `inputMin`: would it be ok if the result was also smaller than `outputMin`? If our program is telling an elevator which floor to go to, that might be a problem. __[BD: This is a nice. Can you elaborate on why this would actually be a problem (using the elevator example)?]__ That's why we add `true` to the tail of this function whenever we need to be careful.

Just in case, oF offers another specific clamp function: 

```cpp
float ofClamp(float value, float min, float max)
```

`ofClamp` returns a float `value` that is confined to `min` and `max`.

##### Range Checking

Two important functions we unjustly left out of this episode;

```cpp
bool ofInRange(float t, float min, float max);
```

Tells you whether a number `t` is between `min` and `max`. 

```cpp
float ofSign(float n);
```

Returns the sign of a number, as either `-1` or `1` __[BD: according to the `ofSign()` [documentation](http://openframeworks.cc/documentation/math/ofMath.html#show_ofSign), it returns an int. I changed `1.0` to `1` inline. Please correct me if I am wrong. ]__. Simple, eh?

### Beyond Linear: Changing Change 

**[mh: I recognize that you are trying to be general here by talking about change, but at least throwing the word motion around as a type of change would give readers something upon which to anchor the concept.]**

So far we've discussed change that is bound to a line. But in Real Life™ there's more than just straight lines. 

In this discussion, we're about to see how we can describe higher orders of complexity, via a cunning use of `lerp`s. Keep in mind that some of the code here is conceptual, not necessarily efficient.

#### Quadratic and Cubic Change Rates
Consider this function:

```cpp
float quadratic (float t){
	float a1 = ofLerp(t, 5, 8);
	float a2 = ofLerp(t, 2, 9);
	float b = ofLerp(t, a1, a2);
	return b;
	}
```

This function used a defined range and a parameter to create `a1`, then used another defined range with the _same_ parameter to create `a2`. The result looks surprising:

**//TODO: Draw quadratic eqn**

We've done something remarkable here. We used the way one parameter changes on two fixed lines to control a third, totally mobile line, and draw one point on it at each point in time between 0 and 1. In Mathspeak, it looks like this:
 
$$
\text{lerp}\left(t,\text{lerp}\left(t,5,8\right),\text{lerp}\left(t,2,9\right)\right)\\
= \text{lerp}\left(t,8\cdot t+5\cdot\left(1-t\right),9\cdot t+2\cdot\left(1-t\right)\right)\\
= \left(9\cdot t+2\cdot\left(1-t\right)\right)\cdot t+\left(8\cdot t+5\cdot\left(1-t\right)\right)\cdot\left(1-t\right)\\
= \left(9t^{2}+2t-2t^{2}\right)+\left(8t+5-5t\right)-\left(8t^{2}+5t-5t^{2}\right)\\
= 4t^{2}+5
$$

Something interesting happened here. Without noticing, we introduced a second order of complexity, a _quadratic_ one. ~~If you don't find this relationship remarkable, please give this book to someone who does.~~ **[mh: a bit too harsh for an intro to math chapter][BD: I second this. Also, how about explaining what a _quadratic_ is?]**


The same manipulation can be applied for a third order:

```cpp
float cubic (float t){
	float a1 = ofLerp(t, 5, 8);
	float a2 = ofLerp(t, 2, 9);
	float a3 = ofLerp(t, 3, -11);
	float a4 = ofLerp(t, -2, 4);
	float b1 = ofLerp(t, a1, a2);
	float b2 = ofLerp(t, a3, a4);
	float c = ofLerp(t, b1, b2);
	return c;
}
```

**[mh: maybe change the variable names here, so that they don't give the impression of lining up with the polynomial eq]**
We'll skip the entire solution, and just reveal that the result will appear in the form of $$ax^{3} + bx^{2} + cx + d$$
See the pattern here? The highest exponent is the number of successive `ofLerp`s we applied, i.e. the number of ~~successive~~**[mh:nested?]** times we ~~changed~~**[mh:mapped?]** using our parameter $t$.

##### …And So On
The general notion in Uni level Calculus is that _you can do anything if you have enough of something_. So fittingly, there's a curious little idea in Mathematics which allows us, with enough of these nested control points, to approximate any curve segment we can imagine. In the original formulation of that idea (called a _Taylor Series_), we only reach a good approximation if the amount of degrees (successive `lerp`s we applied) is close to infinity.  **[mh: important concept, but feels out of place here.  I'd either add an example of taylor expansion or ax the section.  coming from optics where we used the small angle approx constantly, my favorite ones are the trig functions]** In Computer Graphics, as you're about to see - 3 is close enough.

### Splines
**[mh: readers might find this opening a bit sudden, esp. if they don't know what a control point is yet]**
What we've done in the previous ~~chapter~~ __[BD: section?]__ is really quite remarkable. We have built a rig for control points, on top of which we built a rig for controlling these points in pairs, and we continued to do so until we ended up with one parameter, $t$, to control them all. For reasons you're about to see, Mathematicians will often shy away from the description of polynomials as a physical metaphor, so not many math books will describe this process to you this way. But anyone who's done even the slightest bit of design will benefit from that idea immensely. 

The reason to avoid describing polynomials to a physical being is what happens to them soon after they step away from their control points. Every polynomial will eventually go to infinity - which is a broad term, but for us designers it means that slightly off it's range, we'll need a lot more paper, or computer screen real estate, or yarn, or cockroaches (true story **[mh: can't just drop something like this in and then walk away from it...I need to know]**) in order to draw it. 

**//TODO: Draw a polynomial going to infinity **

So instead of using polynomials the way they are, some mathematicians thought of a clever thing to do: use only the good range, wait for the polynomial to do something we don't like (like turn from positive to negative), **then mix it with another polynomial**. That actually works pretty well:

**//TODO: Drawing of a spline with 4 basis curves **

In the illustration, we've taken a few parts of the same cubic (3rd degree) polynomial, moved it around and scaled it to taste, and added all of them together at each point (let's call it 'mixing'). 

The resulting curve is seamless and easy to deal with. It also carries some sweet properties: using it, one can use the absolute minimum of direction changes to draw any cubic polynomial between any two points. **[mh: maybe add another sentence here to unpack this]** In other words, _it's smooth_.

These properties make this way of creating curves pretty popular in computer graphics, and you may find its variants under different names, like _Beziér Curves_ or Spline Curves. The code for implementing this is a little long and tedious in C++, so this chapter won't go into it - but in case you were wondering, it's just the same code for making polynomials we discussed above, only with a lot of `if` statements to check if `t` is in the correct range.

Using the curve functions in openFrameworks is pretty straightforward: All you have to do is start from a point, and then add a destination, along with the control points **[mh: worth defining a control point somewhere in here]** to reach it:
```cpp
// The beginning point
line.addVertex(ofPoint(200, 400)); 
// A sequence of two control points and a destination: 
// The first control point's x and y, the second control point's x and y, 
// and the destination
line.bezierTo(100, 100, 800, 100, 700, 400); 
```
That code generates this image:
![Beziér](http://openframeworks.cc/documentation/graphics/bezier.png)

This is just one example of use though. All of the different combinations are documented extensively in the _Advanced Graphics_ chapter. 


### Tweening

So far we've learned how to use a bunch of control points to create an interesting curve in space. We've used our parameter $t$ to simulate the time it takes to draw each point on the curve __[BD: Is this the first time that you directly mention that $t$ represents time? I know that it might seem implied, but perhaps mention this explicitly the first time you use $t$]__. We also implicitly assumed that time runs only in the period that we let it run in, in the case of our examples, between 0 and 1. But we never really tested what it looks like to run all of that in real time. 

**//TODO: Drawing of a smoothstep curve **

Apparently, it's not that different from running it through space. By looking at the $x$ dimension of this graph as time and the $y$ dimension of this graph as a value for our creation, we can see some patterns of animation forming. The trick is simple: think of all of the values that need to change in your animation, and control them using functions. 

#### Example:
** //TODO: Make a ball bounce, an eye blink, and a door to slam from the wind. **

Tweening is not yet a standard part of the openFrameworks library. In the meantime, some nice utility functions for tweening are available in the ofxTween library.

## More Dimensions: Some Linear Algebra
Until now, we explored several ideas on how to change what's going on the number line. That's cool, but we want to know how to do graphics, and graphics has more than one dimension. Our ancient Mathematician ancestors (Just kidding, most important Mathematicians die before 30. Not kidding) also faced this problem when trying to address the space of shapes and structures, and invented some complex machinery to do so. The fancy name for this machinery is _Linear Algebra_, which is exactly what it sounds like: using algebraic operations (add and multiply, mostly), in order to control many lines. 

In this section you're going to learn many concepts in how to store and manipulate multidimensional information. You'll later be able to use that information to control realtime 3d graphics using OpenGL, and impress the opposite (or same) sex with your mastery of geometry.

### The Vector
You may have heard of vectors before when discussing directions or position, and after understanding that they can represent both, may have gotten a little confused. Here's the truth about Vectors™: 
	
	A vector is just an array that stores multiple pieces of the same type information. 

Seriously, that's all it is. Quit hiding.

This simplicity is also their great power. Just like the number 5 can be used to describe five Kilometres, the result of subtracting 12 and 7, or the number of cookies in a jar - the same works with vectors.

It's up to the user of that mathematical object to choose what it is used as. The vector $v=\left(5,-3,1\right)$ can represent a point in space, a direction of a moving object, a force applied to your game character, or just three numbers. And just like with numbers, algebraic operations such as addition and multiplication may be applied to vectors. 

Oh, but there's a catch. You see, everyone was taught what $a + b$ means. In order to go on with vectors, we need to define that.

#### Vector Algebra
Generally speaking, when dealing with Algebra of numerical structures that aren't numbers, we need to pay close attention to the _type_ of things we're cooking together. In the case of vectors, we'll make a distinction between _per-component_ and _per-vector_ operations.

##### Scalar Multiplication
The product between a vector and a scalar is defined as: 

$$a\left(\begin{array}{c}
x\\
y\\
z
\end{array}\right)=\left(\begin{array}{c}
ax\\
ay\\
az
\end{array}\right)$$

That falls into the category of _per-vector_ operations, because the entire vector undergoes the same operation. Note that this operation is just a scaling.  

```cpp
ofVec3f a(1,2,3);
cout << ofToString( a * 2 ) << endl; 
//prints (2,4,6)
```

##### Vector Addition
Adding vectors is pretty straightforward: it's a _per-component_ operation:

$$\left(\begin{array}{c}
x_{1}\\
y_{1}\\
z_{1}
\end{array}\right)+\left(\begin{array}{c}
x_{2}\\
y_{2}\\
z_{2}
\end{array}\right)=\left(\begin{array}{c}
x_{1}+x_{2}\\
y_{1}+y_{2}\\
z_{1}+z_{2}
\end{array}\right)$$ 


```cpp
ofVec3f a(10,20,30);
ofVec3f b(4,5,6);
cout << ofToString( a + b ) << endl; 
//prints (14,25,36)
```

###### Example: `ofVec2f` as position

Vector addition serves many simple roles. In this example, we're trying to track our friend Gary as he makes his way home from a pub. Trouble is, Gary's a little drunk. He knows he lives south of the pub, so he ventures south; But since he can't walk straight, he might end up somewhere else.

**[mh: does the example here need class structure?  I think it would be equally (or more) readable without it.  Then your chapter wouldn't really require the reader to understand writing custom classes.]**

```cpp
/* in Gary.h: */
class Gary {
public:
	void setPosition(ofVec2f initialPosition){ position = initialPosition; }
	void step(ofVec2f direction){ position += direction; }
	ofVec2f getPosition(){ return position; }
	void draw(){
		//TODO: Fill this
	}
private:
	ofVec2f position;
}

/* in ofApp.h: */
Gary gary;

/* in ofApp.cpp: */
void ofApp::setup(){
	ofVec2f garysStartingPoint( ofGetWidth() / 2., ofGetHeight() / 3. );
	gary.setPosition( garysStartingPoint );
}

void ofApp::update(){
	if (gary.position.y < ofGetHeight * 2. / 3.){
		ofVec2f nextStep(ofRandom(-1.,1.),1.); //Take one step south, Gary
		gary.step();
	}
}

void ofApp::draw(){ gary.draw(); }
```

###### Example: `ofVec2f` as velocity

##### Note: C++ Operator Overloading

**[mh: this proke the flor a bit for me, so I'd recommend pushing it later][BD: Agreed.]**

Just like we had to define the meaning of a product of a scalar quantity and a vector, programming languages - working with abstract representations of mathematical objects, also need to have definitions of such an operation built in. C++ takes special care of these cases, using a feature called _Operator Overloading_: defining the `*` operation to accept a scalar quantity and a vector as left-hand side and right-hand side arguments:

```cpp
ofVec3f operator*( float f, const ofVec3f& vec ) {
    return ofVec3f( f*vec.x, f*vec.y, f*vec.z );
}
```

The same is defined, for example, between two instances of `ofVec3f`:

```cpp
ofVec3f ofVec3f::operator+( const ofVec3f& pnt ) const {
	return ofVec3f( x+pnt.x, y+pnt.y, z+pnt.z );
}
```

naturally representing the idea of vector addition.

The basic arithmetic operations, `+`, `-`, `*`, `/`,`+=`, `-=`, `*=`, `/=`, exist for both combinations of `ofVec2f`, `ofVec3f` and `ofVec4f`s and between any vector object and a scalar quantity. Whenever an operation is postfixed with `=`, it modifies the left-hand side with the operation, _and only then_. The operations `+`,`-`,`*`,`/` will _always_ return a copy.

Some excellent examples of operator overloading done right exist in the source files for the `ofVec` types. It's encouraged to check them out.

**Warning: Overloading operators will make you go blind.** Programmers use operators without checking what they do, so bugs resulting from bad overloads take a long time to catch. If the expression `a + b` unexpectedly returns a reference instead of a copy, a `null` instead of a value, or modifies one of the input values – someone may use it one day, and then that someone may cry for many days. Unless the operator can do one arithmetic thing and that alone, do not overload it with a different meaning. OpenFrameworks may or may not have a feature that tweets for you whenever you've written a silly operator overload. [No one knows](https://code.google.com/p/keytweeter/).

##### Distance Between Points

```cpp
float ofVec3f::distance( const ofVec3f& pnt) const
float ofVec3f::squareDistance( const ofVec3f& pnt ) const
float ofVec3f::length() const
float ofDist(float x1, float y1, float x2, float y2);
float ofDistSquared(float x1, float y1, float x2, float y2);
```
**[mh: might be nice to note an optimization problem where you'd choose to use square distances over distance]**

Let's start by a definition. You may remember the _Pythagorean Theorem_, stating that the length of a line between point $a$ and $b$ is:
$$\text{Distance}\left(\left(\begin{array}{c}
x_{a}\\
y_{a}
\end{array}\right),\left(\begin{array}{c}
x_{b}\\
y_{b}
\end{array}\right)\right)=\sqrt{\left(x_{b}-x_{a}\right)^{2}+\left(y_{b}-y_{a}\right)^{2}}$$

Here's the good news: It's the exact same definition in three dimensions! just add the $z$ term.
$$\text{Distance}\left(\left(\begin{array}{c}
x_{a}\\
y_{a}\\
z_{a}
\end{array}\right),\left(\begin{array}{c}
x_{b}\\
y_{b}\\
z_{b}
\end{array}\right)\right)=\sqrt{\left(x_{b}-x_{a}\right)^{2}+\left(y_{b}-y_{a}\right)^{2}+\left(z_{b}-z_{a}\right)^{2}}$$


Vector Length, then, can be naturally defined as the distance between the vector and the point $\left(0,0,0\right)$:
$$\text{Length}\left(\begin{array}{c}
x\\
y\\
z
\end{array}\right)=\sqrt{x^{2} + y^{2} + z^{2}}$$

And that's exactly what using `.length()` as a property of any `ofVec` will give you.

##### Vector Products: There's More Than One
So you're multiplying two numbers. Simple, right? Five million and seven times three equals something you know. Even if you need a calculator for the result, you still know _it's a number_ that's not the case with vectors. If we just want to resize vectors (the way we do with numbers), we multiply a vector by a scalar and it grows. But what does it mean, geometrically, to multiply by a vector?

If we were to follow the _per-component_ convention that we created, we would get an operation like this:

```cpp
cout << ofToString(ofVec3f(1,2,3) * ofVec3f(1,2,3)) << endl;
//prints (1,4,9)
```

It's also known as the _Hadamard product_. It's intuitive, but not particularly useful. One case it is useful for is if we want to scale something individually in every dimension.

In the next section we describe something more helpful.

##### The Dot Product

```cpp
float ofVec3f::dot( const ofVec3f& vec )
```

The dot product of two vectors has a definition that's not too clear at first. On the one hand, the operation can be defined as $v_{a}\bullet v_{b}=x_{a}\cdot x_{b}+y_{a}\cdot y_{b}+z_{a}\cdot z_{b}$, which is really easy to implement, on the other hand, it can also bet defined as $v_{a}\bullet v_{b}=\left\Vert v_{a}\right\Vert \cdot\left\Vert v_{b}\right\Vert \cdot\cos\theta$, where $\theta$ is the angle between the two vectors.

For reasons you'll learn soon, it's a rather surprising coincidence.

__[BD: Perhaps an english definition of dot product would be helpful]__

**//TODO: Finish this**


##### Example: Dot product for playing billiards in 2D

### The Matrix™ 

**[mh: matrices could use a little motivation for the uninitiated reader, i.e. why they are convient+powerful and why we use them in graphics]**

In the computer world, a program needs the two things to function: Algorithms and Data Structures (it also needs I/O, but we're talking Turings, not Perlins **[mh: huh?]**). In the 3D Maths world it's exactly the same: we call our data structures 'vectors' and our algorithms are operations. 

At the core of the heavy machinery built to control ~~3d~~ 3D __[BD: I'd stay consistent with 3D vs 3d throughout the chapter]__ space, a matrix is just a data structure, like a vector. However, the 'algorithms' applied to this data structure (operations, in Mathland) make it an extremely powerful one. All of the _affine_ operations we care about in 3D can be described in the form of a matrix: translation, rotation, scaling, inversion, squeezing, shearing, projection and more and more.

As a convention, we'll be marking vectors with lowercase letters and matrices with uppercase letters.

COME BACK 
#### Matrix Multiplication as a dot product
The easiest way to look at a matrix is to look at it as a bunch of vectors. Depending on what we care about, we can either look at the columns or rows as vectors. 

**//TODO: Draw 2x2 example**

**[mh: you show left vs right multiplying below with identity matrices, so presumably you will explain that order matters in the example above?]**

##### Identity
Let's start from the simplest case. Just like with numbers, it is a very important property of any algebraic structure to have a _neutral_ member for each operation. For example, in Numberland, multiplication of any $x$ by 1 returns $x$, same goes for addition to 0.
In Matrixland, that identity element is a matrix with 1s along the diagonal zeroes elsewhere. For example, the identity matrix for 3 dimensions is:

$$I_{3} = \left(\begin{array}{ccc}
1 & 0 & 0\\
0 & 1 & 0\\
0 & 0 & 1
\end{array}\right)$$

So for any matrix $M$, $MI = IM = M$.

##### Scale
You might remember that when scaling a vector (i.e point in space and/or velocity and/or force and/or brightness value for a colour, etc), we may choose to scale it uniformly by scalar multiplication **/\* TODO:Example \*/** or, because of a weird language design choice, most graphics applications will allow you to scale non-uniformly on a per-component basis: **/\* TODO:Example \*/**

To put an end to this insanity, scaling in matrix multiplication is well-defined (_sidenote_: well defined means blah blah) in openFrameworks (also in math!). It goes like this: The matrix $S$ that scales $\left(x,y,z\right)^{T}$ to $\left(ax,by,cz\right)^{T}$ is: $$S\cdot \left(\begin{array}{c}
x\\
y\\
z
\end{array}\right)=\left(\begin{array}{ccc}
a & 0 & 0\\
0 & b & 0\\
0 & 0 & c
\end{array}\right)
\cdot \left(\begin{array}{c}
x\\
y\\
z
\end{array}\right) = 
\left(\begin{array}{c}
ax\\
by\\
cz
\end{array}\right)$$

There's logic behind this. Recall that a vector multiplied by a matrix, $M\cdot v$ is just a collection of dot products: 
$$
M\cdot v=\left(\begin{array}{c}
M_{1}\\
M_{2}\\
M_{3}
\end{array}\right)\cdot v=\left(\begin{array}{c}
\begin{array}{c}
M_{1}\cdot v\\
M_{2}\cdot v\\
M_{3}\cdot v
\end{array}\end{array}\right)
$$

**//TODO: Improve this**

So, in order to get a multiplication through that only affects $x$, we tune the vector (upper row of the matrix) $M_{1}$ to be zero anywhere but the interface with $x$: $$M_{1} = \left(a,0,0\right)$$ so the entire calculation would be:

$$
M\cdot v=\left(\begin{array}{c}
M_{1}\\
M_{2}\\
M_{3}
\end{array}\right)\cdot v=
\left(\begin{array}{ccc}
a & 0 & 0\\
M_{2,1} & M_{2,2} & M_{2,3}\\
M_{3,1} & M_{3,2} & M_{3,3}
\end{array}\right)\cdot v=\left(\begin{array}{c}
\begin{array}{c}
a\cdot v_{x} + 0\cdot v_{y} + 0\cdot v_{z}\\
M_{2,1}\cdot v_{x} + M_{2,2}\cdot v_{y} + M_{2,3}\cdot v_{z}\\
M_{3,1}\cdot v_{x} + M_{3,2}\cdot v_{y} + M_{3,3}\cdot v_{z}
\end{array}\end{array}\right)
$$
Making the $x$ component of the resulting vector be $a\cdot v_{x}$, just as promised.

Scalar multiplication of any matrix $M$ becomes really easy, then: it's essentially right multiplication by a diagonal matrix full of $a$'s: $$a\cdot M = a \cdot I \cdot M$$

##### Skew matrices

**[mh: this could use an image]** 

Odd operations like skewing are where things need to get a little less intuitive and more logical. When we think of _skewing_ we normally imagine adding to a certain dimension, suppose $x$, a proportion of a quantity from another dimension, let's say $y$. Suppose that proportion is some $0 < a \leq 1$, as if to say, 'I want to nudge it a little, the more it leaves the ground'. The matrix for doing that in 2 dimensions would look like this: 
$$S = \left(\begin{array}{cc} 
1 & a\\
0 & 1 
\end{array}\right)$$
See what we did there? We made the resulting $x$ value depend on the input $x$ value (being multiplied by 1), but also slightly depend on the input $y$, exactly how slightly being determined by the magnitude of $a$:

$$S\cdot v = \left(\begin{array}{cc} 
1 & a\\
0 & 1 
\end{array}\right)
\left(\begin{array}{c}
x\\
y\end{array}\right) = 
\left(\begin{array}{c}
1\cdot x + a\cdot y\\
0\cdot x + 1 \cdot y\end{array}\right) = 
\left(\begin{array}{c}
x + ay\\
y\end{array}\right)$$

Pretty neat, right? Try to remember this trick, as we're going to use it quite a lot when we move stuff around in the fourth dimension. I'm not even joking.

 
##### Rotation matrices
We now see that any operation in Matrixland can really be expressed in a collection of vectors. We also know that dot products of vectors express the angle between two vectors times their magnitude. A slightly surprising fact is that those two properties are enough to describe any rotation.

In order to grok **[BD: grok might be a bit confusing here, especially when tossing around actual math jargon.]** this last statement, let's first explain how rotating one vector works. Let's suppose for now our vector has length 1 (it's generally a good thing to start from, as it is then neutral to scaling), and that we would like to rotate the vector by an angle $\theta$, starting from a point on the x axis. The rotated vector would be $$v_{\theta}=\left(\begin{array}{c}
\cos\theta\\
\sin\theta
\end{array}\right)$$
 
Let's look at that for a moment. 
**//TODO: write what the cosine and sine is**
Now we found a target for the $x$ axis to go to. In order to find a new home for the old $y$ axis, we only need to know the angle between them. Luckily, we all know that it's 90 degrees, or in radians: $\frac{\pi}{2}$. The new home will then have to be at angle $\theta + \frac{\pi}{2}$ from the x axis (angle 0):
 
$$
y_{\theta}=\left(\begin{array}{c}
\cos\left(\theta+\frac{\pi}{2}\right)\\
\sin\left(\theta+\frac{\pi}{2}\right)
\end{array}\right) = \left(\begin{array}{c}
-\sin\theta\\
\cos\theta
\end{array}\right)
$$
 
That last equality is due to trigonometric equalities. 
###### 2D Rotation Matrices
We now have all of the information we need to build a matrix that moves the vectors $\left\{ \left(\begin{array}{c}
1\\
0
\end{array}\right),\left(\begin{array}{c}
0\\
1
\end{array}\right)\right\}$ to $\left\{ \left(\begin{array}{c}
\cos\theta\\
\sin\theta
\end{array}\right),\left(\begin{array}{c}
-\sin\theta\\
\cos\theta
\end{array}\right)\right\}$ :
 
**//TODO: Write a 2D rotation matrix**
 
Now, hold on. Check out what we did here: we placed the targets for the source vectors as _columns_ in the matrix, and then we took the resulting _rows_ of the matrix to do the rotation. Why did we do that? 
 
Recall that a matrix is just a stack of dot products. How did we construct these dot products?  We just aligned all of the entries that should be affecting the _resulting_ entry in one row of the matrix. That means that when considering the resulting $y$ entry, our vectors defined _the mixture of $y$ components_ from the target vectors that we would like to see in the resulting operation. This makes sense: Think of the vectors that compose the matrix as a new coordinate system, and what we're calculating is how the 'natural' coordinate system is projected onto them.
 
###### 3D Rotation Matrices
 
The trick works the exact same way with 3d matrices: In order to rotate around on 
**//TODO: OH GOD WRITE THIS**
 
* Example: Vibrating a brick-phone in 3D.
    
#### Matrix Algebra
This chapter introduced a different kind of math from what you were used to. But while introducing _a new thing to do things with_ we opened up a lot of unexplored dangers. Notice that we always multiplied vectors by matrices in a certain order: It's always the vector _after_ the matrix, the vector is always transposed, and any new operation applied to an existing situation always happens with a matrix to the left of our result. There's a reason for all of that: Commutativity.
 
##### Commmumamitativiwha?
In high school Algebra, we used to think that $a\cdot b=b\cdot a$. No reason not to think that: The amount of uranium rods that you have times the amount of specially trained monkeys that I have equals the same amount of casualties, no matter the order of multiplication. That's because quantities are _commutative_, the order in which they apply operations to each other doesn't matter.  **[mh: these two sentences say the same thing][BD: I think this repeat is actually helpful. I would leave it.]**
 
But, in matrixland we're not talking about things we counted - instead, we're talking about operations, and _operations are generally not commutative_. There's a difference between scaling a square by x and then rotating it by 90 degrees and doing it the other way around:
 
**//TODO: Draw this**
 
**[BD: ~~It might be worth _really_ stressing the above point. The order of operations with vector's can lead to some confusing bugs if you aren't careful.~~ Just read that you do that in the SRT Operations section. Perhaps it would be nice to mention that "more on order of operations below" or something.]**

What's more, doing it the other way around is not always defined. Matrices and vectors with unequal sizes have very special conditions in which they could be multiplied. We're not dealing with them now, so I'll let you read about it in Wikipedia, but it's important to know that whenever using matrices for manipulating a space, order of operands is really important.
 
##### What else is weird?
**Nothing.** We can still multiply the matrices and vectors in any order that we want to: $$M_{1}⋅M_{2}⋅v = \left(M_{1}⋅M_{2}\right)⋅v = M_{1}⋅\left(M_{2}⋅v\right)$$ as long as we don't change the order in which they appear. That property is called _Associativity_, and it's one of the defining properties of algebraic structures that describe geometric operations, structures which mathematicians call _Groups_. _Commutativity_ is an optional property for groups, it just happens to be a given when dealing with operations between numbers, which is why you've never been told that you need it. There's a lesson here: simulations take a lot of properties for granted. It's sometimes good to ask why.
 
Now grab a pack of ice, place it on your head for 15 minutes and go on reading the next part.
 
 
### "The Full Stack"
 
Now that we know how to construct its major components, let's have a look at all the math that constructs graphics in openFrameworks before sending it to the screen. For that, we'll have to – once again – increase our number of D's.
 
#### Translation matrices
 
If you recall the comment in the beginning of this chapter, mathematicians are very careful when calling things linear. In 2D, a linear operation can basically do 2 things: Rotation and Scaling (including negative scaling - "mirroring"). The reason for this is that these are all operations that can be done in n dimensions to any n-dimensional shape (replace n with 3 for our example).
 
If the entire shape lifts itself magically and moves away from the origin - it can't be done with a matrix, therefore it's not linear. This presents a problem to people who want to use matrices as an algebraic system for controlling 3d: in real life we need to move some stuff around.
 
##### Homogenous coordinates: Hacking 3d in 4d
This problem has caused hundreds of years of agony to the openFrameworks community, until in 1827 a hacker called Möbius pushed an update to the ofMäth SVN repo: use the matrix in 4 dimensions to control a 3 dimensional shape. Here's the shtick: a 3d operation can be described as a 4d operation which doesn't do anything to the 4th dimension. Written as a matrix, we can describe it like this:
 
$$ A _{4\times 4} = \left(\begin{array}{ccc|c}
a_{1,1} & a_{1,2} & a_{1,3} & 0\\
a_{2,1} & a_{2,2} & a_{2,3} & 0\\
a_{3,1} & a_{3,2} & a_{3,3} & 0\\
\hline 0 & 0 & 0 & 1
\end{array}\right)$$
 
Now we already know that a 1D Skew can move all lines in that axis in a certain direction without affecting the other dimensions, and that a 2D skew will do that for all things on a certain plane, so it's easy to imagine that a 3D skew will do that to 3D spaces embedded in a space with more dimension. Möbius figured that feature is useful. On the biannual openFrämeworks meeting in Tübingen, he proposed that all operations should be conducted in 4D space, and then projected back into 3D space, like this:
 
$$T = \left(\begin{array}{ccc|c}
1 & 0 & 0 & t_{x}\\
0 & 1 & 0 & t_{y}\\
0 & 0 & 1 & t_{z}\\
\hline 0 & 0 & 0 & 1
\end{array}\right)$$
 
The 3D Transform vector $t$ is placed in the 4th dimension, with it's 4th entry as 1 (because 1 is neutral to multiplication). The bottom row that is added has zeroes in the $x,y,z$ entries, in order to avoid interfering with other operations. Check out what happens when a vector is multiplied by this matrix: 
 
$$T\cdot v = \left(\begin{array}{ccc|c}
1 & 0 & 0 & t_{x}\\
0 & 1 & 0 & t_{y}\\
0 & 0 & 1 & t_{z}\\
\hline 0 & 0 & 0 & 1
\end{array}\right)\cdot\left(\begin{array}{c}
x\\
y\\
z\\
\hline 1
\end{array}\right)=\left(\begin{array}{c}
x+t_{x}\\
y+t_{y}\\
z+t_{z}\\
\hline 1
\end{array}\right)$$
 
Now all we need to do is discard the 4th dimension to get our translated point. Quite cool, innit?
 
Notice that because we placed a 1 at the $w$ (4th) dimension, all of the multiplication operations went through that component transparently. This trick became the standard of most computer geometry systems. Möbius actually has a lot more going in this theory: if we change that 1 into something else, we're able to simulate a projection into a camera pinhole. This chapter won't cover that fascinating part of math, but when you get to building cameras in OpenGL, keep this amazing hack in mind.
 
#### SRT (Scale-Rotate-Translate) operations
Now we've defined the operations we like the most to describe (sort-of) real world objects moved around in space. Let's spend a few paragraphs talking about how to combine all of the operations together.
 
If you recall, geometric operations are _non-commutative_, which means that if we defined them in a specific order, there's no guarantee that changing the order will provide us with similar results. ~~That means that when building a graphics system we need to exercise systematic vigilance when executing human stuff like "Turn that spindle around so I
may see its refractions of the sun" without accidentally turning the sun around its' axis, incinerating the good people of Uranus.~~ **[mh: this felt distracting]**
 
The way we execute that vigilance is by a predefined order for handling objects. If you grab a pen and paper it won't take too long to figure that order out:

1. Modify the scale (if need be).
2. Modify the orientation (if need be).
3. Modify the position (if need be).
4. Rejoice.
 
Any other order will cause weird effects, like things growing and spinning off their axes (anchor point / pivot, if animation is your jam). This may seem like common sense, but Ken Perlin notes that it was only the late 80s when that system became a standard for 3d. 
 
This set of operations is called _SRT_, or _Scale-Rotate-Translate_, because it can be described by the following sequence of matrices: $$T⋅R⋅S⋅v$$
Where the first operation occuring is the one most adjacent to the vector $v$.
 
If you recall, we can multiply all of these matrices to get one matrix representing all the entire operation:  $$M = T⋅R⋅S$$
 
We call this matrix $M$, because it places objects we give it in their place in the _Model_. Whenever you call `ofTranslate()`, `ofRotate()`, `ofScale()` (or equivalent) on an object, that operation is applied to the **currently active _Model_ matrix**. Whenever you execute `ofPushMatrix()`, a copy of that matrix is saved in _the matrix stack_, so that you can go back to it when necessary. And when necessary, you will then use `ofPopMatrix()`, which will cause the current matrix $M$ to be deleted and replaced with a matrix from the top of the matrix stack. That is the entire mystery about matrices. ~~That's it.~~ **[BD: I don't think you need that.]**
 
In the 'Advanced Graphics' chapter you'll learn about two similar matrices: 
* The _View_ matrix tramsforms the result of the _Model_ matrix to simulate where our camera is supposed to be at.
* The _Projection_ matrix applies the optical properties of the camera we defined and turns the result of the _View_ matrix from a 3D space to a 2D image. The Projection matrix is built slightly different than the _Model-View_ matrix, but if you've made it this far, you won't have trouble reading about it in a special Graphics topic.
 
 
##### Thanks
Thanks to Prof. Ken Perlin and Prof. Bo'az Klartag for your ideas on teaching mathematics.