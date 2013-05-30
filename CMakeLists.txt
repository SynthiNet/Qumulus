###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
#
###############################################################################

cmake_minimum_required(VERSION 2.8.8)
project(Qumulus)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Package info
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Qumulus UML editor")
set(CPACK_PACKAGE_VENDOR "Frank Erens and Randy Thiemann")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")

# Nightlies
option(QUMULUS_NIGHTLY "Enable Nightly Build mode")
if(NOT ${QUMULUS_NIGHTLY})
    set(QUMULUS_VERSION
        "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
else()
    set(QUMULUS_VERSION "nightly")
endif()

# CPack
if(WIN32)
    set(CPACK_PACKAGE_FILE_NAME
        "Qumulus-${QUMULUS_VERSION}")
    set(CPACK_NSIS_DISPLAY_NAME "Qumulus")
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "Qumulus")
    set(CPACK_NSIS_INSTALLED_ICON_NAME qumulus.exe)
    set(CPACK_NSIS_CREATE_ICONS "CreateShortCut '\$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Qumulus UML editor.lnk' '\$INSTDIR\\\\qumulus.exe'")
    set(CPACK_GENERATOR "NSIS")

    set(QUMULUS "qumulus")

    set(BINARY_DEST ".")
    set(RESOURCE_DEST "data")
    set(LIBRARY_DEST ".")
    set(QT_PLUGIN_DEST_DIR "plugins")
    set(QT_CONFIG_DEST_DIR ".")

    set(QUMULUS_WINICON ${CMAKE_BINARY_DIR}/winicon.o)
elseif(APPLE)
    set(CPACK_PACKAGE_FILE_NAME 
        "Qumulus-${QUMULUS_VERSION}")
    set(CPACK_DMG_VOLUME_NAME "Qumulus")
    set(CPACK_GENERATOR "DragNDrop")

    set(QUMULUS "Qumulus")
    set(QUMULUS_BUNDLE_ROOT "${QUMULUS}.app/Contents")

    set(PLIST_PATH "${CMAKE_SOURCE_DIR}/Info.plist")

    set(BINARY_DEST ".")
    set(RESOURCE_DEST "${QUMULUS_BUNDLE_ROOT}/Resources")
    set(LIBRARY_DEST "${QUMULUS_BUNDLE_ROOT}/Frameworks")
    set(QT_PLUGIN_DEST_DIR "${QUMULUS_BUNDLE_ROOT}/plugins")
    set(QT_CONFIG_DEST_DIR "${RESOURCE_DEST}")

elseif(UNIX AND NOT APPLE)
    set(CPACK_PACKAGE_FILE_NAME
        "Qumulus-${QUMULUS_VERSION}")
    set(CPACK_GENERATOR "TGZ")

    set(QUMULUS "qumulus")

    set(BINARY_DEST "bin")
    set(RESOURCE_DEST "share")
    set(LIBRARY_DEST "lib")

    SET(CMAKE_SKIP_BUILD_RPATH FALSE)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
    SET(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

# This needs to be done after we set all options
include(CPack)
include(InstallRequiredSystemLibraries)

# C++11 support
include(EnableCxx11)

# Warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-extra-semi")
    set(CMAKE_CXX_FLAGS 
        "${CMAKE_CXX_FLAGS} -Wno-import-preprocessor-directive-pedantic")
endif()

# MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5XmlPatterns REQUIRED)
find_package(Qt5Help REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(Qt5WebKit REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)

# Qt doesn't provide this for us anymore...
set(QT5_PLUGIN_DIR ${_qt5Core_install_prefix}/plugins)
if(WIN32)
    set(QT5_LIBRARY_DIR ${_qt5Core_install_prefix}/bin)
else()
    set(QT5_LIBRARY_DIR ${_qt5Core_install_prefix}/lib)
endif()

# Gtest options -- does not compile on Clang without these.
set(GTEST_USE_OWN_TR1_TUPLE 1)
set(GTEST_HAS_TR1_TUPLE 0)

# Qt Mac Extras
if(APPLE)
    add_subdirectory(deps/QtMacExtras)
    set(QTMACEXTRAS_LIBRARIES QtMacExtras)
    set(QTMACEXTRAS_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/deps)
    set(QTMACEXTRAS_LIBRARY_DIR ${CMAKE_BINARY_DIR}/deps/QtMacExtras)
endif()

# libavoid
add_subdirectory(deps/libavoid)
set(LIBAVOID_LIBRARIES avoid)
set(LIBAVOID_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/deps)
set(LIBAVOID_LIBRARY_DIR ${CMAKE_BINARY_DIR}/deps/libavoid)

add_subdirectory(src)
add_subdirectory(deps/gtest EXCLUDE_FROM_ALL)
add_subdirectory(test)

# UML file icon for OS X
if(APPLE)
    install(FILES "logo/qumulus.icns" DESTINATION ${RESOURCE_DEST})
    install(FILES "logo/uml/xmi-mac.icns" DESTINATION ${RESOURCE_DEST})
endif()

