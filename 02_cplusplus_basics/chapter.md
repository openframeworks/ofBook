# Chapter 2. C++ Language Basics

###inspirational quote candidates:

+ A hero is someone who understands the responsibility that comes with his freedom. **--Bob Dylan**

+ Differences of habit and language are nothing at all if our aims are identical and our hearts are open. **--Albus Dumbledore**

+ The magician of the future will use mathematical formulas. **--Aleister Crowley** [1 vote]



##Look Alive!

This chapter introduces you to writing small computer programs using the C++ language. Although I assume very little about your previous knowledge, the literacy you gain from this chapter will directly influence your comprehension in subsequent chapters of the book, as most other topics stand on the shoulders of this one. Furthermore, the lessons herein are cumulative, meaning you can't skip one of the topics or you will get lost. If you get stuck on one of the concepts, please seek help in understanding specifically the part that did not make sense before moving on to the next topic. Following the lessons with this sort of rigor will insure that you will get the most out of OpenFrameworks, but also computers in general.



##Progress Not Perfection


I did most of my drawing and painting in the mid-nineties, a high school AP art student sporting a long black ponytail of hair shaved with a step, round eyeglasses, and never an article of clothing without spill, fling, smattering, or splotch of Liquitex Basics acrylic paint. Bored out of my mind in economics class, playing with my TI-82 graphing calculator, I discovered something that flipped a light bulb on in my heart. Unlike smaller calculators around my house growing up, the TI-82 had a thick instruction manual. Amidst sections in this manual about trig functions and other dry out-of-reach science, something caught my thirsty, young eye: a sexy black-on-white pyramid with smaller upside-down pyramids infinitely nested inside, shown in Figure 1.

![Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments](img/sierpinski-fractal-ti82.png "Figure 1: TI-82 rendering of the Sierpinski triangle, Courtesy of Texas Instruments")

This fractal, the famous *Sierpinski triangle*, accompanied about twenty-five computer instructions making up the full SIERPINS program. I looked closer at the code, seeing a few numeric operations – nothing too advanced, and most of it was commanding words, like "do this", or "if something then do another thing". I was able to key in the code from the book into the graphing calculator and run the program. At first, just a blank LCD panel. Slowly a few random pixels switched to black here and there, not really showing any pattern. After a few more seconds, the scene filled in and I could already see faint outlines of triangles. After a good long time, my calculator finally matched the picture in the book. My mind was officially blown. Certain things did not make sense. What sort of miracle of nature caused such a complex form to come from so little instruction? The screen had over six-thousand pixels in it, so why is it that a mere twenty-five instructions was all it took to create this amazing, organism-like artwork? Whose artwork was it? Might I derive a new work from it? Rarely had I ever seen such a magical reward coming from so little work. I had found my new basics. I felt the need to understand the program because (I decided) it was important. I went back into the code and changed some of the numbers, then ran the program again. The screen went blank, then drew a different picture, only this time, skewed to the left, falling out of the viewport. Feeling more courageous, I attempted to change one of the English instructions, and the machine showed an error, failing to run.

![Figure 2: The human loop of a programmer.](img/programmer-cycle.png "Figure 2: The human loop of a programmer.")

The cycle I just described (write code, run app, re-think program's behavior,  revise code, etc.) as shown in Figure 2, is an infinitely repeating loop that I have had a great pleasure of executing for a couple decades and I still love what I do. Each new cycle never fails to surprise me. As I pursue what it means to create a program, and what it means to create software art, the process of iteratively evolving a list of computer instructions always presents as much logical challenge as it does artistic reward. Very few of those challenges have been impossible to solve, especially with other people available to collaborate and assist, or by splitting my puzzle into smaller puzzles. If you have already written code in another environment like Processing, Javascript, or even HTML with CSS, then this first important lesson might seem too obvious.

![Figure 3: Don't get the wrong idea.](img/profit-not.png "Figure 3: Don't get the wrong idea.")

For those just now familiarizing themselves with what it means to write small programs, it is important to understand the iterative nature of the code writing process. The anecdote in Figure 3 shows what this process is *not*. Rarely would you ever enter some code into the editor just once, and expect to hit compile and see your finished outcome. It is natural, and commonly accepted for programs to start small, have plenty of mistakes (bugs), and evolve slowly toward a goal of desired outcome or behavior. In fact it is so commonplace that to make the former assumption is a downright programmer's mistake. Even in older days when programs were hand-written on paper, the author still needed to eyeball the code obsessively in order to work out the mistakes, and therefore the process was iterative. In learning the C++ language, I will provide tiny code examples that you will be compiling on your machine. The abnormal part is typing the code from the book into the editor, and (provided your fingers did not slip), the program magically runs. I am deliberately removing the troubleshooting experience in order to isolate out the subject matter of the C++ language itself. Later on, we will tackle the black art of *debugging* as a topic all its own.



##Compiling My First App

Let us start by making the smallest, most immediate C++ program possible, then use the convenient environment to test small snippits of C++ code throughout this chapter. In order to do that, we must have a *compiler*, which is a program that translates some code into an actual runnable app, sometimes referred to as the executable file. C++ compilers are mostly free of charge to download, and in a lot of cases, open source. The apps we generate will not automatically show up in places like Apple's App store, Google Play, Steam, Ubuntu Apps Directory, or Pi Store. Instead, they are your personal, private program files and you will be responsible for manually sharing them later on. In the following chapter *OF Setup and Project Structure*, the compiler will sit on your local computer, able to run offline. For now, we will be impatient and compile some casual C++ on the web using a convenient tool by Sphere Research Labs. Please open your web browser and go to [ideone](http://ideone.com).

You will notice right away that there is an editor already containing some code, but it is set to another language. We will now switch from Java to C++. Down at the bottom left of the editor, press the button that says "Java", as shown in Figure 4.

![Figure 4](img/where-is-says-java.png "Figure 4")

A menu drops down with a list of programming languages. Please choose C++11, shown in Figure 5.

![Figure 5](img/choose-c11.png "Figure 5")

Notice that the code in the editor changed, and looks something like figure 6.

![Figure 6](img/empty-template.png "Figure 6")

This is just an empty code template that does nothing, and creates no errors. The numbers in the left hand gutter indicate the line number of the code. Press the green button labeled *Run* and you'll see a copy of the code,  "Success" in the comments, the section labeled *stdin* (standard input) will be empty, and *stdout* (standard output) will also be empty.


###Interlude on Typography

Computer programming code is generally presented in fixed-width typesetting, because it is a form of ascii-art. The indentation, white space characters, and repetitive patterns are all important to preserve and easily eyeball for comparison. Every coder I know except artist Jeremy Rotsztain uses some manner of monospaced font for their code. Some typeface suggestions are Courier, Andale Mono, Monaco, Profont, Monofur, Proggy, Droid Sans Mono, Deja Vu Sans Mono, Consolas, and Inconsolata. From now on, you will see the font style switch to `this style` . . .

```C++
or this style ...
```

. . . and that just means you are looking at some code.

###Comments

Now please press *Edit* (Figure 7) at the top left of the code editor.

![Figure 7](img/ideone-edit.png "Figure 7")

You will see a slightly different editing configuration but the same template code will still be editable at the top. We will now edit the code. Find line 5, where it says:

```C++
// your code goes here .
```

A line beginning with a double forward slash is called a comment. You may type anything you need to in order to annotate your code in a way you understand. Sometimes a it's useful to “comment out code” by placing two forward-slashes before it, because that deactivates the C++ without deleting it. Comments in C++ can also take up multiple lines, or happen inside of some code on 1 line, but the syntax for beginning and ending comment-mode is different. Everything between the /* and the */ becomes a comment:


```C++
/* 
this is a multi-line comment. 
still in comment mode.
*/
```

Please delete the code on line 5 and replace it with the following statement:

```C++
cout << "Hello World" << endl;
```

This line of code tells the computer to say "Hello World" into an implied text-space known as *standard output* (aka. *stdout*). When writing a program, it is safe to expect *stdout* to exist and that the program can say things in it. Other times, it's just a window pane in your coding tool, only used to troubleshoot.

You may put almost anything between those quotes. The quoted phrase is a called a *string* of text. More specifically, it is a *c-string literal*. We will cover more on strings later in this chapter. In the code, the chunk `cout <<` part means "send the following stuff to stdout in a formatted way." The last chunk `<< endl` means "add a carriage return (end-of-line) character to the end of the hello world message." Finally, at the very end of this line of code, you see a semicolon (;). In C++, semicolons are like a full-stop or period at the end of the sentence. We must type a semicolon after each statement, and usually this is at the end of the line of code. If you forget to type that semicolon, the compile fails. Semicolons are useful because they allow multiple statements to share one line, or a single statement to occupy several lines, freeing the programmer to be flexible and expressive with ones whitespace. The compiler does not get confused because you help it out and show it where the statement ends.

While you typed, perhaps you noticed the text became multi-colored all by itself. This convenient feature is called *syntax-coloring* and can subconsciously enhance ones ability to read the code, troubleshoot malformed syntax, and assist in searching. Each tool will have its own syntax coloring system so if you wish to change the colors, please expect that it's not the same thing as a word processor. It will not let me assign the font "TRON.TTF" with a glowing aqua color to *just* `endl` (which means end-of-line). Instead, I can choose a special style for a whole category of syntax, and see all parts of my code styled that way as long as it's that type of code. In this case, both `cout` and `endl` are considered keywords and so the tool colors them black. If these things show up as different colors elsewhere, please trust that it's the same code as before. The entire code should now look like this:

```C++
include <iostream.h>
using namespace std;

int main(){
	cout << "Hello World" << endl;
	return 0;
}
```

Now press the green "ideone it!" button at the bottom right corner and watch the output console, which is the bottom half of the code editor, just above that green button. You will see orange status messages saying things like “Waiting for compilation”, “Compilation”, and “Running”. Shortly after, the program will itself, execute, its output printed. You should see the new message in Figure 8.

![Figure 8](img/hello-world.png "Figure 8: Hello World appears in output window")

If you made it this far, then give yourself a great big hug. You just wrote your first line of C++ code, you analyzed it, compiled it, ran it, and saw the output. Please send word of your recent success so that we may heed your triumph. Tweet the following: **cout << "Hello World" << endl; #ofBook
**


##Beyond Hello World

Now that we've gotten our feet wet, let's go back and analyze the other parts of the code. The first line is an include statement:

```C++
#include <iostream>
```

Similar to *import* in Java and CSS, `#include` is like telling the compiler to cut and paste some other useful code from a file called *iostream.h* at that position in the file, so you can depend on its code in your new code. In this case, iostream.h *provides* `cout` and `endl` as tools I can use in my code, just by typing their names. In C++, a filename ending in **.h** is called a header file, and it contains code you would include in an actual C++ implementation file, whose filename would end in **.cpp**. There are many standard headers built into C++ that provide various basic services – in fact too many to mention here. If that wasn't enough, it's also commonplace to add an external library to your project, including its headers. You may also define your own header files as part of the code you write, but the syntax is slightly different:

```C++
#include "MyCustomInclude.h"
```

In OpenFrameworks, double quotes are used to include header files that are not part of the system installation.

###What's with the # ?

It's a whole story, but worth understanding conceptually. The include statement is not really C++ code, it's part of a completely separate compiler pass called *preprocessor*. It happens before your actual programmatic instructions are dealt with. They are like instructions for the code compiler, as opposed to instructions for the computer to run after the compile. Using a pound/hash symbol before these *preprocessor directives*, one can clearly spot them in the file, and for good reason too. They should be seen as a different language in which your real C++ code is interleaved. There aren't many C++ preprocessor directives - they are mostly concerned with herding other code. Here are some you might see.


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

```C++
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

The compiler found an error and did not run the program. Instead, it's showing you  where it got confused in attempt to help you fix it. The first part, *prog.cpp*: tells you the file that contains the error. In this case, ideone.com saved your code into that default file name. Next, it says `In function ‘int main()’`: file showing you the specific section of the code that contains the error, in this case, between the {curly brackets} of a function called *main*. (We will talk about functions and curly brackets later). On the next line, we see `prog.cpp:5:2:`. The 5 is how many lines from the top of the file, and 2 is how many characters rightward from the beginning of the line. Next, we see `error: ‘cout’ was not declared in this scope`. That is a message describing what it believes it wrong in the code. In this case, it's fairly correct. iostream.h is gone, and therefore no `cout` is provided to us, and so when we try to send "Hello World", the compile fails. On the next couple of lines, you see the line of code containing the fallacious `cout`, plus an extra little up-caret character on the line beneath it, and that is supposed to be an arrow pointing at a character in the code. In this case, the arrow should be sitting beneath the 'c' in `cout`. The system is showing you visually which token is at fault. A second error is shown, and this time, the compiler complains that there is no endl. Of course, we know that in order to fix the error, we need to include <iostream.h> so let us do that now. Please un-comment line 1 and re-run the code.

```C++
#include <iostream>
```

When using OpenFrameworks, you have choice of tools and platforms. Each one shows you an error in a different way. Sometimes the editor will open up and highlight the code for you, placing an error talk bubble for more info. Other times, the editor will show nothing, but the compile output will show a raw error formatted similar to the one above. Whilst sometimes useful that we receive several errors from a compile, it can save a lot of grief if you focus on understanding and fixing the very first error that got reported. After fixing the top error, it is likely that all subsequent errors will elegantly disappear, having all been covered by your first fix.

###Namespaces at First Glance

Moving on to line 2, we see:

```C++
using namespace std;
```

Let's say I'm in the 3rd grade of elementary school and I hop on a school bus to get there each morning. As I walk slowly down the aisle, different students notice my unsightly leg braces and tell me (in Southern accents) "Seat's taken" or "You can't sit here". Finally, I find a seat on the bus next to Jenny. I just experienced conflict and resolution in *Seat Space*, finally discovering my unique place on the bus.

Let's say you join a social website and it asks you to choose a username. My name is Joshua Nimoy, username might be JNIMOY. I submit the page and it returns an error, telling me that username is already taken, and I have to choose another, since my father, Joseph Nimoy, registered before I did and he's got JNIMOY. And so I must use my middle initial T, and create a more unique username, JTNIMOY. I just created and resolved a *namespace conflict*. A namespace is a group of unique names - none are identical. It's possible to have identical names, as long as they are a part of two separate namespaces. Namespaces help programmers avoid stepping on each other's toes by overwriting one another's symbols or hogging the good names. Namespaces also provide a neat and tidy organization system to help us find what we're looking for. In OpenFrameworks, everything starts with `of` . . . like `ofSetBackground` and `ofGraphics`. This is one technique to do namespace separation because it's less likely that any other names created by other programmers would begin with `of`. The same technique is used by OpenGL. Every name in the OpenGL API (Application Programming Interface) begins with `gl` like `glBlendFunc` and `glPopMatrix`. In C++ however, it is not necessary to have a strictly disciplined character prefix for your names, as the language provides its own namespacing syntax. In line 2, `using namespace std;` is telling the compiler that this .cpp file is going to use all the names in the `std` namespace. Spoiler-alert! those two names are `cout` and `endl`. Let us now do an experiment and comment out line 2, then run the code. What sort of error do you think the compiler will return?

```C++
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

The compiler says "Hey, I searched for `cout` and I did find it in one of the namespaces included in the file. Here it is. `std::cout`" and in this case, the compiler is correct. It wants us to be *more explicit* with the way we type `cout`, so we express its namespace `std` (standard) on the left side, connected by a double colon (::). it's sort of like calling myself `Nimoy::Joshua`. Continuing our experiment, edit line 5 so that `cout` and `endl` have explicit namespaces added.

```C++
std::cout << "Hello World" << std::endl;
```

When you run the code, you will see it compiles just fine, and succeeds in printing "Hello World" even the line that says `using namespace std;` is still commented out. Now imagine you are writing a program to randomly generate lyrics of a song. Obviously, you would be using `cout` quite a bit. Having to type `std::` before all your `cout`s would get really tedious, and one of the reasons a programming language adds these features is to reduce typing. So although line 2 `using namespace std;` was not necessary, having it in place (along with other `using namespace` statements) can keep ones C++ code easy to type and read, through implied context.

Say I'm at a Scrabble party in Manhattan, and I am the only Josh. People can just call me Josh when it's my turn to have a go at Scrabble. However, if Josh Noble joins us after dinner, it gets a bit confusing and we start to call the Josh's by first and last name for clarity. In C++, the same is also true. It's alright to have two different `cout` names, one from the  `std` namespace, and another from the `improved` namespace, as long as both are expressed with explicit namespaces; `std::cout` and `improved::cout`. In fact, the compiler will complain if you don't.


##Functions

Moving on, let us take a look at line 4:

```C++
int main() {
```

This is the first piece of code that has a beginning and an end, such that it "wraps around" another piece of code. But more importantly, a function *represents* the statements enclosed within it. The closing end of this *function* is the closing curly bracket on line 7:

```C++
}
```

In C++, we enclose groups of code statements inside functions, and each function can be seen as a little program inside the greater program, as in my laughably gross oversimplification in figure 9.

![Figure 9: Many Functions](img/program-anatomy.png "Figure 9. A program contains many functions, and each function contains zero or more statements.")

Each of these functions has a name by which we can call it. To call a function is to execute the code statements contained inside that function. The basic convenience in doing this is less typing, and we will talk about the other advantages later. Like a board game, a program has a starting position. More precisely, the program has an *entrypoint* expected by the compiler to be there. That entrypoint is a function called *main*. The code you write inside the *main* function is the first code that executes in your program, and therefore it is responsible for calling any other functions in your program. Who calls your *main* function? The operating system does! Let's break down the syntax of the main function in this demo. Again, for all you Processing coders, this is old news.

![Figure 10: The Function](img/function-anatomy.png)

When defining a function, the first token is the advertised return type. Functions can optionally return a value, like an answer to a question, a solution to a problem, the result of a task, or the product of a process. In this case, *main* promises to return an `int`, or *integer* type, which is a whole number with no fraction or decimal component. Next token is the name of our function. The system expects the word "main" in all lower-case, but you will later define your own functions and we will get into naming. Next is an opening and closing parenthesis. Yes, it seems kind of strange to have it there, since there is nothing inside it. Later, we will see what goes in there - but never leave out the pair of parentheses with functions because in a certain way, that is the major hint to the human that it's a function. In fact, from now on, when I refer to a function by name, I'll suffix it with a ( ), for example `main()`.

Next, we see an opening curley bracket. Sometimes this opening curley bracket is on the same line as the preceding closing parenthesis, and other times, you will see it on its own new line. It depends on the personal style of the coder and both are fine. Inbetween this opening curley bracket and the closing one, we place our code statements that actually tell the computer to go do something. In this example, I only have one statement, and that is the required `return`. If you leave this out for a function whose return type is `int` then the compiler will complain that you broke your promise to return an int. In this case, the operating system interprets a 0 as "nothing went wrong". Just for fun, see what happens when you change the 0 to a 1, and run the code.

##Custom Functions

We will now define our own function and make use of it as a word template. Type the sample code into your editor and run it.

```C++
#include <iostream>
using namespace std;

void greet(string person){
	cout << "Good night " << person << "." << endl;
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
Good night moon.
Good night red balloon.
Good night comb.
Good night brush.
Good night bowl full of mush.
```

In this new code, notice the second function `greet()` which looks the same but different from `main()`. It has the same curley brackets to hold the code block, but the return type is different. It has the same pair of parentheses, but this time there is something inside. And what about that required return statement? The *void* keyword is used in place of a return type when a function does not return anything. So, since `greet()` has a *void* return type, the compiler will not complain should you leave out the `return`. However, you may still use the return statement to end the execution of the function early. More on this when we get to functions that have multiple lines of code. In the parentheses, you see `string person`. This is an *argument*, an input-value for the function to use. In this case, it's a bit like find-and-replace. Down in `main()`, you see I call `greet()` five times, and each time, I put a different string in quotes between the parentheses. These five lines of code are all ***function calls***. They are telling `greet()` to execute, and passing it the one string argument so it can do its job. That one string argument is made available to `greet()`'s inner code via the argument called `person`. To see the order of how things happen, take a look at Figure 11.

![Figure 11. Function Call Flow](img/function-call.png "Figure 11. Function Call Flow")

The colorful line in Figure 11 is the path drawn by an imaginary playback head that steps over the code as it executes. We start at the blue part and go in through the main entrypoint, then encounter `greet()`, which is where a *jump* happens. As the line turns green, it escapes out of `main()` temporarily so it can go follow along `greet()` for a while. About where the line turns yellow, you see it finished executing the containing code inside `greet()` and does a second jump (the return) this time going back to the previous saved place, where it continues to the next statement. The most obvious advantage we can see in this example is the reduction of complexity from that long `cout` statement to a simple call to `greet()`. If we must call `greet()` five times, having the routine *encapsulated* into a function gives it convenience power. Let's say you wanted to change the greeting from "Good night" to "Show's over ". Rather than updating all the lines of code you cut-and-pasted, you could just edit the one function, and all the uses of the function would change their behavior along with it, in a synchronized way. Furthermore, code can grow to be pretty complex. It helps to break it down into small routines, and use those routines as your own custom building blocks when thinking about how to build the greater software. By using functions, you are liberated from the need to meticulously represent every detail of your system, and therefore a function is one kind of *abstraction* just like abstraction in art. This sort of abstraction is called *encapsulation of complexity* because it's like taking the big complex thing and putting it inside a nice little capsule, making that big complex thing seem smaller and simpler. It's a very powerful idea - not just in code, but in the growth of civilization, and even in the evolution of life on Earth.

##Encapsulation of Complexity

Imagine actor Laurence Fishburne wearing tinted Pince Nez glasses, offering you two options that are pretty complicated to explain. On the one hand, he is willing to help you escape from the evil Matrix so that you may fulfill your destiny as the hacker hero but it involves living life on life's terms and that is potentially painful but whatever, the story must go on and btw, there is a pretty girl. On the other hand, he is also willing to let you forget this all happened, and mysteriously plant you back in your tiny apartment where you can go on living a lie, none the wiser. These two options are explained in the movie *The Matrix* and then the main character is offered the choice in the form of colored pills, as a way to simplify an otherwise wordy film scenario. The two complex choices are encapsulated into a simple analogy that is much easier for movie audiences to swallow. See Figure 12.

![Figure 12. Red Pill and Blue Pill from The Matrix](img/red-blue-pills.png "Figure 12. Red Pill and Blue Pill from The Matrix")

Rather than repeating back the entire complicated situation, Neo (the main character) needed only to swallow one of the pills. Even if it were real medicine, the idea of encapsulating complexity still applies. Most of us do not have the expertise to practice medicine in the most effective way, and so we trust physicians and pharmacologists to create just the right blend of just the right herbs and chemicals. When you swallow a pill, it is like calling that function because you have the advantage of not needing to understand the depths of the pill. You simply trust that the pill will cause an outcome. The same is true with code. Most of the time, a function was written by someone else and if that person is a good developer, you are free to remain blissfully ignorant of their function's inner workings as long as you grasp how to properly call their function. In this way, you are the *higher level* coder, meaning that you simply call the function but you did not write it. Someone who creates a project in OpenFrameworks is sitting on the shoulders of the OpenFrameworks layer. OpenFrameworks sits on the shoulders of the OpenGL Utility Toolkit, which sits on OpenGL itself, and so on. In other words, an OpenFrameworks project is a *higher level* application of C++, a language with a reputation for *lower level* programming. As illustrated in Figure 13, I sometimes run into a problem when I tell people I wrote an interactive piece in C++.

![Figure 13. Standing on Shoulders of Giants](img/shoulders-of-giants.png "Figure 13. Standing on Shoulders of Giants")

There are a few advantages to using C++ over the other options (mostly scripting) for your new media project. The discussion can get quite religious (read: heated) among those who know the details. If you seek to learn C++, then usually it is because you seek faster runtime performance, because C++ has more libraries that you can snap in to your project, or because your mentor is working in that language. An OF project is considered higher level because it is working with a greater encapsulation of complexity, and that is something to be proud of.

## A Brief History

There are many programming languages, each one with its own unique story. Like human languages, they relate in a tangled family tree that eventually leads all the way back to the first computer language by Augusta Ada King, Countess of Lovelace in the 17th century. Languages improve on previous ones for various reasons, such as increasing efficiency/performance, reducing engineering complexity, adding useful features for the programmer, creating new divisions of labor, and in general, making programmers happier. C++, its parent language C, and grandparent language B (BCPL) all come from Bell Laboratories, In fact, the B stands for Bell. Figure 14 shows a picture of Dennis M. Ritchie and Ken Thompson, the creators of C, sitting in front of a PDP-11, the first computer to run Unix. Because C is the next language after B, it uses the next letter in the Roman alphabet.

![Figure 14. Ken Thompson(sitting) and Dennis Richie (standing) in front of a PDP-11, circa 1972](img/kd14.jpg "Figure 14. Ken Thompson(sitting) and Dennis Richie (standing) in front of a PDP-11, circa 1972")

If I ask my father nicely, he will tell stories about his days at Bell Labs in Murray Hill, New Jersey in the late 1960s doing liquid crystal research. Some of his colleagues who did heavier computation work could be seen walking around with shoe boxes filled with punch cards. These punch cards (Figure 15) were difficult to create, share, and maintain (imagine dropping that shoe box). Taking turns running jobs on the GE 600-series mainframes also stifled collaboration because the punch card systems were not multi-user. Perhaps it was a bit like waiting to use the largest CNC machine at TechShop.

![Figure 15. Bell Labs punch card from the mid-1960s, courtesy of Lucent](img/bell1.gif "Figure 15. Bell Labs punch card from the mid-1960s, courtesy of Lucent")


Thompson and Ritchie initiated the development of the Unix operating system in effort to improve these original problems (and provide a useful jig with which they could create their game "Space Travel"). Part of what made Unix attractive was that its heart was written in C, instead of the lower level assembly language - and that made it more portable. The birth of the C language happened along-side the birth of Unix. Hence, the present-day ubiquity of Unix-like OSes may explain the importance of C and its derivative languages.

A decade later, Bjarne Stroustrup created a new strain of the C language in order to update it with a new paradigm called *object oriented programming* which introduces an intermediary container between the function and its program called a *class*. The class system allows a program to do special skateboard tricks that you can read about in the ***OOPS!*** chapter. Since C++ is close enough to C, compiling compatibly with it (if you know what you're doing), C++ rides the popularity of C and Unix. C++ gets its name because putting `++` after something in C means adding 1 to it (or *incrementing* it). C++ is the C language, plus one paradigm. C++ is considered by many to be the most popular programming language of all time.

### Derivative Languages

(My apologies to *The Nails*)

Since establishing the C++ standard, there have been a variety of direct derivative languages - some with the C letter in their name, and some without. *Objective-C* is a decade newer than C++. Intermingled with the NeXT operating system (Figure 16 shows a logo by Paul Rand) and the OpenStep project, Objective-C is most popularly used to develop apps for OS X and iOS. *Java* (20 years newer than C++) is considered a direct derivative of C++. It attempts to remove the "C" and keep only the "++". If you study computer science in university, this language may be one of the first things they teach you, whereas historically, that first language used to be C and C++. *C#* (pronounced C-Sharp) is Microsoft's Java alternative. Originally intended for use in developing .NET apps, you may also use it when developing in Unity - or any platform that uses the Mono project. *C++11* is a newer, more recent version of C++ from 2011 that adds a variety of new features. You may learn more about how it differs from classic C++ in Chapter 15. Finally, *D* is the programming language that takes the next letter in the alphabet after C, also attempting to modernize the language similarly as its contemporaries, and (trivially) did not come from Murray Hill, New Jersey. These different languages are easy to pick up once you grok C++. There are shortcut tutorials to help the C++ programmer understand the other languages and their environments. If you wish to create your own strain of the C++ language, I suggest taking a course on *compiler construction* - for example, the one offered on Coursera by Stanford University's Professor Alex Aiken.

![Figure 16. NeXT Logo by Paul Rand](img/next-logo-paul-rand.jpg "Figure 16. NeXT Logo by Paul Rand")

Although OS X promotes Objective-C and Windows promotes C#, both XCode and Visual Studio will still compile C and C++ along side Linux because the C and C++ language compilers are in higher demand than their proprietary strains. It can be useful to combine code files written in these various languages in order to create a flexible solution that reduces the amount of re-invention you must do. Fundamentally, OpenFrameworks bases its cross-platform portability on the portability of the C++ language. Theoretically, you should be able to write your OpenFrameworks app once, on one platform, then see it compile and run identically in other environments. 

### Conversational Slang

Sometimes I say C, and sometimes I say C++. Since they are closely related, perhaps you can understand how they are almost synonymous. I also leave out the ++ because I am talking about both languages! C++ is mostly a superset of C, so when I talk about the properties of C, I am usually also talking about the properties of C++. To make things worse, the greater slang of C applies to all the C-something languages. Let's say you are a famous code artist and a member of the audience asks you to talk about the programming of your piece. You may have used a combination of C++, C, and Objective-C on Mac OS X to make your OpenFrameworks project happen, but because simplicity is elegant, and because you only have 2 minutes left before they kick you off stage, your answer is shortened - and you say "I wrote it in C". Perhaps later when that audience member buys you a drink, you can unwrap all the C-languages you actually used. This slang is also high context-sensitive. Sometimes preemptively simplifying speech like that is inappropriate when you are speaking to known engineers, developers, and hackers. In that case, saying C when you mean C++ might be construed as fronting!


##Variables

Please enter the following program into ideone and run it.

```C++
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

We understand from a previous lesson that stuff you put between the `<<` operators will get formatted into the `cout` object, and magically end up in the output console. Notice in the last line, I put a bit of light arithmetic (42+1) in-between parentheses, and it evaluated to 43. That is called an *expression*, in the mathematics sense. These three lines of code all say something about the number 42, and so they all contain a literal integer. If I want to change that number, I can do what I know from word processing, and "find-and-replace" the 42 to a new value. Now what if I had 100,000 particles in a 3d world. Some have 42's that need changing, but other 42's that should not be changed? Things can get both heavy and complex when you write code. The most obvious application of *variables* is that they are a very powerful find-and-replace mechanism, but you'll see that variables are useful for more than that. So let's declare an integer at the top of the code and use it in place of the literal 42's.

```C++
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

Now that I am using the variable `answer`, I only need to change that one number in my code, and it will show up in all three sentences as 42. That can be more elegant than find-and-replace. Figure 17 shows the syntax explanation for declaring and initializing a variable on the same line.

![Figure 17. Variable declaration and initialization](img/variable-declaration.png "Figure 17. Variable declaration and initialization")

It is also possible to declare a variable and initialize it on two separate lines. That would look like:

```C++
int answer;
answer = 42;
```

In this case, there is a moment after you declare that variable when its answer may be unpredictable and glitchy because in C (unlike Java), fresh variables are not set to zero for free - you need to do it. Instead, the variable is occupied with what ever old computer memory happens to be sitting there at the time. So, unless you intend to make glitch art, please always initialize your variable to some number upon declaring it, even if that number is zero. 






### Variables have a type.

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum

### Variables are dynamic.

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum

### Variables have a scope.

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum

# this chapter is in-progress. [see outline](outline.md) for upcoming subject matter.
	
	
###bibliography
+ "From the Beginning" - http://snap.nlc.dcccd.edu/learn/selena/history.html
+ "Dennis M. Ritchie" - http://cm.bell-labs.com/who/dmr

