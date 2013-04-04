###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
#
###############################################################################

cmake_minimum_required(VERSION 2.8.8)
project(Qumulus)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# CPack
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Qumulus UML editor")
set(CPACK_PACKAGE_VENDOR "Frank Erens and Randy Thiemann")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")

if(NOT ${QUMULUS_NIGHTLY})
    set(QUMULUS_VERSION
        "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
else()
    set(QUMULUS_VERSION "nightly")
endif()

if(WIN32)
    set(CPACK_PACKAGE_FILE_NAME
        "Qumulus-${QUMULUS_VERSION}")
    set(CPACK_NSIS_INSTALLED_ICON_NAME qumulus.exe)
    set(CPACK_GENERATOR "NSIS")

    set(QUMULUS "qumulus")

    set(BINARY_DEST ".")
    set(RESOURCE_DEST "data")
    set(QT_PLUGIN_DEST_DIR ".")
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
    set(QT_PLUGIN_DEST_DIR "${QUMULUS_BUNDLE_ROOT}/plugins")
    set(QT_CONFIG_DEST_DIR "${RESOURCE_DEST}")

elseif(UNIX AND NOT APPLE)
    set(QUMULUS "qumulus")

    set(BINARY_DEST "bin")
    set(RESOURCE_DEST "share")
endif()

# This needs to be done after we set all options
include(CPack)
include(InstallRequiredSystemLibraries)

# C++11 support
include(EnableCxx11)

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
set(QT5_LIBRARY_DIR ${_qt5Core_install_prefix}/lib)

# Gtest options -- does not compile on Clang without these.
set(GTEST_USE_OWN_TR1_TUPLE 1)
set(GTEST_HAS_TR1_TUPLE 0)

add_subdirectory(src)
add_subdirectory(deps/gtest EXCLUDE_FROM_ALL)
add_subdirectory(test)

# UML file icon for OS X
if(APPLE)
    install(FILES "logo/qumulus.icns" DESTINATION ${RESOURCE_DEST})
    install(FILES "logo/uml/uml-mac.icns" DESTINATION ${RESOURCE_DEST})
endif()
