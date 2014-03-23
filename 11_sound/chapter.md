#Sound

This chapter will demonstrate how to use the sound features that you'll find in openFrameworks, as well as some techniques you can use to generate and process sound.

Here's a quick overview of the classes you can use to work with sound in openFrameworks:

`ofSoundPlayer` provides simple access to sound files, allowing you to easily load and play sounds, add sound effects to an app and extract some data about the file's sound as it's playing.

`ofSoundStream` gives you access to the computer's sound hardware, allowing you to generate your own sound as well as react to sound coming into your computer from something like a microphone or line-in jack.

*[ possibly separate the below from above? (since they're not actually in OF yet) ]*

`ofSoundBuffer` is used to store a sequence of `float` values, and perform audio-related things on said values (like resampling)

`ofSoundFile` allows you to extract uncompressed ofSoundBuffers from files.

`ofSoundObject` is an interface for chaining bits of sound code together, similar to how a guitarist might use guitar pedals. This is mostly relevant for addon authors or people looking to share their audio processing code.

##Getting Started With Sound Files

Playing a sound file is only a couple lines of code in openFrameworks. Just point an `ofSoundPlayer` at a file stored in your app's data folder and tell it to play.

    class ofApp : public ofBaseApp {
      ...
      ofSoundPlayer soundPlayer;
    };

    void ofApp::setup() {
      soundPlayer.loadSound("song.mp3");
      soundPlayer.play();
    }

This is fine for adding some background music or ambiance to your app, but ofSoundPlayer comes with a few extra features that are particularly handy for handling sound effects.

"Multiplay" allows you to have a file playing several times simultaneously. This is great for any sound effect which might end up getting triggered rapidly, so you don't get stuck with an unnatural cutoff as the player's playhead abruptly jumps back to the beginning of the file. With multiplay enabled, you can get natural sound effect behaviour with dead-simple trigger logic like this:

    if ( thingHappened )
      soundPlayer.play();
    }

Multiplay isn't on by default. Use `soundPlayer.setMultiPlay(true)` to enable it.

Another feature built-in to ofSoundPlayer is speed control. If you set the speed faster than normal, the sound's pitch will rise accordingly, and vice-versa (just like a vinyl record). Playback speed is defined relative to "1", so "0.5" is half-speed and "2" is double speed.

Speed control and multiplay are made for each other. Making use of both simultaneously can really extend the life of a single sound effect file. Every time you change a sound player's playback speed with multiplay enabled, previously triggered sound effects continue on unaffected. So, by extending the above trigger logic to something like...

    if( thingHappened ) {
      soundPlayer.setSpeed(ofRandom(0.8, 1.2));
      soundPlayer.play();
    }

...you'll introduce a bit of unique character to each instance of the sound.

One other big feature of ofSoundPlayer is easy spectrum access. On the desktop platforms, you can make use of ofSoundGetSpectrum() to get the *frequency domain* representation of the sound coming from all of the currently active ofSoundPlayers in your app. An explanation of the frequency domain is coming a little later in this chapter, but running the openFrameworks soundPlayerFFTExample will give you the gist.

*[ screencap of the soundPlayerFFTExample ]*

Ultimately, ofSoundPlayer is a tradeoff between ease-of-use and control. You get access to easy multiplay and pitch-shifted playback but you don't get extremely precise control or access to the individual samples in the sound file. For this level of control, ofSoundStream is the tool for the job.

##Getting Started With the Sound Stream

ofSoundStream is the gateway to the audio hardware on your computer, such as the microphone and the speakers. If you want to have your app react to live audio input or generate sound on the fly, this is the section for you!

You may never have to use the ofSoundStream directly, but it's the object that manages the resources needed to trigger audioOut() and audioIn() on your app. Here's the basic structure for a sound-producing openFrameworks app:

    class ofApp : public ofBaseApp {
      ...
      void audioOut( float * output, int bufferSize, int nChannels );
      double phase;
    }

    void ofApp::setup(){
      phase = 0;
      ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
    }

    void ofApp::audioOut( float * output, int bufferSize, int nChannels ) {
      for(int i = 0; i < bufferSize * nChannels; i+=2) {
        float sample = sin(phase); // generating a sine wave sample
        output[i] = sample; // writing to the left channel
        output[i+1] = sample; // writing to the right channel
        phase += 0.05;
      }
    }

When producing or receiving audio, the format is floating point numbers between -1 and 1 (the reason for this is coming a little later in this chapter). The sound will arrive in your app in the form of *buffers*, which you can treat much like arrays.

The buffer size is adjustable, but it's usually a good idea to leave it at the default. The default isn't any number in particular, but will usually be whatever the hardware on your computer prefers. In practice, this is probably about 512 samples per buffer (256 and 1024 are other common buffer sizes).

Buffers are *interleaved* meaning that the samples for each channel are right next to each other, like:

    [Left] [Right] [Left] [Right] ...

This means you access individual sound channels in much the same way as accessing different colours in an ofPixels object (i.e. buffer[i] for the left channel, buffer[i + 1] for the right channel).

##Why -1 to 1?

In order to understand *why* openFrameworks chooses to represent sound as a continuous stream of `float` values ranging from -1 to 1, it'll be helpful to know how sound is created on a physical level.

*[ a minimal picture showing the mechanics of a speaker ]*

At the most basic level, a speaker consists of a cone and an electromagnet. The electromagnet pushes and pulls the cone to create vibrations in air pressure. These vibrations make their way to your ears, where they are interpreted as sound. When the electromagnet is off, the cone is simply "at rest", neither pulled in or pushed out.

[footnote] A basic microphone works much the same way: allowing air pressure to vibrate an object held in place by a magnet, thereby creating an electrical signal.

From the perspective of an openFrameworks app, it's not important what the sound hardware's specific voltages are. All that really matters is that the speaker cone is being driven between its "fully pushed out" and "fully pulled in" positions, which are represented as 1 and -1. [note: would be good to relate this to zach's bit about numbers between 0 and 1 in the animation chapter].

[footnote] Some other systems use an integer-based representation, moving between something like -65535 and +65535 with 0 still being the representation of "at rest". The Web Audio API provides an unsigned 8-bit representation, which ranges between 0 and 255 with 127 being "at rest".

A major way that sound differs from visual content is that there isn't really a "static" representation of sound. For example, if you were dealing with an OpenGL texture which represents 0 as "black" and 1 as "white", you could fill the texture with all 0s or all 1s and end up with a static image of "black" or "white" respectively. This is not the case with sound. If you were to create a sound buffer of all 0s, all 1s, all -1s, or any single number, they would all sound like exactly the same thing: nothing at all.

[footnote] Technically, you'd probably hear a pop right at the beginning as the speaker moves from the "at rest" position to whatever number your buffer is full of, but the remainder of your sound buffer would just be silence.

This is because what you actually hear is the *changes* in values over time. Any individual sample in a buffer doesn't really have a sound on its own. What you hear is the *difference* between the sample and the one before it. For instance, a sound's "loudness" isn't necessarily related to how "big" the individual numbers in a buffer are. A sine wave which oscillates between 0.9 and 1.0 is going to be much much quieter than one that oscillates between -0.5 and 0.5.

##Time Domain vs Frequency Domain

When representing sound as a continuous stream of values between -1 and 1, you're working with sound in what's known as the "Time Domain". This means that each value you're dealing with is referring to a specific moment in time. There is another way of representing sound which can be very helpful when you're using sound to drive something other aspect of your app. That representation is known as the "Frequency Domain".

*[ image of a waveform vs an FFT bar graph ]*

In the frequency domain, you'll be able to see how much of your input signal lies in various frequencies, split into various "bins" (see above image).

You can transform a signal in the time domain into the frequency domain by a ubiquitous algorithm called the Fast Fourier Transform. You can get an openFrameworks-ready implementation of the FFT (along with examples!) in either the ofxFFT or ofxFft addons (by Lukasz Karluk and Kyle McDonald respectively).

*[footnote explaining FFT vs DFT to avoid cluttering the previous paragraph up]*

You can also transform a signal from the frequency domain back to the time domain, using an Inverse Fast Fourier Transform (aka IFFT). This is less common, but there is an entire genre of audio synthesis called Additive Synthesis which is built around this principle (generating values in the frequency domain then running an IFFT on them to create synthesized sound).

- ofSoundStream gives you access to sound in the time domain.
- The time domain is useful for analysing general "loudness", as well as pitch detection ([counterintuitively](http://blog.bjornroche.com/2012/07/frequency-detection-using-fft-aka-pitch.html))
- Frequency domain is useful for isolating particular elements of a sound, such as instruments in a song. It is also useful for analyzing the character/timbre of a sound.

##Reacting to Live Audio

###RMS
One of the simplest ways to add audio-reactivity to your app is to calculate the RMS of incoming buffer of audio data. RMS stands for "root mean square" and is a pretty straightforward calculation that serves as a good approximation of "loudness" (much better than something like averaging the buffer or picking the maximum value). You can see RMS being calculated in the "audioInputExample".

*[ code snippet here ]*

###Onset Detection
Onset detection algorithms attempt to locate moments in an audio stream where an "onset" occurs, which is usually something like an instrument playing a note or the impulse of a drum hit. There are many onset detection algorithms available at various levels of complexity and accuracy, some fine-tuned for speech as opposed to music, some working in the frequency domain instead of the time domain, some made for offline processing as opposed to realtime, etc.

A simple realtime onset detection algorithm can be built on top of the RMS calculation above.

*[ naive RMS threshold-based code sample here ]*

###FFT
Running an FFT on your input audio will give you back a buffer of values representing the input's frequency content. A straight up FFT *won't* tell you which notes are present in a piece of music, but you will be able to use the data to take the input's sonic "texture" into account. For instance, the FFT data will let you know how much "bass" / "mid" / "treble" there is in the input at a pretty fine granulairty (a typical FFT used for realtime audio-reactive work will give you something like 512 to 4096 individual frequency bins to play with).

NOTE TO SELF/EDITORS: I definitely need to clean up the following paragraph. It's pretty crucial but I haven't found a way to get a succinct explanation of it yet.

When using the FFT to analyze music, you should keep in mind that the FFT's bins increment on a *linear* scale, whereas humans interpret frequency on a *logarithmic* scale. So, if you were to use an FFT to split an input signal into 512 bins, the lowest bins (probably bin 0 through bin 30 or so) will contain the bulk of the data, and the remaining bins will mostly just be high frequency content. If you were to isolate the sound on a bin-to-bin basis, you'd be able to easily tell the difference between the sound of bins 3 and 4, but bins 500 and 501 would probably sound exactly the same. Unless you had robot ears.

- Pitch detection
  - FFT -> Power -> IFFT Autocorrelation sort-of-hack
  - Zero crossings
- Conversions to Mel scale, decibels

##Synthesizing Audio
- MIDI / OSC
- Attack Decay Sustain Release
- Working with external sound applications
- Overview of simple synthesis techniques (very high-level)

##Gotchas
### "Popping"
When starting or ending playback of synthesized audio, you should try to quickly fade in / out the buffer, instead of starting or stopping abruptly. If you start playing back a buffer that begins like `[1.0, 0.9, 0.8...]`, the first thing the speaker will do is jump from the "at rest" position of 0 immediately to 1.0. This is a *huge* jump, and will probably result in a "pop" that's quite a bit louder than you were expecting (based on your computer's current volume).

Usually, fading in / out over the course of about 30ms is enough to eliminate these sorts of pops.

If you're getting pops in the middle of your playback, you can diagnose it by trying to find reasons why the sound might be very briefly cutting out (i.e. jumping to 0, resulting in a pop if the waveform was previously at a non-zero value).

### "Clipping" / Distortion
If your samples begin to exceed the range of -1 to 1, you'll likely start to hear what's known as "clipping", which generally sounds like a grating, unpleasant distortion. Some audio hardware will handle this gracefully by allowing you a bit of leeway outside of the -1 to 1 range, but others will "clip" your buffers.

*[ clipped waveform image ]*

Assuming this isn't your intent, you can generally blame clipping on a misbehaving addition or subtraction in your code. A multiplication of any two numbers between -1 and 1 will always result in another number between -1 and 1.

If you *want* distortion, it's much more common to use a waveshaping algorithm instead of trying to find a way to make clipping sound good [todo: link].

###Latency

No matter what, sound you produce in your app will arrive at the speakers sometime after the event that triggered the sound. The total time of this round trip, from event -> your app -> speakers is referred to as *latency*.

In practice, this usually isn't a big deal unless you're working on something like a musical instrument with very tight reaction time requirements (a drum instrument, for instance). If you're finding that your app's sound isn't responsive enough, you can try lowering the buffer size of your ofSoundStream. be careful, though! The default buffer size is typically the default because it's determined to be the best tradeoff between latency and reliability. If you use an smaller buffer size, you might experience "popping" (as explained above) if your app can't keep up with the extra-strict audio deadlines.
