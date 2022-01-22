# Linux Audio

Linux audio uses PulseAudio to bridge application and the audio input/output hardware.

# PulseAudio

The following figure is from wiki:

![](https://upload.wikimedia.org/wikipedia/commons/0/00/Pulseaudio-diagram.svg)

* Sink: audio output
* Source: audio input

The feature of PulseAudio:

* Adjust volume for each applications
* Accept multiple input / output at the same time
* Load module automatically
* Detect / manage multiple audio card
* Most of the audio applications support PulseAudio

## Usage

### pactl

* `pactl list`: list all the modules/input/output of PulseAudio.
  - `pactl list short`: Only list brief message.
* `pactl list sinks`: List the audio output of PulseAudio
  - You can adjust the volume and see its changes.
  - `pactl list short sinks`: Only list brief message.
* `pactl set-sink-mute 1 toggle`: Toggle the audio output (mute or not)
* `pactl list sink-inputs`: List all the application use the audio output now.
  - `pactl list short sink-inputs`: Only list brief message.
* `pactl set-sink-input mute <N> toggle`: Mute audio output of certain application.
* `pactl move-sink-input <N> <ALSA output>`: Move audio ouput of certain application to specific audio hardware
* `pactl info`: Basic info for PulseAudio.

### pacmd

pacmd has the same function of pactl, but it also can show interactive interface on CLI.

The difference between pactl & pacmd: [Change PulseAudio Input/Output from Shell?](https://unix.stackexchange.com/questions/65246/change-pulseaudio-input-output-from-shell)

> pacmd - Used to reconfigure a PulseAudio sound server during runtime.
> 
> pactl - Used to control a running PulseAudio sound server.

Useful commands:

* `pacmd list-cards`: List sound card.
* `pacmd list-sinks`: **Useful**. Same as `pactl list sinks`, but able to show the number who use the sinks.

### pulseaudio

* `pulseaudio --start`: Run PulseAudio daemon
* `pulseaudio --kill`: Kill PulseAudio daemon
* `pulseaudio --check`: Check whether PulseAudio exists or not

Note:
In Ubuntu, PulseAudio is running as service, so you can't kill the pulseaudio directly.
You can stop the service and then try this commands.

Config:

The config of pulseaudio:

* `~/.config/pulse/default.pa`: If the file exist, this config will have the highest priority.
* `/etc/pulse/default.pa`: **Default used**. pulseaudio will use this config while running as user service mode.
* `/etc/pulse/system.pa`: If pulseaudio running as system service, will use this config

Refer to [linux音频声卡 pulseaudio服务](https://blog.csdn.net/qq_42138566/article/details/108626378)

### PulseAudio Service

In Ubuntu, the PulseAudio daemon is running as service/socket.
You can check with the following commands

```bash
systemctl --user status pulseaudio.service
# Since the unit type is socket, you can also use the following commands
systemctl --user status pulseaudio.socket
```

To run / stop the service

```bash
systemctl --user start pulseaudio.socket
systemctl --user stop pulseaudio.socket
```

# ALSA

Advanced Linux Sound Architecture (ALSA) makes sure audio manufacturers follow the same standard to develop.

The list of vendor which supports ALSA: https://www.alsa-project.org/main/index.php/Matrix:Main

You can also download driver from this official website.

# Useful commands
* Basic operations
  - Install: `sudo apt install alsa-utils`
  - Play audio: `aplay /usr/share/sounds/xxx/xxx.wav`
  - Record: `arecord <mywav.wav>`
  - Control the volume of audio (CLI): `alsamixer`
* Control the volume of audio (GUI)
  - `sudo apt install pavucontrol`
  - `pavucontrol`

# Useful file
* `/proc/asound/`: The interface ALSA provides
  - `cards`: sound card
  - `pcm`: hardware codec
  - `modules`: driver module
  - `version`: ALSA version
* `/dev/snd`: List of sound device
  - `controlC?`: control the volume
  - `pcmC?D?p`: play device
  - `pcmC?D?c`: capture device
* `/sys/class/sound`: Same as `/dev/snd`

# Some tips

* While system fails to detect ALSA device and has no audio output, it might be that module-udev-detect fails to detect audio hardware and load corresponding modules.
  - Try to modify `/etc/pulse/default.pa` and uncomment `load-module module-alsa-sink`.
  - Reboot or restart the service `systemctl --user restart pulseaudio.socket`
  - For more information about [module-alsa-sink](https://www.freedesktop.org/wiki/Software/PulseAudio/Documentation/User/Modules/#module-alsa-sink).

# Reference

* [Linux硬體架構與指令之解析-聲音](http://blog.gitdns.org/2017/02/22/pulseaudio/SKNS00008_read.pdf): Help you understand PulseAudio quickly.
* [Arch Linux - PulseAudio](https://wiki.archlinux.org/title/PulseAudio_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
