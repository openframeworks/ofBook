#Sound

This chapter will demonstrate how to use the sound features and objects that you'll find in openFrameworks, as well as some techniques you can use to react to and generate sound.

`ofSoundPlayer` provides simple access to sound files, allowing you to easily load and play sounds, add sound effects to an app and extract some data about the file's sound as it's playing.

`ofSoundStream` gives you access to the computer's sound hardware, allowing you to programmatically generate your own sound as well as react to sound coming into your computer from something like a microphone or line-in jack.

- Mention ofSoundBuffer / ofSoundFile / ofSoundObject
- Quick and dirty play files w/ofSoundPlayer & beep boop `sin()` ofSoundStream examples to set the stage.

##Why -1 to 1?

In order to understand *why* openFrameworks chooses to represent sound as a continuous stream of `float` values ranging from -1 to 1, it'll be helpful to know how sound is created on a physical level.

*[ a minimal picture showing the mechanics of a speaker ]*

At the most basic level, a speaker consists of a cone and an electromagnet. The electromagnet pushes and pulls the cone to create vibrations in air pressure. These vibrations make their way to your ears, where they are interpreted as sound. When the electromagnet is off, the cone is simply "at rest", neither pulled in or pushed out.

[footnote] A basic microphone works much the same way: allowing air pressure to vibrate an object held in place by a magnet, thereby creating an electrical signal.

From the perspective of an openFrameworks app, it's not important what the sound hardware's specific voltages are. All that really matters is that the speaker cone is being driven between its "fully pushed out" and "fully pulled in" positions, which are represented as 1 and -1. [note: would be good to relate this to zach's bit about numbers between 0 and 1 in the animation chapter].

[footnote] Many other systems use an integer-based representation, moving between something like -65535 and +65535 with 0 still being the representation of "at rest". The Web Audio API provides an unsigned 8-bit representation, which ranges between 0 and 255 with 127 being "at rest". NOTE TO SELF DOUBLE CHECK THE SPECIFIC NUMBERS

A major way that sound differs from visual content is that there isn't really a "static" representation of sound. For example, if you were dealing with an OpenGL texture which represents 0 as "black" and 1 as "white", you could fill the texture with all 0s or all 1s and end up with a static image of "black" or "white" respectively. This is not the case with sound. If you were to create a sound buffer of all 0s, all 1s, all -1s, or any single number, they would all sound like exactly the same thing: nothing at all.

[footnote] Technically, you'd probably hear a pop right at the beginning as the speaker moves from the "at rest" position to whatever number your buffer is full of, but the remainder of your sound buffer would just be silence.

This is because what you actually hear is the *changes* in values over time. Any individual sample in a buffer doesn't really have a sound on its own. What you hear is the *difference* between the sample and the one before it. For instance, a sound's "loudness" isn't necessarily related to how "big" the individual numbers in a buffer are. A sine wave which osciallates between 0.9 and 1.0 is going to be much much quieter than one that osciallates between -0.5 and 0.5.

##Time Domain vs Frequency Domain
- "Time domain" means you're dealing with values that specify an amplitude at a point in time (i.e. amplitude vs time). "Frequency Domain" means you're dealing with values that specify amplitudes at certain frequencies (i.e. power(?) vs frequency).
- A time domain signal can be transformed to the frequency domain via a FFT
- You can also invert an FFT to transform a frequency domain signal back to a time domain signal. *Possible shout out to additive synthesis here*.
- ofSoundStream gives you access to sound in the time domain.
- The time domain is useful for analysing general "loudness", as well as pitch detection ([counterintuitively](http://blog.bjornroche.com/2012/07/frequency-detection-using-fft-aka-pitch.html))
- Frequency domain is useful for isolating particular elements of a sound, such as instruments in a song. It is also useful for analyzing the character/timbre of a sound.

##Sound Files
- ofSoundPlayer is a tradeoff between ease-of-use and control. You get access to easy multiplay and pitch-shifted playback but lose precise control and access to the uncompressed sound
- On the opposite end of the spectrum, ofSoundFile will allow you to extract an uncompressed ofSoundBuffer out of a file, allowing you access to the raw time domain signal.
- ofSoundPlayer provides access to the frequency domain content of the sounds being played in the form of `ofSoundGetSpectrum()`, but does not give access to the time domain (i.e. the -1 to 1 uncompressed samples)
- "Multiplay" allows you to have a file playing several times at different pitches simulatenously. Very handy for sound effects.

##Addon Ecosystem


##Reacting to Live Audio
- RMS
- FFT
- Pitch detection
- Onset detection
- Conversions to Mel scale, decibels

##Synthesizing Audio
- Attack Decay Sustain Release
- MIDI / OSC
