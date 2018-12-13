#!/bin/sh

qmake ../MediaPlayer/MediaPlayer.pro -spec linux-g++ CONFIG+=qtquickcompiler
make
