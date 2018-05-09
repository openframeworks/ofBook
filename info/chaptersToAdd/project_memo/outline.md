
# 0. intro
- what this chapter is, and what it isn't.
- what you should know before reading this.
- Not indepth coverage of any one topic, but covering each topic very briefly, to show how many different topics can come together to create an app
- summary of what we will create (Body Paint, Gold, Reincarnation, Depeche Mode Fragile Tension, U2 PUNK), areas we will cover, and how everything fits together

# 1. Video Input
- loading video files (ofVideoPlayer)
- reading live webcam input (ofVideoInput)
- How to write the app in a way to seamlessly switch between taking input from VideoPlayer (i.e. a file) vs Webcam Input (i.e. live)
- OOP / Polymorphism allows ofBaseVideo
- pro tips

# 2. Basic Image Processing + Computer Vision
## Create particle-creation-map:
- frame differencing
- threshold (binary, top, bottom)
- adaptive threshold
- blur, median
- morphology (erode, dilate, open, close)

## Optical flow (to advect fluid simulation)
- blur
- threshold

## Misc
- align input image to desired position in output: image transforms
- pro tips

# 3. Fluid simulation
- non-core addons
- github
- advect fluid with optical flow
- pro tips

# 4. Particles
## Behaviours:
- create with particle-creation-map
- basic dynamics (F=ma, v = u + at)
- vector math (arithmetic, normalising, cross products, dot products etc.)
- gravity, wind, mass, drag, momentum, noisefields, mapping curves, adding variance, sparkles, etc.
- pro tips

## Drawing
- manually (easy way, old fashioned and slow)
- Vertex Array (vs VBO)
- ofMesh
- Vertex Shader?
- pro tips


# 5. Post FX (optional)?
 - fbo
 - fragment shader?
 - pro tips



