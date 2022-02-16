# System

* hardware
```
                                                                          i2c
microphone/speaker ==> amplifier ==> hardware codec(Use PCM for ADC/DAC) ====> Main board
```

* software
```
HW driver ==> pulse audio ==> software codec (mp3...) ==> audio raw data for application
```

* The difference between HW/SW codec
  - HW codec: Transform audio signal between digital and analog (Use PCM).
  - SW codec: To compress audio raw data, we need to use differet compression methods, e.g. mp3.

# Audio quality

We often see the quality of audio: 44100Hz x 16bit x stereo

* 44100Hz: sample rate, 44100 samples per second.
* 16bit: bit rate, each sample use 16bit.
* stereo: Use two channel. (Option: mono, stereo, 5.1)

The size of the audio data each second: 44100 * 16 * 2 = 1411200 bits

# Usage

* List hardware codec: `cat /proc/asound/card0/codec#* | grep -i codec`
* List software codec: `gst-inspect-1.0`
  - Get mp3 codec: `gst-inspect-1.0 | grep decoder | grep mp3`

gstreamer acts as encoder/decoder in audio.

![image](https://user-images.githubusercontent.com/456210/150624381-7ef46a54-b681-441e-a621-4c0ef4c1bcd7.png)
