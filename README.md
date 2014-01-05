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

- Qt 5.2.0
- CMake 2.8.11 or newer

**Mac OS X**:

- Xcode (with command line utilities)

**Linux**:

- GCC 4.8.0 or newer
- chrpath

**Windows**:

- MinGW 4.8.0 or newer
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
  installed Qt in `$HOME/Qt5/Qt5.2.0/clang_64`, you'd put that here.
  Alternatively, add the `bin` folder of your Qt installation to your PATH.
- `-DCMAKE_INSTALL_PREFIX=...`: Where to put the installed binaries. This can be
   a relative path, e.g. `./inst`
- `-G`: Generator to be used. On Mac OS X and Linux this defaults to Makefiles.
  On Windows you'd probably want to use a specific generator, i.e. 
  `-G"MinGW Makefiles"`

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
