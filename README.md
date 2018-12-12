# Sample README file for C++ programming project

This is an initial git repository for your programming project.
It contains an initial directory structure that we wish you could
use as follows:

  * `plan/' -- Here is your project plan. You may use different sources,
    but we hope to get the pan **also as pdf file**.

  * `doc/` -- here are the documentation sources related to your project.
    You may use different tools for documentation (e.g. latex),
    but we hope to get the final version of the document
    **also as pdf file**.

  * `src/` -- here are the C++ source files. You can have subfolders as needed.

  * `README.md` -- This file that you should modify to represent
    your project.

You may also add other new directories as needed, for example
for testing tools.


# Installation
Install required libraries:

```
sudo apt-get install libgl1-mesa-dev libpulse-dev
```

If you are not using QtCreator to build this project, you will probably also need these:
```
sudo apt-get install qtmultimedia5-dev libqt5multimediawidgets5 libqt5multimedia5-plugins libqt5multimedia5
```


# Troubleshooting

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
K-Lite_Codec_Pack_1375_Basic.exe


