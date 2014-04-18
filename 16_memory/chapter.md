#Memory in C++#

*by [Arturo Castro](http://arturocastro.net)*

*corrections by [Brannon Dorsey](http://brannondorsey.com)*

Using memory correctly is one of the trickest parts of working with C++. C++ memory management differs greatly from languages like Java, Python or anything else that works with a virtual machine. In C++, we can explicitly reserve and destroy objects while in other languages, an element called garbage collector does the work for us.

There's also another important difference: In C++ we have two different memory areas, the heap and the stack, while in languages like Processing, Java, or Python we only have heap memory.

We'll see later what the main differences are, but first let's see what memory is and what happens when we create variables in our program.

## Computer memory and variables ##

It's helpful to understand, at least at a high level, how computer memory works.

A computer has different types of memory. In this section we are going to be talking about RAM (Random Access Memory) memory. RAM is the memory where the computer stores the code for the programs that are executing at every moment and the data those programs are using.

Your computer probably has something like 4Gb of RAM. In C++, we can access most of that memory, and we create variables in order to do so. Memory is divided in bytes, which are the minimum memory size that we can usually use in a C++ application. Each data type like char, int, float... has a different size all measured in bytes. Those sizes can be different for different platforms but the most usual is something like:

- char:  1 byte
- short: 2 bytes
- int:   4 bytes
- float  4 bytes
- double 8 bytes

Other types might have variable sizes depending on their contents, like for example, an array or a string.

When we create a variable like:

```cpp
int i;
```

we are reserving 4 bytes of those 4Gb to store an int. It doesn't really matter if we are storing ints or other types of data, the sizes might be different for an int a char, a float or a string, but the type of memory is always the same. **[BD: And what type of memory is this again?]**

Internally, the computer doesn't really now about that memory area as `i`, but rather as a memory address. A memory address is just a number that points to a specific byte in the 4Gg of memory.

When we create a variable like `int i`, we are telling our program to reserve 4 bytes of memory, associate the address of the first byte of those 4 to the variable name `i` and restrict the type of data that we are going to store in those 4 bytes to only ints.

<img src="images/int_i.svg" height="300"/>

Usually memory addresses are represented in [hexadecimal](http://en.wikipedia.org/wiki/Hexadecimal). In C++ you can get the memory address of a variable by using the `&` operator, like:

```cpp
cout << &i << endl;
```

The output of that cout is the memory address of the first byte of the variable `i` that we just created.

Later on when we assign a value to that variable, we are storing that value in the memory area that we've just reserved by declaring it. So when we do:

```cpp
i = 0;
```

Our memory will look like:

<img src="images/int_i_equals_0.svg" height="300"/>

The order in which the bytes that form the int are layer out in the memory depends on the architecture of our computer, you might have seen probably [little endian and big endian](http://en.wikipedia.org/wiki/Endianness) mentioned sometime. Those terms refer to how the bytes of a data type are ordered in memory. ~~if the most significative bytes come first or last.~~ Most of the time we don't really need to know about this order but most modern computer architectures use little endian.

If you've used C++ for a while you've probably had crashes in your programs because of bad memory accesses. Usually the message you'll see is something like `segmentation fault...`. What does that mean?

When you create variables in a program, even in C++, you can't really access all the memory in the computer, for security reasons. Imagine you had your bank account opened in your browser, if any program could access all of the memory in the computer a malign application could just access the memory of the browser and get that information or even modify it. To avoid this, the operating system assigns chunks of memory to every program. When your application starts it's assigned a `segment` of memory. Later on as you create variables, if there's enough memory in that `segment` your variables will be create there. When there's not more memory available the application asks the operating system for another segment and starts using that. If you try to access a memory address that doesn't belong to a segment assigned to your application, the operating system just kills the application to avoid possible security risks. **[BD: This is a very nice description]**

How does that happen usually? Well most of the time you just don't try to access memory addresses by their **[BD: Hexidecimal number?]** number, so how's it possible that sometimes you try to access a variable and you get a segmentation fault? Most of the time this happens because you try to access a variable that doesn't exist anymore, usually because you stored a pointer to a memory area and then free or move that memory somewhere else. We'll talk in more detail about this later.

## Stack variables, variables in functions vs variables in objects

As we said at the beginning of the chapter, there's two types of memory in C++: the stack and the heap. Let's talk first about the stack since that's the easiest type of memory to use and what you'll use most frequently in openFrameworks.

The stack is the type of memory that you use when creating variables inside a function or in the .h of your class as long as you don't use pointers and the `new` keyword.

It's called stack because it's organized like a [stack](http://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29). When a function is called in our application, there's an area in memory assigned to that specific function **call** where it can create variables in that area.

Those variables stop existing when the function call ends. So for example you can't do:

```cpp
void ofApp::setup(){
    int a = 0;
}

void ofApp::update(){
    a = 5; // error a doesn't exist outside setup
}
```

Also, since we are talking about function calls, you can't store a value in a stack variable and expect it to be there when the function is called again.

In general we can say that variables exist in the block where they've been defined. A block in C++ is defined by the `{}` inside which a variable was defined, so for example, doing this won't be valid either:

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

The last example is not very common but is used sometimes to define the life of a variable inside a function. This occurs mostly when that variable is an object that holds resources and we want to only hold them for a specific duration.

The life of a variable is called `scope`.

Apart from creating variables inside functions, we can also create variables in the class declaration in our .h like:

```cpp
class Ball{
public:
    void setup();

    float posX;
}
```

**[BD: Changed `pos_x` to `posX` to stick with camelCase standards]**

These kind of variables are called `instance variables` because every instance or object of our class will get a copy of it. The way they behave is more or less the same as the stack variables created in functions. They exist for the duration of the {} in which they were defined, in this case the {} of the object to which they belong.

These variables can be accessed from anywhere in the class. When we need to have data that is accessible from any function in an instance (object) of this class we create it like this.


The memory in the stack is limited, the exact size, depends on the architecture of our computer, the operating system and even the compiler we are using. In some systems it can even be changed during the runtime of the application, but most of the time we won't reach that limit.

Even if we create all of our variables in the stack, usually the objects that consume most memory, like for example a vector or an ofPixels, will automatically create most of the memory that they use internally in the heap. The heap is limited only by the amount of memory available in the computer so we don't need to worry about it.

We'll see in the next sections how the heap works and the advantages of using the heap or the stack.

## Pointers and references ##

Before talking about heap memory, let's see how pointers and references work in C++, take a look at their syntax and what's really happening with memory when we create a pointer or a reference.

As we've seen before we can get the address of a variable by doing:

```cpp
cout << &i << endl;
```

And that will give us the memory address of the first byte used by that variable no matter it's type. When we store that memory address in another variable that variable is called a pointer. The syntax is:

```cpp
int i = 0;
int * p = &i;
```

And what we get in memory is something like:

<img src="images/pointer.svg" height="300"/>

A pointer usually occupies 4/8 bytes (depending if we are on a 32 or 64bits application), we are representing it as 1 byte only to make things easier to understand, but as you can see it's just another variable. Instead of containing a value, it contains a memory address that points to a value. That's why it's called pointer.

A pointer can point to heap or stack memory.

Now, let's explain something that it's really important to take into account when programming in C++. As we've seen until now, when we declare a variable like:

```cpp
int i;
```
We get a memory layout like:

<img src="images/int_i.svg" height="300"/>

As we see there's no value in that memory area yet. In other languages like Processing, doing something like:

```java
int i;
println(i)
```

is illegal. The compiler will tell us that we are trying to use a variable that is not initialized. In C++ though, that's perfectly legal but the contents of that variable are undefined. Most of the times we'll get 0 because the operating system will clear the memory before assigning it to our program, again, for security reasons. But if we are reusing memory that we had already assigned, then, that memory area could contain anything, and the results of our program will be undefined.

If for example, we have a variable that defines the position of something we are going to draw, and we fail to initialize that variable, it will lead to that object being drawn anywhere.

Now, most objects have default constructors that will initialize their value to, for example 0, so in the case of objects it's usually not necessary to give them a value.

What happens when we use an uninitialized pointer? Well, since a pointer contains a memory address, if the value we get in that memory area points to an address that doesn't belong to our program and we try to retrieve or modify the value stored in that address, the OS will kill our application with a segmentation fault signal.

Back to pointers. We've seen that we can create a pointer like:

```cpp
int i = 5;
int * p = &i;
```

Now, if we try to use the pointer directly like;

```cpp
cout << p <<< endl;
```

<<<<<<< HEAD
what we'll get is a memory address not the value 5. So how do we access the value pointed by a pointer? Well we can use the opposite operator to `&`: as `&` gives us the address of a variable, `*` gives us the value pointed by a memory address, so we can do:

```cpp
cout << *p << endl;
```

and we'll get the value 5 printed now. We can also do:

```cpp
int j = *p;
cout << j << endl;
```

and again will get the value 5 since we made a copy of the value pointed by p in j.

The `&`operator is called the *reference operator* since it gives us a reference to a variable, it's memory address. The `*` operator is it's opposite, the *dereference operator* and it gives us the value pointed **[pointed at?]** by a pointer, it dereferences a reference so that we can access it's value instead of the address.

Until now, we've worked with primitive values, ints really, but the behavior will be the same for any other primitive value like float, short, char, unsigned int...  In C++ in fact, the behavior is also the same for objects.

If you are used to Java, for example, you've probably noticed that while in Java and C++ this:

```cpp
int a = 5;
int b = a;
a = 7;
cout << "a: " << a << " b: " << b << endl;
```

will behave the same (of course changing cout for the equivalent in java). That is: `a` will end up being 7 and `b` will be 5. When we use objects, the behavior in C++ is different to that of Java. For example, let's say we have a class Ball:

```cpp
class Ball{
public:
    void setup();
    //...

    ofVec2f pos;
}
```

or the similar class in Processing;

```java
class Ball{
    void setup();

    PVector pos;
}
```

if in C++ we do:

```cpp
Ball b1;
b1.pos.set(20,20);
Ball b2;
b2 = b1;
b2.pos.set(30,30);
```

b1 pos will end up being 20,20 and b2 pos will be 30,30. If you do the equivalent in Java, both b1 and b2 will have position 30,30:


```cpp
Ball b1 = new Ball();
b1.pos.set(20,20);
Ball b2;
b2 = b1;
b2.pos.set(30,30);
```

Notice how, in the case of Java, we have used `new` for the first ball but not for the second. That's because in Java, everything that is an object is a pointer in the heap. So when we do `b2 = b1`we are actually turning b2 into a reference to b1, and when we later change b2, we are also changing b1.

In C++, instead when we do `b2 = b1`, we are actually copying the values of the variables of b1 into b2. Because of this, we still have 2 different variables instead of a reference. When we modify b2, b1 stays the same.

In both languages the `=` means copy the value of the right side into the variable on the left side of the `=`. The difference is that in Java, an object is really a pointer to an object. The contents of `b1` or `b2` are not the object itself, but it's memory address. In c++ b1 actually contains the object itself. **[BD: Most of this paragraph is redundant to what you've already said.]**

This is more or less what memory would look like in Java and C++:

<img src="images/objects_java_c.svg" height="300"/>

As you can see in C++, objects in memory are just all of their member variables one after another. When we make an object variable equal to another, by default, c++ copies all the object to the left side of the equal operator.

Now what would happen if we have a class like:

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

As before, C++ will copy the contents of p1 into p2. The contents of p1 are an ofVec2f, which consists of 2 floats, x and y, and then a pointer to a ParticleSystem, and that's what gets copied. The ParticleSystem itself won't get copied, only the pointer to it. P2 will end up having a copy of the pos of p1 and a pointer to the same ParticleSystem.


<img src="images/object_pointers.svg" height="300"/>

The fact that things are copied by default and that objects can be stored in the stack as opposed to being always a pointer has certain advantages. For example, in C++, a vector or an array of particles like the ones we've used in the last example will look like:

```cpp
vector<Particle> particles;
```

In memory all the particles will be contiguous, among other things, that makes accessing them faster than if we had pointers to a different location in memory. It also makes it easier to translate C++ vectors to openGL memory structures, but that's the topic for a whole chapter.

Among other things, we need to be aware of the fact that C++ copies things by default, when passing objects to functions as parameters. For example this:

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

So we pass a copy of our particle to the function which modifies it's values and returns a modified copy which we then copy into p1 again. See how many times we've mentioned copy in the previous sentence?  The compiler will optimize some of those **[BD: Those what? Copies?]** out, and for small objects it's perfectly ok to do that, but imagine we had something like this:

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

If we have 1 million particles that would be awfully slow. Memory is really slow compared to the CPU **[BD: Perhaps a sentence here explaining why this is the case.]**, so anything that involves copying memory or allocating new memory should be usually avoided. So what can we do to avoid all those copies?

Well, we could use pointers right?

```cpp
void moveParticle(Particle * p){
    p->x += 10;
    p->y += 10;
}
...

Particle p1;
moveParticle(&p1);
```

Now, here's something new. Notice that we refer to the variables of a pointer to an object with the `->` operator instead of using the dot? Every time we want to access a variable in a pointer to an object, instead of having to dereference it like:

```cpp
(*p).x +=10
```

we can use the `->`

```cpp
p->x += 10
```

So that solves our problem. By using a pointer instead of passing a copy of the object, we are passing a reference to it, so the function will actually modify the original.

The main problem with this is that the syntax is kind of weird. Imagine what it would look like if we passed a pointer for the second example, the one with the vector:

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
ps = moveParticles(ps);
```

Now, the function will look like:

```cpp
void moveParticles(vector<Particle> * ps){
```

the problem is that now we can't use the [] operator to access the elements in the vector because ps is not a vector anymore, its a pointer to a vector. What's more, this

```cpp
ps[i].x += 10;
```

would actually compile but would surely give us a memory access error (a segmentation fault). ps is now a pointer, and when using pointers, the `[]' behaves like if we had an array of vectors!

We'll explain this in more depth in the section about memory structures, but let's see how to pass a reference that doesn't have pointer syntax. In C++ this is called a reference and it looks like:

```cpp
void moveParticles(vector<Particle> & ps){
    for(int i=0;i<ps.size();i++){
        ps[i].pos.x += 10;
        ps[i].pos.y += 10;
    }
}

vector<Particle> ps;
moveParticles(ps);
```

Now we are passing a reference to the original object but instead of having to use pointer syntax we can still use it as if it was a normal object.

> Advanced note: Some times we want to use references to avoid copies but still be sure that the function we pass our object to, won't modify it's contents, in that case it's recomendable to use `const` like:

```
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
> `const` makes it imposible to modify the variable, even if it's a reference. From a code readability standpoint, it and tells programmers using a function that the data passed into it woun't be changed. It also lets programmers modifying that function know that the particle system shouldn't be modified.

**[BD: I would maybe move this whole Advanced note below mentioning it only once you have fully explained references]**

Outside of parameters, references have a couple of special characteristics. First, we can't modify the content of a reference once it's created. For example we can do:

**[BD: Before illustrating the shortcoming and dangers of references. Perhaps a good use case example would be in order. Maybe illustrating another example of when using a reference is a much better decision than a pointer.]**

```cpp
ofVec2f & pos = p.pos;
pos.x = 5;
```

but trying to change the reference itself like:

```cpp
ofVec2f & pos = p.pos;
pos.x = 5;
pos = p2.pos;  // error
```

results in an error because a reference can only be assigned during its declaration.

You can also return a reference, but depending on what that reference is pointing to, it can be a bad idea:

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

Will actually compile but will probably result in a segmentation fault at some point or even just work but we'll get weird values when calling this funciton. The problem is that we are creating the variable `average` in the stack so when the function returns it'll be *deleted* from memory, the reference we return will be pointing to a memory area that is not reserved anymore for average and as soon as it gets overwritten we'll get invalid values or a pointer to a memory area that doesn't belong to our program anymore. **[BD: This is a nice explanation :) ]**

This is one of the most annoying problems in C++. It's called dangling pointers or in this case references, and it's caused when we have a pointer or a reference that points to a memory area that is somehow freed.

More modern languages solve this with different strategies, for example Java won't let this happen because objects are only deleted once the last reference to them goes out of scope. It uses something called a garbage collector that, from time to time, goes through the memory looking for objects which have no more references pointing to them, and deletes them. This solves the problem but makes it hard to know when objects are going to get truly deleted. Latest versions of C++, and more modern languages, try to solve this using new kinds of pointers that define ownership of the object. We'll talk about it in the later section of this chapter, smart pointers.

## Variables in the heap ##

Now that we now the syntax and semantics of pointers, lets see how to use the heap. The heap is an area of memory common to all of our application. Any function can create variables in this space and share it with others, to use it we need to use the `new` keyword:

```cpp
Particle * p1 = new Particle;
```

If you know Processing or Java, that looks a little bit like it, right? Indeed, this is exactly the same as a Java object: when we use `new` we are creating that variable in the heap instead of the stack. `new` returns  a pointer to a memory address in the heap, and in C++, we explicitly need to specify that the variable `p1` is a pointer by using the `*` in the declaration.

To access the variables or functions of a pointer to an object, as we've seen before, we use the `->` operator so we would do:

```cpp
Particle * p1 = new Particle;
p1->pos.set(20,20);
```

or:

```cpp
Particle * p1 = new Particle;
p1->setup();
```

A pointer, like any variable, can be declared without initializing it. Be careful of this:

```cpp
Particle * p1;
p1->setup() // this will compile but fail when executing the application
```

We can imagine the heap as some kind of global memory as opposed to the stack being local memory. In the stack, only the block that owns a variable can access it, while things created in the heap outlive the scope in which they were created. Any function can access a variable stored in the heap as long as they have a reference (a pointer) to it. For example:

```cpp
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

`createParticle` created a new `Particle` in the heap, so even when createParticle finishes, that `Particle` still exists. ~~To use it outside of the function, pass a reference to it to other functions...~~ **[BD: I don't think that you need this]**

So how can we say that we don't want to use that variable anymore? we use the keyword `delete`:

```cpp
Particle * p1 = new Particle;
p1->setup();
...
delete p1;
```

Using `delete` is **very** important when using the heap. If we fail to do this we'll get with what is called a memory leak, memory that is not referenced by anyone **[BD: define "anyone"]** but continues to leave in the heap, making our application use more and more memory over time until it fills all of the available memory in our computer:

```cpp
void ofApp::draw(){
    Particle * p1 = new Particle;
    p1->setup();
    p1->draw();
}
```

Every time we call `draw`, it'll create a new particle. Once each `draw` call finishes, we loose the reference `*p1` to it but the memory we allocated using `new` is not freed when the function call ends so our program will slowly use more and more memory. You can watch this happen using the system monitor.

As we've mentioned before, the stack memory is limited, so sometimes we need to use the heap. Trying to create 1 million particles in the stack will probably cause a stack overflow. In general, though, most of the time in C++ we don't need to use the heap, at least not directly. Classes like vector, ofPixels and other memory structures allow us to use heap memory but still have stack semantics, for example this:


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

## Memory structures, arrays and vectors ##

Arrays are the most simple way in C++ to create collections of objects. Just like any other C++ variable type, they can also be created in the stack or in the heap. Arrays in the stack have a limitation though, they need to have a predifined size that needs to be specified in it's declaration and can't change afterwards:

```cpp
int arr[10];
```

The previous declaration reserves memory for 10 ints, we don't need to use new, and that memory will be uninitialized. To access them, as you might know from previous chapters, you can just do:

```cpp
int arr[10];
arr[0] = 5;
int a = arr[0];
```

if we try to do:

```cpp
int arr[10];
int a = arr[5];
```

the value of a will be undefined since the memory in the array is not initialized to any value when it's created. Also if we try to do:

```cpp
int arr[10];
int a = arr[25];
```

Our application will probably crash if the memory address at arr + 25 is outside the memory that the operating system has assigned to our application.

We've just said arr + 25? what does that mean? As we've seen before, a variable is just some place in memory. We can get it's memory address, which ~~is~~ holds the first byte that is assigned to that variable in memory **[BD: The memory address is not literal first byte of the variable assigned there. Rather it is hex of where the first byte is stored. Right?]**. Arrays are pretty much the same, for example, since we know that an int occupies 4 bytes in memory, an array of 10 ints will occupy 40 bytes and those bytes are contiguous:

<img src="images/array.svg" height="300"/>

Remember that memory addresses are expressed as hexadecimal, so `40 == 0x0028`. Now, to get the address of an array, as with other variables, we might want to use the `&` operator and indeed we can do it like:

```cpp
int arr[0];
int * a = &arr[0];
```

That gives us the address of the first element of the array which is indeed that of the array, but with arrays, the same variable is actually a pointer itself:

```cpp
int arr[10];
int * a = &arr[0];
cout << "a: " << a << " arr: " << arr << endl;
```

This will print the same value for both a and arr. So an array is just a pointer to a memory address with the only difference being, that the memory address is the beginning of reserved memory **[BD: Reserved memory section?]** enough to allocate, in our case, 10 ints. All those ints will be one after another, so when we do `arr[5]`, we are just accessing the value that is in the memory address of our array + the size of 5 ints. If our array started in the memory address `0x0010`, and ints occupy `4 bytes`, arr[5] would be `10 + 4 * 5 = 30` which in hexadecimal is `0x001E`. We can actually do this in our code:

```cpp
int arr[10];
arr[5] = 20;
cout << "&arr[5]: " << &arr[5] << "arr+5: " << arr+5 << endl
cout << "arr[5]: " << arr[5] << "*(arr+5): " << *(arr+5) << endl
```

**[BD: I think a sample console output would be nice here]**

That's called pointer arithmetic. Its really weird and most of the time you won't use it. The first cout will print the address in memory of the int at position 5 in the array. The first case uses the `&` operator to get the address of `arr[5]` and the second directly adds 5 to the first address of `arr` doing `arr+5`. In the second cout we print the value at that memory location, using `arr[5]` or dereferencing the address `arr+5` using the `*` operator.

**[BD: It is worth explicitly mentioning, or if you showed the example cout output like I mentioned above, that each cout statement prints the same pair of values]**

Note that when we add `5` to the address of the array, it's not bytes we are adding, but the size in bytes of the type it contains. In this case `+5` actually means `+20` bytes. We can check it by doing:

```cpp
int arr[10]
arr[5] = 7;
cout << "arr: " << arr << "arr+5: " << arr+5 << endl
```

and subtracting the hexadecimal values in a calculator. If you try to subtract them in your program like:

```cpp
int arr[10]
arr[5] = 20;
cout << "arr: " << arr << "arr+5: " << arr+5 << endl
cout << "(arr+5) - arr: " << (arr+5) - arr << endl
```

You will end up with `5` again because as we've said pointer arithmetic works with the type size not bytes.

The syntax of pointer arithmetics is kind of complicated, and the idea of this part wasn't really to show pointer arithmetics itself but how arrays are just a bunch of values one after another in memory. Don't worry if you haven't fully understood the syntax, it is probably something you won't need to use. However, it is important to remember that an array variable acts as a pointer so when we refer to it without using the `[]` operator we end up with a memory address instead of the values it contains.

The arrays we've created until now were created in the stack. Be careful when using big arrays like this because it might be problematic.

Arrays in the heap are created like anything else in the heap, by using `new`:

```cpp
int arr[] = new int[10];
```

or

```cpp
int * arr = new int[10];
```

As you can see this confirms what we've said before, an array variable is just a pointer. When we call `new int[10]` it allocates memory to store 10 integers and returns the memory address of the first byte of the first integer in the array. We then keep that address in a pointer like in the second example or use `int arr[]` which declares an array of unknown size.

Like other variables created in the heap, we'll need to delete this array manually when we are done with it. We use the `delete` key word to deallocate that memory, in the case of arrays in the heap the syntax is slightly special:

```cpp
int arr[] = new int[10];
...
delete[] arr;
```

If we fail to use the `[]` when deleting it, only the first value will be deallocated and we'll end up with a memory leak.

There's also some problems with the syntax of arrays, for example this:


```cpp
int arr[10]
int arrB[10];
arrB = arr;
```

will fail to compile. And this:


```cpp
int arr[] = new int[10];
int arrB[] = new int[10];
arrB = arr;
```

will actually compile, but as with other variables, we are not copying the values that arr points to into arrB, but instead its memory address. In this case, we'll end up with 2 pointers pointing to the same memory location: the one that we created when creating arr and loose memory that we allocated when initializing arrB **[BD: This sentence is confusing]**. Again, we have a memory leak as the memory allocated when doing `int arrB[] = new int[10];` is no longer referenced by any variable so we can't delete it. There are some **C** (not C++) functions for copying arrays like `memcpy` but their syntax is kind of complex. For the above reasons it is recomended to use vectors when working in C++.

C++ vectors are very similar to arrays, indeed their layout in memory is the same as an array. They contain a bunch of values contiguous in memory and always allocated in the heap. The main difference is that we get a nicer syntax and [*stack semantics*](http://msdn.microsoft.com/en-us/library/ms177191.aspx). To allocate a vector to contain 10 ints we can do:

```cpp
vector<int> vec(10);
```

We can even give an initial value to those 10 ints in the initialization like:

```cpp
vector<int> vec(10,0);
```

Copying a vector into another works as expected:

```cpp
vector<int> vec(10,0);
vector<int> vecB = vec;
```

This will create a copy of the contents of vec in vecB. Also, even if the memory that the vector uses is in the heap, when a vector goes out of scope (when the block in which it was declared ends), the vector is destroyed because the vector itself is created in the stack. Going out of scope, triggers it's destructor that takes care of deleting the memory that it has created in the heap:

```cpp
void ofApp::update(){
    vector<int> vec(10);
    ...
}
```

That makes vectors easier to use than arrays since they have easier syntax and we don't need to worry about deleting them, ending up with dangling pointers, or memory leaks...

Vectors have some more features but using them properly might be tricky mostly if we want to optimize for performance or use them in multithreaded applications, but that's beyond the scope of this chapter. You can find some tutorials about vectors on the openFrameworks site:
- [Vectors Basics](http://openframeworks.cc/tutorials/c++%20concepts/001_stl_vectors_basic.html)
- [std::vector](http://arturocastro.net/blog/2011/10/28/stl::vector/) (advanced concepts)


## Other memory structures, lists and maps ##

Having objects in memory ordered one after another is what we want most of the time. The access is really fast no matter if we access each element sequentially or one randomly. Since a vector is just an array, accessing position 20 just means that internally it needs to get the memory address of the first position and add 20 to it. In some cases though, vectors are not the most optimal memory structure. For example, if we frequently want to add or remove elements in the middle of the vector, and we imagine the vector as a memory strip, that means that we need to move the rest of the vector over one position to the right and then insert the new element in the free location. In memory there's no such thing as move, moving contiguous memory means copying it and as we've said before, copying memory is a relatively slow operation.

<img src="images/vector_inserting.svg" height="300"/>

Sometimes, if there's not enough memory to move/copy the elements, one position to the right, the vector will need to copy the whole thing to a new memory location. If we are working with thousands of elements and doing this very frequently, like for example every frame, this can really slow things down a lot.

Other memory structures exist to solve that problems like this. For example, in a list, memory is not contiguous. Instead, each element has a pointer to the next and previous element, so inserting one element just means changing those pointers to point to the newly added element. In a list, we never need to move elements around. It's main disadvantage is that, because its elements are not contiguous in memory, it's access can be slightly slower than that of a vector. This is somewhat limiting, for example, to upload data to the graphics card we need contiguous memory.

<img src="images/list.svg" height="300"/>

Another problem of lists comes in trying to access an element in the middle of the list (what is called random access). This is slow since we always have to go through the entire list until we arrive to the desired element. Lists are used then, when we seldom need to randomly access a position of it and we need to add or remove elements in the middle frequently. For the specifics of the syntax of a list you can check the [C++ documentation on lists](http://www.cplusplus.com/reference/list/list/).

There's several memory structures in the C++ standard library or other C++ libraries, apart from vectors and lists we are only going to breifly see maps.

Sometimes we don't want to access things by their position or have an ordered list of elements, but instead have something like an index or dictionary of elements that we can access by some key. That's what a map is. In a map we can store key => value pairs and lookup a value by it's key. For example, let's say we have a collection of objects which have a name. If that name is unique for all the objects, we can store them in a map to be able to look for them by their name:

**[BD: It may be helpful to also mention that this is a hash map, hash table, or hash, for those who know it by another name]**

```cpp
map<string, NamedObject> objectsMap;

NamedObject o1;
o1.name = "object1";
objectsMap[o1.name] = o1;
```

Later on we can look for that object using it's name like:

```cpp
objectsMap["object1"].doSomething();
```

Be careful though, if the object didn't exist before, using the `[]` operator will create a new one. If you are not sure, it's usually wise to try to find it first and only use it if it exists:

```cpp
if(objectsMap.find("object1")!=objectsMap.end()){
    objectsMap["object1"].doSomething();
}
```

You can find the complete reference in the [C++ documentation for maps](http://www.cplusplus.com/reference/map/map/).


## Smart pointers ##

As we've said before, traditional C pointers, also now called *raw pointers*, are sometimes problematic. The most frequent problems are dangling pointers (pointers that were once probably valid but now point to an invalid memory location), trying to dereference a `NULL` pointer, and possible memory leaks if we fail to deallocate memory before loosing the reference to that memory address.

Smart pointers try to solve that by adding what we've been calling stack semantics to memory allocation. The correct term for this is RAII: [Resource Acquisition Is Initialization](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization), and it means that the creation of an object in the stack allocates the resources that it'll use later. When it's destructor is called because the variable goes out of scope, the destructor of the object is triggered which takes care of deallocating all of the used resources. There's some more implications to RAII, but for this chapter, this is what matters to us most.

Smart pointers use this technique to avoid all of the problems that we've seen with raw pointers. They do this by defining better who is the owner of some allocated memory or object. Until now, we've seen how things allocated in the stack belong to the function or block that creates them. We can return a copy of them (or in c++11 or later, move them) out of a function as a return value but their ownership is always clear.

With heap memory though, ownership becomes way more fuzzy, something might create a variable in the heap like:

```cpp
int * createFive(){
    int * a = new int;
    *a = 5;
    return a;
}
```

Now, when someone calls that function, what owns `new int`?  Things can get even more complicated. What if we pass a pointer to that memory to another function or even an object?


```cpp
// ofApp.h
int * a;
SomeObject object;

// ofApp.cpp
void ofApp::setup(){
    a = createFive();
    object.setNumber(a);
}
```

**[BD: Maybe it would be more wise to say "what owns" rather than "who owns". I left everything as "who" but I think it could be a bit confusing for the reader.]**

Who is now the owner of that memory? ofApp? object? The ownership defines. among other things, who is responsible for deleting that memory when it's not used anymore. Now both ofApp and object have a reference to it, if ofApp deletes it before object is done with it, object might try to access it and crash the application, or the other way around. In this case it seems logical that ofApp takes care of deleting it since it knows about both object and the pointer to int a, but what if we change the example to:


```cpp
// ofApp.h
SomeObject object;

// ofApp.cpp
void ofApp::setup(){
    int * a = createFive();
    object.setNumber(a);
}
```

or even:



```cpp
// ofApp.h
SomeObject object;

// ofApp.cpp
void ofApp::setup(){
    object.setNumber(createFive());
}
```


now ofApp doesn't know about the allocated memory, but both cases are possible, so we actually need to know details of the implementation of object to know if we need to keep a reference of that variable to destroy it later or not. That, among other things, breaks encapsulation (you might know from chapter 1). We shouldn't need to know how an object works internally to be able to use it. This makes the logic of our code really complicated and error prone.

Smart pointers solve this by clearly defining who owns and object and by automatically deleting the allocated memory when the owner is destroyed **[BD: What does this mean?]**. Sometimes we need to share an object among several owners. For those cases we have a special type of smart pointers called shared pointers that defined a shared ownership and free the allocated memory only when all the owners cease to use the variable.

We are only going to see this briefly as there's lots of examples on the web about how to use smart pointers and reference to their syntax. The most important thing is to understand the problems they solve and that they work by defining a pointer's ownership clearly compared to raw pointers.

### unique_ptr

A unique_ptr, as it's name suggests, is a pointer that defines a unique ownership for an object. We can move it around and the object or function that has it at any given point is the owner of it. No more than one reference at the same time is valid and when it goes out of scope it automatically deletes any memory that we might have allocated.

To allocate memory using a unique_ptr we do:

```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;
}
```

As you can see, once it's created it's syntax is the same as a raw pointer. We can use the `*` operator to dereference it, access or modify it's value. If we are working with objects like:

```cpp
void ofApp::setup(){
	unique_ptr<Particle> p(new Particle);
	p->pos.set(20,20);
}
```

we can also use the `->` to access it's member variables and functions.

When the function goes out of scope, being a unique_ptr an object, it's destructor will get called, which internally will call `delete` on the allocated memory so we don't need to call delete on unique_ptr at all.

Now let's say we want to move a unique_ptr into a vector:

```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;

	vector<unique_ptr<int>> v;
	v.push_back(a);  // error
}
```

That will generate a long error, depending on the compiler, that is really hard to understand. What's going on is that `a` is still owned by ofApp::setup so we can't put it in the vector. What we can do is move it into the vector by explicitly saying that we want to move the ownership of that unique_ptr into the vector:

```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;

	vector<unique_ptr<int>> v;
	v.push_back(move(a));
}
```

There's a problem that unique_ptr doesn't solve, we can still do:


```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;

	vector<unique_ptr<int>> v;
	v.push_back(move(a));

	cout << *a << endl;
}
```

The compiler won't fail there but if we try to execute the application it'll crash since `a` is no longer owned by ofApp::setup. Having to explicitly use `move` tries to solve that problem by making the syntax clearer, however after using move, we can't use that variable anymore except through the vector. More modern langauages like [Rust](http://www.rust-lang.org/) completely solve this by making the compiler detect these kind of uses of moved variables and producing a compiler error. This will probably be solved at some point in C++, but for now you need to be careful to not use a moved variable.


### shared_ptr

As we've seen before, sometimes having unique ownership is not enough and we need to share a pointer among several owners. In C++11 or later, this is solved through `shared_ptr`. The usage is pretty similar to `unique_ptr`, we create it like:

```cpp
void ofApp::setup(){
	shared_ptr<int> a(new int);
	*a = 5;

	vector<shared_ptr<int>> v;
	v.push_back(a);
}
```

The difference is that now, both the vector and ofApp::setup, have a reference to that object, and doing:


```cpp
void ofApp::setup(){
	shared_ptr<int> a(new int);
	*a = 5;

	vector<shared_ptr<int> > v;
	v.push_back(a);

	cout << *a << endl;
}
```

Is perfectly ok. The way a shared_ptr works is by keeping a count of how many references there are to it. Whenever we make a copy of it, it increases that counter by one, whenever a reference is destroyed it decreases that reference by one. When the reference count arrives to 0 it frees the allocated memory. That reference counting is done atomically, which means that we can share a shared_ptr across threads without having problems with the count. That doesn't mean that we can access the contained data safely in a multithreaded application, just that the reference count won't get messed up if we pass a shared_ptr across different threads.

**[BD: This chapter covers a lot of material (in a very nice way :]), however it ends in a very specialized way (talking about shared_ptrs with threads). A small paragraph would be helpful.]**

<em style="font-size:0.8em; text-align:center; display:block;">This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.</em>

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>
