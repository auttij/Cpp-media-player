
# Media Player Pro 2000

Project directories: 

  * `plan/` -- here is the project plan.

  * `doc/` -- here are the documentation sources related to the project.

  * `src/` -- here are the C++ source files. 

  * `samples/`-- here are audio & video samples.


## Requirements & Installation
This software works with Qt 5.11+. Recommended way to build and run this project is to use QtCreator.
If you are not using QtCreator to build, the following qmake call can be used instead.

Release:
```
qmake src/MediaPlayer/MediaPlayer.pro -spec linux-g++ CONFIG+=qtquickcompiler
```

Debug:
```
qmake src/MediaPlayer/MediaPlayer.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
```
This will create a Makefile for you which will compile the project.


You can also use `build.sh` which is found in src/build/


### Install required libraries:

Playing audio and video files require these to be installed. (the project won't compile without these)
```
sudo apt-get install libgl1-mesa-dev libpulse-dev
```

You might also need these depending on how you installed Qt:
```
sudo apt-get install qtmultimedia5-dev libqt5multimediawidgets5 libqt5multimedia5-plugins libqt5multimedia5
```


## Troubleshooting

If you get errors such as "No decoder available for type 'video/x-h264" or "your gstreamer installation is missing a plug-in.", you need to install gstreamer. These errors cause black screen when playing videos.
### Fix 1:
```
sudo apt-get install gstreamer1.0-plugins-good gstreamer1.0-plugins-ugly gstreamer1.0-plugins-bad
```

### Fix 2:
```
sudo apt-get install ubuntu-restricted-extras
```

You can also try to add `-r GST_VERSION=1.0` parameter to qmake call.

For windows, you will need to install this codec to play videos:
`K-Lite_Codec_Pack_1375_Basic.exe`

