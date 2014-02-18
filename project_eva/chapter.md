# Case Study in the Making: Choreographies for Humans and Stars ** FAR FROM READY #

Permanent? outdoor interactive installation developed by **daily tous les jours** for the Planetarium in Montreal, 2013. 
Chapter by Eva Schindling, Pierre Thirion

----------

# Project Overview #

## The Abstract ##
**Choreographies for Humans and Stars** is a permanent outdoor installation hosted at Montreal's Planetarium. The interactive projection on the building's facade invites passers-by to a series of impromptu performances inspired by the different mechanics of planets and stars. Exploring both dance and astronomy, participants use their bodies to understand celestial dynamics like eclipses, forces of attraction and combustion. Tracked by a camera system, the movements across the dance stage directly control the projected animations. 

## Call, Competition and Commission ##
The project started out as an official call by the City of Montreal. For the opening of the new Planetarium the city wanted to commission their first digital artwork. 

Official brief? Possibly budget info?

We passed two/three selection rounds and finally were commissioned by Espace Pour La Vie end of 2012? **[get more details]** 

## Timeline, wished-for and realistic ##
From first brainstorms to final hand-over of the project it took X months? When you work with that many players (the city!, the planetarium, industrial designers..), your first and second attempt at a project timeline is bound to fail. Our first ambitious goal was to get it all done by November 2013, with the main intention to avoid all the snow and coldness that comes along with Montreal's winter season. Naturally we slipped right past that goal, and had our big opening midst lots of snow mid January, with temperatures ranging between -15 to -25. 

- 1st selection round, x competitors
- 2nd selection round, 3 competitors
- official commission
- ideation
- interaction scenario
- content animation workshops
- tech sourcing (Aug/Sept)
- production software (Aug-Jan)
- camera installation and calibration on site (SEPT)
- installation, testing
- opening
- maintenance
- tech hand-over

**[find those dates and durations]**

## Everyone involved ##

Credit lists quickly grow long. The internal DTLJ team includes Mouna and Melissa being the main artists with the vision, Eva handling software, Pierre being heavily involved with visual identity and video production, Michael handling the LEDs in the outdoor furniture. The list of external collaborators include a producer (Nicolas), a technical director (Frederic), a software engineer (Emmanuel), a film animator (Patrick), a choreographer (Dana), an industrial design studio (Dikini), a graphic designer (Jacinthe), a beton workshop (M3Beton), ... 


----------


# The big Ideation process #

**[This section still needs a lot]**
Where did the ideas come from? And how many ideation stages did we go through? ...

## Choreographers ##
Working with a choreographers. Using their bodies, participants come to understand celestial dynamics together. 

Interaction scenarios, testing sessions. ...

## The narrative ##
The sequential structure. 

## Producing video content ##
The video content was created using simple analog animation techniques.

- Shooting stars animation...
- Starry skies...
- light painting animation of revolving planets...

Since the project will be permanently installed, we involved locals in the making of these images, aiming to create a sense of ownership within the community that will be living next to the project for many years to come. ...

## The dance stage ##

While camera and projector stay intangible, it was important to give the project a physical presence. Who's main purpose was to define the active tracking zone for the participants, but who would also present a different version of the project during the daylight hours, when the projection was off. ...

----------


# Finding the Technical Solutions #

## The site and its challenges ##
Outdoor installation, all weather conditions, run after sunset, every night for at least the next 3 years. 

### Put the Projector with the animals ###
The projection surface being a 20 meter high building covered with shiny tiles, we needed a high-lumen projector, which naturally ate almost half the budget. To save further costs, and for protection and easy-access reasons the projector was placed in the neighbouring building - the Montreal biodome - which has a large glass facade facing the planetarium. A glass replacement window needed to be cut out of the slightly tinted facade of the biodome. A simple $15 heater makes sure our window is be kept clear of ice and condensation. Additionally we negotiated with the landscape architects of the site to be able to trim any trees that were likely to grow into our projection cone during the next 3 years.

Distance between projector and projection surface: 87m. 

Projection size: 13.5m times 19m.  

### Camera style and placement ###
In an ideal camera tracking scenario you have a controlled indoor environment that gives you a clean top-down camera view and lets you create the lighting and background design of your choice. Our site at the planetarium is outdoors and therefore subject to all possible weather conditions. The scene can change from dark (cement floor) to white (snow), and often gets temporarily lit up by the flashlights of a driving-by car. 

There's the obvious fact that it's rather dark at night, and that our camera system needed to live through -40 degrees in the winter. The distance between any possible camera location and the dance stage being around 20 meters, made it impossible to consider Kinects 3d sensing abilities. 

So when first brainstorming technical solutions for tracking, our list included thermal imaging cameras (\$\$ and low-res), laser range finders (\$\$ and limited to one dimension), stereoscopic 3d cameras (), and cameras placed at 2 different angles to allow for dynamic mapping of two perspectives into one (double the fun). 

Finally we settled on going with one single camera, with high sensitivity that would make use of the few surrounding lights, and a tracking solution that could convert the 2d information into 3 dimensions.

Strict architecture codes prohibited us from being able to place the camera on top or somewhere along the surface of the planetarium building. After long negotiations we were limited to placing our camera at a quite low angle slightly to the left of the projection site. > more overlapping > need to rotate perspective


### Network negotiations ###
After calculating our camera's bandwidth requirements (resolution 800x600px * framerate 28fps * color depth 8bit * compression raw = xxx bit/sec) we discovered that the local network wouldn't allow us to send the camera data directly to the projector site. We had to place one computer in close proximity to the camera, and another computer next to the projector. 

The network being part of the city network, was heavily controlled, subject to 15min timeout internet access. A couple of forms later we had a LAN connection between our two computers. VPN access for remote maintenance and remote updates took about 2-3 months, and we are still in negotiation to get SSH access. Cities protect their networks.

## Hardware Choices ##

### Camera and lens ###
We picked Basler's [Scout scA1600-28gm](http://www.baslerweb.com/products/scout.html?model=130) camera for it's high sensitivity. Going black&white eliminates any color focused tracking, but gives you even more sensitivity for low-light situations. High-res camera, gigabit ethernet. lens [Fuji HF12.5SA-1](https://www.fujifilmusa.com/products/optical_devices/machine-vision/2-3-5/hf125sa-1/) ...

Surveillance style, we packed the camera into an ugly weatherproof housing (#HEB26D0A000B), together with a power supply, a heater and a fan system.

### Computer hardware and OS ###
Computer #1: Intel Core i5 3570K 3.40G/6M/S1155 with 8GB ram

Computer #2: Intel Core i7 3770K 3.40G/8M/S1155 with 16GB ram and an Asus GTX680 graphics card. 

Both computer run Ubuntu 12.04 LTS 

### Projector ###
Projector model: Barco HDX-W20, resolution of 1920*1200px (16:10) used in horizontal view. 

## System ##
diagram

## Choice of tracking software ##
For the tracking software we found a collaborator in Emmanuel Durand, part of the research lab at [Society for Arts and Technologies](http://www.sat.qc.ca/ "SAT"). Emmanuel had developed [blobserver](https://github.com/paperManu/blobserver "blobserver on github") - a opencv based software to implement various realtime detection algorithms - and was looking for first test projects. For the project he further developed and adapted blobserver to our needs. Blobserver is designed to take in multiple camera or video sources, detect entities and then report its findings via OSC. Further configuration and communication of blobserver can be done through OSC as well, which allows for easy integration into any OSC-friendly software. 

### Method of Tracking ###
To track participants on our performance stage we used blobserver's HOG detector - [histogram of oriented gradients](http://en.wikipedia.org/wiki/Histogram_of_oriented_gradients) - which learns from a database of human shapes to detect human outlines. The HOG detection is processing optimized by limiting its areas of interest to areas with recent movements, detected by background subtraction. 

First tracking tests were done based on publicly available databases of human shapes, but to get better results for our environment (camera view at slight top-down angle, specific background, ..) we had to create our own database, and compute our own model:

1. collect images from site
2. crop images to human shapes with blobcrop
3. produce model with blobtrainer
4. run blobserver with model

### Tracking challenges ###
finetuning of tracking (challenges: weather, perspective, kids, overlapping)

reducing our expectations (tracking gestures, people rotating, specific movements) to the bare minimum (presence and location)

Even though the camera could output 1628 x 1236px we went with a binning value of 2 and therefore a resolution of 800 x 600px. To achieve better sensitivity. 

[Screenshot camera view with tracking windows]


## Choice of visualization software ##
This project provided the perfect excuse for me to jump back into openFrameworks. Previous company projects relying on computation have mostly lived in the realm of music (max/MSP) or the web (python, node.js). On the rare occasion that visuals were involved, the timeline were mostly too short for extensive development and the pragmatic choice of software then was (processing). Not that openFrameworks can't dabble into audio or the web, but the pull of the timeline usually pollutes the neverending prototype and simply turns it into production software. 

This project, with its demands of high-res live video animations, provided a decent time frame allowing for proper project development and gave me all the right reasons to go back to openFrameworks (its been a while). Helpful at this stage was as well that most prototyping of content and interaction happened with non-interactive videos produced with video editing software. Any truly interactive prototype had to wait for all the pieces (camera placement on site, tracking success, etc.) to come together.  

Choosing openFrameworks as the programming environments can be blamed on C++'s fast processing speed, the existence of multiple addons, the range of projects out there that deal with video and animation content and present their code out there on github, and mostly its avid and rarely not-helpful community forum. A main reason was also openFrameworks cross-platform ability, as i am personally on a Windows 7 laptop, while the office is reigned by Macs, and the decision had been made to give it a try with Linux computers for the installation. So being able to jump between the different operating systems while still developing the same software, naturally a plus. 


## Additional software used ##
processing, gstreamer, switcher, oscdump, ..


----------


# Developing the Visualization Software #

### development setup ###
The openFrameworks linux install (# ) is build for codeblocks, yet as i have come to like the code editor Sublime for its lightweightness and simplicity, i chose to program in Sublime and then compile by simply running the `make` command inside the terminal. (Also useful: Run software from terminal with `/bin/exampleApp`). On my laptop (win7) i code with Sublime, but compile and run the software from within Codeblocks. 

Besides its purpose of providing a history of the code, i used this project's github repository mainly to push code between computers. And to search my own code history, as i still rarely dare to roll back and forth within the git repository itself. 

My usual programming setup includes an open browser with tabs open on the openFrameworks forum, the openFrameworks documentation page, and github (to search specific function uses). 

### externals used ###

 - **ofEvents** ... for controlling the animation
 - **ofxOsc** ... for communication btw. computers
 - **ofxOpenCv** ... for running a perspective transformation
 - **ofxGui** ... to build a GUI

## input tracking data ##
- OSC communication: dealing with fsp diff, dummies for testing
- blobs data structure with std::map, updating 
- perspective transformation

**[reference network/OSC chapter]**

## implementing video content ##
- content preparation (quest for right format, tools used) gstreamer green line
- dynamic video elements (ofVideoPlayer, ofPtr)
- preloading versus dynamic loading

**[i am sure there's someone to reference about video]**

## sequential structure ##
- structure with scenes, segments
- transitioning with timers and/or events

## event-driven animation ##
blob events (onEnterStage, onLost, onFreeze, onSteady, ..) driving video content

**[reference chapter with events]**

## finetuning interaction ##
- calibration of final behavior (importance of GUI)
- screenshot of debug GUI


----------


# Fail-safes and dirty fixes #
worst case scenarios and the messiness of the real-world

## first: keep your app alive ##
segmentation faults: how to keep your app alive nevertheless
supervise, launchd, lingon, ...

## second: framerate cheats ##
- variables FPS: update animation with fps-dependent value, ofGetLastFrameTime() 
- memory leaks, dropping FPS: regularly terminate app, seamless transitions
- put limits on your number of objects (blobs, video elements)

## always: investigate ##
- ofLogToFile with dynamic date
- monitor process times for operations to find the bottleneck
- try + catch: not everything throws exceptions!

## finally: optimize ##
- replace video with opengl-animation
- what to implement with threads?


