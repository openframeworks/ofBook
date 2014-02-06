# That Math Chapter: From 1D to 4D 

## Intro: How Artists Approach Math
** // TODO: Write intro **

…

## About this Chapter
This chapter will be divided into _'numbers of D's'_ : we'll start from one dimension, and slowly explore the possibilities of using scale and change in different dimensions. Depending on how you choose to read it, this section contains hundreds of Mathematicians' lifetime research, or in other words, several classes of college math, so it's worth bookmarking.

When bringing math to innocent readers, most programming books will try to explain the idea, not necessarily the exact implementation. This book is no different. This chapter contains detailed breakdowns of concepts, but if you want to find out what's going on under the hood, there's no alternative to reading the source code - in fact, since all the math here is only a few lines long - it's actually _encouraged_ to have a look at the source.

## One Dimension: Using Change
** // TODO: Write intro **
### Interpolation
#### Linear Interpolation: The `ofLerp`
`float ofLerp(float start, float stop, float amt)`

As xkcd once put it, if you've seen a number larger than 7, you're not doing real math.

Those of you that have already done a little time-based or space-based work have probably noticed that you can often describe elements of your work as sitting on a line between two known points. A frame on a timeline is at a known location between 00:00:00 and the runtime of the film, a scrollbar is pointing to a known location between the beginning and the end of a page. That's exactly what `lerp` does.

With the `lerp` function, you can take any two quantites, in our case `start` and `stop`, and find any point between them, using amounts (`amt`) between 0 and 1. To be verbose: 
 $$\text{lerp}\left(a,b,t\right) = t\cdot b+\left(1-t\right)\cdot a$$ 

##### Note: What does _linear_ really mean?
Engineers, Programmers and English Speakers like to think of _linear_ as _anything you can put on a line_. Mathematicians, having to deal with all the conceptual mess the former group of people creates, define it _anything you can put on a line **that begins at (0,0)**_. There's  good reasoning behind that, which we will see in the discussion about Linear Algebra. In the meantime, think of it this way: if our transformation is taking a line that has a value 0 at the point 0 and returning a line with the same property, (thus in the form $$$f\left(x\right)=ax$$$), It's _linear_. If it returns a value different from 0 at $$$x=0$$$ (in the form $$$f\left(x\right)=ax + b$$$), it's _affine_. 

##### Exercise: Save NASA's Mars Lander 
In 1999, an masterpiece of engineering was making its final approach to Mars. All instruments were showing that the approach distance matched the speed, and that it's just about to get there and do some science. But instead, it did something rather rude: it crashed into the red planet. An investigation made later by NASA revealed that while designing the lander, one team worked with their test equipment set to _centimiters_, while the other had theirs set to _inches_. **By the way, this is all true.**

Help the NASA teams work together: write a function that convers centimeters to inches. For reference, $$$1\_{\text{in}} = 2.54\_{\text{cm}}$$$. Test your result against three different real-world values.

**Think:**

1. Why can we use `lerp` outside the range of 0 and 1?
2. What would it take to write a function that converts inches into centimeters?

#### Affine Mapping: The `ofMap`
`float ofMap(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp = false)`

In the last discussion, we saw how by using `lerp`, any value between two points can be _linearly_ adressed as a value between 0 and 1. That's very convient, and therefore the reason we build most of our arbitrary numerical ranges (`ofFloatColor`, for example) in the domain of 0 and 1. 
However, when dealing with real world problems, programmers run into domains of values that they wish to map to other ranges of values, neither of which are confined to 0 and 1. For example, someone trying to convert the temperature in Celsius to Farenheit won't be able to use  Surely, the way of doing that must involve a `lerp`, but it needs a little help:

If we want to use the `lerp` function, we're aiming to get it to the range between 0 and 1. We can do that by knocking `inputMin` off the input `value` so that it starts at 0, then dividing by the size of the domain: $$x=\frac{\text{value}-\text{inputMin}}{\text{inputMax}-\text{inputMin}}$$
Now that we've tamed the input domain to be between 0 and 1, we do the exact opposite to the output: `ofMap(value, inputMin, inputMax, outputMin, outputMax)` $$$=\frac{\text{value}-\text{inputMin}}{\text{inputMax}-\text{inputMin}}\cdot\left(\text{outputMax}-\text{outputMin}\right)+\text{outputMin}$$$

Now you'll notice that we're missing the `clamp` parameter. This may not matter to us if we're using the `ofMap` function in the range that we defined, but suppose we select a `value` smaller than `inputMin`: would it be ok if the result was also smaller than `outputMin`? If our program is telling an elevator which floor to go to, that might be a problem. That's why we add `true` to the tail of this function whenever we need to be careful.


### Beyond Linear: Changing Change
** // TODO: Write intro **
The notion of _linear_ is where most math begins. 
#### Quadratic Splines
Consider this function:

```
float foo (float t){
	float a1 = ofLerp(t, 5, 8);
	float a2 = ofLerp(t, 2, 9);
	float b = ofLerp(t, a1, a2);
	return b;
	}
```
This function used a defined range and a parameter to create `a1`, then used another defined range with the _same_ parameter to create `a2`. Their result looks surprising:
** // TODO: Draw cublic spline **

We've done something remarkable here. We used the way one parameter changes on two fixed lines to control a third, totally mobile line, and draw one point on it at each point in time between 0 and 1. In Mathspeak, it looks like this:
 
$$
\text{lerp}\left(t,\text{lerp}\left(t,5,8\right),\text{lerp}\left(t,2,9\right)\right)\\\\
= \text{lerp}\left(t,8\cdot t+5\cdot\left(1-t\right),9\cdot t+2\cdot\left(1-t\right)\right)\\\\
= \left(9\cdot t+2\cdot\left(1-t\right)\right)\cdot t+\left(8\cdot t+5\cdot\left(1-t\right)\right)\cdot\left(1-t\right)\\\\
= \left(9t^{2}+2t-2t^{2}\right)+\left(8t+5-5t\right)-\left(8t^{2}+5t-5t^{2}\right)\\\\
= 4t^{2}+5
$$

Something interesting happened here. Without noticing, we introduced a second order of complexity, a _quadratic_ one. If you don't find this relationship remarkable, please give this book to someone who does.

**Exercise:** Find three rulers and plot this line.

#### Cubic splines
The same manipulation can be applied for a third order:

```

float foo (float t){
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
For obvious reasons, we'll skip the entire process, and just tell reveal that the result will appear in the form of $$ax^{3} + bx^{2} + cx + d$$


### Tweening
** //TODO: Write this **
#### Example:
Make a ball bounce, an eye blink, and a door to slam from the wind.

## More dimensions: Some Linear Algebra

Those of you who haven't run into any post-high school math may find this new.

### The Vector
#### Scalar operations
##### A Note About Operator Overloading
Just like we had to define the meaning of a product of a scalar quantity and a vector, $$a\left(\begin{array}{c}
x\\\\
y\\\\
z
\end{array}\right)=\left(\begin{array}{c}
ax\\\\
ay\\\\
az
\end{array}\right)$$ programming languages - working on abastract representations of mathematical objects, also need to have definitions of such an operation built in. C++ takes special care of these cases, using a feature called _Operator Overloading_: defining the `*` operation to accept a scalar quantity and a vector as left-had side and right-hand side arguments:

```
ofVec3f operator*( float f, const ofVec3f& vec ) {
    return ofVec3f( f*vec.x, f*vec.y, f*vec.z );
}
```

The same is defined, for example, between two instances of `ofVec3f`:

```
ofVec3f ofVec3f::operator+( const ofVec3f& pnt ) const {
	return ofVec3f( x+pnt.x, y+pnt.y, z+pnt.z );
}
```

naturally representing the idea of vector addition: 

$$\left(\begin{array}{c}
x\_{1}\\\\
y\_{1}\\\\
z\_{1}
\end{array}\right)+\left(\begin{array}{c}
x\_{2}\\\\
y\_{2}\\\\
z\_{2}
\end{array}\right)=\left(\begin{array}{c}
x\_{1}+x\_{2}\\\\
y\_{1}+y\_{2}\\\\
z\_{1}+z\_{2}
\end{array}\right)$$ 

The basic arithmetic operations, `+`, `-`, `*`, `/`,`+=`, `-=`, `*=`, `/=`, exist for both combinations of `ofVec2f`, `ofVec3f` and `ofVec4f`s and between any vector object and a scalar quantity.

As with previous discussions, some details have been omitted from the source code. _Viewing the ofMath and ofVec3f sources is encouraged_.

#### Vector Length
```
float ofVec3f::length() const
```
#### Distance between points
* Example: `ofVec2f` as position
* Example: `ofVec2f` as velocity
#### The Dot Product
* Example: Dot product for playing billiards in 2D

### The Matrix (TM)
#### Matrix Multiplication as a dot product
#### Some operations with Matrices
##### Identity
##### Scale
##### Rotation matrices
1. in 2D
1. in 3D
	* Example: Vibrating a brick-phone in 3D.
#### The inverse matrix
### "The Full Stack"
#### Homogenous coordinates: Hacking 3d in 4d
#### Translation matrices
#### SRT (Scale-Rotate-Translate) operations
* Example: a pack of sharks swimming
### Really using normals
#### The cross product
#### Normals for lighting
* Example: Dot product for lighting
#### Normals for directions
                
                
                
# Making your software generate (aka That other math chapter)

1. Probability
	1. How artists use probability
	1. Some interesting properties of probability
		1. Always sum to 1
		1. Expectation, Average
			* Example: Flocking, via finding the average of points.
		1. Probability as a density
			* Example: Cell colony in 2D
1. Randomness
	1. Different types of random functions: Uniform, Gaussian, etc
		* Example: Circle packing using `ofRandom`
	1. Markov Chains
		 * Example: ?
1. Noise
	1. From random numbers to streams:
		* Example: White noise
	1. Octaves: The construction of white noise
	1. Building things with `ofNoise`
		* Example: FDM
		* Example: Generative terrain
		* Example: Flickering lights


