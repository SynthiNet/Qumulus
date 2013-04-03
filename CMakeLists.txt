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
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Qumulus UML editor")
SET(CPACK_PACKAGE_VENDOR "Frank Erens and Randy Thiemann")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

if(WIN32)
    set(BINARY_PATH ".")

    set(QUMULUS "qumulus")
elseif(APPLE)
    set(CPACK_PACKAGE_FILE_NAME 
        "Qumulus-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
    set(CPACK_GENERATOR "Bundle")
    set(CPACK_BUNDLE_NAME "Qumulus")
    set(CPACK_BUNDLE_PLIST "${CMAKE_SOURCE_DIR}/Info.plist")
    set(CPACK_BUNDLE_ICON "${CMAKE_SOURCE_DIR}/logo/qumulus.icns")

    set(BINARY_PATH "../MacOS")

    set(QUMULUS "Qumulus")
elseif(UNIX AND NOT APPLE)
    set(BINARY_PATH "./bin")

    set(QUMULUS "qumulus")
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

# Gtest options -- does not compile on Clang without these.
set(GTEST_USE_OWN_TR1_TUPLE 1)
set(GTEST_HAS_TR1_TUPLE 0)

add_subdirectory(src)
add_subdirectory(deps/gtest EXCLUDE_FROM_ALL)
add_subdirectory(test)

# UML file icon for OS X
if(APPLE)
    install(FILES "logo/uml/uml-mac.icns" DESTINATION .)
endif()
