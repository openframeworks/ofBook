#Memory in c++#

Correctly using the memory is one of the trickest parts of working with c++. The main difference with other languages like Java, Python and in general any language that works with a virtual machine is that in c++ we can explicitly reserve and destroy objects while in those an element called garbage collector does the work for us.

There's also an important difference, in c++ we have two different memory areas, the heap and the stack, if you are used to work with processing, Java or Python you'll be used to only have heap memory.

We'll see later what the main differences are, but first let's see what's memory and what happens when we create variables in our program.

## Computer memory and variables ##

It's helpful to understand at least at a high level how computer memory works.

A computer has different types of memory, in this section we are going to be talking about RAM (Random Access Memory) memory. The kind of memory where the computer stores the code for the programs that are executing at every moment and the data those programs are using.

Your computer probably has something like 4Gb of RAM, in c++ we can access most of that memory, and to access it what we do is create variables.

For example when we create a variable like:

```cpp
int i;
```

what we are doing is reserve 4 bytes of those 4Gb to store an int, it doesn't really matter if we are storing ints or other types of data, the sizes might be different for and int a char, a float or a string but the type of memory is always the same.

Internally the computer doens't really now about that memory area as i but as a memory address. A memory address is just a number that points to a specific byte in the 4Gb of memory.

When we create a variable like `int i` we are telling our program to reserve 4 bytes of memory, associate the address of the first byte of those 4 to the variable name `i` and restrict the type of data that we are going to store in those 4 bytes to only ints.

<img src="https://rawgithub.com/openframeworks/ofBook/master/16_memory/int_i.svg" height="300"/>

Usually memory addresses are represented in [hexadecimal](http://en.wikipedia.org/wiki/Hexadecimal). In c++ you can get the memory address of a variable by using the `&` operator, like:

```cpp
cout << &i << endl;
```

The output of that cout is the memory address of the first byte of the variable `i` we just created.

Later on when we asign a value to that variable, what it's happening is that we are storing that value in the memory area that we've just reserved by declaring the variable, so when we do:

```cpp
i = 0;
```

Our memory will look like:

<img src="https://rawgithub.com/openframeworks/ofBook/master/16_memory/int_i_equals_0.svg" height="300"/>

The order in which the bytes that form the int are layed out in the memory depends on the architecture of our computer, you'll prpbably seen [little endian and big endian](http://en.wikipedia.org/wiki/Endianness) mentioned sometime. Those terms refer to how the bytes of a data type are ordered in memory, if the most significative bytes come first or last. Most of the time we don't really need to know about this order but most modern computer architectures use little endian.

If you've used c++ for a while you've probably had crashes in your programs because of bad memory accesses. Usually the message you'll see is something like `segmentation fault...`. What does that mean?

When you create variables in a program, even in c++, you can't really access all the memory in the computer, for security reasons. Imagine you had your bank account opened in your browser, if any program could access all the memory in the computer a malign application could just access the memory of the browser and get that information or even modify it. To avoid it the operating system asigns chuncks of memory to every program. When your application starts it's asign a `segment` of memory, later on as you create variables if there's enough memory in that `segment` your variables will be create there. When there's not more memory available the application asks the operating system for another segment and starts using that. If you try to access a memory address that doesn't belong to a segment asigned to your application, the operating system just kills the application to avoid possible security risks.

How does that happen usually? Well most of the time you just don't try to access memory addresses by their number, so how's it possible that sometimes you try to access a variable and you get a segmentation fault. Most of the time this happens because you try to access a varible that doesn't exist anymore, usually because you stored a pointer to a memory area and then free or move that memory somewhere else. We'll talk in more detail about this later

## Stack variables, variables in functions vs variables in objects 

As we said at the beginning of the chapter there's two types of memory in c++ the stack and the heap. Let's talk first about the stack since that's the easiest type of memory to use and what you'll use more frequently in openFrameworks.

The stack is the type of memory that you use when creating variables inside a function or in the .h of your class as long as you don't use pointers and the keyword new.

It's called stack because it's organized like a [stack](http://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29). When in our application we call a function, there's an area in memory asigned to that function **call** where it can create variables in that area. 

Those variables stop existing when the function call ends. So for example you can't do:

```cpp
void ofApp::setup(){
    int a = 0;
}

void ofApp::update(){
    a = 5; // error a doesn't exist outside setup
}
```

Also since we are talking about function calls you can store a value in an stack variable and expect it to be there when the function is called again.

In general we can say that variables exist in the block they've been defined, a block in c++ is defined by the `{}` inside which a variable was defined, so for example, doing this won't be valid either:

```cpp
for (int i=0;i<10;i++){
    int a = 5;
}
cout << a << endl; // error a doesn't exist outside the {} of the for
```

We can even do this:

```cpp
void ofApp::setup(){
   {
        int a = 0;
        // do something with a
   }
   
   {
        int a = 0;
        // do something with a
   }
}
```

which is not very common but is used sometimes to define the life of a variable inside a function, mostly when that variable is an object that holds resources and we want to only hold them for a specific time.

The life of a variable is called `scope`.

Apart from creating variables inside functions we can also create variables in the class declaration in our .h like:

```cpp
class Ball{
public:
    void setup();
    
    float pos_x;
}
```

These kind of variables are called `instance variables` because every instance or object of our class will get a copy of it. The way they behave is the more or less the same as the stack variables created in functions. They exist for the duration of the {} in which they were defined, in this case the {} of the object to which they belong.

These variables can be accessed from anywhere in the class so when we need to have data that is accessible from any function in an object of this class we create it like this.

The memory in the stack is limited, the exact size, depends on the architecture of our computer, the operating system and even the compiler we are using. In some systems it can even be changed during the runtime of the application, but most of the time we won't hit that limit.

Even if we create all of our variables in the stack, usually the objects that consume most memory like for example a vector or in openFrameworks something like ofPixels, will create most of the memory they use internally in the heap which is only limited by the amount of memory available in the computer so we don't need to worry about it.

We'll see in the next sections how the heap works and what are the advantages of using the heap or the stack.

## Pointers and references ##

Before talking about heap memory let's see how pointers and references work in c++, what's their syntax and what's really happening with memory when we create a pointer or a reference.

As we've seen before we can get the address of a variable by doing:

```cpp
cout << &i << endl;
```

And that will give us the memory address of the first byte used by that variable no matter it's type. When we store that memory address in another variable that's what we call in c++ a pointer. The syntax is:

```cpp
int i = 0;
int * p = &i;
```

And what we get in memory is something like:

<img src="int_i_equals_0.svg" height="100"/>

A pointer usually occupies 4 bytes, we are representing it as 1 byte only to make things easier to understand, but as you can see it's just another variable, that instead of containing a value contains a memory address that points to a value that's why it's called pointer.

A pointer can point to heap or stack memory.

Now, let's explain something that it's really important to take into account when programming in c++. As we've seen till now, when we declare a variable like:

```cpp
int i;
```
We get a memory layout like:

<img src="int_i.svg" height="100"/>

As we see there's no value in that memory area yet. In other languages like processing doing something like:

```java
int i;
println(i)
```

is illegal, the compiler will tell us that we are trying to use a variable that is not initialized. In c++ though, that's perfectly legal but the contents of that variable are undefined. Most of the times we'll get 0 because the operating system will clear the memory before assigning it to our program, again for security reasons. But if we are resuing memory that we had already assigned then that memory area will contain anything and the results of our program can be undefined.

If for example we have a variable that defined the position of something we are going to draw, failing to initialize it will lead to that object being drawn anywhere.

Now most objects have default constructors that will initialize their value to, for example 0, so in the case of objects it's usually not necessary to give them a value.

What happens when we use an initialized pointer? Well since a pointer is a memory address if the value we get in that memory area points to an address that doesn't belong to our program and we try to retrieve or modify the value stored in that address the OS will kill our application with a segmentation fault signal.

Back to pointers, we've seen that, we can create a pointer like:

```cpp
int i = 5;
int * p = &i;
```

now, if we try to use the pointer directly like;

```cpp
cout << p <<< endl;
```

what we'll get is a memory address not the value 5. So how do we access the value pointed by a pointer, well we can use the opposite operator to `&`, as `&` gives us the address of a variable, `*` gives us the value pointed by a memory address, so we can do;

```cpp
cout << *p << endl;
```

and we'll get the value 5 printed now. We can also do:

```cpp
int j = *p;
cout << j << endl;
```

and again will get the value 5 since we made a copy of the value pointed by p in j.

The `&`operator is called the *reference operator* since it gives us a reference to a variable, it's memory address. The `*` operator is it's opposite, the *dereference operator* and it gives us the value pointed by a pointer, it dereferences a reference, a memory address, so we can access it's value instead of the address.

Till now, we've work with primitive values, ints really but the behaviour will be the same for any other primitive value, like float, short, char, unsigned int...  In c++ in fact the behaviour is also the same for objects.

If you are used to Java, for example you've probably noticed that while in Java and C++ this:

```cpp
int a = 5;
int b = a;
a = 7;
cout << "a: " << a << " b: " << b << endl;
```

will behave the same, that's, a will end up being 7 and a will be 5. When we use objects the behaviour in c++ is different to that of Java. For example, let's say we have a class Ball:

```cpp
class Ball{
public:
    void setup();
    //...
    
    ofVec2f pos;
}
```

or the similar class in processing;

```java
class Ball{
    void setup();
    
    PVector pos;
}
```

if in c++ you do:

```cpp
Ball b1;
b1.pos.set(20,20);
Ball b2;
b2 = b1;
b2.pos.set(30,30);
```

b1 pos will end up being 20,20 and b2 30,30 while if you do the equivalent in java both b1 and b2 will have position 30,30:


```cpp
Ball b1 = new Ball();
b1.pos.set(20,20);
Ball b2;
b2 = b1;
b2.pos.set(30,30);
```

Notice how in the case of Java we have made new for the first ball but not for the second, that's because in Java everything that is an object is a pointer in the heap so when we do `b2 = b1`we are actually turning b2 into a reference to b1, and when we later change b2, we are also changing b1.

In c++, instead when we do `b2 = b1` we are actually copying the values of the variables of b1 into b2 so we still have 2 different variables instead of a reference. When we modify b2, b1 stays the same.

This is more or less what memory would look like in Java and C++:

<img src="objects_java_c++.svg" height="100"/>

As you can see in c++ objects in memory are just all their member variables one after another. When we make an object variable equal to another, by default, c++ copies all the object to the left side of the equal operator.

Now what would happen if have a class like:

```cpp
class Particle{
public:
    void setup();
    //...
    
    ofVec2f pos;
    ParticleSystem * parent;
}
```

And we do:

```cpp
Particle p1;
Particle p2;
ParticleSystem ps;

p1.pos.set(20,20);
p1.parent = &ps;
p2 = p1;
```

Well as before c++ will copy the contents of p1 on p2, the contents of p1 are an ofVec2f which consits of 2 floats x and y and then a pointer to a ParticleSystem, and that'w what gets copied, the ParticleSystem itself won't get copied only the pointer to it, so p2 will end up having a copy of the position of p2 and a pointer to the same ParticleSystem but we'll have only 1 particle system.


<img src="object_with_pointers.svg" height="120"/>

The fact that things are copied by default and that objects can be stored in the stack as oposed to being always pointer has certain adavantages. For example, in c++ a vector or an array of particles like the ones we've used in the last example will look like:

```cpp
vector<Particle> particles;
```

in memory all the particles will be contiguous, among other things that makes accessing them faster than if we had pointers to a different location in memory. It also makes it easier to translate c++ vectors to openGL memory structures but that's the topic for another chapter.

Among other things we need to be aware of the fact that c++ copies things by default, when passing objects to functions as parameters. For example this:

```cpp
void moveParticle(Particle p){
    p.x += 10;
    p.y += 10;
}

...

Particle p1;
moveParticle(p1);
```

Is perfectly valid code, but won't have any effect since the function will receive a copy of the particle and modify that copy instead of the original.

We can do this:

```cpp
Particle moveParticle(Particle p){
    p.x += 10;
    p.y += 10;
    return p;
}
...

Particle p1;
p1 = moveParticle(p1);
```

So we pass a copy of our particle to the function which modifies it's values and returns a modified copy which we then copy into p1 again. See how many times we've mentiponed copy in the previous sentence?  The compiler will optimize some of those out and for small objects it's perfectly ok to do that but imagine we had something like this:

```cpp
vector<Particle> moveParticles(vector<Particle> ps){
    for(int i=0;i<ps.size();i++){
        ps[i].x += 10;
        ps[i].y += 10;
    }
    return ps;
}
...

vector<Particle> ps;
...
ps = moveParticles(ps);
```

If we have 1 million particles that will be awfully slow, memory is really slow compared to the cpu, so anything that involves copying memory or allocating new memory should be usually avoided. So what can we do to avoid all that copies?

Well we could use pointers right?

```cpp
void moveParticle(Particle * p){
    p->x += 10;
    p->y += 10;
}
...

Particle p1;
moveParticle(&p1);
```

Now, here's something new, notice how to refer to the variables of a pointer to an object instead of using the dot, we use the `->` operator, everytime we want to access a variable in a pointer to an object instead of having to dereference it like:

```cpp
(*p).x +=10
```

we can use the `->`

```cpp
p->x += 10
```

So that solves our problem, using a pointer instead of passing a copy of the object, we are passing a reference to it, it's memory address, so the function will actually modify the original.

The main problem with this is that the syntax is kind of weird, imagine how would look like if we passed a pointer for the second example, the one with the vector:

```cpp
vector<Particle> moveParticles(vector<Particle> ps){
    for(int i=0;i<ps.size();i++){
        ps[i].pos.x += 10;
        ps[i].pos.y += 10;
    }
    return ps;
}
...

vector<Particle> ps;
...
ps = moveParticles(ps);
```

Now, the function will look like:

```cpp
void moveParticles(vector<Particle> * ps){
```

the problem is that now we can't use the [] operator to access the elements in the vector cause ps is not a vector anymore but a pointer to a vector. What's more this

```cpp
ps[i].x += 10;
```

would actually compile but would mostly sure give as a memory access error, a segmentation fault. ps is now a pointer and when using pointers the `[]' behaves like if we had an array of vectors!

Will explain this in more depth in the section about memory structures, but let's see how to pass a reference that doens't have pointer syntax. In c++ is called a reference and it looks like:

```cpp
void moveParticles(vector<Particle> & ps){
    for(int i=0;i<ps.size();i++){
        ps[i].pos.x += 10;
        ps[i].pos.y += 10;
    }
}

vector<Particle> ps;
...
moveParticles(ps);
```

Now we are passing a reference to the original object but instead of having to use pointer syntax we can still use it as if it was a normal object.

> Advanced note: Some times we want to use references to avoid copies but still be sure that the function we pass our object to won't modify it's contents, in that case it's recomendable to use const like:
```cpp
ofVec2f averagePosition(const vector<Particle> & ps){
    ofVec2f average;
    for(int i=0;i<ps.size();i++){
        average += ps[1].pos;
    }
    return average/float(ps.size());
}
vector<Particle> ps;
...
ofVec2f averagePos = averagePosition(ps);
```
> const only makes it imposible to modify the variable even if it's a reference and tells anyone using that function that they can pass their data into it and it won't be changed, also anyone modifying that function knows that in the future it should stay the same and not modify the parameter

Outside of parameters, references have a copule of special characteristics. 

First we can't modify the content of a reference once it's created, for example we can do:

```cpp
ofVec2f & pos = p.pos;
pos.x = 5;
```

but trying to change the reference itself like in:


```cpp
ofVec2f & pos = p.pos;
pos.x = 5;
pos = p2.pos  // error, a reference can only be asigned on it's declaration
```

Also you can return a reference but depending on what that reference it's pointing to it can be a bad idea:

```cpp
ofVec2f & averagePosition(const vector<Particle> & ps){
    ofVec2f average;
    for(int i=0;i<ps.size();i++){
        average += ps[1].pos;
    }
    average/=float(ps.size());
    return average;
}
```

Will actually compile but will probably result in a segmentation fault at some point or even just work but will get weird values when calling this funciton. The problem is that we are creating the variable `average` in the stack so when the function returns it'll be deleted from memory, the reference we return will be pointing to a memory area that is not reserved anymore for average and as soon as it get overwritten we'll get invalid values or a pointer to a memory area that doesn't belong to our program anymore.

This is one of the most annoying problems in c++ it's called dangling pointers or in this case references and it's caused when we have a pointer or a reference that point to a memory area that is later freed somehow.

More modern langauges solve this with diferent strategies, for example Java won't let this happen since objects are only deleted once the last reference to them goes out of scope but it uses something called a garbage collector that from time to time goes through the memory looking for objects which have no more references pointing to them, and deletes them. This solves the problem but makes it hard to know when objects are going to get really deleted. c++ in it's latest version, c++11, and more modern languages try to solve this using new kinds of pointers that define ownership of the object, will talk about it in the latest section of this chpater, smart pointers.

## Variables in the heap ##

Now that we now the syntax and semantics of pointers lets see how to use the heap. The heap is an area of memory common to all of our application, any function can create variables in this space and share it with others, to use it we need a new keyword `new`:

```cpp
Particle * p1 = new Particle;
```

If you know processing or Java that looks a little bit like it, right? indeed this is exactly the same as a Java object, a pointer to a memory address in the heap, except that in c++ we explictly say that this is a pointer by using the `*` in the declaration.

To access the variables or functions of a pointer as we've seen before we use the `->` operator so we would do:

```cpp
Particle * p1 = new Particle;
p1->pos.set(20,20);
```

or:

```cpp
Particle * p1 = new Particle;
p1->setup();
```

A pointer as any variable can be declared but not initialized as we've seen before:

```cpp
Particle * p1;
p1->setup() // this will compile but fail when executing the application
```

As we've said things created in the heap live as long as we want and any function can access them as long as they have a reference (a pointer) to them. For example:

```
Particle * createParticle(){
    return new Particle;
}

void modifyParticle(Particle * p){
    p->x += 10;
}

...

Particle * p = createParticle();
modifyParticle(p);
```

So how can we say that we don't want to use that variable anymore? we use the keyword `delete`:

```cpp
Particle * p1 = new Particle;
p1->setup();
...
delete p1;
```

This is important when using the heap, if we fail to do this we'll get with what is called a memory leak, memory that is not referenced by anyone but continues to leave in the heap, making our application use more and more memory over time till it fills all the available memory in our computer:

```cpp
void ofApp::draw(){
    Particle * p1 = new Particle;
    p1->setup();
    p1->draw();
}
```

every time we call draw, it'll create a new particle, once we get out of the function we loose the reference *p1 to it but the memory we allocated using new is not freed when the function call ends so our program will slowly get more and more memory, you can check it using the system monitor.

In general most of the time in c++ we don't need to use the heap, at least not directly, classes like vector, ofPixels and other memory structures allow us to use heap memory but still have stack semantics, for example this:


```cpp
void ofApp::draw(){
    vector<Particle> particles;
    for(int i=0; i<100; i++){
        particles.push_back(Particle())
        particles.back().setup();
        particles.back().draw();
    }
}
```

is actually using heap memory since the vector is internally using that, but the vector destructor will take care of freeing that memory for us as soon as the particles variable goes out of scope, when the current call to draw finishes.

## memory structures, arrays vs vectors ##

## other memory structures, maps, sets and lists ##

## smart pointers ##
