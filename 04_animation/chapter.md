The word animation is a mideval term stemming from the Latin animare, which means ‘instill with life’.  In modern terms, it's used to describe the process of creating movement from still, sequential images.  Early creators of animation used spinning discs (phenakistoscope) and cylinders (zoetrope) with successive frames to create the illusion of a smooth movement from persistance of vision.   In modern times, we're quite used to other techniques such as flip books and cinmetic techniques like stop motion.  Increasingly, artist have been using computational techniques to create animtion -- using code to "bring life" to objects on the screen over successive frames.  This chapter is going to look at these techniques and specifically, try to address a central question, "how can we create compelling, organic and absurd movement through code"

As a side note, I studied fine arts, painting and printmaking, and it was accidental that I started using computers.  The moment that I saw how you could write code to move something across the screen, even as simple as silly rectangle, I was hooked.  I began during the first dot com era working with flash / actionscript and lingo / director and have never looked back. 

The first point to make about animation is that it's based on successive still frame.  In openFrameworks we have a certain loop cycle that's based roughly on game programming paradigms.  It goes like: 

- setup()
- update()
- draw()
- update() 
- draw()
- ....

setup gets called once and update / draw get called repeatedly.  Sometimes people ask why two functions the called repeatedly? Especially if they are used to processing, which has only a setup and a draw command. There are a few reasons.  The first is that drawing in opengl is asynchronous, meaning there's a chance, when you send  drawing code to the computer, that it can return execution back to your program so that it can do other operations while it draws.  The second is that it's generally very practical to have your drawing code seperated from your non drawing code.  If you need to quickly debug something -- say for example your code is running slow -- you can comment out the draw function and just leave the update running.  It's seperating out the update of the world from the presentation and it can often help clean up / organize your code.  Mentally think about it like an stop frame animator working with an overhead camera who might reposition objects while the camera is not taking a picture then snap a photograph the moment things are ready.  In the update function you would be moving things around and in the draw function you draw things exactly as they are at that moment. 

The second point to make about animation is that it requieres variables.  A variable is a placeholder for a value, which means that you can put the value in and you can also get the value out.  Variable are essential for animation since they "hold" value from frame to frame.  Ie, if you put a value in to a variable in the setup function or update function, you can also get it out from memory in the draw function.  Take this example: 

**[note: simple animation example here]**

The third point to make about OF and animation is frame rate.  
