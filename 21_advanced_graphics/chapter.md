# Advanced graphics

*by [Arturo Castro](http://arturocastro.net)*

## 2D, immediate mode vs ofPolyline/ofPath

Traditionally, in frameworks like openFrameworks or processing, the way of drawing things has been something like:

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

Which will draw a red square of side 20 at 20,20. For simple primitives like a rectangle we can use `ofRect()`, but if we want to draw more complex shapes the above method is common. This kind of syntax comes from the openGL equivalent:

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

However, that method is now deprecated. OpenFrameworks actually does something else. This is because while drawing a rectangle like that works in triangle fan mode, if we try to draw something more complex (mostly any concave shape), it won't work. Because OpenGL only knows how to draw triangles, drawing a concave shape needs one more step called tessellation. The tessellation process involves converting a shape into several triangles before sending to the graphics card.
**[BD: I changed around the wording a fair amount in this paragraph. Make sure that my rewording is still true.]**

The GL syntax is now actually deprecated **[BD: Which one, the one you already mentioned?]** and it won't work if you use openGL 3+, in openFrameworks through the programmable renderer, or if you are using openGL ES (Android, iPhone, or ARM Linux in openFrameworks).

The openFrameworks version **[BD: Be explicit about exactly what "version" refers to.]** continues to work but it's ineffective depending on what we are doing. Internally, the openFrameworks version is tessellating the shape, then storing all the triangles in an ofMesh, and then drawing that ofMesh. If you are using openGL 3+ instead of an ofMesh that will be drawn through a VBO using an ofVboMesh, since that's the only possible way of drawing in newer openGL versions.

Tessellation is kind of slow, but also depending on the number of points our shape has it doesn't make much sense to send them to the graphics card every time**[BD: Every frame?]**. The paradigm that newer versions of openGL use is something like: create the shape once, upload it to the graphics card, and then draw it several times **[BD: Is "several times" needed here? It is a bit confusing.]**.

In openFrameworks, the ofPolyline and ofPath classes do this in 2D.

### ofPolyline

ofPolyline, allows us to represent the contour of a shape. The equivalent to the previous example using a polyline would be something like:

```cpp
//ofApp.h

ofPolyline polyline;

//ofApp.cpp

void ofApp::setup(){
    polyline.lineTo(20,20);
    polyline.lineTo(40,20);
    polyline.lineTo(40,40);
    polyline.lineTo(20,40);
    polyline.close();
}

void ofApp::draw(){
    polyline.draw();
}
```

Now, instead of calculating the vertices every frame, we are creating them once in setup and drawing them every frame.

However, an ofPolyline still sends its vertices to the graphics card. ofPolyline is really a class meant to be used to do operations over polylines, like simplifications, smoothing... Also ofPolyline can only draw outlines, not filled shapes. ofPath is recommended to draw shapes.

### ofPath

ofPath is kind of a complex class internally. It's use is simple, and pretty similar to ofPolyline. It follows the same paradigm of creating the shape once and drawing it multiple times:

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

Unlike ofPolyline, ofPath draws filled shapes by default. As you may have noticed by now, ofFill/NoFill doesn't effect ofPolyline or ofPath. That's because they also follow the more modern openGL where most global state values are deprecated. For example if you use openGL 3+, `glColor4f` or `glLineWidth` don't exist anymore. Instead, you can set the color per vertex on every shape. We'll see this later when learning about ofMesh. We could also use a shader to specify a color or line thickness. **[BD: This last sentence is a bit distracting. It is completely true, and relevant, but it breaks the pattern of talking about ofPath and ofPolyline]**

Instead, ofPath allows us to specify if we want to draw it with outline, fill, color, and width per path:

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

This avoids several problems, for example when using global colors, a function needs to store the current color, draw something, and then restore the previous color. Storing the color of a shape in the same object makes it easier to draw several things without having to care about the global color or keeping the global state as it was.

Globals in programming are usually a bad idea, and the way openGL has worked untill now was heavily based on globals. Associating every attribute of a shape to the object that represents it solves several problems.

ofPath packages even more interesting stuff. For example, when we draw a path the first time, ofPath internally calculates it's tessellation and stores it in an ofVboMesh, keeping its vertices in the GPU. If the vertices haven't changed when we draw an ofPath the next time, no uploads are sent to the graphics card. This makes things really fast. **[BD: Is this different than ofPolyline?]**

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

The tessellation only represents the fill of our shape. If the path has no fill, it'll return an empty mesh.

We can also access the outlines of an ofPath as a vector of ofPolylines using `path.getOutline()`

> Advanced note: ofPath works with similar API to other formats and libraries for 2D drawing, like SVG, cairo, or nvidia's path rendering openGL extension. That makes it easier to use it not only to draw to the screen using openGL but also to other formats like vectorial formats like PDF or SVG through the cairo renderer in openFrameworks. The use of the cairo renderer is outside of the scope of this chapter, but the important thing to know is that ofPath stores primitives in their original format as ofPath::Commands. Those commands are things like lineTo, bezierTo... and usually end up decomposed in polylines, and later on tesselated if we want to draw them as filled shapes. That's mainly because openGL doesn't know how to decompose things like a bezier into line segments or tessellate a shape but other formats like an SVG or PDF do. When rendering through the cairo renderer ofPath won't decompose or tessellate shapes. Instead it will just send the original primitives to the renderer which will later scale well no matter how big or small we want to show them. Usually we don't need to be aware of this, since openFrameworks will know internally which kind of representation of ofPath it's better to use. If you are working with openGL only there's a flag that can be activated `path.setMode(ofPath::POLYLINES)` which will make that path override the creation of primitives and work directly with ofPolylines which can be slightly faster in certain cases, mostly if you are creating a really high number of paths and modifying them frequently.


## 3D

The same way that we have objects to create 2D shapes and draw them later, there's similar classes to work with 3D like ofMesh, ofVboMesh, and of3dPrimitive. Before looking at them, let's see a another topic related to how things are done in the newest versions of openGL and learn the openFrameworks equivalent.


### Transformation matrices

If you've worked with processing, openFrameworks or similar frameworks you are probably used to do things like: **[BD: This sentence is almost equivalent to the opening one. Perhaps you could _spice it up_.]**

```cpp
ofTranslate(20,20);
ofRotate(45);
ofRect(20,20,20,20);
```

This draws a square rotated 45 degrees around it's top-left corner. Usually you would enclose that between `ofPush/PopMatrix` so later drawings won't be affected by the transformations that we've just applied.

This comes from the openGL equivalent:

```cpp
glTranslatef(20,20);
glRotatef(45);
ofRect(20,20,20,20);
```

This is also deprecated since openGL 3.  What!? "I can't do use translate/rotate/scale anymore?", you might ask. Well, in openFrameworks you can still use the equivalent `ofTranslate/Rotate/Scale` if you want, but that has a number of problems and that's why they've been deprecated. Let's see why:

We've seen how, when drawing things in most modern versions of openGL, the paradigm is to create the shape once and then draw it several times with transformations. Each call to ofTranslate, Rotate, Scale, or the gl equivalents for that matter, are doing a multiplication of 4x4 matrices. This is not really that slow, unless you are doing it tons of times. But we can avoid it somehow. Instead of doing all of the multiplications of the matrices every frame, we can use an ofMatrix4x4 for each shape we use, do all of that shape's transformations once (or every time the shape moves), and apply them later when we want to draw that frame:

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

Now we are avoiding 1 matrix multiplications every frame. That's not much really, and probably for something like this is just easier to keep using ofTranslate and ofRotate, but you get the idea. If we have hundreds of transformations, storing them only when they change ~~and storing them with the every shape~~ makes things faster.

Not only that, we store the transformations with their shape the same way we stored the color or line width with each path. This avoids confusing global states. Each shape sets it's transformations before drawing.

In openFrameworks, the classes that apply transformations still return the matrix to it's original state so things can work as before.

If you want to know more about how transformation matrices work you should check out the chapter on mathematics. The purpose of this chapter is not so much to show how they work, but rather the newest paradigms in the latest versions of openGL.

In openFrameworks, there's a utility class called ofNode, that allows you to apply complex transformations like set an object to look to another, set a hierarchy of nodes... Again, this is explained in more detail in the mathematics chapter **[BD: I just read that, he doesn't mention ofNode.]**, but when working with 3D it's useful to keep an ofNode along with every mesh that represents it's transformations, so when you draw each mesh, instead of using ofTranslate, rotate, scale you can just apply the transformation of it's node using `node.transformGL()`. This will multiply the current matrix by the one in the node. When you are done **[BD: Done transforming?]** you can use `node.restoreTransformGL()`to go back to the previous state.

The most important idea of this section is that when working with complex transformations, instead of using ofTranslate/Rotate/Scale, it is usually easier to implement an ofNode associated to each mesh or shape that you draw. This is also much easier for readability. For meshes, there's a new class in openFrameworks since 0.8.0 called of3DPrimitive, that internally has an ofVboMesh and an ofNode so you can use this paradigm in an easy way.


### ofCamera

When using openGL, we always have a perspective matrix that affects how 3D objects are projected into the 2d surface, that is the screen, to give appearance of 3D. There's several ways to setup that matrix, but usually we need to know the FOV. The FOV, or field of view, is the angle of the virtual camera that we are looking through. We also need the near and far clip planes. These define the distance at which things begin and end to be drawn. Finally, we need the width and height of the viewport. All of those parameters define a frustrum **[BD: frustum?]**, a 6 sides polyhedra that defines the bounding box of things that will appear in the screen as well as how they'll be projected from 3D into 2D. You can find more information about this in the math chapter. **[BD: Nothing on frustums or 3D-2D projection in math chapter yet.]**

We also have a second matrix, called the model view, which defines the location of the virtual camera through which we view. The modelview**[BD: Is it one word or two?]** matrix is actually the inverse of the matrix that defines the position of the camera, so when we alter it we actually transform the position, rotation and scale of things being drawn. It's this matrix that gets modified when we use ofTranslate, ofRotate and ofScale. Again there's more information about this in the maths chapter.

By default, openFrameworks sets a projection matrix with a FOV of 60, width and height of the screen, and clip planes automatically calculated from the other parameters. It then calculates a model view that "moves the virtual camera" back from 0,0 to a position where the top left of the screen matches with 0,0 and the bottom right with width,height.

In openGL however, by default, those matrices are set to the identity matrix which makes the center of the screen (0,0), the top left corner (1,-1) and the bottom right corner (-1,1). You might have noticed that, in openGL, the y coordinate grows upward while in openFrameworks, it grows downwards. This is to avoid confusion and make it easier to work with images or mouse coordinates in openFrameworks, as they also grow downwards. Other libraries we use also follow that convention. Since 0.8.0 you can change that by calling: `ofSetOrientation(OF_ORIENTATION_DEFAULT,false)` being false a false vertical flip.

So most of the time, especially when working with 2D, these perspective settings are enough. We can draw things and the coordinates will match nicely with the size of the screen in pixels. When working with 3D though, we might need something more complex, like moving the camera along a scene or changing the field of view... That's what ofCamera allows.

ofCamera is actually an ofNode, so you can do with it anything that you might do with an ofNode. For instance, you can set it to look to another object, or you could add it in a hierarchy of nodes so that when its parent moves it moves relatively to its parent position... that mostly defines where the camera is and where it's looking at, the view matrix. **[BD: This last sentence doesn't really make since]**

On top of that, ofCamera allows you to set a perspective matrix. That's the matrix that defines how things will be projected to the 2D screen. To use it, usually we set it up like so:

```cpp
//ofApp.h
ofCamera camera;

// ofApp.cpp

void ofApp::setup(){
    camera.setFov(60);  // this will actually do nothing since 60 is the default
}

void ofApp::draw(){
    camera.begin();
    // draw something
    camera.end();
}
```

When using an ofCamera, 0,0 will be at the center of the screen, and y will grow upwards. With the default settings, the top,left of the screen will be (-w/2,h/2) and the bottom,right (w/2,-h/2).

As we see in the example to draw things as if they were looked at from the camera we call `camera.begin()` draw them and then call `camera.end()` to stop using that camera and go back to the default perspective, or whatever we had setup before. **[BD: What is meant by the "default perspective".]**

While our application runs, we can tweak the camera parameters in update to move it, or even change the fov. We could easily simulate changing the "zoom" of a real camera in this way.


### ofMesh

In openFrameworks, the ofMesh class allows us to represent a 3D model. Internally, it's just a bunch of vectors. Each vector represents one mesh attribute. Those attributes are: vertices, colors, texture coordinates and normals. Each mesh should usually have the same number of each of those attributes unless it's not using one of them in which case it'll be empty.

For example to define a mesh that draws a red square we can do:

```cpp
// ofApp.h

ofMesh mesh;

// ofApp.cpp

void ofApp::setup(){
    mesh.addVertex(ofVec3f(20,20);
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,20);
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,40);
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(20,40);
    mesh.addColor(ofColor::red);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

void ofApp::draw(){
    mesh.draw();
}
```

Every color we add is applied to the vertex in the same position **[BD: the vertex that was last added?]**, that way we can do things like define gradients:


```cpp
// ofApp.h

ofMesh mesh;

// ofApp.cpp

void ofApp::setup(){
    mesh.addVertex(ofVec3f(20,20);
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,20);
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,40);
    mesh.addColor(ofColor::blue);
    mesh.addVertex(ofVec3f(20,40);
    mesh.addColor(ofColor::blue);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

void ofApp::draw(){
    mesh.draw();
}
```

Same goes for texture coordinates and normals. Each of them apply to the vertex in the same position:

```cpp
// ofApp.h

ofMesh mesh;
ofImage img;

// ofApp.cpp

void ofApp::setup(){
    mesh.addVertex(ofVec3f(20,20);
    mesh.addTexCoord(ofVec2f(0,0));
    mesh.addVertex(ofVec3f(40,20);
    mesh.addTexCoord(ofVec2f(20,0));
    mesh.addVertex(ofVec3f(40,40);
    mesh.addTexCoord(ofVec2f(20,20));
    mesh.addVertex(ofVec3f(20,40);
    mesh.addTexCoord(ofVec2f(0,20));
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    img.loadImage("some20x20img.png");
}

void ofApp::draw(){
    img.bind();
    mesh.draw();
    img.unbind();
}
```

**[BD: Perhaps briefly touch on the ofImage.bind() method here]**

we could even combine color and texture tinting the texture with the color we apply to each vertex.

There's more information about how ofMesh works in the ~~openGL chapter~~**[BD: Is this chapter happening?]** and in this [tutorial](http://openframeworks.cc/tutorials/graphics/opengl.html).

### ofVboMesh

ofVboMesh is a simple class that encapsulates a vbo and inherits from ofMesh. That means that we can use it exactly the same as an ofMesh, but when it's drawn, instead of uploading all the vertices every time **[BD: every time we what? draw()?]** to the graphics card, it uploads them once and only uploads them again if they change. Usually when working with openGL it is advised to use ofVboMesh instead of ofMesh.

There's a case where using an ofVboMesh might be slower, and that's if we want to draw an ofVboMesh and then modify and draw it in the same frame again. The problem here is that openGL doesn't really draw things as soon as we tell it to draw. Instead, it stores all the drawing commands and then draws all of them at once and in parallel with the execution of our program. When we try to draw a vbo, modify it's contents and then draw it again in the same frame, openGL would need to really draw the vbo at that exact moment, which means drawing everything else to that point. That would slow things down a lot. If you need to do something like this, make a copy of the vbo and modify the copy instead of the original. In general don't draw, modify and redraw a vbo in the same frame:

```cpp
// ofApp.h

ofVboMesh mesh;

// ofApp.cpp

void ofApp::setup(){
    mesh.addVertex(ofVec3f(20,20);
    mesh.addVertex(ofVec3f(40,20);
    mesh.addVertex(ofVec3f(40,40);
    mesh.addVertex(ofVec3f(20,40);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

void ofApp::draw(){
    mesh.draw();
    mesh.getVertices()[1].x+=0.1;
    mesh.draw(); // slow!!
}
```

instead do:


```cpp
// ofApp.h

ofVboMesh mesh;
ofVboMesh mesh2;

// ofApp.cpp

void ofApp::setup(){
    mesh.addVertex(ofVec3f(20,20);
    mesh.addVertex(ofVec3f(40,20);
    mesh.addVertex(ofVec3f(40,40);
    mesh.addVertex(ofVec3f(20,40);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh2 = mesh;
}

void ofApp::update(){
    mesh.getVertices()[1].x+=0.1;
    mesh2.getVertices()[1].x=mesh.getVertices()[1].x + 0.1;
}

void ofApp::draw(){
    mesh.draw();
    mesh2.draw(); // fast!!
}
```

You can find more information about advanced uses of ofVboMesh and vbo's in the openGL chapter**[BD: Again, I'm not sure that there is an openGL chapter anymore :( ]**.


### of3dPrimitive

As we've mentioned before, of3DPrimitive is a helper class that encapsulates an ofVboMesh and inherits from ofNode. You can call any method you would call on an ofNode, add it to a node hierarchy... And when you call `draw` on it **[BD: the primitive?]** it'll draw the mesh it contains as its applying the transformation defined by it's node.

There's several predefined 3D primitives, like `ofPlanePrimitive`, `ofSpherePrimitive`, `ofIcoSpherePrimitive` or `ofCylinderPrimitive` which know about the particulars of the geometry of the mesh they contain. This makes it easy to apply textures to it or change the resolution of the mesh...

Or you can create your own using `of3DPrimitive` directly:

```cpp
// ofApp.h

of3DPrimitive primitive;

// ofApp.cpp

void ofApp::setup(){
    primitive.getMesh().addVertex(ofVec3f(20,20);
    primitive.getMesh().addVertex(ofVec3f(40,20);
    primitive.getMesh().addVertex(ofVec3f(40,40);
    primitive.getMesh().addVertex(ofVec3f(20,40);
    primitive.getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

void ofApp::update(){
    primitive.move(ofVec3f(10,0,0));
}

void ofApp::draw(){
    primitive.draw();
}
```

>Note: Don't use of3DPrimitive for simple primitives like the one above. Calculating the transformations of an ofNode is kind of expensive in terms of cpu usage. For primitives with lots of vertices it's usually ok, but for something like the previous example it is usually just faster to recalculate all the points in their new position using an ofVboMesh

**[BD: Because the above example isn't actually that practical, how about you use an example where it actually makes more since to use a of3DPrimitive]**


<em style="font-size:0.8em; text-align:center; display:block;">This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.</em>

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>
