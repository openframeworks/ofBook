#Editor's Style Guide

The following guide aims to outline a standard of writing (and code) practices for ofBook. The multiple-author-model that ofBook uses allows for a well rounded and diverse insight to openFrameworks/C++ techniques and practices, however, it also proposes some possible clarity and consistency challenges from a reader's perspective. This guide attempts to tackle some of these issues by outlining a style guide for editors (and authors) to follow.

A general ofBook [Style Guide](StyleGuide.md) already exists. Think of this one as an add-on directed towards editors.

##Code Practices
To remain consistent to oF's coding practices ofBook will use the official [oF Code Style](https://github.com/openframeworks/openFrameworks/wiki/oF-code-style). Here are some notable highlights:

Comments have a space after the `//`
```cpp
// Wrong
//this is a comment

// Correct
// this is a comment
```

Don't align variables with tabs, and declare each variable on a separate line (`string dont, declare, like, do, this`).

```cpp
// Wrong
int    height;      // Comment A
float  scaleFactor; // Comment B
string name;        // Comment C

// Correct
int height; // Comment A
float scaleFactor; // Comment B
string name; // Comment C
```

Don't use whitespace between keyword and parenthesis in conditionals and loops.

```cpp
// Wrong
if (foo) {
    // do something
}

// Correct
if(foo){
    // do something
}
```
	
For pointers or references, always use a single space between the type and * or &, and a space between the * or & and the variable name.

```cpp
	// Wrong
	char* x;
	
	// Correct
	char * x;
```

Surround binary operators with spaces

```cpp
	// Wrong
	int a = b+c;
	
	// Correct
	int a = b + c;
```

The left curly brace goes on the same line as the start of the statement. **No exceptions**.

```cpp
	// Wrong
	if (codec)
	{
	    // do something
	} 
	
	// Correct
	if(codec){
	    // do something
	}
```


##Referring to code in text

###Variables, functions, and functions with arguments
Referring to code in text can be tricky. Here is a list of uniform practices to use when referring to the following keywords, variable types, functions, etc...

- `variableName`
- `ClassName` or `ofClassName`
- `functionName()` where the function requires __no__ parameter.
- `functionName(...)` where the function requires __one or more__ parameter.

###Misc
Be careful not to interchange the use of "parameter" and "argument". See the accepted answer to [this](http://stackoverflow.com/questions/1788923/parameter-vs-argument) Stack Overflow question for more info.

When referring to a __specific__ line of example code try to mention it in-line without the semicolon. e.g. `ofBackground(255)` instead of like this `ofBackground(255);`. 

Make sure that "property" vs "variable" and "function" vs "method" are used correctly. Technically all variables and functions that are used in `ofBaseApp` are properties and methods, but for instructional purposes they should be illustrated to be functions and variables.

Refer to openFrameworks app (and subsequent `.h` and `.cpp` files) as `baseApp` not `testApp`.

Refer to all keywords and variable types in text as `int`, `for` loop, and `if` statements with in-line code highlighting like this sentence employs.

##Questions?

###Contradictions to of-code-style
- Why not use `cout`? This makes since for oF developers but is it safe for use with openFrameworks/C++ instruction? It seems like it is an important C++ feature and one that is used prevalently with oF users.

###Buggy Functions

With functions that don't necessarily work how they are supposed to in the documentation, like `ofEnableAlphaBlending()`, you should value how it is __documented__ over how it actually __works__. That is, as long as the discrepancy doesn't break its functionality. The reasoning behind this is that it is easier for a user to track code through documentation and change logs than trial and error in code.

(^Is this correct?)