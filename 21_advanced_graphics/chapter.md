# Advanced graphics

*by [Arturo Castro](http://arturocastro.net)*

*<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.*

## 2D, immediate mode vs ofPolyline/ofPath

Traditionally in frameworks like openFrameworks or processing the way of drawing things have been something like:

```cpp
void ofApp::draw(){
    ofFill();
    ofSetColor(255,0,0);
    ofBeginShape();
    ofVertex(20,20);
    ofVertex(40,20);
    ofVertex(40,40);
    ofVertex(20,40);
    ofEndShape(true);
}
```

Which will draw a red square of side 20 at 20,20. Now, for simple primitives as a rectangle we can use `ofRect()` but if we want to draw more complex shapes that's been the usual way to do it. This kind of syntax comes from thw equivalent in openGL:

```cpp
void ofApp::draw(){
    glColor4f(1.0,0.0,0.0,1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex(20,20);
    glVertex(40,20);
    glVertex(40,40);
    glVertex(20,40);
    glEnd();
}
```

Which is now deprecated, the openFrameworks actually does something else, drawing a rectangle like that works in triangle fan mode but if we try to draw something more complex, mostly any concave shape, it won't work. OpenGL only knows how to draw triangles drawing a concave shape needs one more step, called tesselation, which means converting that shape into several triangles and sending that to the graphics card.

The GL syntax is now actually deprecated and it won't work if you use openGL 3+, in openFrameworks through the programmable renderer, or if you are using openGL ES (android, iphone or arm linux in openFrameworks).

The openFrameworks version continues to work but it's somehow ineffective depending on what we are doing. internally the openFrameworks version is tessellating the shape, then storing all the triangles in an ofMesh and then drawing that ofMesh. If you are using openGL 3+ instead of an ofMesh that will be drawn through a VBO using an ofVboMesh, since that's the only possible way of drawing in newest openGL versions.

Tessellation is kind of slow, but also depending on the number of points our shape has it doesn't make much sense to send them every time to the graphics card. The paradigm that newest versions of openGL use, is something like create the shape once, upload it to the graphics card and draw it several times. 

In openFrameworks, the classes ofPolyline and ofPath do that in 2D:

### ofPolyline

ofPolyline, allows us to represent the contour of a shape, the equivalent to the previous example using a polyline would be something like

```cpp
//ofApp.h

ofPolyline polyline;

//ofApp.cpp

void ofApp::setup(){
    polyline.moveTo(20,20);
    polyline.lineTo(40,20);
    polyline.lineTo(40,40);
    polyline.lineTo(20,40);
    polyline.close();
}

void ofApp::draw(){
    polyline.draw();
}
```

Now instead of calculating the vertices every frame, we are creating them once in setup and drawing them every frame. 

An ofPolyline though, still sends the vertices to the graphics card. ofPolyline is really a class meant to be used to do operations over polylines like simplifications, smoothing... Also ofPolyline can only draw outlines not filled shapes so to actually draw shapes it's recomended to use ofPath.

### ofPath

ofPath is kind of a complex class, not in it use but in that it does a lot of things internally. It's use is pretty similar to ofPolyline and follows the same paradigm of create the shape once, draw multiple times:

```cpp
//ofApp.h

ofPath path;

//ofApp.cpp

void ofApp::setup(){
    path.moveTo(20,20);
    path.lineTo(40,20);
    path.lineTo(40,40);
    path.lineTo(20,40);
    path.close();
}

void ofApp::draw(){
    path.draw();
}
```

Opposed to ofPolyline, ofPath by default draws filled shapes. As you've probably noticed by now, ofFill/NoFill don't affect ofPolyline or ofPath. That's because they also follow the same as in more modern openGL where most global state values are deprecated, for example if you use openGL 3+ `glColor4f` or `glLineWidth` don't exist anymore instead you can set the color per vertex on every shape, which we'll see later when learning about ofMesh or we can use a shader to specify a the color or create thick lines.

Instead ofPath allows to specify per path if we want to draw it with outline, fill or both, the color of the fill and outline, the width of the outline...:

```cpp
//ofApp.h

ofPath path;

//ofApp.cpp

void ofApp::setup(){
    path.moveTo(20,20);
    path.lineTo(40,20);
    path.lineTo(40,40);
    path.lineTo(20,40);
    path.close();
    path.setStrokeColor(ofColor::blue);
    path.setFillColor(ofColor::red);
    path.setFilled(true);
    path.setStrokeWidth(2);
}

void ofApp::draw(){
    path.draw();
}
```

This avoids several problems, for example when using global colors a function needs to store the current color, draw something and then restore the previous color. Storing the color of a shape in the same object makes it easier to draw several things without having to care about the global color or keeping the global state as it was.

Globals in programming are usually a bad idea, and the way openGL has worked till now was heavily based on globals, associating every attribute of a shape to the object that represents it solves several problems.

Apart from this ofPath does some interesting stuff. For example, when we draw a path the first time, ofPath internally it's calculating it's tessellation and storing it in an ofVboMesh, which stores the vertices in the GPU. So when we draw an ofPath the next times, if it hasn't changed, there's no uploads to the graphics card making things really fast.

You can actually access that tessellation using:

```cpp
//ofApp.h

ofPath path;
ofVboMesh tessellation;

//ofApp.cpp

void ofApp::setup(){
    path.moveTo(20,20);
    path.lineTo(40,20);
    path.lineTo(40,40);
    path.lineTo(20,40);
    path.close();
    path.setStrokeColor(ofColor::blue);
    path.setFillColor(ofColor::red);
    path.setFilled(true);
    path.setStrokeWidth(2);
    tessellation = path.getTessellation();
}

void ofApp::draw(){
    tessellation.drawWireframe();
}
```

The tessellation only represents the fill of our shape, if the path has no fill, it'll return an empty mesh. 

We can also access the outlines as a vector of polylines using `path.getOutline()`

> Advanced note: ofPath works with similar API to other formats and libraries for 2D drawing, like SVG, cairo, or nvidia's path rendering openGL extension. That makes it easier to use it not only to draw to the screen using openGL but also to other formats like vectorial formats like PDF or SVG through the cairo renderer in openFrameworks. The use of the cairo renderer is outside of the score of this chapter but the important thing is that ofPath stores primitives in their original format as ofPath::Commands. Those commands are things like lineTo, bezierTo... and usually end up decomposed in polylines and later on tesselated if we want to draw them as filled shapes. That's mainly cause openGL doens't know how to decompose things like a bezier into line segments or tessellate a shape, but other formats like an SVG or PDF do so when rendering through the cairo renderer ofPath won't decompose or tessellate shapes and will just send the original primitives to the renderer which will later scale well no matter how big or small we want to show them. Usually we don't need to be aware of this, since openFrameworks will know internally which kind of representation of ofPath it's better to use. If you are working with openGL only there's a flag that can be activated `path.setMode(ofPath::POLYLINES)` which will make that path override the creation of primitives and work directly with ofPolylines which can be slightly faster in certain cases, mostly if you are creating a really high number of paths and modifying them every frame



## 3D

The same way we have objects to create 2D shapes and draw them later, there's similar classes to work with 3D like ofMesh, ofVboMesh and of3dPrimitive. Before seeing them let's see a bit another topic related to how things are done in the newest versions of openGL and what's the openFrameworks equivalent


### Transformation matrices

If you've worked with processing, openFrameworks or similar frameworks you are probably used to do things like:

```cpp
ofTranslate(20,20);
ofRotate(45);
ofRect(20,20,20,20);
```
    
which draws a square rotated 45 degrees around it's top-left corner. Usually you'll enclose that between `ofPush/PopMatrix` so later drawings won't get affected by the transformations that we've just applied.

This comes from the openGL equivalent:

```cpp
glTranslatef(20,20);
glRotatef(45);
ofRect(20,20,20,20);
```

which is deprecated since openGL 3.  What!? i can't do use translate/rotate/scale anymore? you might ask. Well in openFrameworks you can still use the equivalent `ofTranslate/Rotate/Scale` if you want, but that has a number of problems and that's why they've been deprecated. Let's see why:

The same way that when drawing things we've seen how in most modern versions of openGL the paradigm is create the shape once, draw several times, happens with transformations. Each call to ofTranslate, Rotate, Scale, or the gl equivalents for that matter, are doing a multiplication of 4x4 matrices. This is not really that slow, unless you are doing it tons of times. But we can avoid it somehow. Instead of doing all the multiplications of the matrices every frame we can use an ofMatrix4x4 for each shape we use, do all it's transformations once (or every time the shape moves) and apply them later when we want to draw that frame:

```cpp
//ofApp.h
ofPath path
ofMatrix4x4 m;

//ofApp.cpp
void ofApp::setup(){
    path.moveTo(20,20);
    path.lineTo(40,20);
    path.lineTo(40,40);
    path.lineTo(20,40);
    path.close();
    m.rotate(45);
    m.translate(20,20);
}

void ofApp::draw(){
    ofMultMatrix(m);
    path.draw();
}
```

Now we are avoiding 1 matrix multiplications every frame, that's not much really and probably for something like this is just easier to keep using ofTranslate and ofRotate, but i guess you get the idea, if we have hundreds of transformations, storing them only when they change and storing them with the every shape makes things faster.

Not only that, we store the transformations with their shape, the same way we stored the color or line width with each path, avoiding confusing global states. Eahc shape sets it's transformations before drawing.

In openFrameworks, the classes that apply transformations still return the matrix to it's original state so things can work as before.

If you want to knoe more about how transformation matrices work you should check the chapter on mathematics, the purpose of this chapter is not so much to show how they work but the newest paradigms in the latest versions of openGL

In openFrameworks, there's a utility class called ofNode, that allows to apply complex transformations like set an object to look to another, set a hierarchy of nodes... again this is explained in mode detail in the mathematics chapter, but when working with 3D it's useful to keep an ofNode along with every mesh that represents it's transformations, so when you draw each mesh, instead of using ofTranslate, rotate, scale you can just apply the transformation of it's node using `node.transformGL()` which will mutliply the current matrix by the one in the node. When you are done you can use `node.restoreTransformGL()`to go back to the previous state.

The most important idea of this section is that when working with complex transformations, instead of using ofTranslate/Rotate/Scale is usually easier to implement and what's more important much easier to understand later, to use an ofNode associated to each mesh or shape that you draw. For meshes there's a new class in openFrameworks since 0.8.0 called of3DPrimitive that internally has an ofVboMesh and an ofNode so you can use this paradigm in an easy way.


### ofCamera


### ofMesh


### ofVboMesh


### of3dPrimitive


### Applying simple textures to 3d primitives and ofFbo

