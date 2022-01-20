# 2D/3D architecture

![image](https://user-images.githubusercontent.com/456210/150244728-f4e46ea4-5b4d-47a9-8614-ab9af7a506c7.png)

[image src](http://dri.sourceforge.net/doc/dri_data_flow.html)

* DDX(Device Dependent X): 2D device driver of X server. Able to configure resolution, color depth, 2D acceleration...
* DIX(Device Independent X): Help X server to decode X protocol.
* DRI(Direct Rendering Interface): X client can use DRI to pass commands to Graphic Card.
* DRM(Direct Rendering Manager): Handle the hardware interface.

# backup the graphic

* Switch to terminal console
* Backup the current display: `sudo cp /dev/fb0 fb.log`
* Restore the current display: `sudo cp fb.log /dev/fb0`
