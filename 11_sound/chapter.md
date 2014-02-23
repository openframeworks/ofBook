Sound
=====

- Introduce ofSoundPlayer, ofSoundStream.
- Mention ofSoundBuffer / ofSoundFile / ofSoundObject
- Quick and dirty play files w/ofSoundPlayer & beep boop `sin()` ofSoundStream examples to set the stage.

Why -1 to 1?
------------
- Sound = oscillation. As opposed to visual content (i.e. images), there's not really such a thing as static sound. What is heard is the changes in amplitude over time.
- 0 is "at rest". -1 / 1 aren't "loud" on their own.
- What makes a sound loud is how much it changes over time. -0.5 to 0.5 is much louder than 0.9 to 1.0.

Time Domain vs Frequency Domain
-------------------------------
- "Time domain" means you're dealing with values that specify an amplitude at a point in time (i.e. amplitude vs time). "Frequency Domain" means you're dealing with values that specify amplitudes at certain frequencies (i.e. power(?) vs frequency).
- A time domain signal can be transformed to the frequency domain via a FFT
- You can also invert an FFT to transform a frequency domain signal back to a time domain signal. *Possible shout out to additive synthesis here*.
- ofSoundStream gives you access to sound in the time domain.
- The time domain is useful for analysing general "loudness", as well as pitch detection ([counterintuitively](http://blog.bjornroche.com/2012/07/frequency-detection-using-fft-aka-pitch.html))
- Frequency domain is useful for isolating particular elements of a sound, such as instruments in a song. It is also useful for analyzing the character/timbre of a sound.

Sound Files
-----------
- ofSoundPlayer is a tradeoff between ease-of-use and control. You get access to easy multiplay and pitch-shifted playback but lose precise control and access to the uncompressed sound
- On the opposite end of the spectrum, ofSoundFile will allow you to extract an uncompressed ofSoundBuffer out of a file, allowing you access to the raw time domain signal.
- ofSoundPlayer provides access to the frequency domain content of the sounds being played in the form of `ofSoundGetSpectrum()`, but does not give access to the time domain (i.e. the -1 to 1 uncompressed samples)
- "Multiplay" allows you to have a file playing several times at different pitches simulatenously. Very handy for sound effects.

Addon Ecosystem
---------------


Reacting to Live Audio
----------------------
- RMS
- FFT
- Pitch detection
- Onset detection
- Conversions to Mel scale, decibels

Synthesizing Audio
------------------
- Attack Decay Sustain Release
- MIDI / OSC
