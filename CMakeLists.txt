###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
#
###############################################################################

cmake_minimum_required(VERSION 2.8.8)
project(Qumulus)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

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
