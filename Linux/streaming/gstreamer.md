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

# Run

```bash
gst-launch-1.0 v4l2src device=/dev/video0 ! videoconvert ! videoscale ! video/x-raw,format=RGB ! queue ! videoconvert ! ximagesink
```
