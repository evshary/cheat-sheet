# GStreamer

GStreamer is a framework for creating streaming media application.

* Architecture

![image](https://user-images.githubusercontent.com/456210/154885324-dbcbe1ff-b401-4f40-8d8c-b4e4bd3b468c.png)

* Communication

![image](https://user-images.githubusercontent.com/456210/154885387-219b67da-fe75-4e26-9b3b-10269fec3100.png)

# Installation

```bash
sudo apt install libgstreamer1.0-dev
```

# Usage

* gst-inspect-1.0: Show the detail of the element

```bash
gst-inspect-1.0 oggdemux
```

* gst-launch-1.0: Launch the pipeline

```bash
gst-launch-1.0 v4l2src device=/dev/video0 ! videoconvert ! videoscale ! video/x-raw,format=RGB ! queue ! videoconvert ! ximagesink
```

# Programming

* Write GStreamer application: https://gstreamer.freedesktop.org/documentation/application-development/basics/index.html?gi-language=c
* Write Plugin: https://gstreamer.freedesktop.org/documentation/application-development/basics/index.html?gi-language=c

# Plugin

The existed plugin usage: https://gstreamer.freedesktop.org/documentation/plugins_doc.html?gi-language=c

## Build your own plugin

* Install meson first

```bash
sudo apt install meson ninja-build
```

* Get code

```bash
git clone https://gitlab.freedesktop.org/gstreamer/gst-template.git
cd gst-template
# The latest version can't match gstreamer in Ubuntu 20.04
git checkout 1.18
```

* Build

```bash
cd ../../
meson builddir
ninja -C builddir
```

* Test

```bash
# Show basic info
gst-inspect-1.0 builddir/gst-plugin/libgstplugin.so
# Show camera image with plugin
gst-launch-1.0 --gst-plugin-path=$PWD/builddir/gst-plugin v4l2src device=/dev/video0 ! plugin ! videoconvert ! videoscale ! video/x-raw,format=RGB ! queue ! videoconvert ! ximagesink
```

# Reference

* [Gstreamer基础教程](https://www.cnblogs.com/xleng/tag/gstreamer/)
