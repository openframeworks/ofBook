# C++ Language Basics (unabridged) #

*by [jtnimoy](http://jtnimoy.net)*

> The magician of the future will use mathematical formulas.
>
> **--Aleister Crowley, 1911**

## Look Alive!

This chapter introduces you to writing small computer programs using the C++ language. Although I assume very little about your previous knowledge, the literacy you gain from this chapter will directly influence your comprehension in subsequent chapters of the book, as most other topics stand on the shoulders of this one. Furthermore, the lessons herein are cumulative, meaning you can't skip one of the topics or you will get lost. If you get stuck on one of the concepts, please seek help in understanding specifically the part that did not make sense before moving on to the next topic. Following the lessons with this sort of rigor will insure that you will get the most out of OpenFrameworks, but also computers in general.

## Iteration


I did most of my drawing and painting in the mid-nineties, a high school AP art student sporting a long black ponytail of hair shaved with a step, round eyeglasses, and never an article of clothing without spill, fling, smattering, or splotch of Liquitex Basics acrylic paint. Bored out of my mind in economics class, playing with my TI-82 graphing calculator, I discovered something that flipped a light bulb on in my heart. Unlike smaller calculators around my house growing up, the TI-82 had a thick instruction manual. Amidst sections in this manual about trig functions and other dry out-of-reach science, something caught my thirsty, young eye: a sexy black-on-white pyramid with smaller upside-down pyramids infinitely nested inside, shown in Figure 1.

![Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments](images/sierpinski-fractal-ti82.png "Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments")

This fractal, the famous [Sierpinski triangle](https://www.wolframalpha.com/input/?i=sierpinski+triangle), accompanied about twenty-five computer instructions making up the full SIERPINS program. I looked closer at the code, seeing a few numeric operations – nothing too advanced, and most of it was commanding words, like "do this", or "if something then do another thing". I was able to key in the code from the book into the graphing calculator and run the program. At first, just a blank LCD panel. Slowly a few random pixels switched to black here and there, not really showing any pattern. After a few more seconds, the scene filled in and I could already see faint outlines of triangles. After a good long time, my calculator finally matched the picture in the book. My mind was officially blown. Certain things did not make sense. What sort of miracle of nature caused such a complex form to come from so little instruction? The screen had over six thousand pixels in it, so why is it that a mere twenty-five instructions was all it took to create this amazing, organism-like artwork? Whose artwork was it? Might I derive a new work from it? Rarely had I ever seen such a magical reward coming from so little work. I had found my new basics. I felt the need to understand the program because (I decided) it was important. I went back into the code and changed some of the numbers, then ran the program again. The screen went blank, then drew a different picture, only this time, skewed to the left, falling out of the viewport. Feeling more courageous, I attempted to change one of the English instructions, and the machine showed an error, failing to run.

![Figure 2: The human loop of a programmer.](images/programmer-cycle.png "Figure 2: The human loop of a programmer.")

The cycle illustrated in Figure 2 is an infinitely repeating loop that I have had a great pleasure of executing for a couple decades and I still love what I do. Each new cycle never fails to surprise me. As I pursue what it means to create a program, and what it means to create software art, the process of iteratively evolving a list of computer instructions always presents as much logical challenge as it does artistic reward. Very few of those challenges have been impossible to solve, especially with other people available to collaborate and assist, or by splitting my puzzle into smaller puzzles. If you have already written code in another environment like Processing, Javascript, or even HTML with CSS, then this first important lesson might seem too obvious.

![Figure 3: Don't get the wrong idea.](images/profit-not.png "Figure 3: Don't get the wrong idea.")

For those just now familiarizing themselves with what it means to write small programs, it is important to understand the iterative nature of the code writing process. The anecdote in Figure 3 shows what this process is *not*. Rarely would you ever enter some code into the editor just once, and expect to hit compile and see your finished outcome. It is natural, and commonly accepted for programs to start small, have plenty of mistakes (bugs), and evolve slowly toward a goal of desired outcome or behavior. In fact it is so commonplace that to make the former assumption is a downright programmer's mistake. Even in older days when programs were hand-written on paper, the author still needed to eyeball the code obsessively in order to work out the mistakes; therefore the process was iterative. In learning the C++ language, I will provide tiny code examples that you will be compiling on your machine. The abnormal part is typing the code from the book into the editor, and (provided your fingers do not slip) the program magically runs. I am deliberately removing the troubleshooting experience in order to isolate the subject matter of the C++ language itself. Later on, we will tackle the commonplace task of *debugging* (fixing errors) as a topic all its own.

## Compiling My First App

Let us start by making the smallest, most immediate C++ program possible, then use the convenient environment to test small snippets of C++ code throughout this chapter. In order to do that, we must have a *compiler*, which is a program that translates some code into an actual runnable app, sometimes referred to as the executable file. C++ compilers are mostly free of charge to download, and in a lot of cases, open source. The apps we generate will not automatically show up in places like Apple's App store, Google Play, Steam, Ubuntu Apps Directory, or Pi Store. Instead, they are your personal, private program files and you will be responsible for manually sharing them later on. In the following chapter *OF Setup and Project Structure*, the compiler will sit on your local computer, able to run offline. For now, we will be impatient and compile some casual C++ on the web using a convenient tool by Sphere Research Labs. Please open your web browser and go to [ideone](http://ideone.com) (http://ideone.com).

You will notice right away that there is an editor already containing some code, but it may be set to another language. Let's switch the language to C++11 if it is not already in that mode. Down at the bottom left of the editor, press the button just to the left of "stdin", as shown in Figure 4. The label for this button could be any number of things.

![Figure 4](images/where-is-says-java.png "Figure 4")

A menu drops down with a list of programming languages. Please choose C++11, shown in Figure 5.

![Figure 5](images/choose-c11.png "Figure 5")

Notice that the code in the editor changed, and looks something like figure 6.

![Figure 6](images/empty-template.png "Figure 6")

This is just an empty code template that does nothing, and creates no errors. The numbers in the left hand gutter indicate the line number of the code. Press the green button labeled *Run*. You will see a copy of the code,  "Success" in the comments, and the section labeled *stdin* (standard input) will be empty. *stdout* (standard output) will also be empty.


### Interlude on Typography

Most fonts on the web are variable width, meaning the letters are different widths; the eye finds that comfortable to read. Fonts can also be fixed-width, meaning all the letters (even the W and the lowercase i) are the same width. Although this may look funny and quant like a typewriter, it serves an important purpose. A fixed width font makes a block of text into a kind of game board, like chess squares or graphing paper. Computer programming code is generally presented in fixed-width typesetting, because it is a form of ascii-art. The indentation, white space characters, and repetitive patterns are all important to preserve and easily eyeball for comparison. Every coder I know except artist Jeremy Rotsztain uses some manner of monospaced font for their code. Some typeface suggestions are Courier, Andale Mono, Monaco, Profont, Monofur, Proggy, Droid Sans Mono, Deja Vu Sans Mono, Consolas, and Inconsolata. From now on, you will see the font style switch to `this inline style` . . .

```cpp
and this style encased in a block . . .
```

. . . and that just means you are looking at some code.

### Comments

Now please press *Edit* (Figure 7) at the top left of the code editor.

![Figure 7](images/ideone-edit.png "Figure 7")

You will see a slightly different editing configuration but the same template code will still be editable at the top. We will now edit the code. Find line 5, where it says:

```cpp
// your code goes here .
```

A line beginning with a double forward slash is called a comment. You may type anything you need to in order to annotate your code in a way you understand. Sometimes a it's useful to “comment out code” by placing two forward-slashes before it, because that deactivates the C++ code without deleting it. Comments in C++ can also take up multiple lines, or insert like a tag. The syntax for beginning and ending comment-mode is different. Everything between the `/* and the */` becomes a comment:


```cpp
/* 
this is a multi-line comment. 
still in comment mode.
*/
```

Please delete the code on line 5 and replace it with the following statement:

```cpp
cout << "Hello World" << endl;
```

This line of code tells the computer to say "Hello World" into an implied text-space known as *standard output* (aka. *stdout*). When writing a program, it is safe to expect *stdout* to exist. The program will be able to "print" text into it. Other times, it's just a window pane in your coding tool, only used to troubleshoot.

You may put almost anything between those quotes. The quoted phrase is a called a *string* of text. More specifically, it is a *c-string literal*. We will cover more on strings later in this chapter. In the code, the chunk `cout <<` part means "send the following stuff to stdout in a formatted way." The last chunk `<< endl` means "add a carriage return (end-of-line) character to the end of the hello world message." Finally, at the very end of this line of code, you see a semicolon (;).

In C++, semicolons are like a full stop or period at the end of the sentence. We must type a semicolon after each statement, and usually this is at the end of the line of code. If you forget to type that semicolon, the compile fails. Semicolons are useful because they allow multiple statements to share one line, or a single statement to occupy several lines, freeing the programmer to be flexible and expressive with one's whitespace. By adding a semicolon you ensure that the compiler does not get confused: you help it out and show it where the statement ends. When first learning C or C++, forgetting the semicolon can be an extremely common mistake, and yet it is necessary for the code to compile. Please take extra care in making sure your code statements end in semi-colons.

While you typed, perhaps you noticed the text became multi-colored all by itself. This convenient feature is called *syntax-coloring* and can subconsciously enhance one's ability to read the code, troubleshoot malformed syntax, and assist in searching. Each tool will have its own syntax coloring system so if you wish to change the colors, please expect that it's not the same thing as a word processor, whose coloring is something you add to the document yourself. A code editor will not let me assign the font "TRON.TTF" with a glowing aqua color to *just* `endl` (which means end-of-line). Instead, I can choose a special style for a whole category of syntax, and see all parts of my code styled that way as long as it's that type of code. In this case, both `cout` and `endl` are considered keywords and so the tool colors them black. If these things show up as different colors elsewhere, please trust that it's the same code as before, since different code editors provide different syntax coloring. The entire code should now look like this:

```cpp
#include <iostream.h>
using namespace std;

int main(){
	cout << "Hello World" << endl;
	return 0;
}
```

Now press the green *ideone it!* button at the bottom right corner and watch the output console, which is the bottom half of the code editor, just above that green button. You will see orange status messages saying things like “Waiting for compilation,” “Compilation,” and “Running”. Shortly after, the program will execute in the cloud and the standard output should show up on that web page. You should see the new message in Figure 8.

![Figure 8](images/hello-world.png "Figure 8: Hello World appears in output window")

You made it this far. Now give yourself a pat on the back. You just wrote your first line of C++ code; you analyzed it, compiled it, ran it, and saw the output.

## Beyond Hello World

Now that we've gotten our feet wet, let's go back and analyze the other parts of the code. The first line is an include statement:

```cpp
#include <iostream>
```

Similar to *import* in Java and CSS, `#include` is like telling the compiler to cut and paste some other useful code from a file called *iostream.h* at that position in the file, so you can depend on its code in your new code. In this case, iostream.h *provides* `cout` and `endl` as tools I can use in my code, just by typing their names. In C++, a filename ending in **.h** is called a header file, and it contains code you would include in an actual C++ implementation file, whose filename would end in **.cpp**. There are many standard headers built into C++ that provide various basic services – in fact too many to mention here. If that wasn't enough, it's also commonplace to add an external library to your project, including its headers. You may also define your own header files as part of the code you write, but the syntax is slightly different:

```cpp
#include "MyCustomInclude.h"
```

In OpenFrameworks, double quotes are used to include header files that are not part of the system installation.

### What's with the # ?

It's a whole story, but worth understanding conceptually. The include statement is not really C++ code (notice the absence of semi-colon). It is part of a completely separate compiler pass called *preprocessor*. It happens before your actual programmatic instructions are dealt with. They are like instructions for the code compiler, as opposed to instructions for the computer to run after the compile. Using a pound/hash symbol before these *preprocessor directives*, one can clearly spot them in the file, and for good reason too. They should be seen as a different language, mixed in with the real C++ code. There aren't many C++ preprocessor directives — they are mostly concerned with herding other code. Here are some you might see.

`#define`
`#elif`
`#else`
`#endif`
`#error`
`#if`
`#ifdef`
`#include`
`#line`
`#pragma`
`#undef`

Let's do an experiment. In the code editor, please comment out the include directive on line 1, then run the code. To comment out the line of code, insert two adjacent forward-slashes at the beginning of the line.

```cpp
//#include <iostream>
```

The syntax coloring will change to all green, meaning it's now just a comment. Run the code by pressing the big green button at the bottom right, and you'll see something new in the output pane.

```
prog.cpp: In function ‘int main()’:
prog.cpp:5:2: error: ‘cout’ was not declared in this scope
  cout << "Hello World" << endl;
  ^
prog.cpp:5:27: error: ‘endl’ was not declared in this scope
  cout << "Hello World" << endl;
                           ^
```

The compiler found an error and did not run the program. Instead, in attempt to help you fix it, the compiler is showing you where it got confused in attempt to help you fix it. The first part, *prog.cpp*: tells you the file that contains the error. In this case, ideone.com saved your code into that default file name. Next, it says `In function ‘int main()’`: file showing you the specific section of the code that contains the error, in this case, between the {curly brace} of a function called *main*. (We will talk about functions and curly braces later). On the next line, we see `prog.cpp:5:2:`. The 5 is how many lines from the top of the file, and 2 is how many characters rightward from the beginning of the line. Next, we see `error: ‘cout’ was not declared in this scope`. That is a message describing what it believes it wrong in the code. In this case, it's fairly correct. iostream.h is gone, and therefore no `cout` is provided to us, and so when we try to send "Hello World", the compile fails. On the next couple of lines, you see the line of code containing the fallacious `cout`, plus an extra little up-caret character on the line beneath it, and that is supposed to be an arrow pointing at a character in the code. In this case, the arrow should be sitting beneath the 'c' in `cout`. The system is showing you visually which token is at fault. A second error is shown, and this time, the compiler complains that there is no endl. Of course, we know that in order to fix the error, we need to include `<iostream.h>` so let us do that now. Please un-comment line 1 and re-run the code.

```cpp
#include <iostream>
```

When using OpenFrameworks, you have choice of tools and platforms. Each one shows you an error in a different way. Sometimes the editor will open up and highlight the code for you, placing an error talk bubble for more info. Other times, the editor will show nothing, but the compile output will show a raw error formatted similarly to the one above. While sometimes useful that we receive several errors from a compile, it can save a lot of grief if you focus on understanding and fixing the very first error that got reported. After fixing the top error, it is likely that all subsequent errors will elegantly disappear, having all been covered by your first fix.  By commenting out that single line of code at the top, we caused two errors.

### Namespaces at First Glance

Moving on to line 2, we see:

```cpp
using namespace std;
```

Let's say you join a social website and it asks you to choose a username. My name is Joshua Nimoy — username might be JNIMOY. I submit the page and it returns an error, telling me that username is already taken, and I have to choose another, since my father, Joseph Nimoy, registered before I did and he's got JNIMOY. And so I must use my middle initial T, and create a unique username, JTNIMOY. I just created and resolved a *namespace conflict*. A namespace is a group of unique names — none are identical. It's possible to have identical names, as long as they are a part of two separate namespaces. Namespaces help programmers avoid stepping on each other's toes by overwriting one another's symbols or hogging the good names. Namespaces also provide a neat and tidy organization system to help us find what we're looking for. In OpenFrameworks, everything starts with `of` . . . like `ofSetBackground` and `ofGraphics`. This is one technique to do namespace separation because it's less likely that any other names created by other programmers would begin with `of`. The same technique is used by OpenGL. Every name in the OpenGL API (Application Programming Interface) begins with `gl` like `glBlendFunc` and `glPopMatrix`. In C++ however, it is not necessary to have a strictly disciplined character prefix for your names, as the language provides its own namespacing syntax. In line 2, `using namespace std;` is telling the compiler that this .cpp file is going to use all the names in the `std` namespace. Spoiler-alert! those two names are `cout` and `endl`. Let us now do an experiment and comment out line 2, then run the code. What sort of error do you think the compiler will return?

```cpp
/* using namespace std; */
```

It's a very similar error as before, where it cannot find `cout` or `endl`, but this time, there are suggested alternatives added to the message list.

```
prog.cpp:5:2: note: suggested alternative:
In file included from prog.cpp:1:0:
/usr/include/c++/4.8/iostream:61:18: note:   ‘std::cout’
   extern ostream cout;  /// Linked to standard output
                  ^
```

The compiler says, "Hey, I searched for `cout` and I did find it in one of the namespaces included in the file. Here it is. `std::cout`" and in this case, the compiler is correct. It wants us to be *more explicit* with the way we type `cout`, so we express its namespace `std` (standard) on the left side, connected by a double colon (::). it's sort of like calling myself `Nimoy::Joshua`. Continuing our experiment, edit line 5 so that `cout` and `endl` have explicit namespaces added.

```cpp
std::cout << "Hello World" << std::endl;
```

When you run the code, you will see it compiles just fine, and succeeds in printing "Hello World". Even though the line that says `using namespace std;` is still commented out. Now imagine you are writing a program to randomly generate lyrics of a song. Obviously, you would be using `cout` quite a bit. Having to type `std::` before all your `cout`s would get really tedious, and one of the reasons a programming language adds these features is to reduce typing. So although line 2 `using namespace std;` was not necessary, having it in place (along with other `using namespace` statements) can keep one's C++ code easy to type and read, through implied context.

Say I'm at a Scrabble party in Manhattan, and I am the only Josh. People can just call me Josh when it's my turn to play. However, if Josh Noble joins us after dinner however, it gets a bit confusing and we start to call the Joshes by first and last name for clarity. In C++, the same is also true. I would be `Nimoy::Josh` and he would be `Noble::Josh`. It's alright to have two different `cout` names, one from the `std`namespace, and another from the `improved` namespace, as long as both are expressed with explicit namespaces; `std::cout` and `improved::cout`. In fact, the compiler will complain if you don't.

You will see more double-colon syntax (::) when I introduce classes.

## Functions

Moving on, let us take a look at line 4:

```cpp
int main() {
```

This is the first piece of code that has a beginning and an end, such that it "wraps around" another piece of code. But more importantly, a function *represents* the statements enclosed within it. The closing end of this *function* is the closing curly brace on line 7:

```cpp
}
```

In C++, we enclose groups of code statements inside functions, and each function can be seen as a little program inside the greater program, as in the simplified diagram in figure 9.

![Figure 9: Many Functions](images/program-anatomy.png "Figure 9. A program contains many functions, and each function contains zero or more statements.")

Each of these functions has a name by which we can call it. To call a function is to execute the code statements contained inside that function. The basic convenience in doing this is less typing, and we will talk about the other advantages later. Like a board game, a program has a starting position. More precisely, the program has an *entrypoint* expected by the compiler to be there. That entrypoint is a function called *main*. The code you write inside the *main* function is the first code that executes in your program, and therefore it is responsible for calling any other functions in your program. Who calls your *main* function? The operating system does! Let's break down the syntax of the main function in this demo. Again, for all you Processing coders, this is old news.

![Figure 10: The Function](images/function-anatomy.png)

When defining a function, the first token is the advertised return type. Functions can optionally return a value, like an answer to a question, a solution to a problem, the result of a task, or the product of a process. In this case, *main* promises to return an `int`, or *integer* type, which is a whole number with no fraction or decimal component. Next token is the name of our function. The system expects the word "main" in all lower-case, but you will later define your own functions and we will get into naming. Next is an opening and closing parenthesis. Yes, it seems kind of strange to have it there, since there is nothing inside it. Later, we will see what goes in there — but never leave out the pair of parentheses with functions because in a certain way, that is the major hint to the human that it's a function. In fact, from now on, when I refer to a function by name, I'll suffix it with a ( ), for example `main()`.

Next, we see an opening curly bracket. Sometimes this opening curly bracket is on the same line as the preceding closing parenthesis, and other times, you will see it on its own new line. It depends on the personal style of the coder, project, or group — and both are fine. For a complete reference on different indent styles, see the the Wikipedia article on Indent Style (http://en.wikipedia.org/wiki/Indent_style).

In between this opening curly bracket and the closing one, we place our code statements that actually tell the computer to go do something. In this example, I only have one statement, and that is the required `return`. If you leave this out for a function whose return type is `int`, then the compiler will complain that you broke your promise to return an int. In this case, the operating system interprets a 0 as "nothing went wrong". Just for fun, see what happens when you change the 0 to a 1, and run the code.

## Custom Functions

We will now define our own function and make use of it as a word template. Type the sample code into your editor and run it.

```cpp
#include <iostream>
using namespace std;

void greet(string person){
	cout << "Hi there " << person << "." << endl;
}

int main() {
	greet("moon");
	greet("red balloon");
	greet("comb");
	greet("brush");
	greet("bowl full of mush");
	return 0;
}
```

The output shows a familiar bedtime story.

```
Hi there moon.
Hi there red balloon.
Hi there comb.
Hi there brush.
Hi there bowl full of mush.
```

In this new code, notice the second function `greet()` which looks the same but different from `main()`. It has the same curly brackets to hold the code block, but the return type is different. It has the same pair of parentheses, but this time there is something inside. And what about that required return statement? The *void* keyword is used in place of a return type when a function does not return anything. So, since `greet()` has a *void* return type, the compiler will not complain should you leave out the `return`. In the parentheses, you see `string person`. This is a parameter, an input-value for the function to use. In this case, it's a bit like find-and-replace. Down in `main()`, you see I call `greet()` five times, and each time, I put a different string in quotes between the parentheses. Those are *arguments*.

As an aside, to help in the technicality of discerning between when to call them *arguments* and when to call them *parameters*, see this code example:

```cpp

void myFunction(int parameter1, int parameter2){
	//todo: code
}

int main(){
	int argument1 = 4;
	int argument2 = 5;
	myFunction(argument1,argument2);
	return 0;
}

```

Getting back to the previous example, those five lines of code are all ***function calls***. They are telling `greet()` to execute, and passing it the one string argument so it can do its job. That one string argument is made available to `greet()`'s inner code via the argument called `person`. To see the order of how things happen, take a look at Figure 11.

![Figure 11. Function Call Flow](images/function-call.png "Figure 11. Function Call Flow")

The colorful line in Figure 11 is the path drawn by an imaginary playback head that steps over the code as it executes. We start at the blue part and go in through the main entrypoint, then encounter `greet()`, which is where a *jump* happens. As the line turns green, it escapes out of `main()` temporarily so it can go follow along `greet()` for a while. About where the line turns yellow, you see it finished executing the containing code inside `greet()` and does a second jump (the return) this time going back to the previous saved place, where it continues to the next statement. The most obvious advantage we can see in this example is the reduction of complexity from that long `cout` statement to a simple call to `greet()`. If we must call `greet()` five times, having the routine *encapsulated* into a function gives it convenience power. Let's say you wanted to change the greeting from "Good night" to "Show's over ". Rather than updating all the lines of code you cut-and-pasted, you could just edit the one function, and all the uses of the function would change their behavior along with it, in a synchronized way. Furthermore, code can grow to be pretty complex. It helps to break it down into small routines, and use those routines as your own custom building blocks when thinking about how to build the greater software. By using functions, you are liberated from the need to meticulously represent every detail of your system; therefore a function is one kind of *abstraction* just like abstraction in art. This sort of abstraction is called *encapsulation of complexity* because it's like taking the big complex thing and putting it inside a nice little capsule, making that big complex thing seem smaller and simpler. It's a very powerful idea — not just in code.

## Encapsulation of Complexity

Imagine actor Laurence Fishburne wearing tinted Pince-nez glasses, offering you two options that are pretty complicated to explain. On the one hand, he is willing to help you escape from the evil Matrix so that you may fulfill your destiny as the hacker hero, but it involves living life on life's terms and that is potentially painful but whatever. The story must go on and btw, there is a pretty girl. On the other hand, he is also willing to let you forget this all happened, and mysteriously plant you back in your tiny apartment where you can go on living a lie, none the wiser. These two options are explained in the movie *The Matrix* and then the main character is offered the choice in the form of colored pills, as a way to simplify an otherwise wordy film scenario. The two complex choices are encapsulated into a simple analogy that is much easier for movie audiences to swallow. See Figure 12.

![Figure 12. Red Pill and Blue Pill from The Matrix](images/red-blue-pills.png "Figure 12. Red Pill and Blue Pill from The Matrix")

Rather than repeating back the entire complicated situation, Neo (the main character) needed only to swallow one of the pills. Even if it were real medicine, the idea of encapsulating complexity still applies. Most of us do not have the expertise to practice medicine in the most effective way, and so we trust physicians and pharmacologists to create just the right blend of just the right herbs and chemicals. When you swallow a pill, it is like calling that function because you have the advantage of not needing to understand the depths of the pill. You simply trust that the pill will cause an outcome. The same is true with code. Most of the time, a function was written by someone else, and if that person is a good developer, you are free to remain blissfully ignorant of their function's inner workings as long as you grasp how to properly call their function. In this way, you are the *higher-level* coder, meaning that you simply call the function but you did not write it. Someone who creates a project in OpenFrameworks is sitting on the shoulders of the OpenFrameworks layer. OpenFrameworks sits on the shoulders of the OpenGL Utility Toolkit, which sits on OpenGL itself, and so on. In other words, an OpenFrameworks project is a *higher-level* application of C++, a language with a reputation for *lower-level* programming. As illustrated in Figure 13, I sometimes run into a problem when I tell people I wrote an interactive piece in C++.

![Figure 13. Standing on Shoulders of Giants](images/shoulders-of-giants.png "Figure 13. Standing on Shoulders of Giants")

There are a few advantages to using C++ over the other options (mostly scripting) for your new media project. The discussion can get quite religious (read: heated) among those who know the details. If you seek to learn C++, then usually it is because you seek faster runtime performance, because C++ has more libraries that you can snap in to your project, or because your mentor is working in that language. An OF project is considered higher-level because it is working with a greater encapsulation of complexity, and that is something to be proud of.

## A Brief History

I'm going to take a break from learning how to use the language and look into its social history for a moment, because it knowing who and where the language comes from can help in understand why certain things are the way they are.

There are many programming languages, each one with its own unique story. Like human languages, they relate in a tangled family tree that eventually leads all the way back to the first computer language by Augusta Ada King, Countess of Lovelace in the 17th century. Languages improve on previous ones for various reasons, such as increasing efficiency/performance, reducing engineering complexity, adding useful features for the programmer, creating new divisions of labor, and in general, making programmers happier. C++, its parent language C, and grandparent language B (BCPL) all come from Bell Laboratories, In fact, the B stands for Bell. Figure 14 shows a picture of Dennis M. Ritchie and Ken Thompson, the creators of C, sitting in front of a PDP-11, the first computer to run Unix. Because C is the next language after B, it uses the next letter in the Roman alphabet.

![Figure 14. Ken Thompson(sitting) and Dennis Richie (standing) in front of a PDP-11, circa 1972](images/kd14.jpg "Figure 14. Ken Thompson(sitting) and Dennis Richie (standing) in front of a PDP-11, circa 1972")

If I ask my father nicely, he will tell stories about his days at Bell Labs in Murray Hill, New Jersey in the late 1960s doing liquid crystal research. Some of his colleagues who did heavier computation work could be seen walking around with shoe boxes filled with punch cards. These punch cards (Figure 15) were difficult to create, share, and maintain (imagine dropping that shoe box). Taking turns running jobs on the GE 600-series mainframes also stifled collaboration because the punch card systems were not multi-user. Perhaps it was a bit like waiting to use the largest CNC machine at TechShop.

![Figure 15. Bell Labs punch card from the mid-1960s, courtesy of Lucent](images/bell1.png "Figure 15. Bell Labs punch card from the mid-1960s, courtesy of Lucent")


Thompson and Ritchie initiated the development of the Unix operating system in effort to improve these original problems (and provide a useful jig with which they could create their game "Space Travel"). Part of what made Unix attractive was that its heart was written in C, instead of the lower level assembly language - and that made it more portable. Back then, every new machine invented needed to have an assembly language specific to it - that was always the first job of its users. Because Thompson and Ritche ported Unix over to C, it made Unix very portable - giving it a very good chance to spread virally. The birth of the C language happened along-side the birth of Unix. Hence, the present-day ubiquity of Unix-like OSes may explain the importance of C and its derivative languages.

A decade later, Bjarne Stroustrup created a new strain of the C language in order to update it with a new paradigm called *object oriented programming* which introduces an intermediary container between the function and its program called a *class*. The class system allows a program to do special skateboard tricks that you can read about in the ***OOPS!*** chapter. Since C++ is close enough to C, compiling compatibly with it (if you know what you're doing), C++ rides the popularity of C and Unix. C++ gets its name because putting `++` after something in C means adding 1 to it (or *incrementing* it). C++ is the C language, plus one paradigm. C++ is considered by many to be the most popular programming language of all time.

### Derivative Languages

(My apologies to *The Nails*)

Since establishing the C++ standard, there have been a variety of direct derivative languages - some with the C letter in their name, and some without. *Objective-C* is a decade newer than C++. Intermingled with the NeXT operating system (Figure 16 shows a logo by Paul Rand) and the OpenStep project, Objective-C is most popularly used to develop apps for OS X and iOS. *Java* (20 years newer than C++) is considered a direct derivative of C++. It attempts to remove the "C" and keep only the "++". If you study computer science in university, this language may be one of the first things they teach you, whereas historically, that first language used to be C and C++. *C#* (pronounced C-Sharp) is Microsoft's Java alternative. Originally intended for use in developing .NET apps, you may also use it when developing in Unity - or any platform that uses the Mono project. *C++11* is a newer, more recent version of C++ from 2011 that adds a variety of new features. You may learn more about how it differs from classic C++ in Chapter 15. Finally, *D* is the programming language that takes the next letter in the alphabet after C, also attempting to modernize the language similarly as its contemporaries, and (trivially) did not come from Murray Hill, New Jersey. These different languages are easy to pick up once you grok C++. There are shortcut tutorials to help the C++ programmer understand the other languages and their environments. If you wish to create your own strain of the C++ language, I suggest taking a course on *compiler construction* - for example, the one offered on Coursera by Stanford University's Professor Alex Aiken.

![Figure 16. NeXT Logo by Paul Rand](images/next-logo-paul-rand.jpg "Figure 16. NeXT Logo by Paul Rand")

Although OS X promotes Objective-C and Windows promotes C#, both XCode and Visual Studio will still compile C and C++ along side Linux because the C and C++ language compilers are in higher demand than their proprietary strains. It can be useful to combine code files written in these various languages in order to create a flexible solution that reduces the amount of re-invention you must do. Fundamentally, OpenFrameworks bases its cross-platform portability on the portability of the C++ language. Theoretically, you should be able to write your OpenFrameworks app once, on one platform, then see it compile and run identically in other environments. 

### Conversational Slang

Sometimes I say C, and sometimes I say C++. Since they are closely related, perhaps you can understand how they are almost synonymous. I also leave out the ++ because I am talking about both languages! C++ is almost a superset of C (see figure 17), so when I talk about the properties of C, I am usually also talking about the properties of C++. To make things worse, the greater slang of C applies to all the C-something languages. Let's say you are a famous code artist presenting at the EyeO festival and a member of the audience asks you to talk about the programming of your piece. You may have used a combination of C++, C, and Objective-C on Mac OS X to make your OpenFrameworks project happen (not to mention Java and C# on your Linode server), but because simplicity is elegant, and because you only have 2 minutes left before they kick you off stage, your answer is shortened - and you say "I wrote it in C". Perhaps later when that audience member talks to you individually, you can be more specific about all the strains of C-language you actually used. Like most slang, relaxed conversational use of "C" is also context-sensitive. Sometimes preemptively simplifying speech like that is inappropriate when you are speaking to known engineers, developers, and hackers. In that case, saying C when you mean C++ might be construed as fronting!

![Figure 17. C++ is a non-strict superset of C](images/non-strict-superset.png "Figure 17. C++ is a non-strict superset of C")

## Variables (part 1)

> A “thing” is a “think”, a unit of thought
> 
> -- Alan Watts


Please enter the following program into ideone and run it.

```cpp
#include <iostream>
using namespace std;

int main(){
	cout << "My friend is " << 42 << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << 42 << "." << endl;
	cout << "That number plus 1 is " << (42+1) << "." << endl;
	return 0;
}
```

The output looks like this:

```
My friend is 42 years old.
The answer to the life the universe and everything is 42.
That number plus 1 is 43.
```

We understand from a previous lesson that stuff you put between the `<<` operators will get formatted into the `cout` object, and magically end up in the output console. Notice in the last line, I put a bit of light arithmetic (42+1) between parentheses, and it evaluated to 43. That is called an *expression*, in the mathematics sense. These three lines of code all say something about the number 42, and so they all contain a *literal* integer. A literal value is the contents typed directly into the code; some would say "hard wired" because the value is fixed once it is compiled in with the rest.

If I want to change that number, I can do what I know from word processing, and "find-and-replace" the 42 to a new value. Now what if I had 100,000 particles in a 3d world. Some have 42s that need changing, but other 42s that should not be changed? Things can get both heavy and complex when you write code. The most obvious application of *variables* is that they are a very powerful find-and-replace mechanism, but you'll see that variables are useful for more than that. So let's declare an integer at the top of the code and use it in place of the literal 42s.

```cpp
#include <iostream>
using namespace std;

int main(){
	
	int answer = 42;
	
	cout << "My friend is " << answer << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << answer << "." << endl;
	cout << "That number plus 1 is " << (answer+1) << "." << endl;
	return 0;
}
```

Now that I am using the variable `answer`, I only need to change that one number in my code, and it will show up in all three sentences as 42. That can be more elegant than find-and-replace. Figure 18 shows the syntax explanation for declaring and initializing a variable on the same line.

![Figure 18. Variable declaration and initialization](images/variable-declaration.png "Figure 18. Variable declaration and initialization")

It is also possible to declare a variable and initialize it on two separate lines. That would look like:

```cpp
int answer;
answer = 42;
```

In this case, there is a moment after you declare that variable when its answer may be unpredictable and glitchy because in C (unlike Java), fresh variables are not set to zero for free — you need to do it. If you don't, the variable can come up with unpredictable values — computer memory-garbage from the past. So, unless you intend to make glitch art, please always initialize your variable to some number upon declaring it, even if that number is zero.

### Naming your variable

Notice the arrow below saying "must be a valid name". We invent new names to give our namespaces, functions, variables, and other constructs we define in code (classes, structs, enums, and other things I haven't taught you). The rules for defining a new identifier in code are strict in a similar way that choosing a password on a website might be.

+ Your identifier must contain only letters, numbers, and underscores.
+ it cannot begin with a number, but it can certainly begin with an underscore.
+ The name cannot be the same as one of the language keywords (for example, the word `void`)

The following identifiers are okay.

```
a
A
counter1
_x_axis
perlin_noise_frequency
_         // a single underscore is fine
___       // several underscores are fine
```

Notice lowercase a is a different identifier than uppercase A. Identifiers in C++ are case-sensitive.
The following identifiers are not okay.

```cpp
1infiniteloop         // should not start with a number
transient-mark-mode   // dashes should be underscores
@jtnimoy              // should not contain an @
the locH of sprite 1  // should not contain spaces
void                  // should not be a reserved word
int                   // should not be a reserved word
```

naming your variable `void_int`, although confusing, would not cause any compiler errors because the underscore joins the two keywords into a new identifier. Occasionally, you will find yourself running into `unqualified id` errors. Here is a list of C++ reserved keywords to avoid when naming variables. C++ needs them so that it can provide a complete programming language.

```
alignas alignof and and_eq asm auto bitand bitor bool break case catch
char char16_t char32_t class compl const constexpr const_cast continue
decltype default delete do double dynamic_cast else enum explicit
export extern false final float for friend goto if inline int long
mutable namespace new noexcept not not_eq nullptr operator or or_eq
override private protected public register reinterpret_cast return
short signed sizeof static static_assert static_cast struct switch
template this thread_local throw true try typedef typeid typename
union unsigned using virtual void volatile wchar_t while xor xor_eq
```

### Naming conventions

> Differences of habit and language are nothing at all if our aims are identical and our hearts are open.
>
> **--Albus Dumbledore**


Identifiers (variables included) are written with different styles to indicate their various properties, such as type of construct (variable, function, or class?), data type (integer or string?), scope (global or local?), level of privacy, etc. You may see some identifiers capitalized at the beginning and using `CamelCase`, while others remain all `lower_case_using_underscores_to_separate_the_words`. Global constants are found to be named with `ALL_CAPS_AND_UNDERSCORES`. Another way of doing lower-case naming is to start with a lowercase `letterThenCamelCaseFromThere`. You may also see a hybrid, like `ClassName__functionName__variable_name`. These different styles can indicate different categories of identifiers.

More obsessively, programmers may sometimes use what is affectionately nicknamed *Hungarian Notation*, adding character badges to an identifier to say things about it but also reduce the legibility, for example `dwLightYears` and `szLastName`. Naming conventions are not set in stone, and certainly not enforced by the compiler. Collaborators generally need to agree on these subtle naming conventions so that they don't confuse one another, and it takes discipline on everyone's part to remain consistent with whatever convention was decided. The subject of naming convention in code is still a comically heated debate among developers, just like deciding which line to put the curly brace, and whether to use tabs to indent. Like a lot of things in programming, someone will always tell you you're doing it wrong. That doesn't necessarily mean you are doing it wrong.

### Variables change

We call them variables because their values *vary* during runtime. They are most useful as a bucket where we put something (let's say water) for safe keeping. As that usually goes, we end up going back to the bucket and using some of the water, or mixing a chemical into the water, or topping up the bucket with more water, etc. A variable is like an empty bucket where you can put your stuff. Figure 19 shows a bucket from the game *Minecraft*.

![Figure 19. Bucket, courtesy of Mojang AB](images/minecraft-bucket.png "Figure 19. Bucket, courtesy of Mojang AB")

If a computer program is like a little brain, then a variable is like a basic unit of remembrance. Jotting down a small note in my sketchbook is like storing a value into a variable for later use. Let's see an example of a variable changing its value.

```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter = 1;
	cout << counter;
	counter = 2;
	cout << counter;
	counter = 3;
	cout << counter;
	counter = 4;
	cout << counter;
	counter = 5;
	cout << counter;
	return 0;
}
```

The output should be `012345`. Notice the use of the equal sign. It is different than what we are accustomed to from arithmetic. In the traditional context, a single equal sign means the expressions on both sides would evaluate to the same value. In C, that is actually a double equal (==) and we will talk about it later. A single equal sign means "Solve the expression on the right side and store the answer into the variable named on the left side". It takes some getting used to if you haven't programmed before. If I were a beginning coder (as my inner child is perpetually), I would perhaps enjoy some alternative syntax to command the computer to store a value into a variable. Something along the lines of: `3 => counter` as found in the language *ChucK* by Princeton sound lab, or perhaps something a bit more visual, as my repurposing of the Minecraft crafting table in figure 20.

![Figure 20. Minecraft crafting table repurposed for variable assignment](images/minechuck.png "Figure 20. Minecraft crafting table repurposed for variable assignment")

The usefulness of having the variable name on the left side rather than the right becomes apparent in practice since the expressions get get quite lengthy! Beginning a line with `varname =` ends up being easier for the eyeball to scan because it's guaranteed to be two symbols long before starting in on whatever madness you plan on typing after the equals sign.

Analyzing the previous code example, we see the number increments by 1 each time before it is output. I am repeatedly storing literal integers into the variable. Since a programming language knows basic arithmetic, let us now try the following modification:

```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	counter = counter + 1;
	cout << counter;
	return 0;
}
```

The output should still be `012345`. By saying `counter = counter + 1`, I am incrementing `counter` by 1. More specifically, I am using `counter` in the right-hand "addition" expression, and the result of that (one moment later) gets stored into `counter`. This seems a bit funny because it talks about `counter` during two different times. It reminds me of the movie series, *Back to the Future*, in which Marty McFly runs into past and future versions of himself. See Figure 21.

![Figure 21. The future Marty uses the past Marty](images/futuremarty.png "Figure 21. The future Marty uses the past Marty")

Great Scott, that could make someone dizzy! But after doing it a few times, you'll see it doesn't get much more complicated than what you see there. This is a highly *practical* use of science fiction, and you probably aren't attempting to challenge the fabric of spacetime (unless you are Kyle McDonald, or maybe a Haskell coder <!-- i mean these things as a high compliment, not as mockery -->). The point here is to modify the contents of computer memory, so we have `counter` from one instruction ago, in the same way that there might already be water in our bucket when we go to add water to it. Figure 22 shows `bucket = bucket + water`.

![Figure 22. bucket = bucket + water](images/minecraft-inc.png "Figure 22. bucket = bucket + water")

Incrementing by one, or adding some value to a variable is in fact so commonplace in all programming that there is even syntactic sugar for it. *Syntactic Sugar* is a redundant grammar added to a programming language for reasons of convenience. It helps reduce typing, can increase comprehension or expressiveness, and (like sugar) makes the programmer happier. The following statements all add 1 to `counter`.

```cpp
counter = counter + 1; // original form
counter += 1;          // "increment self by" useful because it's less typing.
counter++;             // "add 1 to self" useful because you don't need to type a 1.
++counter;             // same as above, but with a subtle difference.
```

Let's test this in the program.

```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	counter++;
	cout << counter;
	return 0;
}
```

Yes, it's a lot less typing, and there are many ways to make it more concise. Here is one way.

```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	cout << counter++;
	return 0;
}
```

The answer is still `012345`. The postfix incrementing operator will increment the variable even while it sits inside an expression. Now let's try the prefix version.

```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	cout << ++counter;
	return 0;
}
```

If you got the answer `123456`, that is no mistake! The prefix incrementing operator is different from its postfix sister in this very way. With `counter` initialized as 0, `++counter` would evaluate to 1, while `counter++` would still evaluate to 0 (but an incremented version of `counter` would be left over for later use). The output for the following example is `1112`.

```cpp
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	cout << ++counter; // 1: increments before evaluating
	cout << counter;   // 1: has NOT changed.
	cout << counter++; // 1: increments after evaluating
	cout << counter;   // 2: evidence of change.
	return 0;
}
```

For arithmetic completeness, I should mention that the subtractive *decrementing* operator (counter--) also exists. Also, as you might have guessed by now, if one can say `counter + 1`, then a C compiler would also recognize the other classic arithmetic like `counter - 3` (subtraction), `counter * 2` (asterisk is multiplication), `counter / 2` (division), and overriding the order of operations by using parentheses, such as `(counter + 1) / 2` evaluating to a different result than `counter + 1 / 2`. Putting a negative sign before a variable will also do the right thing and negate it, as if it were being subtracted from zero. C extends this basic palette of maths operators with boolean logic and bitwise manipulation; I will introduce them in Variables part 2.

There are a few more essentials to learn about variables, but we're going to take what we've learned so far and run with it in the name of fun. In the meantime, give yourself another pat on the back for making it this far! You learned what variables are, and how to perform basic arithmetic on them. You also learned what the ++ operator does when placed before and after a variable name.

The C++ language gets its name from being the C language plus one.

## If-Then

Imagine riding your bicycle in the streets of your city. When you encounter intersections or forks in the road, you must decide whether to turn, go straight, or turn around based on where you are going, your urgency in getting home, and other places you may want to stop at. The next day, you may take the same route but end up taking very different streets based on the domino effect of your decisions.

Your ability to judge a situation and change your behavior based on your analysis is a kind of prediction behavior that defines intelligence. A computer program can also stop, analyze, and decide how to act in a more simplified way. *Conditionals* or *branching* in code are what provides this kind of simple yet useful intelligence. With just a little bit of *If-Then-Else* in your code, you can automate very complex decision making.

Figure 23 shows a generative, interactive cluster of branching neurons coded in OpenFrameworks for the CLOUDS Interactive Documentary. 

![Figure 23. Neuron simulation from CLOUDS Interactive Documentary](images/vsneurons.png "Figure 23. Neuron simulation from CLOUDS Interactive Documentary")

In beginning to understand how code branches, let's imagine the code is a shopping list (code I run on myself). I've been sent to the supermarket by my grandma Ceil to pick up ingredients for *Kreplach*, the (Ashkenazi) Jewish wonton. We have family visiting from Closter, NJ and since they had the chutzpah to schlep all the way to Brighton Beach, we're going to give them the works - kugel, brisket, and even tzibele kichel to nosh while she finishes cooking (instead of the stale hamantaschen from last Purim). But the only job I have is buying the ingredients for Kreplach. Here is the shopping list:

```
flour
kosher salt
dozen giant brown organic eggs
1 bottle corn oil
4 sweet onions
ground beef
parsley
pepper
garlic
potatoes
scallions
carrots
```

An experienced shopper knows that products and preferred brands are not always in stock, and so we notate the shopping list with alternative purchases in case the primary preference is not available.

```
Heckers unbleached all purpose flour (pillsbury or gold medal would be fine)
Morton Kosher Salt
dozen giant brown organic eggs (white eggs ok too)
1 bottle Mazola corn oil
4 sweet onions (white onions would be acceptable)
ground beef (ground chicken also ok, but NO traif!)
parsley
pepper
garlic
potatoes (red rose, white rose, yukon gold) NOT Idaho or Russet, not too much shmutz
scallions (chives will do but call me)
carrots
```

Although the above is more realistically how one would express conditionals in a shopping list (placing them after the primary product topic), let us refactor the shopping list to C-style conditionals by using indentation, and by "wrapping" code inside some if-braces.

```
if ( they have Heckers unbleached all purpose flour ){
	get that;
}else if( they only have Heckers BLEACHED flour){
	i'll settle for that over the other brands;
}else{
	get the pillsbury or gold metal brands;
}

get Morton Kosher Salt;

if ( there are giant brown organic eggs ){
	get a dozen of those;
}else{
	get a dozen of whatever eggs;
}

get 1 bottle Mazola corn oil;

if ( there are sweet onions ){
	get 4 of those;
}
//otherwise do nothing, I have white onions in the apartment.

if(the butcher has chop meat AND that meat is not traif AND (it is chicken or it is beef) ){
	get 2 lb of it;
}else{
	Boychik, call me and i'll direct you another kosher butcher in our hood;
}

get parsley;
get pepper;
get garlic;

if(they have red rose, white rose, or yukon potatoes and they don't have a lot of shmutz){
	get 8 of them;
}

if(they don't have scallions){
	get chives;
}else{
	get scallions;
}

get carrots;

```

Perhaps you noticed a pattern in the above *pseudo-code*, where I define a bracing structure that looks similar to a function in that it has parentheses and curly braces. Those are if-then-else statements, and they are a type of *flow control*. Figure 24 explains the parts.

![Figure 24. Anatomy of a conditional](images/conditional-anatomy.png "Figure 24. Anatomy of a conditional")

The part labelled `test` is a *boolean logic* expression, and that means it ultimately results in a TRUE or FALSE answer. Let us look at some real code to see how a true or false test looks in context.

```cpp
#include <math.h>
#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	
	counter++;
	cout << counter;
	if(counter > 1){
		cout << " is greater than 1";
	}
	cout << endl;

	counter++;
	cout << counter;
	if(counter > 1){
		cout << " is greater than 1";
	}
	cout << endl;

	counter++;
	cout << counter;
	if(counter > 1){
		cout << " is greater than 1";
	}
	cout << endl;

	return 0;	
}
```

Each time, I am checking to see if `counter` is greater than 1, and if that is the case, then a bit of extra text gets printed to the console. If you run this code (and I highly encourage you to do so), you would see the following output.

```
1
2 is greater than 1
3 is greater than 1
```

The first time it evaluates `counter > 1`, the result is false, and so the indented code does not execute. There are a couple other pieces of the if-structure worth introducing. One important one is `else`, which opens up a second block of code to execute if the condition is false.

```cpp

//this code happens regardless

if(true){
	// this code happens if the condition is true
}else{
	// this code happens if it is false
}

//this code happens regardless

```

This is different from simply putting an un-braced line of code beneath the if-clause since that free-roaming line of code would execute *whether or not* the condition were true. So `else` turns out to be pretty convenient. Another similar piece is `else if` that allows you to cascade your if-then clauses in a way similar to CSS.

```cpp

if(condition1){
	// this code happens if condition1 is TRUE, then the rest is skipped.
}else if(condition2){
	// this code happens if condition1 was FALSE, however condition2 is TRUE.
}else if(condition3){
	// this code happens if condition2 and condition1 were both FALSE, however condition3 is TRUE.
}else{
	// this code happens if none of the 3 conditions are true
}

```

Using `else if`, it's easy to build a flexible filter system for decision making.

### Syntactic Sugar for Conditionals

The following is debated as something worth avoiding by folks like JSLint (who are also strict about whitespace). The reason I introduce it here is because you'll see it in OpenFrameworks related code, and I want you to recognize what you are seeing. If-statements can be expressed more concisely by using the single-line syntax, which is less flexible.

```cpp
if (counter > 1) cout << "yes, it's greater";
cout << "... this line will always execute regardless." endl;
```

An if-statement with no curly braces will only "limit" the one immediately following line of code. Even with the other snap-in parts, the same "next line only" rules apply.

```cpp
if (counter > 1) cout << "yes, it's greater";
else if (counter < 10) cout << "well, it's still smaller than 10";
else cout << "The counter was outside the 2-10 range.";
cout << "... this line will always execute regardless." endl;
```

The above code will do the exact same thing as:

```cpp
if (counter > 1) {
	cout << "yes, it's greater";
} else if (counter < 10) {
	cout << "well, it's still smaller than 10";
} else {
	cout << "The counter was outside the 2-10 range.";
}
```

You can even mix and match which parts of the clause are "braced" and which ones are one-liners.
If at all possible, I recommend using the fully braced syntax for all new code in the name of fast eyeball scanning. There is also something called a *ternary operator* that looks like `a > b ? x : y`. I'll let you google that on your own if you are genuinely curious, but I should discourage the use of ternary-ifs as well because they are esoteric, not terribly portable, difficult to scale or nest, and can get confusing fast. On the other hand, I do recommend you get to know ternaries in case you run into someone else's.

### Inequality Operators

So far, I've glossed over that part that goes `counter > 1`. Perhaps you recall a moment in third grade when the teacher taught you the "pacman" rule of inequality, where greedy pacman wants to go chomp the bigger number, so he faces in that direction. Comparison operators in C are based on that.

```cpp
a > b // a is greater than b
a < b // a is less than b
a >= b // a is greater-than-or-equal-to b
a <= b // a is less-than-or-equal-to b
a == b // a is equal to b
a != b // a is not equal to b
```
You will notice the use of double-equal sign to mean the original thing you thought an equal sign was supposed to be used for. A common mistake for beginning coders is the blending between single and double equal signs. Please take the time to know this difference because it will save you some mind-numbingly mysterious errors in the future.

### Boolean Logic

Inequalities can be joined together with logical operators called AND, OR, and NOT, which do much the same thing they are already doing in natural English. AND is typed out as the `&&` operator, while OR is the `||` operator. NOT is a prefixed exclamation mark, and it inverts the truth state of an expression. Here are some boolean logic expressions.

```cpp
true || false             // true
false || false            // false
true || false || false    // true

false && true             // false
true && true              // true
false && false            // false

!true                     // false
!false                    // true

true && !(true || false)  // false
false || true && !false   // true
```

"Boolean" is named after George Boole, one of the fathers of computer science who worked out this sort of true/false maths. You'll find boolean logic in everything  partly because it powers the if-then clauses. The keywords `true` and `false` are considered *global constants*. Conveniently, any non-zero number qualify as true when placed in a boolean context, whilst all zero values qualify as false. In that way, you might set up your arithmetic to land on a zero or non-zero in formulating a testing expression for your if-then clause. In the following example of a conditional, you'll see boolean logic operators used to join numeric comparison.

```cpp
if (counter > 10 && counter < 20) {
	cout << "it's within the 10-20 range";
} else if (counter <= 0) {
	cout << "it's zero or less";
} else {
	cout << "all other cases";
}
```

### Nesting

If-then clauses may also be *nested* meaning you can place an entire if-then clause inside one of the code blocks of another. Of course, the indentation needs to observe proper recursion.

```cpp

if( counter > 30 ){
	
	if(counter > 50){
		// todo: do something
	}
	
}else{

	if(counter < 0){
		
		if(counter < -10){
			//todo: do something
		}
		
	}else{
		//todo: do something else
	}
	
}
```

The term *nesting* is the same concept as the Matryoshka doll, as shown in Figure 25. You can place the hollow Russian dolls inside one another until it appears like there is only one doll. It's trippy because of the concentric modules (recursion) but it is incredibly useful in crafting an algorithm.

![Figure 25. Matryoshka nesting doll](images/Russian-Matroshka2.jpg "Figure 25. Matryoshka nesting doll")
**[JTN: this needs copyleft attribution and highest res version needs to be archived]**


## Looping

You may have noticed that the recent C++ example code had a lot of cutting and pasting in it. This brute-force way of forging repetitive behavior is not as flexible, and nowhere near as concise as simply telling your code to loop.

```cpp
#include <math.h>
#include <iostream>
using namespace std;

int main(){
    int counter = 0;

	while(true){
    	counter	++;
	    cout << counter << ", ";
	}
	
    return 0;   
}
```

If you run this code, the output starts like this . . .

```
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104,
105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132,
133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160,
161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174,
175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188,
189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202,
203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214 . . .
```

. . . and continues to execute until ideone decides to kill the process (force quit) the program prematurely. Truth be told, if you were running the very same app directly on your laptop as you would be doing in a normal OpenFrameworks situation, the program would run forever - until the computer runs out of resources, reboots, or you kill the process yourself. The reason it keeps incrementing `counter` then prints its value to the console infinitely is because I placed a `true` into the parentheses. Figure 26 explains each part of the simple yet powerful `while` clause.

![Figure 26. While Clause](images/while-anatomy.png "Figure 26. While Clause")

Normally, you would not want your program to simply loop forever. Let's modify the code so that the loop knows to stop after hitting 100.


```cpp
while(counter < 100){
	counter	++;
    cout << counter << ", ";
}
```

I changed the contents of the `while`'s conditional expression so that it will only loop up to 100. The output:

```
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100,

```

This is not the only way to stop a while loop. Let us nest some if-then clauses into the while loop, so I can demonstrate the `break` statement, and later, I will show you the `continue` statement.

```cpp
	while(true){
    	counter	++;
	    cout << counter << " ";
	    if(counter==10){
	    	break;	
	    }
	}
```

The output is `1 2 3 4 5 6 7 8 9 10 `. As I loop, I am repeatedly checking to see if counter is 10, and if that is the case, I `break` out of the loop. 

### Modulo %

For the next example, I'd like to introduce you to the modulo operator, which is not so common in basic arithmetic but turns out to be useful and fun in programming. It is the percent sign operator, placed between 2 numbers, and it computes the *remainder* from dividing the left number by the right number. Here are a few examples:

+ 4 % 2 is 0 because 4 / 2 ends up being 2 with no remainder.
+ 10 % 3 is 1
+ 10 % 4 is 2
+ 9 % 10 is 9
+ 10 % 10 is 0
+ 11 % 10 is 1

Still confused? You are not alone.

Remember how to divide numbers on paper? The remainder is the little bit left over at the end that did not fit.

![Figure 26.5 Long Division with Remainder](images/remainder.png "Figure 26.5 Long Division with Remainder")

It turns out that dividing a fixed number into an incrementing value will produce a remainder that "wraps around" from 0 to that number. So for example, here is the output of (i % 4) while i goes from 0 to 16.

`0 1 2 3 [wrap] 0 1 2 3 [wrap] 0 1 2 3 [wrap] 0 1 2 3`

Because of this easily controllable stepping behavior, Modulo is great for easily making patterns. The following example prints an alternating pattern of # and space, forever.
 

```cpp
while(true){
	counter	++;
    if(counter % 2 == 0){
    	cout << '#';
    }else{
    	cout << ' ';
    }
}
```

This outputs `# # # # # #`. The next modification prints out `# ## ## ## ## ##`.

```cpp
while(true){
	counter	++;
    if(counter % 3 < 2){
    	cout << '#';
    }else{
    	cout << ' ';
    }
}
```

Getting back to demonstrating the `continue` statement, I will use the % operator to "skip" only even numbers.

```cpp
while(true){
	counter	++;
    if(counter % 2 == 0){
    	continue;
    }else{
    	cout << counter << ' ';
    }
}
```

The output begins with `1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47`, only odd numbers. The `continue` statement is different from `break` because it only breaks out of that one instance of the loop and starts directly at the next. `break` will end the loop entirely.

The following program uses a nested while-loop and an additional counter variable to generate a sawtooth wave pattern in ASCII art.

```cpp
#include <math.h>
#include <iostream>
using namespace std;

int main(){
    int counter = 0;
	int innerCounter = 0;
	while(true){
		counter	++;
	    
	    innerCounter = 0;
	    while(innerCounter < (counter % 32) ){
			innerCounter++;
	    	cout << 'O';
	    }
	    cout << endl;
	}
	
    return 0;   
}
```

The output is a vertical sawtooth wave:

```
O
OO
OOO
OOOO
OOOOO
OOOOOO
OOOOOOO
OOOOOOOO
OOOOOOOOO
OOOOOOOOOO
OOOOOOOOOOO
OOOOOOOOOOOO
OOOOOOOOOOOOO
OOOOOOOOOOOOOO
OOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

O
OO
OOO
OOOO
OOOOO
OOOOOO
OOOOOOO
OOOOOOOO
OOOOOOOOO
OOOOOOOOOO
OOOOOOOOOOO
OOOOOOOOOOOO
OOOOOOOOOOOOO
OOOOOOOOOOOOOO
OOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

O
OO
OOO
OOOO
OOOOO
OOOOOO
OOOOOOO
OOOOOOOO
OOOOOOOOO
OOOOOOOOOO
OOOOOOOOOOO
OOOOOOOOOOOO
OOOOOOOOOOOOO
OOOOOOOOOOOOOO
OOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
```

## For-Loop

Because a *finite* loop is so common, there is syntactical sugar for it. This sugar is so common in every language that it ceases to be sugar. A for-loop allows you to concisely iterate through a counting range. The loops are considered safer because they prevent the whole "infinity" thing, and on the other hand, there are ways to trick a for-loop into looping infinitely. They are incredibly practical, and you see them everywhere. Figure 27 shows the syntax breakdown of a for-loop that iterates 100 times.

![Figure 27. For-Loop Anatomy](images/for-anatomy.png "Figure 27. For-Loop Anatomy")

That whole chunk of `for( int i = 0 ; i < 100 ; i++ )` seems confusing at first but you will get to know it pretty fast. it just means "do this 100 times", and it is worth practicing typing that very thing out a few times so you can commit it into muscle memory. Here are a few for-loops.

```cpp

for(int i = 100 ; i >= 0 ; i--){
	//iterates with i from 100 to 0
}

for( int i = 0 ; i < 100 ; i += 2){
	//iterates with i from 0 to 100, skipping 2 each time.
}

for( int i = 0 ; i < 10 ; i++ ){
	for( int j = 0 ; j < 10 ; j++ ){
		for( int k = 0 ; k < 10 ; k++ ){
			// a triple nested for-loop using variables i,j,k
		}
	}
}

```

The iterating variable in a for-loop is commonly named `i`, the inner one is named `j`, and the one inside that is `k`. After that, the emerging standard starts to vary but I have seen `ii`,`jj`,`kk`, and then `iii`,`jjj`,`kkk`. Programmers also just break down and start using more expressive variable names. In nested for-loops that iterate through pixels, you will commonly see `x`, `y`, and sometimes `z` as the iterator names. If you see the variable `i` in someone's code, chances are it's a local variable declared at the top of the for-loop. Just like the while-loop, a for-loop will respond to `break` and `continue` statements. Here is an example of a double for-loop that generates a 2-dimensional pattern into the console.

```cpp
#include <iostream>
using namespace std;

int main(){
    for( int y = 0; y < 20 ; y++ ){ 
        for( int x = 0 ; x < 80 ; x++ ){
            if(y%2==0){
                if(x%2==0){
                    cout << ')';
                }else{
                    cout << ' ';
                }
            }else{
                if(x%2==0){
                    cout << ' ';
                }else{
                    cout << '(';
                }                
            }
        }
        cout << endl;
    }
    return 0;
}

```

And the output should look like this.

```
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
```

Just for fun, I'm going to introduce a distance function. You don't need to understand the pythagorean theorem (unless you want to) but just paste the useful function into your code so you can measure distance.


```cpp
#include <iostream>
#include <math.h>
using namespace std;

int distance(int x1,int y1,int x2, int y2){
    int xDelta = x1-x2;
    int yDelta = y1-y2;
    return sqrt(xDelta * xDelta + yDelta * yDelta);
}

int main(){
    for( int y = 0; y < 20 ; y++ ){ 
        for( int x = 0 ; x < 80 ; x++ ){
	
            if( distance(x,y,40,10) < 6 ){ // if this pixel is inside the hole
                cout << ' '; // render only spaces.
            }else if(y%2==0){ // otherwise do the usual wave thing.
                if(x%2==0){
                    cout << ')';
                }else{
                    cout << ' ';
                }
            }else{
                if(x%2==0){
                    cout << ' ';
                }else{
                    cout << '(';
                }                
            }
        }
        cout << endl;
    }
    return 0;
}
```

The output looks like this:

```
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (         ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (             ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (             ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (             ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (             ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (         ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
```

The new if-statement measuring the distance from the circle's center allows us to render the inside of the circle with a different letter. The reason it looks tall and skinny is because in ACSII art, the characters are 2x taller, and we have not accounted for that in the code. We can fix that by multiplying the correct things by 2 in the arguments of `distance()` call.

```cpp
            if( distance(x,y*2,40,20) < 17 ){ // Y and circle-center-Y both multiplied by 2
```

The output should be more circular, depending on the line-height of the font renderer.

```
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( (                     ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) )                           ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( (                             ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) )                               ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( (                                 ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) )                                   ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( (                                 ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) )                                   ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( (                                 ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) )                                   ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( (                                 ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) )                               ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( (                             ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) )                           ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( (                     ( ( ( ( ( ( ( ( ( ( ( ( ( ( (
) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )           ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) 
 ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (

```

## Returning Early from a Function

When I first introduced functions, we had not learned enough code statements to fill those functions with more than one line of code. Now that you've seen a bit more, I'd like to cover something I had omitted. You have seen how it is possible to `break` out of a loop. it is also possible to break out of an entire function with the special `return` statement, and this will skip the rest of the function and go directly back to the calling code.

```cpp
void doSomething(int a){
	if ( a <= 0 ) {
		return;
	} else {
		for(int i=0;i<a;i++){
			cout << '#';
		}
		cout << endl;
	}
}
```

The above function has a return type of `void` and so it is not required to return any value. You can see at the top that I am validating the value of `a` to make sure it is above zero before I render that many `#`s into the console. I call the `return` statement early, and it escapes from the function.


## Bouncing Ball

We will now combine our new knowledge of variables, conditionals, looping, and functions to render an animation of a ball bouncing. Let's start with an empty ASCII art picture and add a ball to it.

```cpp
#include <iostream>
using namespace std;

int width = 20;
int height = 6;

void drawFrame(){
	for(int y = 0 ; y < height; y++ ){
		for(int x = 0 ; x < width; x++ ){
			cout << '.'; // draw each column
		}
		cout << endl; // new row
	}
	cout << endl; // margin-bottom
}

int main(){
	drawFrame();
	return 0;
}
```
The output should look like this.

```
....................
....................
....................
....................
....................
....................
```

We have a function `drawFrame()` whose job it is to render 1 frame of animation into the console as ASCII art. Above that, we have a couple variables `width` and `height` to store the size of the canvas. Now let's add the ball. To do this, we add a couple more global variables below `width` and `height` to hold the ball's position, and then we add an if-statement to the renderer to make sure it makes a visual exception for the ball position, which is 1 character.

```cpp
#include <iostream>
using namespace std;

int width = 20;
int height = 6;
int ballX = 10;                                   // new
int ballY = 3;                                    // new

void drawFrame(){
	for(int y = 0 ; y < height; y++ ){
		for(int x = 0 ; x < width; x++ ){
			if ( x == ballX && y == ballY ) {     // new
				cout << 'O';                      // new
			} else {                              // new
				cout << '.'; // draw each column
			}
			
		}
		cout << endl; // new row
	}
	cout << endl; // margin-bottom
}

int main(){
	drawFrame();
	return 0;
}
```

The output changes to look like this.

```
....................
....................
....................
..........O.........
....................
....................
```

Let's make the ball move left and right by adding a `force` global variable just for the x value of the ball, then start adding the force to the ball's position, rendering frame after frame.

```cpp
#include <iostream>
using namespace std;

int width = 20;
int height = 6;
int ballX = 10;
int ballY = 3;
int forceX = 1;                   // new

void updatePhysics(){             // new
	ballX += forceX;              // new
}                                 // new

void drawFrame(){
	for(int y = 0 ; y < height; y++ ){
		for(int x = 0 ; x < width; x++ ){
			if ( x == ballX && y == ballY ) {
				cout << 'O'; // draw the ball
			} else {
				cout << '.'; // draw each column
			}
			
		}
		cout << endl; // new row
	}
	cout << endl; // margin-bottom
}

int main(){
	while(true){                   // new
		updatePhysics();           // new
		drawFrame();
	}                              // new
	return 0;
}
```
The output should start with this.

```
....................
....................
....................
...........O........
....................
....................

....................
....................
....................
............O.......
....................
....................

....................
....................
....................
.............O......
....................
....................

....................
....................
....................
..............O.....
....................
....................

....................
....................
....................
...............O....
....................
....................

....................
....................
....................
................O...
....................
....................

....................
....................
....................
.................O..
....................
....................

....................
....................
....................
..................O.
....................
....................

....................
....................
....................
...................O
....................
....................

....................
....................
....................
....................
....................
....................

....................
....................
....................
....................
....................
....................
```

As you can see, the ball's position keeps getting 1 added to it, and eventually it falls off the canvas. To make it bounce off the walls, we must add conditions into `updatePhysics()` that detect the ball collision with the wall, and change the direction of its force.

```cpp
void updatePhysics(){
	if( (ballX+1) ==width || ballX==0){   // new
		forceX = -forceX;           // new
	}                               // new
	ballX += forceX;
}
```

The output will show the ball properly bouncing off the left and right walls.

```
....................
....................
....................
...........O........
....................
....................

....................
....................
....................
............O.......
....................
....................

....................
....................
....................
.............O......
....................
....................

....................
....................
....................
..............O.....
....................
....................

....................
....................
....................
...............O....
....................
....................

....................
....................
....................
................O...
....................
....................

....................
....................
....................
.................O..
....................
....................

....................
....................
....................
..................O.
....................
....................

....................
....................
....................
...................O
....................
....................

....................
....................
....................
..................O.
....................
....................

....................
....................
....................
.................O..
....................
....................

....................
....................
....................
................O...
....................
....................

....................
....................
....................
...............O....
....................
....................

....................
....................
....................
..............O.....
....................
....................

....................
....................
....................
.............O......
....................
....................

....................
....................
....................
............O.......
....................
....................

....................
....................
....................
...........O........
....................
....................

....................
....................
....................
..........O.........
....................
....................

....................
....................
....................
.........O..........
....................
....................

....................
....................
....................
........O...........
....................
....................

....................
....................
....................
.......O............
....................
....................

....................
....................
....................
......O.............
....................
....................

....................
....................
....................
.....O..............
....................
....................

....................
....................
....................
....O...............
....................
....................

....................
....................
....................
...O................
....................
....................

....................
....................
....................
..O.................
....................
....................

....................
....................
....................
.O..................
....................
....................

....................
....................
....................
O...................
....................
....................

....................
....................
....................
.O..................
....................
....................

....................
....................
....................
..O.................
....................
....................

....................
....................
....................
...O................
....................
....................

....................
....................
....................
....O...............
....................
....................

....................
....................
....................
.....O..............
....................
....................

....................
....................
....................
......O.............
....................
....................

....................
....................
....................
.......O............
....................
....................
```

To make the ball move up and down in addition to left and right, we simply add a `forceY` and repeat the working algorithm over from the X behavior.

```cpp
int forceX = 1;
int forceY = 1;                           // new

void updatePhysics(){
	if( (ballX+1)==width || ballX==0){
		forceX = -forceX;
	}
	
	if( (ballY+1)==height || ballY==0){   // new
		forceY = -forceY;                 // new
	}                                     // new
	
	ballX += forceX;
	ballY += forceY;                      // new
}

```

The output will show the ball bouncing diagonally.

```
....................
....................
....................
....................
...........O........
....................

....................
....................
....................
....................
....................
............O.......

....................
....................
....................
....................
.............O......
....................

....................
....................
....................
..............O.....
....................
....................

....................
....................
...............O....
....................
....................
....................

....................
................O...
....................
....................
....................
....................

.................O..
....................
....................
....................
....................
....................

....................
..................O.
....................
....................
....................
....................

....................
....................
...................O
....................
....................
....................

....................
....................
....................
..................O.
....................
....................

....................
....................
....................
....................
.................O..
....................

....................
....................
....................
....................
....................
................O...

....................
....................
....................
....................
...............O....
....................

....................
....................
....................
..............O.....
....................
....................

....................
....................
.............O......
....................
....................
....................

....................
............O.......
....................
....................
....................
....................

...........O........
....................
....................
....................
....................
....................

....................
..........O.........
....................
....................
....................
....................

....................
....................
.........O..........
....................
....................
....................

....................
....................
....................
........O...........
....................
....................

....................
....................
....................
....................
.......O............
....................

....................
....................
....................
....................
....................
......O.............

....................
....................
....................
....................
.....O..............
....................

....................
....................
....................
....O...............
....................
....................

....................
....................
...O................
....................
....................
....................

....................
..O.................
....................
....................
....................
....................

.O..................
....................
....................
....................
....................
....................

....................
O...................
....................
....................
....................
....................

....................
....................
.O..................
....................
....................
....................

....................
....................
....................
..O.................
....................
....................

....................
....................
....................
....................
...O................
....................

....................
....................
....................
....................
....................
....O...............
```

If you were able to follow along this far, then give yourself another hug because you just wrote a basic physics simulator and rendered it to the console frame by frame.

## Next Steps

What you know so far is powerful enough to write a bouncing ball, but we still have more to go. What if we want the ball to travel slower than 1 pixel per frame? We would need to use fractions somehow. What if we want the ball to leave trails? We would need some way of remembering the pixel values. These skills and more are coming up before the end of the chapter. The previous bouncing ball excercise was a way for you to test yourself and see if you understand each part of the language. It was also a way for you to put all those pieces together and see how they work as one. If you found it intimidating or confusing, please go back and try to review the parts of this chapter that cover those topics you are fuzzy about before continuing. On the other hand, if you feel like you have got this and want to practice, then here are some bonus excercises to help you develop your C++ skills.

+ Expand the canvas and render the ball like the below example, adjusting the scene so no part of the ball falls out of frame.
```
.......
..._...
../ \..
..\_/..
.......
```

+ Change the diagonal pattern of the ball so it is not always travelling in 45 degree angles.
+ Try adding a second ball to the scene and render it differently than the first.
+ If the two balls ever collide, print "YOU WIN" and stop the program.
+ Try rendering the balls as larger circles using the `distance()` function from a previous example.


## Variables (part 2)

### Variables have a scope.

You may have noticed something different in the bouncing ball example. There were variables declared outside of the functions. In previous examples, I had declared variables inside the functions. Other variables were declared inside the parentheses of functions as arguments, and inside the for-loop as an iterator. These variables are declared in different *scopes* of the code. We talk about scope by saying a variable is *local* (existing only inside my immediate curly braces) or *global* (existing for the entire program). Intuitively, we can think about global and local variables in the geographic sense of the words "local" and "global." Let us apply this idea to musical trends.

Something that is local (a local concert by a local band) will happen in a smaller, lesser known location - and will happen by a lesser known (but just as important!) local band. A world traveller may come to see the show but since she goes to so many shows in so many locations, she forgets about our local band. Because she forgets about the local band, it gives the band an opportunity to change their name from "From First to Last" to "Skrillex", and adopt a fresher musical genre. When our world traveller returns to the same city to see the same local band, it has benefited from a fresh new start. This fresh new start is why we use local variables. Their ability to reset (their values forgotten quickly) is incredibly useful to us. Global variables, on the other hand, are classical musicians like Ludwig van Beethoven or Wolfgang Amadeus Mozart, whose names ring far and wide about the Earth (and possibly beyond), never to be forgotten. Their music was appreciated long ago and will continue to be appreciated, in many countries. Their musician names are known globally, and persist (stay the same) globally. This absolute stability of a global variable is what makes them so useful, in contrast to a more local variable. We need both global and local variables to make the whole system work, just like we need both global and local musicians for the health of music!

![Figure 26. Global versus Local, with apologies to Sonny Moore ](images/global-local.png "Figure 26. Global versus Local with apologies to Sonny Moore")

### Apologies

I know it is hip to hate on Skrillex, so remember that his career has just begun. He has gone from local to global in a small amount of time, which is impressive. I am sure he will transform into an even more globally recognized musician than he already is, and then we will all stop hating on him. On the other hand, people have been hating on Mozart's appearance and character for 256 years (a more globally persisting rejection).

Like making music, someone will always tell you you're not a real coder. Do not let that stop you. Having read the book "Coders at Work" in which Peter Seibel interviews the top programmers and computer scientists, I was pleasantly surprised to learn that people came from a diversity of backgrounds, and some saw themselves as architects or writers. Being a good programmer is different from being a good computer scientist or mathematician!

Variables at a more local scope are incredibly impactful and important because they deal with that which is closest to us, a bit like being closer to ones nerves. If we did everything using global variables all the time, we would have collisions - and perhaps remember too much garbage. Code and computer memory would grow tangled like the ratty hair of electronic musician. The idea of a local variable is newer, and was introduced for organization reasons. Programmers have made good efforts to avoid tangled, confusing code - and one way to do it is through keeping variables local.

When dealing with nested clauses in code, global and local are less black and white since the *scope* is more than 2 matryoshka dolls deep. A variable declared at various locations within the curly brace garden can be viewed as "slightly more global" or "much more local", as in figure 27.

![Figure 27. Locality](images/global-local-circles.png "Figure 27. Locality")

Let us see how this looks in code.

```cpp
#include <iostream>
using namespace std;

int myGlobal;

void addOne(){
	myGlobal += 1;
}

int main() {
	for(int i=0;i<4;i++){
		cout << myGlobal << ' ';
		addOne();
	}
	cout << endl;
	
	return 0;
}
```

The output is `0 1 2 3`. Notice `addOne()` and `main()` are *sharing* the global variable. Its value remains the same between them. Unfortunately, `myGlobal` is forgotten when the program is finished running, which makes it *local* within the scope of this program. To make its value even more persistent, we need to write it to a file, database, or share it over the network. That level of global-ness is one you will see explained in later chapters by other authors. Now let's deliberately cause an error.

```cpp
#include <iostream>
using namespace std;

void addOne(){
	cout << i;
}

int main() {
	for(int i=0;i<4;i++){
		addOne();
	}
	cout << endl;
	return 0;
}
```

The output is a compiler error.

```
prog.cpp: In function ‘void addOne()’:
prog.cpp:5:10: error: ‘i’ was not declared in this scope
  cout << i;
          ^
```

The compiler has a problem understanding what you mean by `i` within the scope of `addOne()` because `i` is not a global variable (it only exists inside the for-loop of `main()`) and because no local variable `i` has been declared for the personal use of `addOne()`. If we wanted to access the value of `i` from within `addOne()`, the best thing to do would probably be to pass `i`'s value as an argument in the `addOne()` function.

```cpp
#include <iostream>
using namespace std;

void addOne(int i){
	i *= 2;
	cout << i;
}

int main() {
	for(int i=0;i<5;i++){
		addOne(i);
	}
	cout << endl;
	return 0;
}
```

The output of this code is `02468`, not `026` as if `int i` were shared between the two functions. You see I added a parameter to `addOne()` called `int i`. Notice I manipulate the value of `i` while inside `addOne()` by multiplying it by 2 before printing it out. Each time `addOne()` is called, the value of `i` passed to it is copied over from the `int i` in the for-loop of `main()`, as if it forgot that it was multiplied by 2 in `addOne()`. That is because there are 2 separate *local* versions of `int i`. See figure 28.

![Figure 28. Two separate local variables named i](images/both-named-i.png "Figure 28. Two separate local variables named i")


When I call `addOne()`, I am only passing the *value* of the first `i` so that it gets stored in the more temporary `int i` argument of `addOne()`. Figure 29 shows the lifespan of a function's argument, which is a certain type of local variable.

![Figure 29. Lifespan of a local](images/local-born-die.png "Figure 29. Lifespan of a local")

Just the same, if I were to declare any variables inside the scope of that function, those variables will also be forgotten when the function returns. They only exist inside that scope. In addition to *passing by value*, there is also such thing as *passing by reference* in which you are not only sharing the value of the variable, you are also sharing the actual place in computer memory - as if the variable were made global. memory pointers are an advanced topic better covered later, but the syntax looks like `void addOne(int& i){` with an ampersand specified before the variable name. if you made this slight modification to the above code example, you will see the output becomes `026`. 


### Fundamental Types

Variables have different *types*, meaning they hold different kinds of information in them. Some take up more memory than others. Returning to the Minecraft metaphor, we can think about putting more than just water in more than just iron buckets.

![Figure 30. Minecraft Vessles](images/minecraft-vessles.png "Figure 30. Minecraft Vessles")

In Minecraft, Buckets will hold milk and lava in addition to water. Furthermore, there are a few other kinds of containers meant for other liquids and other stuff. Requiring the correct container for the correctly according data makes C a *strictly typed* (or *strongly typed*) language because it is strict about which type of variable you use. Strictly typed variables are arguably a big virtue for a programming language, and are kept in as a matter of choice since they reduce errors, and greatly speed the app's performance. The issue of whether or not to use a strict or loosely typed language for a project is a very important decision to make, but whether or not one should devote ones career exclusively to strict or loose typing is an unhealthy sort of xenophobia. Both walks of life have their pros and cons.

In the beginning of this chapter, we declared strings and since then, we've declared mostly integers with the keyword `int` just because they were a convenient general purpose data type for immediate gratification, but as I hinted during the bouncing ball exercise, an `int` has its limitations. Let me introduce a couple new types.

```
float myNumber = 340.1928; 
char myLetter = 'E';
```

Unlike an `int`, a `float` allows decimal points, and so you can work at a higher resolution. A `char` holds a single ASCII character. It only needs to take up 8-bits of memory whilst the `float` and `int` take up more (therefore allowing them to express a wider range of values). I will touch briefly on the bits and bytes of memory when we get into bitwise operators, and then Arturo will give you much more in Chapter 16. Let's see the `float` in action!

#### Float

```cpp
#include <iostream>
using namespace std;

int main() {
	float myNumber = 0.0;
	for(int i=0;i<100;i++){
		myNumber += 0.012;
		cout << myNumber << endl;
	}
	return 0;
}
```

The output is a stream of numbers that increment by 0.12.

```
0.012
0.024
0.036
0.048
0.06
0.072
0.084
0.096
0.108
0.12
0.132
0.144
0.156
0.168
0.18
0.192
0.204
0.216
0.228
0.24
0.252
0.264
0.276
0.288
0.3
0.312
0.324
0.336
0.348
0.36
0.372
0.384
0.396
0.408
0.42
0.432
0.444
0.456
0.468
0.48
0.492
0.504
0.516
0.528
0.54
0.552
0.564
0.576
0.588
0.6
0.612
0.624
0.636
0.648
0.66
0.672
0.684
0.696
0.708
0.72
0.732
0.744
0.756
0.768
0.78
0.792
0.804
0.816
0.828
0.840001
0.852001
0.864001
0.876001
0.888001
0.900001
0.912001
0.924001
0.936001
0.948001
0.960001
0.972001
0.984001
0.996001
1.008
1.02
1.032
1.044
1.056
1.068
```

Floating point values are useful because they allow us get in-between the piano keys of an integer, and that is why I call them the violin of variables. But notice in this list of fractionally incrementing values that a phantom 0.000001 is added for a little while, beginning around 0.840001. Sometimes you will see these minuscule errors when working with floating point numbers. This strange phenomenon is called a *floating point error* and is a fundamental problem with floating point technology at large, sometimes bringing a headache to a designer trying to render the number in a sane looking way. For the purposes of this chapter, I will not point out floating point errors when they arise, but please be comforted in knowing this is a hot topic in computer science, and there are certainly ways of remedying it, later.

Look what happens when we go back to that code example and change the type from `float` to `int`.

```cpp
#include <iostream>
using namespace std;

int main() {
	int myNumber = 0.0;      // changed from float to int!
	for(int i=0;i<100;i++){
		myNumber += 0.012;
		cout << myNumber << endl;
	}
	return 0;
}
```

The output becomes a long, serene list of zeros since the `int` data type cannot handle a tiny fraction like 0.012. So during the moment it tries to add 0.012 to myNumber (which is an int), 0.012 gets everything to the right side of the decimal point trimmed off, and that becomes zero every time. Now let's try the opposite example, storing ints into a float.

```cpp
#include <iostream>
using namespace std;

int main() {
	float myNumber = 0.0;
	for(int i=0;i<100;i++){
		myNumber += 1;
		cout << myNumber << endl;
	}
	return 0;
}
```
The variable type was changed back to `float` and within the for-loop, i am now adding an integer `1`. It turns out there is no loss in precision since a float is more than enough to store the first 100 integers. So far so good. Now here's a gotcha!

```cpp
#include <iostream>
using namespace std;

int main() {
	float myNumber = 22 / 7;
	cout << myNumber << endl;
	return 0;
}
```

The output is simply `3`, not 3.14286. For the beginner in variable types, this can be somewhat confusing. On the one hand, I have declared the variable as a `float` so it *must* be able to handle decimal points. The answer lies in the syntax used for integers 22 and 7. Like variables, literal numbers (values typed out with numeric digits right into the code) in C have a type, inferred by the compiler based on *how you formatted the number*. In this case, 22 and 7 are both literal integers since they are nothing but number. Let's try changing them to be literal *floats* by suffixing them with `.0`.

```cpp
	float myNumber = 22.0 / 7.0;
```

The output should now be `3.14286` since the expression is now floating point division, rather than integer division, which chops off the fraction. To shed a bit more light about this important difference between integers and floats, let's remove the `.0` from just the 7 and see what happens.

```cpp
	float myNumber = 22.0 / 7;
```

The output is still `3.14286`, since the division operator needs to have only one of its participating numbers be a float in order to act with more precision. Therefore, it should not matter which side of the division operator has the floating point type . . .


```cpp
	float myNumber = 22 / 7.0;
```

The output remains `3.14286`.

##### What's in a name?

I grew up in Southern California. When someone says the word "float" I am reminded of the Pasadena Tournament of Roses, a new years parade with flower-covered **floats** - decorated platforms on wheels. That's why I can understand if it's difficult at first to remember that a float is the variable type that allows decimal points. Often times, when I am having trouble associating a name like this in my mind, it helps me to look deeper into the reasoning behind the nomenclature. The reason these are called *floats* has historical significance. *Floating point precision* means the decimal place can shift left and right (because powers of 10 are useful), in contrast to *fixed point precision* like `double`, a type we will learn later on. If that still doesn't make sense, just do like a scripting language and use floats for everything. *When in doubt, use the type with a higher precision.*


#### Char

`Char` is another type that stores a single character, whose value is traditionally 0-255, a range that fits inside 8-bits (1 byte). Often times, a char is referred to as a byte for this 8-bit reason. You may know the term `8-bit` if you are a fan of chiptune music or had a Nintendo Entertainment System (NES). A single byte is a pretty classic unit of memory, and as such - incredibly useful for dealing with data. You'll learn more about bits and bytes in chapter 16, in which Arturo will be covering the subject in greater detail. For now, let's start playing with the `char` type and begin to understand its basic uses.

```cpp
#include <iostream>
using namespace std;

int main() {
	char myLetter = 'A';
	myLetter += 1;
	cout << myLetter << endl;
	return 0;
}
```

This program outputs `B`. You've already seen strings surrounded by double quotes. A literal char is surrounded by single-quotes. This strictness can be difficult getting used to if you bring habits from scripting languages that use double and single quotes interchangeably. In C, a char is always surrounded by single quotes. When I add 1 to `myLetter`, it increments from A to B. On the next line, `cout` knows just what to do with the char, and prints it as a letter.

#### Casting

Okay, what if we want to see the numeric representation of our char, instead of the letter? *Explicit type conversion* (or casting) allows you to force the surrounding expression to treat a variable with one type as if it had another type. We do this by placing the desired type in parentheses and attach it to the left of the variable. In the following example, I loop from 'A' (65) to 'z' (122), and print out all the letters with their according numbers.

```cpp
#include <iostream>
using namespace std;

int main() {
	for(char i = 'A' ; i <= 'z' ; i++){
		cout << i << ' ' << (int)i << endl;
	}
	return 0;
}
```

Here is the output:

```
A 65
B 66
C 67
D 68
E 69
F 70
G 71
H 72
I 73
J 74
K 75
L 76
M 77
N 78
O 79
P 80
Q 81
R 82
S 83
T 84
U 85
V 86
W 87
X 88
Y 89
Z 90
[ 91
\ 92
] 93
^ 94
_ 95
` 96
a 97
b 98
c 99
d 100
e 101
f 102
g 103
h 104
i 105
j 106
k 107
l 108
m 109
n 110
o 111
p 112
q 113
r 114
s 115
t 116
u 117
v 118
w 119
x 120
y 121
z 122
```

Naturally, you can cast between any of the fundamental types. The computer will increase and decrease precision as needed. Here's an example where I cast from char to float, then to int, then to char again. Try to guess what the output will be.

```cpp
#include <iostream>
using namespace std;

int main() {
	int a = (float)'D' + 0.7;
	cout << (char)a << endl;
	return 0;
}
```

The output is 'D'.

Perhaps you guessed that the answer would be 'E' since I had added 0.7 before storing into `int a`. You were correct to assume that the computer is converting from float to int, but incorrect to say that 68.7 is "rounded" to 69, therefore producing the letter E. Instead, conversion from float to int is more technically a `floor()` function, meaning it just chops off the fraction and replaces it with a zero. So even (int)2.99999999999 will still come out as 2. If you need to actually round the number, bringing 0.5 and higher to the ceiling, then use `round()`

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float theNum = 3.449;
	int f = floor(theNum);
	int c = ceil(theNum);
	int r = round(theNum);
	cout << f << ' ' << c << ' ' << r << endl;
	return 0;
}
```

The output is `3 4 3`, and notice that I have included `<math.h>` so I can use floor(), ceil(), and round().

### Randomness

I admit that last topic about variable types was a bit numeric, but it was important so if you feel fuzzy about any of it, please go back and re-read. For now, let's have fun with what we just learned. `math.h` comes with all kinds of useful tools for art. One of them generates a fake data stream of evenly distributed values. Programmers call it *random* and ironically, it's anything but random. To see what I mean, run the following program three times, each time noting the output.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int i=0;i<3;i++){
		cout << rand() << endl;
	}
	return 0;
}
```

Every time you run the program, you get the same output.

```
1804289383
846930886
1681692777
```

This tells us that the sequence starts over again. There are things you can do about that and it will be covered in a later chapter. Since these are pretty big numbers, let's normalize them by dividing by `RAND_MAX`, a constant provided by math.h which is the highest possible value that the random function is willing to return.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int i=0;i<10;i++){
		float r = rand() / (float)RAND_MAX;
		cout << r << endl;
	}
	return 0;
}

```

Notice in the output, all numbers are somewhere between 0 and 1.

```
0.840188
0.394383
0.783099
0.79844
0.911647
0.197551
0.335223
0.76823
0.277775
0.55397
```

Let's use this normalized random in an ascii art generator. By multiplying a normalized random output by 52, we get random values between 0 and 52. 

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int i=0;i<30;i++){
		float r = rand() / (float)RAND_MAX; //normalize random
		cout << '8';                        //snake tail
		for(int j = 0; j < r * 52;j++){     //from 0 to no more than 52...
			cout << '=';                    //print snake body
		}
		cout << "O~" << endl;               // print snake head
	}
	return 0;
}
```

In this output, each rattle snake has a different length.

```
8============================================O~
8=====================O~
8=========================================O~
8==========================================O~
8================================================O~
8===========O~
8==================O~
8========================================O~
8===============O~
8=============================O~
8=========================O~
8=================================O~
8===================O~
8===========================O~
8==================================================O~
8================================================O~
8==================================O~
8======================================O~
8========O~
8================================O~
8=O~
8=============O~
8========O~
8==========================================O~
8=========O~
8=====================O~
8=======O~
8======O~
8====================================================O~
8============O~
```

Artists like the random function because it creates a lot of organic aesthetic with very little typing. The experienced eye can spot the random function even several perlin octaves deep, in the same way you can look at an advertisement in the mall and call it out like "that was so photoshopped". Using the random function is like leaving the "Lorem Ipsum" in. Perhaps I can express my sentiment with more concreteness. If you find it sexy to create visual pieces that have *fake nature*, just imagine the impact you could have if you used *not-fake* nature. By that I mean replacing the random function with real world data. For example, you could set up an arduino or raspberry pi with a photocell (light sensor) to measure the way the cars passing by your apartment window temporarily block a nearby streetlight, and use that as an input to drive your software art. Also try working with big data from the past. Creating generative art, data visualizations, and working with physical computing will be covered in later chapters. But don't say I didn't warn you about the politics.

In the following example, I am using the same random scaled to 52, casting it to `char`, and outputting a pseudo-chaotic wall of letters. 

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int i=0;i<40;i++){                      // 40 rows
		for(int j=0;j<100;j++){                 // 100 columns
			float r = rand() / (float)RAND_MAX; // normalized random
			r *= 52;                            // scale to 52
			r = 'A' + r;                        // offset by 'A' ascii value
			cout << (char)r;                    //output without a newline
		}
		cout << endl;                           //finally add the newline
	}
	return 0;
}
```

The output should look like this:

```
AGhX\LCddqT\lBC\cATDVd_qm\EcVephNCgRahtSMtfhbDaoOWhYMOSIZopDp[[QtZNErD[TOp\YqChilGAdnagftoMPS[_lVlOV
\YOJH^jB\Zrg]oalILfGEOAVBeqMJQobHdUUZH_l_r]HtVH^NZYrGKQaGbajMYUKBoWHrVGoEIDSNHiXSXkqbLdpNmY[`khYraWk
detrmP\[FV^nWfnfjegAo\YDfZcdKpno]HXtLXQ[nWYjSKtHaaAAifQVddKlelEEhaLLEUrrUNdOiiVOKAJtMkHU`JlItNMFLbej
ehcaC`LQeGh\]_ReHIZmk]gQH\Q_[WNTUXYUOETNcd[ffrXqQX[cU`tHcR]\lAOb]pNsMleXkBIeeW_hteOhIAZEIoigWA_[D]UL
Uace]OkTdQAF\iLCDIfPCYX\XHOle_dRCt]AmBTZ^gd\BGsJS``G]rSlsNNWkoMheXNcGKF]AJ`WEdTlGsBEZiqNShZgcdhBLL^b
aTLMbIgICcGrZapA_fZCW[iDXsYRXgKITqsNDG\I[FlTWRf^nhleUq`S]XUMEVYPFLj\cmMfNTEXMjZANcWJsGjrI`DSP[klfRja
CCHhD\qLKEeeZNfTKMWYmsXB\Bh_kRM\WUtsmnQHtbYqdk]^IrkICRFF[B^m[dgeBJcRDHpLT_IBdhfE_qqW[lp`f\ZIs^O\ecF]
`cZ^_WH[gBC\QBMFT]``qi[ZbeVZYe\O`Oe\qMV`ipdk\LHoNbAqOmOr[GVeWFhFWRPhRRC^ZKFsmZTjIIDHYTnWVbQDkopoiI^B
j\mOn_Uk\qV_gnRJgfnDenSEIVFd^knibonZFTTdGDHYeMUsadpSmjWDZZXZgqPHFEsVMslKGKR^W_WTT`WHcteUmkjTAYbbbjTS
UReHPcmQH`ApT[RNPlGbCXTIhcAj^PVQ[flMYTCDK^lVlPJSq_TYarVCX_gmGFcl_ctApKs\Of_llcfbS\cQnXpOrGVlsR\\kqcM
q`GMoKIl`alcUncGAdaX^BSmTc^DgOXJEot_BdZ^oWdKZOrMrYGrmLAiCrb^HGk[c[\GocOUUlMGfbKmBFJSifc_SIPILcVo_RWe
ljmONI\DthGIWiLWBqFNZjNLOTKqha^SpKFjeAgFocRTLRApiUflnGRqSSE^ilZkbWSSOpagIiN`mQ`GTGNGKhDXsMKdEmHGkrCD
lHjLU`cCtkVBFsnclMf_LLAXVqB[Tmj`RacbNBtKb^TGXH_]ZoESFPlplskjlXbekYKUqYT[LotHXdOVgBPKkOfVif_ajAaSYZ\Q
mHUUmCXhPsutgSjK`]NK^[g`tj]HF\M^RdDlnRHgcU_]Z`q`NCaRBI`W^fTTTE_VFQd^n\sDYFt]eGYDXpWmt]GmJccsXIHOs`mD
qrYOXWnKUhkcfdQIdpIAJJKcd[QYQEnXHbqncKIAIFS^sMBBoop]IZkq_]YhRI[TlsAPXolNglVeV\\EUiNQJhabRIJX\IqVBI^t
HRQSIQTb`BRE]ZONWcQAsFQrSItGCriLFNWMO]nmc]homhMtNTPgthWbYFJm[qoPas]lCJshnB[TsKL`o]EiieCnDtOZdgrdpIkO
ZpeUIoK]TNjMcR\X`cBkT]sgjhXVMeLcVORPdrioBsCVIjA`pF]D]TZUV^qe_AOUg^]NGISkNJVb\DYTFZGLWStoSWjtP^]H[ZfE
LIUTNImMojsNO]f[ZSmVBpr^tU_jVC]G^sdK^lPPst_R\Ekd_KKIOKjnjEIMh[UnR`itrkidlahU_VjYdk]P_YoWNYAcE^dcgbtO
iAEDqLiNOgPYppoNhdYYK[olrspHNUiiiXVbbglOiJGitEWlarWrjTMlCLEmCrkn[htVLUFSFKUkoskVkfXV_`ctgAaGodRMXdNH
e`dDnKLgirfgKLBlhLVOdlCaaXFfAV\FbWBMRaT]hEhCJYlRTmiOkeonVJ]\SfsMHMjkUn`ChZsSfInQdHOpB_rl^KB_bIDP^TKB
hDOiTPSsaeSI[^edjXgIRAWjq^^^tfF[XY]_Hf\R_Bph[VYIeBeINrgkPRclWWWDTb[Kgd[T[GVkB]Gga][e[fserTaJZPdemZjJ
XMB\nRXdJ`SkWClHqmkBsOgFliAj`A]aBQ_QbkggdGhQAF^nLaMnET_jUbjDt_sRmNYInfCDjJCMdKbROQBsLcLqDiPbTJgN\BOZ
qs_oRnAJQL[kL]JJboZOHSJeECSMP^TSnPpQgcjq[jkP_QFDdKW[Q]t`At\baJOIXqHUnKhjnkR^`EjFVgQc[[oJXNVXrrZJd[p`
UgsRTslFGFijiTSHMFBGefE_q__t^DOTNMktOGCb_c\SpnEImZrE`GWGUGcVdNY^iJMIa`ZFBRipVqNMVjH__kd[kc]ThKG^^e`N
iGTCGCIjROlLG[NPOF[HskpdQLcIKeFEBGJMmmPTYKcdChLAnMfJDnbC^qqoSQ]JsIftIbcqDiJXZGZRTTafqiAn[VUc\aTYqihN
iEc^pPDHYfAhaD`dZth_iBPYsVILTl_J_kCYiUWQPpP[aHNqt[oZAOtoBCDoI\qPPTErXcX_r[[Td]VCjFr_dbFkDa\ITgbcFg`q
LD_SsJkNp^CYteGkZAKDVAFsW`pQBj`LVNYKTbt_MWdLOrBSYGdLOH^dffiNUtIKGIlDOa_SrSZHO\_mPrAmLpNrMoGT[AVRO_kq
qnFp[mGHbHeannN`B\rTq]sPf_XJIi]]RBYhsZliHBTmSfbRRMHkSFpK\M[KJD[t[\SSQO`XtZnqkXCOeHrn`qkprBTIOOO]MAHB
F`KHI`]T_XdfPHoFas`GaGqoB`dC`MjIPDIZkdZH\pWLYMkLPbKLQETAnmKdZN\rFO^KFom`AlLBmobbAnMEMmX[_ZhANIn]ks[d
adBOJVtMHVJFRWdXQaUhYVb^DWY`aYsMH[WstWkc\KPiqKBHPgRZthXBccIFMi\X\Ib_Hlp`eKDZTelVNoMJhqk^]ZC\i_pIBf[V
DADDFsTMASVkqQ]Rob\TLHpCL`L^JVJaieCM]lYbsfpR^ss_bBZ]gPUZWPqAQhtWEAnXYWRcB]QViZ]P]mTRHntFOA_naEjpshKm
ItcSiM]]QE]KUqGZFS^hTdFXq]qfceBiNmGjGXh[A[`AOWJqqiWZDEarBeW[UENTMTnJZEDrNUK`tK^XITAhRFYdsLbJpkmMA^XN
[XoCTp\aBsDS]mXrXmAnmAFSAacgbN`ZCHhZoPnsF^HfXingeVkkl\U_WggOrgdWVlBFodVOnMecVA`ZQG[VWZjRmCAU]`kWSWjF
ZYY^AERTMbrKWD`_nojkCjEHVLEQi`Ms]o^hbLLVZFgWqiGilCrkJ^GD]NH_sbEpHhn[VrHijrH]NpiVEXWgbjcaP]tdMgA`TkJK
co`PfQiYGHKkmOindjgMi^iptspkemVpBaZlN^[iA\OakDkV]c[Sr[QaqrYW\CGfOGhimXdKRX^jpI^tEUbRWKVkbWCOLSP[JRMl
j\XUtEIFJNo^hoOoIMgkklGWqghLR__nKd_XtJe^jWOYXWjRIpcGiHRr]THpTfI]tnsKInULkpE]NOojOPCLUqiBL\R`dYY^Ki`X
p^NPhDj\Ilj]jNnnPlX`onn[pOiihJsSNehtl`]G[UULRttHXk^mrpOQtAEJpBmcfeBtXPEmEEoYPsEZRcfUJraDsH\iK\qMkDE[
^C[XXJE`_\TcT\De[nop[RFpC]OtKhtP`mMLhqErpIXbMXlf[NMYdltrV_Y_cFadPgemQgOOcSaBGZbQPTH^ikaVgNYc[DmYQm]S
LVt_anFDeHVjjJR`nF^C\oge[ElhXr[TGVoWrCNXGFZiJik\MbK^RAg`[pfmaYGfAAJF\LREqCZJZS_RZIPsBYmL\QmhShd]^UQt
WM\^fNOaJYrJpkpe`_PH^UMrmPbShtk`tiKdlhZMir`HD[\rE`qCLkLfUZsT[NVmGIlf[toeRtJOoNooJFJTUlAg^soeT`MqhOhF
```

To make it more interesting, I will inform the palette of characters with column index, and I will randomize a "masking" part of the code which inserts a space according to a custom conditional.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int i=0;i<40;i++){                        // 40 rows
		for(int j=0;j<80;j++){                    // 100 columns
			float r1 = rand() / (float)RAND_MAX;  // normalized random
			float r2 = rand() / (float)RAND_MAX;  // normalized random
			r1 *= 3;                              // scale to 3
			r1 = 30 + r1 + j;                     // offset by 'L' ascii value
			if(r2 > (i/40.0) || -i < -j+10){    // artistically tweaked inequalities
				r1 = ' ';                             //blank it out
			}
			cout << (char)r1;                     //output without a newline
		}
		cout << endl;                             //finally add the newline
	}
	return 0;
}
```

In the line marked "artistically tweaked inequalities", my process was simply changing one thing about the expression, hitting compile, and seeing how I feel. I sat with the code until I reached a sweet spot. Here is the output.

```
              =               K              Z                   
                 >   C                    XZ                     
                                  P          Z          fg       
                   B B                        ]             i   n
                 >                                    c       l  
               =  @                P  T   W  Z            h      
              <==     C EH  J L            X  \]              m  
                   @ B   G    MM PP      W  [   _   a cd   h    m
             :     AB   EH IK M            Y     ^ b d         n 
               =   @ B E  G     N QP RU          _` c    g iij nm
                  A     GH J     N       V       `` a c gh   j nn
             < >   A C  EH    L   QP         [  ^`a     f h  k   
               >?>      G  JJ KNMP P     WYY    ]^  a d  fh  lm  
                ? A@  DDE    K L N    S WWXY \ ^] ``  c      l  n
               =>@     EFG        QR TS  W   \  ] `   d  g   j l 
             ;;=  A BCD   I IKML  Q QRU VXX       _ab     gi    o
              ;>   BBB DE G J  LO PQ  UUWV  Z \]_ _`b  e fh   k  
             < = @?   D E HI   N  Q Q     Y ZZ[ ^^ bb ddg  h  k  
                >@ @B  D  G      N  RR   V   [[\__ ` ddd g jj m n
                ? ? BD EFFHIKLK OOQQ RS WW    []]    cceg  j  km 
                           JK LN  PQ R VWW Z Z\] __`ab  fhgh   l 
                  A@ D  F GJK  N    ST VW   Z[\ _   adcf   i jm m
                   AA    H    KMNNPPQ TV WY ZZ  ]` b dd  g  jjmnm
                   @C  EEG JJ     P RR  W  Y[[ \    ad de      no
                       FG HIKJ  NO  QRU UX X  [  _a`bcdfff  jlk n
                     D  EHG JK  MO PRRUVU  XYZ ^ ` acdcee   klkm 
                      CEE G J L ONOQ RTV V   \ ]^ `aacc fhhjk lno
                        EGHH K LN  QRRS UWWX  \\]_  ccedffhh l no
                           JKKMNMOPRRT U XYYY  ^ `aaa  ef ih lln 
                         GII KLLNPQP  STUVY [\]^^` aadde  hhjjmlo
                          GH  MLNPQR SU WW XY[ ]^ _`bcddfhiij mno
                           HI KLM PQS SVV W Z ]\_``bbb  gh ji ll 
                             LLLNOQPQS TUWYZZZ\\_^_b bed   ikkkmo
                              KNNPP QTUUVVX   \^___abb eeghijkmmn
                              MMOOPQS  UV WZZ  ]^_abace efghilmmn
                               MNNOPRTTVWVWZZZ]]]^`abbefe gjkl nm
                                MO RQ T UWWX[[] ]```bcddefiijk ln
                                 PPQSTSVVXYZYZ]\_^`  ddffhhjikklo
                                  PRRTTUUXYXZ\[^_`_bbbddefijillmo
```

Having already warned you of its dangers, I am also of the opinion that computer random, just like Lorem Ipsum, fake plastic trees, and the Roland 808 cowbell sound all have their place as real elements in art, particularly when the artist is making a real statement about those very tools, and their people.

### Algorithm

The classic random number generator *algorithm* is just a feedback loop wherein a variable feeds back on itself, each time having some manipulation done to it. What gets returned to us is a snapshot of that. An algorithm is just a procedure for doing something. It's a fancy term to describe a useful chunk of code. Figure 31 shows an algorithm represented as a flowchart, which is easier for a lot of people to look at than indented code syntax. Notice it has conditionals, looping, and a main entry point.

![Figure 31. Flowchart by Randall Munroe, xkcd](images/flow_charts.png "Figure 31. Flowchart by Randall Munroe, xkcd")

If you can understand `random()` at an algorithmic level, you will be able to deeply remix it. The following is my own quick random function. It takes a char (0-255) and adds a prime number to it, causing it to wrap around from 255 to 0 as we iterate. The reason the number wraps from 255 to 0 (instead of advancing to 256) is because a char cannot hold more than that amount, so it's an *overflow* behavior.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	unsigned char iterator = 0;
	for(int i=0;i<40;i++){
		iterator += 67;
		float normalized = iterator / 256.0;
		cout << normalized << endl;
	}
	return 0;
}
```

The output looks pretty organic and chaotic from here.

```
0.261719
0.523438
0.785156
0.046875
0.308594
0.570312
0.832031
0.09375
0.355469
0.617188
0.878906
0.140625
0.402344
0.664062
0.925781
0.1875
0.449219
0.710938
0.972656
0.234375
0.496094
0.757812
0.0195312
0.28125
0.542969
0.804688
0.0664062
0.328125
0.589844
0.851562
0.113281
0.375
0.636719
0.898438
0.160156
0.421875
0.683594
0.945312
0.207031
0.46875
```

Now let's visualize the same number sequence by drawing bars.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	unsigned char iterator = 0;
	for(int i=0;i<40;i++){
		iterator += 67;
		float normalized = iterator / 256.0;
		for(int j = 0 ; j < 100 * normalized ; j++){    // new
			cout << 'Z';
		}
		cout <<  endl;
	}
	return 0;
}
```

The visualization reveals a pattern that is quite different from classic random, and yet it is *algorithmically* related.

```
ZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
```

Sometimes, a surprising feedback loop might be all you need, instead of reaching for vanilla `random()` every time.

### Signed, Unsigned ###

You may have noticed the use of a special keyword in the previous example, `unsigned`. In languages like Java or Javascript, all numbers are *signed* meaning they are capable of being negative. (the *sign* tells us whether the number is negative). When working in C, we benefit from the convenience of specifying explicitly whether or not an int or char is signed or unsigned by adding the keyword before the type. `unsigned char myByte = 128;` To see the difference between signed and unsigned, let's loop through all the values of a char, printing each one.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int i=0;i<256;i++){
		unsigned char c = i;          //convert integer to char
		cout << (int)c << ' ';
	}
	return 0;
}
```

The output is a list of integers 0 through 255 as you would expect.

```
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72
73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95
96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113
114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130
131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147
148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164
165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181
182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198
199 200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215
216 217 218 219 220 221 222 223 224 225 226 227 228 229 230 231 232
233 234 235 236 237 238 239 240 241 242 243 244 245 246 247 248 249
250 251 252 253 254 255
```

Chars are signed by default. change `unsigned` to `signed`, and run it again. The output is different.

```
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72
73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95
96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113
114 115 116 117 118 119 120 121 122 123 124 125 126 127 -128 -127 -126
-125 -124 -123 -122 -121 -120 -119 -118 -117 -116 -115 -114 -113 -112
-111 -110 -109 -108 -107 -106 -105 -104 -103 -102 -101 -100 -99 -98
-97 -96 -95 -94 -93 -92 -91 -90 -89 -88 -87 -86 -85 -84 -83 -82 -81
-80 -79 -78 -77 -76 -75 -74 -73 -72 -71 -70 -69 -68 -67 -66 -65 -64
-63 -62 -61 -60 -59 -58 -57 -56 -55 -54 -53 -52 -51 -50 -49 -48 -47
-46 -45 -44 -43 -42 -41 -40 -39 -38 -37 -36 -35 -34 -33 -32 -31 -30
-29 -28 -27 -26 -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -15 -14 -13
-12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1
```

Instead of counting all the way up to 255, it looks like the sequence stops after 127, switches over to -128, then counts up from there until it reaches -1. A `signed char` can only count to 127 in exchange for the ability to do negative values.

### Bool

I previously mentioned George Boole when talking about the business of true and false. Whilst a true/false can be stored as a number (zero being false, and non-zero being true), C provides a convenient type called a `bool` whose value can only be true or false. In the following example, I declare a boolean variable and store a counting integer into it.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	bool foo;
	for(int i=0;i<10;i++){
		foo = i;
		cout << foo;
	}
	return 0;
}
```

The output is `0111111111` since `bool` only cares if the number is zero or non-zero. of course, since a bool is true or false, it goes naturally with OR (||), AND (&&), and NOT(!) as I discussed back in the *Boolean Logic* section. The following example program declares 4 booleans and uses them as bits of logic in a 4-bit counter.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

void render(bool v){
	if(v){
		cout << "democratic ";
	}else{
		cout << "republican ";
	}
}

int main() {
	
	bool bit0 = false;
	bool bit1 = false;
	bool bit2 = false;
	bool bit3 = false;
	
	for(int i=0;i<32;i++){
		
		render(bit3);
		render(bit2);
		render(bit1);
		render(bit0);
		cout << endl;
				
		bit0 = !bit0;
		if(!bit0){
			bit1 = !bit1;
			if(!bit1){
				bit2 = !bit2;
				if(!bit2){
					bit3 = !bit3;
				}
			}
		}

	}
	return 0;
}
```

The output is the 4 bits properly counting upward in binary.

```
republican republican republican republican 
republican republican republican democratic 
republican republican democratic republican 
republican republican democratic democratic 
republican democratic republican republican 
republican democratic republican democratic 
republican democratic democratic republican 
republican democratic democratic democratic 
democratic republican republican republican 
democratic republican republican democratic 
democratic republican democratic republican 
democratic republican democratic democratic 
democratic democratic republican republican 
democratic democratic republican democratic 
democratic democratic democratic republican 
democratic democratic democratic democratic 
republican republican republican republican 
republican republican republican democratic 
republican republican democratic republican 
republican republican democratic democratic 
republican democratic republican republican 
republican democratic republican democratic 
republican democratic democratic republican 
republican democratic democratic democratic 
democratic republican republican republican 
democratic republican republican democratic 
democratic republican democratic republican 
democratic republican democratic democratic 
democratic democratic republican republican 
democratic democratic republican democratic 
democratic democratic democratic republican 
democratic democratic democratic democratic
```

## Switch Case

There's a flow control structure similar to if-then that can sometimes be more convenient especially if you have a long chain of if-elseif-elseif-else. It looks at a single integer and jumps to a marker (a `case`) depending on what value the integer has.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	for(int i=0;i<200;i++){
		float rnd = rand() / (float)RAND_MAX;
		int num = round(rnd * 5);
		
		switch(num){	
		case 0:
			cout << "////";
			break;
		case 1:
			cout << "''''";
			break;
		case 2:
			cout << "||||";
			break;
		default:
			cout << "    ";
		}
		
		if(i%16==15)cout << endl;
		
	}
	return 0;
}
```

In this example, you see the keyword `switch` is followed (like an if) by `(num)` which is its criteria. Then inside its curly braces, you see instances of `case 0:` and those are the bookmarks. If num was 0 during that loop iteration, then it would jump over to that part of the case and execute the code. The output would look like:

```
////''''    ||||    ''''////            ||||        ////////    
    ////||||////||||                    ////    ||||            
''''////    ||||            ||||''''                ////        
''''||||    ||||''''''''||||''''||||        ////            ||||
    ||||''''////    ////    ||||''''        ||||    ////        
    ''''////                            ''''||||||||            
||||    ''''||||    ||||''''''''''''        ////    ||||        
                ''''''''    ''''////''''////||||////        ''''
''''||||        ''''    ||||||||||||''''                    ''''
    ||||''''    ''''||||||||    ''''''''||||    ''''            
''''||||||||''''////    ||||''''    ||||''''    ////''''////||||
''''''''    ||||||||||||            ''''        ''''    ||||    
            ||||        ||||
```

Notice there is more whitespace in the output than other ascii phrases. That is because num is being set to a random number between 0 and 5, but I only provided cases for 0, 1, and 2. At the bottom of the case, you see the final `default` catching all the rest of the unsaid cases. One tricky thing with cases is that their blocks of code require a `break` statement at the end if you want to skip all the way to the closing curly brace when finished. Otherwise, the code will actually continue running right into the next case!

```cpp
#include <iostream>
#include <math.h>
using namespace std;

float rnd(){
	return rand() / (float)RAND_MAX;
}

int main(){
	for(int i=0;i<20;i++){

		switch(0){
		case 0:
			cout << "You make me come";
			if(rnd()>0.5)break;         //break only half the time
		case 1:
			cout << "-plete";
			if(rnd()>0.5)break;         //break only half the time
		case 2:
			cout << "ly miserable";
			if(rnd()>0.5)break;         //break only half the time
		default:
			cout << " (guitar)";
		}
		
		cout << '.' << endl;
		
	}
	return 0;
}
```

Given the option to break or not break can have *cascading* results. The output shows each line definitely starting with case 0, then sometimes continuing to case 1. Among those who got to case 1, some of them also throw in case 2, and so on.

```
You make me come-pletely miserable.
You make me come-plete.
You make me come-pletely miserable.
You make me come.
You make me come.
You make me come-plete.
You make me come.
You make me come-pletely miserable.
You make me come.
You make me come-pletely miserable (guitar).
You make me come-plete.
You make me come.
You make me come.
You make me come.
You make me come.
You make me come-plete.
You make me come-plete.
You make me come.
You make me come.
You make me come-pletely miserable.
```

## Escape Sequence

When dealing with paint, some paints have special handling instructions. One pigment is toxic and needs to be kept away from children. Another pigment requires refrigeration, and yet another is water insoluble and is more picky about the medium. In C, special characters like that are handled with an escape sequence.

Let's jump back to the previous code example that was rendering the `////''''    ||||` and attempt to make some changes. Warning, this is going to cause an error, and it's not your fault. In `case 1`, Change the four single quotes to **three** double quotes.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	for(int i=0;i<200;i++){
		float rnd = rand() / (float)RAND_MAX;
		int num = round(rnd * 5);
		
		switch(num){	
		case 0:
			cout << "////";
			break;
		case 1:
			cout << """; // <--------------- changing this from '''' to """
			break;
		case 2:
			cout << "||||";
			break;
		default:
			cout << "    ";
		}
		
		if(i%16==15)cout << endl;
		
	}
	return 0;
}
```

The error is not as useful as we've seen because the preprocessor is just that confused.

```
/Users/jtnimoy/Downloads/tmp.cpp:15:90: error: expected ';' after expression
                        cout << """; // <--------------- changing this from single quote ' to double quote "
                                                                                                              ^
                                                                                                              ;
1 error generated.
```

You cannot put a double quote character into a string literal without using an escape sequence. In C, an escape sequence starts with a backslash and that just means the following character is to be interpreted in a special way.

```cpp
#include <iostream>
using namespace std;

int main(){
	cout << "This is a quote     ---> \" <---- Thank you." << endl;
	cout << "This is a backslash ---> \\ <---- Hooray." << endl;
	cout << "This is a tab       ---> \t <---- Good Grief." << endl;
	cout << "This is a return    ---> \n <---- What next?" << endl;
	cout << "This \
is a \
multiline \
string \
literal. Done." << endl;
	return 0;
}
```

The output shows that the backslash is a magical thing.

```
This is a quote     ---> " <---- Thank you.
This is a backslash ---> \ <---- Hooray.
This is a tab       ---> 	 <---- Good Grief.
This is a return    ---> 
 <---- What next?
This is a multiline string literal. Done.
```

In strings surrounded by double quotes, we need a backslash to insert a double quote. The same is true for chars surrounded by single quotes. You're fine putting a double quote between single quotes, but if you want the actual single quote character, *escape it* with the backslash. Escape sequences are confusing because they are self-reflexive and look odd, but worth getting used to because you'll see them all the time.

## Arrays

In some of the previous examples, you saw I numbered similar variables by naming them with numbers at the end. They relate in name and the data is similar.

```cpp
#include <iostream>
using namespace std;

int main(){
	int egg0 = 4;
	int egg1 = 5;
	int egg2 = 6;
	int egg3 = 7;
	
	cout << egg0 << egg1 << egg2 << egg3 << endl;
		
	egg0 += 1;
	egg1 += 1;
	egg2 += 1;
	egg3 += 1;

	cout << egg0 << egg1 << egg2 << egg3 << endl;

	egg0 += 1;
	egg1 += 1;
	egg2 += 1;
	egg3 += 1;

	cout << egg0 << egg1 << egg2 << egg3 << endl;	
		
	return 0;
}

```

In the above example, I must update each of the four `egg` variables by copying the text around. Whilst easy to understand, and syntactically more simple, this brute force, cut-and-paste method is laborious, and the computer has no idea that the four eggs are related and have an order. The numbers at the end of their variable names are merely part of the word `egg`. We miss the opportunity to *address* each egg by number, in effect, controlling which egg we're working with. Well, what if I told you it doesn't have to be that way?

![Figure 32. Egg Cartons photographed by Melissa Baldwin](images/5602248074_7f51aa5d69_b.jpg "Figure 32. Egg Cartons photographed by Melissa Baldwin")

If a variable is a bucket or coffee cup, then an array is an egg carton - a single box holding several of the same thing. An array is a single variable name but it refers to a list of values. These values all share one type. Let's re-write the above example using an array rather than named variables. To do so, we need to know how to declare the array.

![Figure 33. Declaring an array.](images/array-anatomy.png "Figure 32. Declaring an array.")

Working with the individual eggs of this carton uses a similar square bracket syntax.

```cpp
cout << eggs[2]; // output the value at index 2
eggs[0] = 45; // store 45 into the first index
```

When referring to the array, the square brackets mean "look specifically at that one", and when declaring an array, the square brackets mean "make these many slots." The new egg program, translated in the most basic way (but not all the way) looks like this.

```cpp
#include <iostream>
using namespace std;

int main(){
	int eggs[4]; // declare an integer array with 4 slots		

	eggs[0] = 4;
	eggs[1] = 5;
	eggs[2] = 6;
	eggs[3] = 7;

	cout << eggs[0] << eggs[1] << eggs[2] << eggs[3] << endl;

	eggs[0] += 1;
	eggs[1] += 1;
	eggs[2] += 1;
	eggs[3] += 1;

	cout << eggs[0] << eggs[1] << eggs[2] << eggs[3] << endl;
	
	eggs[0] += 1;
	eggs[1] += 1;
	eggs[2] += 1;
	eggs[3] += 1;

	cout << eggs[0] << eggs[1] << eggs[2] << eggs[3] << endl;
		
	return 0;
}

```

You can see the array syntax is being used, and that individual eggs may be handled one by one. Because the number is no longer part of the identifier, and now a real integer, we can apply a for-loop rather than cutting and pasting in order to loop through all of them. This makes the code more concise, easier to maintain, and opens us up to doing more intelligent things in the program. Here is a new version of the same program that replaces the one-by-one method with for-loops.

```cpp
#include <iostream>
using namespace std;

int main(){
	int eggs[4] = {4,5,6,7};   // declare an integer array with 4 slots,
							   // and initialize it to a literal array of 4 values
	// print them out
	for(int i=0;i<4;i++){
		cout << eggs[i];
	}
	cout << endl;

	// increment them all
	for(int i=0;i<4;i++){
		eggs[i]++;
	}

	// print them out
	for(int i=0;i<4;i++){
		cout << eggs[i];
	}
	cout << endl;
	
	// increment them all
	for(int i=0;i<4;i++){
		eggs[i]++;
	}

	// print them out
	for(int i=0;i<4;i++){
		cout << eggs[i];
	}
	cout << endl;
	
	//report success
	return 0;
}
```

In the above evolution of the same example, you see I could make the size of the eggs array as big as I want without seeing my code get longer in response. 

Let's take this incrementing idea further by printing out an array while altering it.

```cpp
#include <iostream>
using namespace std;

int main(){
	char eggs[8] = { '|',' ','o',' ','x', ' ', '_' , ' ' };
	
	for(int j=0;j<20;j++){
		
		// print
		for(int i=0;i<8;i++){
			cout << eggs[i];
		}
		cout << endl;
		
		
		for(int i=8 ; i >= 1 ; i--){ //loop from max to min+1
			eggs[i] = eggs[i-1]; // set current egg to previous egg's value
		}
		eggs[0] = eggs[7]; // wrap rightmost egg to leftmost egg
		
	}
		
	//report success
	return 0;
}
```

In this example, I am shifting the contents of the array to the right, and making them wrap around. The output is like a candy cane.

```
| o x _ 
_| o x _
 _| o x 
x _| o x
 x _| o 
o x _| o
 o x _| 
| o x _|
_| o x _
 _| o x 
x _| o x
 x _| o 
o x _| o
 o x _| 
| o x _|
_| o x _
 _| o x 
x _| o x
 x _| o 
o x _| o
```

By sweeping downward and leaving a trail, we've made a 1-dimensional array look 2D.

### Multidimensional Arrays

You don't have to keep your arrays 1 dimensional however. To declare an extra dimension, add additional square brackets at the end.

```cpp
#include <iostream>
using namespace std;

int main(){
	//initialize a 2D array
	int tictactoe[3][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};
	
	for(int y=0;y<3;y++){ // loop rows
		for(int x=0;x<3;x++){ // loop columns
			cout << tictactoe[y][x]; // print
		}
		cout << endl;
	}
		
	return 0;
}

```

Notice the syntax for initializing it with literal data has inner nested curly braces for each row. A 2D array may be used as a pixel buffer for remembering your color values.

```cpp
#include <iostream>
using namespace std;

int main(){
	//initialize a 2D array
	int smiley[5][5] = {
		{0,0,0,0,0},
		{0,1,0,1,0},
		{0,0,0,0,0},
		{1,0,0,0,1},
		{0,1,1,1,0}
	};
	
	//render it right side up
	for(int y=0;y<5;y++){ // loop rows
		for(int x=0;x<5;x++){ // loop columns
			if(smiley[y][x]){
				cout << '#';
			}else{
				cout << ' ';
			}
		}
		cout << endl;
	}
	
	cout << endl;
	
	//render it sideways
	for(int y=0;y<5;y++){ // loop rows
		for(int x=0;x<5;x++){ // loop columns
			if(smiley[x][y]){ // <----- X and Y flipped this time
				cout << '#';
			}else{
				cout << ' ';
			}
		}
		cout << endl;
	}
	
	return 0;
}

```

In the above example, I render the pixels right side up, then I render it a second time with X and Y flipped inside the `smiley[x][y]`. The output should look like this:

```

	 # # 

	#   #
	 ### 

	   # 
	 #  #
	    #
	 #  #
	   #
```

### Errors

There are a couple things about arrays that make them dangerous. One of them is related to what we learned from variables, and that has to do with left-over memory if you don't initialize it with a value. Let's actually do that in the next example.

```cpp
#include <iostream>
using namespace std;

int main(){
	//initialize a 2D array
	int smiley[5][5]; // <-------look, no initialization
	
	//render it right side up
	for(int y=0;y<5;y++){ // loop rows
		for(int x=0;x<5;x++){ // loop columns
			cout << smiley[y][x] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

```

My output (which is no doubt different from yours) looked like this.

```
1479976160 32767 1608491643 32767 1479976184 
32767 1479976184 32767 0 1 
1479976208 32767 126439424 1 0 
14 1479976224 32767 0 0 
0 0 0 0 0
```

Some day your piece will glitch and you'll love it but eventually wonder how to fix it. When that day comes, I hope you'll recall that C arrays and variables need to be initialized with a starting value or else you'll find them filled with a visualization of your computer's internal memory.

Another error is when you try and access an index in your array that is outside its boundaries. In the case of `int eggs[4]`, that is any number below 0 or above 3. Arrays are zero-indexed, meaning the first one is at slot zero, and the last one is at (size - 1). This provides a lot of mathematical advantage for the programmer and is worth getting used to. Let's make the mistake on purpose.

```cpp
#include <iostream>
using namespace std;

int main(){
	int eggs[4];
	
	for( int i = 0 ; i < 10 ; i++ ){
		cout << eggs[i] << endl;
	}
	
	return 0;
}

```

The scary thing is that even as I loop beyond 4 and up to 10, it's still accessing mysterious memory and outputting it. Here is my glitchy output.

```
0
0
0
0
0
0
227347776
1
1906995960
32767
```

If you loop for long enough, you may eventually cause a `Segmentation fault` error. The program is stopped by the operating system because it attempted to reach into a forbidden place.

### Passing Arrays to Functions

When you pass an array to a function, it is defaultly *passed by reference*, and that means the function does not get a local copy of the variable and instead, gets to work with the same variable. Let's see this in action.


```cpp
#include <iostream>
using namespace std;

/**
	i will add 1 to each item in an array
	len is the length of the array
	a is the array
*/
void addOne(int a[], int len){
	for( int i = 0 ; i < len ; i++ ){
		a[i] ++;
	}
}

int main(){
	// declare
	int eggs[10];
	
	// initialize values
	for( int i = 0 ; i < 10 ; i++ ){
		eggs[i] = 42;
	}
	
	// pass to function which adds one
	addOne( eggs, 10 );

	// output the new values
	for( int i = 0 ; i < 10 ; i++ ){
		cout << eggs[i] << ' ';
	}
	cout << endl;

	return 0;
}
```

In this example, I initialize all eggs with the value 42, then I pass it as an argument to `addOne()`. The array does not carry its own "size" meta-data, so one needs to pass the size as a second argument. Then `addOne()` loops through all the items and adds one to each. Notice I am not returning the array and yet, back in `main()` afterwards when I output the values, they are 43. An array is passed by reference. If you want to pass a copy, then you need to declare a second one and copy the values over to it. Swapping between arrays can be very powerful. In the following example, I do not quite copy the values to the second array verbatim. Instead, I use the previous state as simple rules.

```cpp
#include <iostream>
using namespace std;

int main(){
	
	int width = 10;
	int height = 10;
	// setup
	int worlds[2][10][10] = {
		
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}
		}		
	};
	bool currentWorld = true;
	
	//------------------------------------------------
	
	
	for(int i=0;i<9;i++){


		// draw
		for(int y=0;y<10;y++){
			for(int x=0;x<10;x++){
				if(worlds[!currentWorld][y][x]==1){
					cout << '#';
				}else{
					cout << '.';
				}
			}
			cout << endl;
		}
	
		cout << endl;

		//------------------------------------------------
		
		// update
		for(int y=0 ; y < height ; y++){
			for(int x=0 ; x < width ; x++){
				bool center = worlds[!currentWorld][y][x];
				
				// collect which neighboring pixels are on
				// modulo by width or height for wrap-around access.
				int left = worlds[ !currentWorld ][ y ][ (x + width -1) % width ];
				int right = worlds[ !currentWorld ][ y ][ (x+1) % width ];
				int up = worlds[ !currentWorld ][ (y + height -1) % height ][ x ];
				int down = worlds[ !currentWorld ][ (y+1) % height ][ x ];
				
				if( left + right + up + down > 0){
					worlds[currentWorld][y][x] = !center; // flip value
				}else{
					worlds[currentWorld][y][x] = 0; // write a blank
				}
			}
		}
	
		//------------------------------------------------
	
		// swap buffers
		currentWorld = !currentWorld;
	}
	
	return 0;
}

```

As I copy the values from one buffer to the next, I count how many neighboring pixels are on. If there are any, I reverse the value and otherwise write a blank. The result is a rippling effect that can take a dot, and iterate it out as a checkered diamond.

```
..........
..........
..........
..........
.....#....
..........
..........
..........
..........
..........

..........
..........
..........
.....#....
....#.#...
.....#....
..........
..........
..........
..........

..........
..........
.....#....
....#.#...
...#.#.#..
....#.#...
.....#....
..........
..........
..........

..........
.....#....
....#.#...
...#.#.#..
..#.#.#.#.
...#.#.#..
....#.#...
.....#....
..........
..........

.....#....
....#.#...
...#.#.#..
..#.#.#.#.
.#.#.#.#.#
..#.#.#.#.
...#.#.#..
....#.#...
.....#....
..........

....#.#...
...#.#.#..
..#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
..#.#.#.#.
...#.#.#..
....#.#...
.....#....

...#.#.#..
..#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
..#.#.#.#.
...#.#.#..
....#.#...

..#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
..#.#.#.#.
...#.#.#..

.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
..#.#.#.#.
```

Evolving a pixel buffer using itself as the simple rules is often called *cellular automata*, and is an inspiring model of nature. If this sounds like a direction you're going in, try *Conway's Game of Life* and Wolfram.

In the above code example, you see I have a *setup* routine, followed by a loop which does an *update*, then draws something. If the web dev community has *Model, View, Controller* (MVC) design pattern, creative coders have a *Setup, Update, Draw* design pattern. We could at least separate out the chunks of code into their own functions. Here is the same example, refactored to compartmentalize each of the three standard routines. Notice that in order to share variables between the functions, I had to make them global.

```cpp
#include <iostream>
using namespace std;

int width;
int height;

int worlds[2][10][10] = {
	
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	}		
};
bool currentWorld;

// --------------------------------------

void setup(){
	width = 10;
	height = 10;
	currentWorld = true;
}

// --------------------------------------

void update(){
	for(int y=0 ; y < height ; y++){
		for(int x=0 ; x < width ; x++){
			bool center = worlds[!currentWorld][y][x];
			
			// collect which neighboring pixels are on
			// modulo by width or height for wrap-around guard.
			int left = worlds[ !currentWorld ][ y ][ (x + width -1) % width ];
			int right = worlds[ !currentWorld ][ y ][ (x+1) % width ];
			int up = worlds[ !currentWorld ][ (y + height -1) % height ][ x ];
			int down = worlds[ !currentWorld ][ (y+1) % height ][ x ];
			
			if( left + right + up + down > 0){
				worlds[currentWorld][y][x] = !center; // flip value
			}else{
				worlds[currentWorld][y][x] = 0; // write a blank
			}
		}
	}

	// swap buffers
	currentWorld = !currentWorld;
}

// --------------------------------------

void draw(){
	for(int y=0;y<10;y++){
		for(int x=0;x<10;x++){
			if(worlds[!currentWorld][y][x]==1){
				cout << '#';
			}else{
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl;
}

// --------------------------------------

int main(){
	setup();
	for(int i=0;i<9;i++){
		draw();
		update();
	}
	return 0;
}

```

I was able to lose the comments that label the code section since the containing function is called that. Self-documenting code which needs less comments is good code. Some say that if you write a program correctly, it needs no comments. Notice also that I've added dividing lines between the functions just to make it easier to see. Those are optional but do show up all over OpenFrameworks.

In the following example, I use the same pixel buffer technique to draw a spiral (cosine and sine functions) but this time, I only show the last frame.

```cpp
#include <iostream>
#include <math.h>
using namespace std;

int width, height;
int world[10][40];
int spiralCounter;
// --------------------------------------

void setup(){
	width = 40;
	height = 10;
	spiralCounter = 0;
	
	//zero the memory
	for(int y=0;y<height;y++){
		for(int x=0;x<width;x++){
			world[y][x] = 0;
		}
	}
}

// --------------------------------------

float rnd(){
	return (float)rand() / RAND_MAX;
}

// --------------------------------------

void update(){
	int offsetX = 20;
	int offsetY = 5;
	float rScale = 0.0415;
	float thScale = 0.075;
	float theta = spiralCounter * thScale;
	float r = spiralCounter * rScale;
	
	//basic use of cos() and sin()
	int y = offsetY + round(sin( theta ) * r);
	int x = offsetX + round(cos( theta ) * r) * 2; // x 2 for ascii art aspect
	if(y < height && y >= 0 && x < width && x >= 0){
		world[y][x] = 1;
	}
	
	spiralCounter++;
}

// --------------------------------------

void draw(){
	for(int y=0;y<height;y++){
		for(int x=0;x<width;x++){
			if(world[y][x]==1){
				cout << '@';
			}else{
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl;
}

// --------------------------------------

int main(){
	setup();
	for(int i=0;i<500;i++){
		update();
	}
	draw();
	
	return 0;
}

```

The output is a spiral trail.

```
....@.@.......@.@.........@.@.@.......@.
....@.......@.................@.@.....@.
....@.....@.........@.@.........@.......
..@.......@.......@...@.@.@.....@.@.....
..@.......@.....@.........@.......@.....
..@.......@.....@...@.....@.@.....@.....
..@.......@.......@.@.....@.@.....@.....
....@.....@.@.............@.......@.....
....@.......@.@.........@.@.....@.@.....
......@.......@.@.@.@.@.@.......@.......
```

## Dynamic Allocation and Pointers

Besides declaring new variables and arrays the way I have shown you so far, there is another way which uses a different syntax and is a bit trickier but worth knowing. *Dynamic allocation* allows us to reserve global memory with more flexibility than traditional *stack based* declarations. The whole business of dynamic allocation pivots around the `new` and `delete` keywords, and contraversially, you are responsible for cleaning up after yourself. Here is a dynamically allocated integer.

```cpp
#include <iostream>
using namespace std;

int main(){
	int *myNumber = new int;
	(*myNumber) = 5;
	cout << myNumber << endl;
	delete myNumber;
	return 0;
}
```

That asterisk prefix is part of *pointer* syntax. Using it in a declaration means that the variable will not be an int, but a pointer to an int. Using it on the next line to assign the value 5 to myNumber, the asterisk *de-references* causing the pointer `myNumber` to act as a normal variable for the moment I assign the value. You may have noticed a peculiar output from this program - something like 0x7feb6ac03980. That big number happened because we sent `myNumber` to `cout` in raw without de-referencing it. If you add an asterisk right before `myNumber` in the code and re-run, you'll see the satisfying 5. Sound confusing? You are not alone. This is infamous for being one of the most difficult parts of C.

### What is a pointer?

![Figure 34. C++ Pointers](images/pointers/01.png "Figure 34. C++ Pointers")

Imagine the variable `a`, an integer holding the value 42.

![Figure 35. int a = 42;](images/pointers/02.png "Figure 35. int a = 42;")

Well, 42 is sitting in the computer memory somewhere. You can think of the computer memory like a neighborhood and each place is like a house with an address. Those addresses can be written down and exchanged.

![Figure 36. Computer memory is like houses with addresses.](images/pointers/03.png "Figure 36. Computer memory is like houses with addresses.")

In C++, we use the ampersand *reference* operator before the variable name in order to mean `3`, the address in memory where the value `42` is living.

![Figure 37. Ampersand reference operator.](images/pointers/04.png "Figure 37. Ampersand reference operator.")

When declaring a pointer, we precede the name with an asterisk * meaning that it contains an address reference, and then we can store a reference into it. 

![Figure 38. Asterisk address operator.](images/pointers/05.png "Figure 38. Asterisk address operator.")


One reason this can be confusing is that the variable can sit alone, without any asterisk or ampersand, and look like a regular variable - but it's still a pointer. 

![Figure 39. B is still a pointer.](images/pointers/06.png "Figure 39. B is still a pointer.")

So what if I'm writing code that uses B and I want to access the value, instead of the pointer address? I precede the variable with another kind of asterisk, a *dereferencing operator*, in order to turn the 3 back into a 42.

![Figure 40. B dereferenced.](images/pointers/07.png "Figure 40. B dereferenced.")
 
In the following example, I will create a pointer to an already existing variable, then increment both.

```cpp
#include <iostream>
using namespace std;

int main(){
	int a = 42;
	int *b = &a; // create a pointer to a
	cout << b << ' ' << a << endl;
	a++;
	(*b)++;
	cout << b << ' ' << a << endl;
	return 0;
}

```

Notice the last output is 44, since incrementing b and a will add 1 to the same variable.

Pointers may also be passed as arguments to functions with the same results. In the below example (whose output is 45), I show a couple techniques.

```cpp
#include <iostream>
using namespace std;

void addOne(int *that){
	(*that) ++;
}


void addTwo(int &that){
	that += 2;
}

int main(){
	int a = 42;
	addOne( &a );
	addTwo( a );
	cout << a << endl;
	return 0;
}

```

In `addOne()`, I pass a pointer. This can be useful because it does not let me forget that I'm working with something special. In `addTwo()`, I am *passing by reference* with that ampersand, and it provides for cleaner code at the risk of forgetting the local variable is connected to something bigger.

## Forward Declaration

Perhaps you noticed that all my functions in the previous examples were defined in a certain order. `main()` has always been very last. What if I put `main()` before?

```cpp
#include <iostream>
using namespace std;

int main(){	
	doSomething();
	return 0;
}

void doSomething(){
	cout << "hi there" << endl;
}
```

The error shows that the compiler was not able to find `doSomething()`.

```
/Users/jtnimoy/Downloads/tmp.cpp:5:2: error: use of undeclared identifier 'doSomething'
        doSomething();
        ^
1 error generated.
```

If I had to manage everything in an order of dependency all the time, things would get out of control pretty quickly. Luckily, C++ has *forward declarations*. Declaring a function in the beginning without defining the full piece of code provides a legend to the compiler so it will allow you to place your functions in any order (after that).

```cpp
#include <iostream>
using namespace std;

//forward declaration
void doSomething();

int main(){	
	doSomething();
	return 0;
}

void doSomething(){
	cout << "hi there" << endl;
}
```

In fact, forward declarations are such an essential part of writing C and C++ that we put them in a header file. The following is an example header file separated out. `#pragma once` means make sure this file is only included once. The header file can take over the job of including libraries, using namespaces, and this is where you should be forward declaring functions.

```cpp

// -------- filename: code.h ----------

#pragma once
#include <iostream>
using namespace std;

void doSomething();
int main();

```

Meanwhile in the C++ file, there is a lot less to deal with, and you can put your functions in any order.


```cpp
// -------- filename: code.cpp ----------

#include "code.h"

int main(){	
	doSomething();
	return 0;
}

void doSomething(){
	cout << "hi there" << endl;
}

```

Let us modify this example to use a personal namespace.


```cpp

// -------- filename: code.h ----------

#pragma once
#include <iostream>
using namespace std;
namespace tutorial{
	void doSomething();
};
int main();

// -------- filename: code.cpp ----------

#include "code.h"

int main(){	
	tutorial::doSomething();
	return 0;
}

void tutorial::doSomething(){
	cout << "hi there" << endl;
}

```
Notice in the header file, the namespace `tutorial` contains the forward declaration of a function in that namespace, then in the code implementation file (.cpp), the function name is decorated with `tutorial::` before it. In C++, the double colon means the thing on the right is organized inside the thing on the left, a bit like a biological classification. `life::domain::kingdom::phylum::class::order::family::genus::species`. A namespace is not the only thing you can employ to organize your functions into nice bundles. In the last section, I will provide a tour of structs and classes, and it should be enough to get you through the initial OpenFrameworks topics. Classes and *Object Oriented Programming* will be covered in greater depth in a later chapter.

## Classes

It's nice to organize things into clusters, to form associations between them, stay tidy, and operate on them as a group - another kind of abstraction. A *class* is one construct that lets you do this. Let's bunch integers `x` and `y` into a class `Point`.

```cpp
// -------- filename: code.h ----------

#pragma once
#include <iostream>
using namespace std;

namespace tutorial{
    class Point{
	public:
		float x;
        float y;
    };
}

// -------- filename: code.cpp ----------

#include "code.h"

int main(){
    tutorial::Point p;
    p.x = 5.8;
    p.y = 2.5;

    cout << p.x << ' ' << p.y << endl;
    return 0;
}

```

In the above example, I define the class `Point` and inside it, you see there is a `public:` label that allows me to use dot syntax and say `p.x` later on. If I had left out the `public:`, it would be the same as typing `private:` and the compiler would not allow me to refer to the inner members of the class. A class can also hold functions! Let's add a function to the `Point` class which will operate on its values in an encapsulated way.

```cpp
// -------- filename: code.h ----------
#pragma once
#include <iostream>
using namespace std;

namespace tutorial{
    class Point{
    public:
        float x;
		float y;
        void move(int offsetX,int offsetY);
    };
}

// -------- filename: code.cpp ----------

#include "code.h"

int main(){
    tutorial::Point p;
    p.x = 5.8;
    p.y = 2.5;

    p.move(4,4);

    cout << p.x << ' ' << p.y << endl;
    return 0;
}

void tutorial::Point::move(int offsetX,int offsetY){
    x += offsetX;
    y += offsetY;
}

```


Notice the namespace syntax applies when defining the function later ... `tutorial::Point::move`. Within that function, I am referring to `x` and `y` as local variables, and it turns out that works because the function is in the `Point` class, next to those member variables, so this makes sense. When I call `p.move()`, the one instance of that class adds 4 to both its x and y members.

When dynamically allocating an instance of a class, one uses pointer syntax just the same, but the dot syntax changes to arrows.

```cpp
int main(){
    tutorial::Point *p = new tutorial::Point();
    p->x = 5.8;
    p->y = 2.5;

    p->move(4,4);

    cout << p->x << ' ' << p->y << endl;

	delete p;
    return 0;
}
```

Now that you've seen the arrow syntax for class instance pointers, here is a more verbose way of referring to x and y in `move()`:

```cpp
void tutorial::Point::move(int offsetX,int offsetY){
    this->x += offsetX;
    this->y += offsetY;
}
```

The reason x and y work is because they are implicitly members of `this`, which is a pointer to the current class instance.

When seeing classes in OpenFrameworks code templates, the top of the class declaration might contain more than I've taught you. Something like:

```cpp
class ofApp : public ofBaseApp{
```

The mysterious part at the end that goes `: public ofBaseApp` means that the class `ofApp` is *inheriting* some pre-written variables and functions from OpenFrameworks so it is more capable than meets the eye.

## STL Strings

Now that you understand a little bit about classes, let's look back at some classes that have always been with us. `std::cout` is an instance of iostream, and the << operator is like calling a "writeLine" function, sort of like `cout.write()`. Although C traditionally uses c-strings (char arrays with zero bytes at the end) as its string format of choice, OpenFrameworks conventionally chooses the more robust STL String as it is closer to Java and has a lot of useful features. 

```cpp
#include <iostream>
int main(){	
	std::string s = "hi";
	s += " there";
	std::cout << s << ' ' << s.size() << std::endl;
	return 0;
}
```

In the above example, I am adding additional text to my string with the addition + operator, and calling `s.size()` to get the number of bytes in the text.

As the STL String object enhances the c-string, there are many classes and packages in C++ that are here to enhance different domains. OpenFrameworks is one such collection of reusable code.

## Conclusion

Congratulations, you should now know enough C++ to get started with OpenFrameworks, a collection of functions and classes to make your life easier as a computational poet. Of course, I did not just teach you the entire language, but if you wish to go further with learning C and C++, here are a couple books I recommend.

Brian W. Kernighan; Dennis M. Ritchie (March 1988). The C Programming Language (2nd ed.). Englewood Cliffs, NJ: Prentice Hall. ISBN 0-13-110362-8. (Amazon: http://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628 )

Bjarne Stroustrup (2013). The C++ Programming Language (4th ed.).  Addison-Wesley. ISBN 978-0-321-56384-2 (Amazon: http://www.amazon.com/The-Programming-Language-4th-Edition/dp/0321563840 )

For online reference, I recommend http://en.cppreference.com and http://cplusplus.com

===
===
===

### Bibliography
+ Back to the Future II. Dir. Robert Zemeckis. Perf. Michael J Fox, Christopher Lloyd, Lea Thompson,. Universal Pictures, 1989. Film.
+ Carver, Cecily "Things I Wish Someone Had Told Me When I was Learning How to Code." *HACKER MONTHLY Issue 45* February 2014: Page 28 - 30. Print.
+ Cubbi, "C++ keywords." *cppreference.com* 29 November 2013. Web. 15 February 2014. http://en.cppreference.com/w/cpp/keyword
+ "Dan Benjamin", "Top 10 Programmer Fonts."  *hivelogic.com* 17 May 2009. Web. 22 March 2014. http://hivelogic.com/articles/top-10-programming-fonts
+ "From the Beginning" - http://snap.nlc.dcccd.edu/learn/selena/history.html
+ "Dennis M. Ritchie" - http://cm.bell-labs.com/who/dmr
+ Maeda, John. Design by Numbers. Cambridge, MA: MIT, 1999. Print.
+ The Matrix. Dir. Brothers Wachowski. Perf. Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss. Warner Brothers, 1999. Film.
+ Minecraft. Version 1.7.5. Mojang. February 27, 2014. Video game.
