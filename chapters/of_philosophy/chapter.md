# Philosophy

*by [Zach Lieberman](http://thesystemis.com)*

The endeavour of openFrameworks is guided by a number of goals: it should be collaborative, usable and simple, consistent and intuitive, cross-platform, powerful, and extensible. It is also driven by a "do it with others" (DIWO) philosophy.

### Collaborative

The development of openFrameworks is collaborative. It thrives on the contributions of many people who engage in frequent discussion, and collaborate on addons and projects. We encourage people to make openFrameworks their own and contribute to the ecosystem.

We use git, a distributed versioning system, which means that people can branch, experiment, and make suggestions. If you look at the network diagram on [GitHub](https://github.com/openframeworks/openFrameworks "link to the GitHub repository of openFrameworks"), it looks like some alien diagram, full of weaving branches, code pulling apart and coming together. There's a huge community all over the world working on the core code: fixing bugs, submitting pull requests, and shaping the tool the way they want to see it. It's a world wide project and it's common to wake up in the USA to an inbox full of pull requests and issues emails from coders in Asia and Europe. Over 70 people have contributed to the openFrameworks core directly, and hundreds of people have forked the code or contributed in other ways.

### Simplicity

openFrameworks tries to balance usability and simplicity. The earliest versions of openFrameworks used the core as a tool for teaching C++ and [OpenGL](https://en.wikipedia.org/wiki/OpenGL "wikipedia article on OpenGL"), but over time the examples have become the best way to learn while the core takes advantage of more advanced features. In exchange, we've created many more examples that come with openFrameworks, with the goal of trying to make simple, hackable starting points for experimentation.

We want openFrameworks to be as simple as possible, especially for folks coming from other languages and environments. C++ is a "large" language, large in the sense that you can write very different types of C++ code. If you go to the bookstore, you'll see hundreds of C++ books. We want to create a library where you don't need to be an expert, where at most you might need a book or two, but that the patterns, approaches and style of the code is simple and intuitive. We were especially interested in achieving a sort of parity with [Processing](http://www.processing.org/ "processing language and IDE website"), where many of the functions are similar, allowing easier movement from one framework to another.

### Consistent and Intuitive

openFrameworks is consistent and intuitive: it should operate on the principle of least surprise, so that what you learn about one part of openFrameworks can be applied to other parts of it. Beginners can use openFrameworks to learn about common programming patterns, and advanced users will be able to apply their experience from other languages and toolkits.

Students first is the motto. A lot of the thinking guiding openFrameworks is: what would I have liked in a tool 5 or 10 years ago? We want the patterns of coding to be simple and to make it as easy as possible to type. This means having self-explanatory function names like "play" and "stop" for video players, and variable names that are intuitive. We have lots of discussions about intuition, driven by a desire to make the code as straightforward as possible. You should learn by typing, autocomplete should be helpful, etc.

### Cross-platform

openFrameworks is a cross-platform toolkit. openFrameworks supports as many development environments and operating systems as possible. When you download openFrameworks, you can pick your platform and development environment of choice, and have projects and examples ready to learn from and play with. Difficult-to-port code is kept out of the core, and kept in addons instead.

openFrameworks is designed to work on a multitude of platforms: OS X, Windows, Linux, iOS, Android, embedded ARM Linux systems, as well as experimental platforms such as BlackBerry PlayBook. openFrameworks developers have devised some clever ways of interfacing with other languages, such as Java in the case of Android, or Objective-C in the case of iOS.

The joy of a cross-platform library is that it's easy to port your ideas from platform to platform. You can sketch on your laptop then immediately run it on your phone. It allows your ideas to come first, without worrying about the grunt work in making something work across platforms.

### Powerful

openFrameworks is powerful: it allows you to leverage advanced libraries like [OpenCV](http://opencv.org/ "OpenCV, a library for (real-time) computer vision"), use hardware like your graphics card efficiently, and connect peripherals like cameras and other devices.

We chose C++ because it's a fairly low level language but can still be programmed in a high level way. Because C++ is an extension of the older C programming language, it's possible to write very low level, oldschool C code or higher level C++ code. In openFrameworks, we try to harness both approaches and present simple, clear, yet powerful ways of working with code. Using C++ also makes it easier to interface to the many libraries that have been written in C and C++ without needing to rely on a wrapper for another language.

openFrameworks essentially wraps other libraries such as OpenGL, [Cairo](http://cairographics.org/ "Cairo, a vector graphics library"), [FreeType](http://freetype.org/ "FreeType, a software library to render fonts"), [FreeImage](http://freeimage.sourceforge.net/ "FreeImage, a library to work with common computer graphic image formats"), and OpenCV. You can think of openFrameworks as a layer of code between user code (the code you will write) and these libraries. The libraries have different styles, idioms, approaches, etc. and our job is to wrap them in a way which makes them more consistent and intuitive.

### Extensible

openFrameworks is extensible. When you find something missing from openFrameworks it's easy to create addons that extend it. The core addons for openFrameworks generally wrap libraries rather than solving problems in novel ways. When openFrameworks wraps libraries, the libraries are left exposed for further hacking.

One mental image of openFrameworks is a scaffolding, or shoulders to stand on, while building what you want. One thing that helps keep the core light is that rather than try to include everything we can, openFrameworks has an "addon" system that allows for additional code, libraries, and approaches to be shared between users and woven into projects as necessary.

An openFrameworks addon can be a snippet of code, or it might wrap much more complex libraries such as OpenNI, Tesseract, or Box2d. Addon names usually begin with the prefix "ofx", allowing you to easily see the difference between "core" code and non core code. In addition, we include "core addons", addons that we think people will probably want to use, such as ofxOpenCv, but aren't essential for every project.

We try to organize and support the community developing addons through the [http://ofxaddons.com](http://ofxaddons.com "ofxaddons, a collection of oF addons") site, which automatically collects addons from GitHub by looking for repos that contain the term "ofx" in the title. Right now there are more than 1,500 addons.

### Do it with others (DIWO)

The driving philosophy behind openFrameworks is "do it with others" (DIWO). We love do it yourself (DIY) culture, which has been heavily promoted and facilitated by the rise of tutorial website like Instructables or Make. But we're also excited about the idea of "making socially" ("with others"). We practice DIWO through workshops, developer conferences, hackathons/labs, knitting circles and meetups in person, and online in the form of mailing lists, forum posts, and so on. We even have a gang sign. Because if you have a gang, you have to have a gang sign. The most important thing we want to stress is that you are not alone, that there's a great group of people out there learning, teaching, hacking, making and exploring the creative side of code.

