
# Intro

- The birth of the render pipeline and a brief history of the GPU
- Explanation of Vertex Shader and Frag shader

# Fragment Shader

- What are they for? How do they work? Comparison with old pixel-by-pixel operations. [References](https://github.com/ofZach/ofDocs/blob/master/chapter7.md)
- First example: all red billboard (+ basic explanation of how to make a QUAD mesh with texCoords)
- Second example: make a grayscale // make a checkerboard using shaders
- Uniforms 
- Third example: using 'uniform float’ to make animated patterns (passing ofGetElipsetime() sin() cos() to make interesting patterns) 
- Fourth example: using ‘uniform vec2’ to get mouse interaction
- Fifth example: using ‘uniform texture2DRect’ to alpha mask and multi texturing (explanation of OF examples)
- Exercise: make simple shaders that emulate basic openCV operations such as: grayscale, brightness, contrast, threshold,  absDiff

# Vertex Shader

- What are they for? How do they work?
- Varings
- Example: cheap DOF passing the alpha value from the vertex shader

# Advanced

- The Programmable-Render on OF
- Differences between openGL2, openGL ES and openGL3
- Using GPU not for rendering, instead using textures to pass information
-  Sixth example: simple particle system (explanation of OF example)
- Exercise: Implement cool shaders from shaderToy in OF 