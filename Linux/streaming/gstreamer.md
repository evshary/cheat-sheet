# GStreamer

GStreamer is a framework for creating streaming media application.

# Installation

```bash
sudo apt install libgstreamer1.0-dev
```

# Run

```bash
gst-launch-1.0 v4l2src device=/dev/video0 ! videoconvert ! videoscale ! video/x-raw,format=RGB ! queue ! videoconvert ! ximagesink
```
