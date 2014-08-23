# That Math Chapter: From 1D to 4D 

1. Intro: How artists approach math
2. One Dimension: Using change
	1. Linear interpolation
	    1. The lerp
        1. The map
        	* Example: Mars lander with an inch vs cm calibration system (TRUE STORY).
        1. Splines
			1. Quadratic splines, using linear interpolations
			1. Cubic splines
		1. Tweening
			* Example: How to make a ball bounce, an eye blink, and a door to slam from the wind.

1. More dimensions: Some Linear Algebra
	1. The Vector
		1. Scalar operations
			1. Vector Length
				1. Distance between points
					* Example: `ofVec2f` as position
					* Example: `ofVec2f` as velocity
				1. The Dot Product
					* Example: Dot product for playing billiards in 2D

	1. The Matrix (TM)
		1. Matrix Multiplication as a dot product
		1. Some operations with Matrices
			1. Identity
				1. Scale
				1. Rotation matrices
					1. in 2D
					1. in 3D
						* Example: Vibrating a brick-phone in 3D.
                1. The inverse matrix
        1. "The Full Stack"
        	1. Homogenous coordinates: Hacking 3d in 4d
			1. Translation matrices
			1. SRT (Scale-Rotate-Translate) operations
				* Example: a pack of sharks swimming
        1. Really using normals
			1. The cross product
			1. Normals for lighting
				* Example: Dot product for lighting
			1. Normals for directions
                
                
                
# Making your software generate (aka That other math chapter)

1. Probability
	1. How artists use probability
	1. Some interesting properties of probability
		1. Always sum to 1
		1. Expectation, Average
			* Example: Flocking, via finding the average of points.
		1. Probability as a density
			* Example: Cell colony in 2D
1. Randomness
	1. Different types of random functions: Uniform, Gaussian, etc
		* Example: Circle packing using `ofRandom`
	1. Markov Chains
		 * Example: ?
1. Noise
	1. From random numbers to streams:
		* Example: White noise
	1. Octaves: The construction of white noise
	1. Building things with `ofNoise`
		* Example: FDM
		* Example: Generative terrain
		* Example: Flickering lights


