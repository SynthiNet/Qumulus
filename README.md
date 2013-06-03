![](http://synthi.net/img/qumulus-full.svg)

# Qumulus #

## Binaries ##

Binaries are available for the following platforms:

- [Windows (32 bit) [.exe installer]](http://ftp.synthi.net/releases/qumulus/nightly/Qumulus-nightly.exe)
- [Mac OS X (64 bit Intel) [.dmg image]](http://ftp.synthi.net/releases/qumulus/nightly/Qumulus-nightly.dmg)
- [Linux (64 bit) [.tar.gz archive]](http://ftp.synthi.net/releases/qumulus/nightly/Qumulus-nightly.tar.gz)

## Installation Instructions ##

### Dependencies ###

**All Platforms**:

- Qt 5.0.2
- CMake 2.8.8 or newer

**Mac OS X**:

- Xcode (with command line utilities)

*Note*:
> In order for cursors to work, you need to install a custom patch for Qt. The
> patched version can be found at 
> [http://ftp.synthi.net/builds/qt5/qcocoa/](http://ftp.synthi.net/builds/qt5/qcocoa/) .
> Please also run the script qtplugin-fix-libraries.sh found in the same
> directory on each of the patched plugins. Modify the script so `QT5` points to
> your Qt 5 installation.

**Linux**:

- GCC 4.7.0 or newer
- chrpath

**Windows**:

- MinGW 4.7.0 or newer
- Microsoft Visual C++

*Note*:
> Qumulus will only build with MinGW on Windows. However, the dependency
> resolver for Windows requires `dumpbin.exe`, which comes with Microsoft Visual
> C++ (any version). Also, make sure all dependencies are in PATH.

### Installation ###

It is recommended to build Qumulus out-of-source:

    mkdir build
    cd build

Next, run CMake:

    cmake ..

A few options that can be passed to CMake:

- `-DCMAKE_PREFIX_PATH=...`: Search path for libraries. E.g. if you have
  installed Qt in `$HOME/Qt5/Qt5.0.2/clang_64`, you'd put that here.
- `-DCMAKE_INSTALL_PREFIX=...`: Where to put the installed binaries. This can be
   a relative path, e.g. `./inst`
- `-G`: Generator to be used. On Mac OS X and Linux this defaults to Makefiles.
  On Windows you'd probably want to use a specific generator, i.e. 
  `"-GMinGW Makefiles"`

Build and install the project:

    make install

Or, with MinGW:

    mingw32-make install

To create an installable package:

    make package

Or, with MinGW:

    mingw32-make package

## Usage ##

Documentation can be found in the Help &rarr; Documentation menu.

## Acknowledgements ##

Qumulus was written by Frank Erens and Randy Thiemann.

Algorithm for dynamic connector routing by Michael Wybrow through 
[libavoid](http://www.adaptagrams.org/documentation/libavoid.html).

Graphical interface made using [Qt](http://qt-project.org).
