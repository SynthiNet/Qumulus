###############################################################################
#
# Qumulus UML editor
#
# Copyright (c) 2014 Frank Erens <frank@synthi.net>
# Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
###############################################################################

include(Qumulus/Gui/SourcesList.txt)
include(Qumulus/Lib/SourcesList.txt)
include(Qumulus/Uml/SourcesList.txt)

set(QUML_ALL_SRC ${QUMULUS_LIB_ALL_SRC} ${QUMULUS_UML_ALL_SRC})

# No Obj-C++ on non-OS X
if(NOT APPLE)
    set(QUMULUS_GUI_ALL_MM_SRC "")
endif()

# Include path
include_directories(
    Qumulus 
    ${LIBAVOID_INCLUDE_DIRS}
)

# Compiled-in resources
set(QUMULUS_RSC ${CMAKE_SOURCE_DIR}/resources.qrc)
qt5_add_resources(QUMULUS_RSC_RCC ${QUMULUS_RSC})

if(WIN32)
    # MinGW icon resource
    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/winicon.o
        COMMAND windres.exe "-I${CMAKE_SOURCE_DIR}"
        "-i${CMAKE_SOURCE_DIR}/logo/winicon.rc"
        "-o${CMAKE_BINARY_DIR}/winicon.o" )
endif()

# quml library
add_library(quml STATIC ${QUML_ALL_SRC})
target_link_libraries(quml Qt5::Core Qt5::Xml)

# Qumulus application
add_executable(${QUMULUS} WIN32 MACOSX_BUNDLE
    main.cpp
    ${QUMULUS_GUI_ALL_SRC}
    ${QUMULUS_GUI_ALL_MM_SRC}
    ${QUMULUS_RSC_RCC}
    ${QUMULUS_WINICON}
)

target_link_libraries(${QUMULUS} 
    quml 
    ${LIBAVOID_LIBRARIES}
    ${Qt5Core_QTMAIN_LIBRARIES}
    Qt5::Widgets
    Qt5::PrintSupport
    Qt5::Svg
    Qt5::Xml)

if(APPLE)
    set_target_properties(${QUMULUS} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${PLIST_PATH})
endif()

# Installation
install(TARGETS ${QUMULUS} 
    RUNTIME DESTINATION ${BINARY_DEST} 
    BUNDLE DESTINATION ${BINARY_DEST})

# Install Qt plugins
install(DIRECTORY "${QT5_PLUGIN_DIR}/imageformats" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime
    PATTERN "*d.*" EXCLUDE)
install(DIRECTORY "${QT5_PLUGIN_DIR}/platforms" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime
    PATTERN "*d.*" EXCLUDE)
install(DIRECTORY "${QT5_PLUGIN_DIR}/printsupport" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime
    PATTERN "*d.*" EXCLUDE)
install(DIRECTORY "${QT5_PLUGIN_DIR}/accessible" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime
    PATTERN "*d.*" EXCLUDE)


# Install qt.conf file
install(CODE "
    file(WRITE 
        \"\${CMAKE_INSTALL_PREFIX}/${QT_CONFIG_DEST_DIR}/qt.conf\" 
        \"
        \")
    " COMPONENT Runtime)

# Deployment
if(WIN32)
    set(EXECUTABLE_SUFFIX .exe)
elseif(APPLE)
    set(EXECUTABLE_SUFFIX .app)
endif()

install(CODE "
    file(GLOB_RECURSE QTPLUGINS
        \"\${CMAKE_INSTALL_PREFIX}/${QT_PLUGIN_DEST_DIR}/*${CMAKE_SHARED_LIBRARY_SUFFIX}\")
    include(BundleUtilities)
    fixup_bundle(\${CMAKE_INSTALL_PREFIX}/${QUMULUS}${EXECUTABLE_SUFFIX}
        \"\${QTPLUGINS}\"
        \"${QT5_LIBRARY_DIR};${LIBAVOID_LIBRARY_DIR}\")
    " COMPONENT RUNTIME)
