
#openFrameworks project structure and setup

So, after you read a bit about C++ on chapter 2, let's get into openFrameworks, OF from now on. Chapter 1 talks about OF in very abstract and conceptual manner, which are really useful to understand in order to understand the decisions made to design the OF environment. So read it if you haven't.

I have found very useful to explain OF making analogies to cooking. Coding and cooking have a lot of things in common, and as almost everyone has experienced cooking it makes a lot of sense to me to use a cooking analogies/naming style.

##Welcome to your new kitchen##

###First things first###
You need to download the OF version and the IDE (acronym for Integrated Development Environment) that suit your platform. The IDE is a piece of software that will let you write, compile, run and debug the code you write. It is "Integrated" because this software uses other pieces of software to do each of the mentioned tasks, which you can also use in a separate way without using the IDE, but the IDE will make your programming life so much easier.

Go to [www.openframeworks.cc/downloads](www.openframeworks.cc/downloads "Download openFrameworks!") and download the version that you need. By the side of each available version you will find a link to the where to download the needed IDE and how to make it run.
So once you've done this and tested that installation went fine, by opening any example, compiling and running it without problems we are ready to continue.

###OF structure###

If you go into the uncompressed OF version that you downloaded you will find several folders, with several others inside, so let's take a look at what these are and how to use them.
We will call the OF root folder the one that your uncompressed OF download created, that should contain, at least, the following:

- addons
- apps
- examples
- libs
- other
- projectGenerator_osx
- scripts
####Addons####
Addons folder will contain the included "core" addons. Addons are extra pieces of code that extend OF's functionalities, allowing you to do almost anything with OF. Addons are usually written by third parties that have shared these. The "core" addons, the ones already included in your OF download, are addons that are used so frequently that it has been decided to include them as part of the oficial OF download. These are coded and mantained by the OF's core developers. 
These included addons are the following:


###IDE:###
- What is it for.
- Different brands, almost the same thing.
- Intro to xCode, VS, C::B, ¿maybe Eclipse?
	- The main goal here would be to establish the similarities between all IDEs and explain where are the fundamental options needed to compile and solve common errors (missing include paths, linker errors).
	- Adding files to the IDE, in particular adding addons (should we mention, as a sidenote Adam's xCode OF plugin?). How it must be done in each IDE.

- The NO-IDE IDE. Using the terminal and makefiles.
	- Possible scenarios where this is useful (rPI, remote compiling via SSH)
	- How to deal with it. Installing the needed stuff to make it work (make, etc)
	- How to use OF's make files. 
	- Using addons

###The OF Pantry:###

- What stuff is in here.
- Its usefulness. 
- How it is arranged/ordered.
- How to use it. Probably mention al the available "things", link to another chapter where some explanation of use is available. Add some explanation for the ones that are not covered anywhere else in the book.

###The recipes; .h and .cpp files:###
- Make a straight analogy between these files and recipes, the bill of materials, needed tools and instructions-steps.
- Why 2 files instead of just one.
- How these files are structured (in OF)
- Peeking at others files, OF's files in search for some help.
- Some basic OOP, related to the idea of making a lot of the same recipe, how to deal with it. Link to the other chapters where OOP is covered.

##h and cpp files, some OOP and the IDE##
