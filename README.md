# Image Finder

Image Finder is a little plug-in for [QupZilla](https://github.com/QupZilla/qupzilla), which helps user to find image source on the web in two clicks.

Supported reverse image search engines:
  - Google
  - Yandex
  - TinEye (in progress)

### Building
Before starting, make sure you have QtWebEngine (>=5.6)
Change the working directory to QupZilla source tree
```sh
$ cd src/plugins
```
Clone ImageFinder source code, run
```sh
$ git clone https://github.com/innermous/image-finder-plugin.git
$ cd image-finder-plugin
```
Generate a Makefile and build
```sh
$ qmake
$ make -j4
```

### Contributing
All contributions are welcome, just fork this project, make your changes and make pull-request. 
Translations, bug-fixes and issue reports are wanted.