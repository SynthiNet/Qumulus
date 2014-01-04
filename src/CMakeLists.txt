###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
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
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)
install(DIRECTORY "${QT5_PLUGIN_DIR}/platforms" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)
install(DIRECTORY "${QT5_PLUGIN_DIR}/printsupport" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)
install(DIRECTORY "${QT5_PLUGIN_DIR}/accessible" 
    DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)


# Install qt.conf file
install(CODE "
    file(WRITE 
        \"\${CMAKE_INSTALL_PREFIX}/${QT_CONFIG_DEST_DIR}/qt.conf\" 
        \"
        \")
    " COMPONENT Runtime)

# Deployment
if(APPLE)
    # Fix library references
    install(CODE "
        file(GLOB_RECURSE QTPLUGINS
            \"\${CMAKE_INSTALL_PREFIX}/${QT_PLUGIN_DEST_DIR}/*${CMAKE_SHARED_LIBRARY_SUFFIX}\")
        include(BundleUtilities)
        fixup_bundle(\${CMAKE_INSTALL_PREFIX}/${QUMULUS}.app 
            \"\${QTPLUGINS}\" 
            \"${QT5_LIBRARY_DIR};${QTMACEXTRAS_LIBRARY_DIR};${LIBAVOID_LIBRARY_DIR}\")
        " COMPONENT Runtime)
elseif(WIN32)
    # Install required libraries
    install(CODE "
        include(GetPrerequisites)

        get_prerequisites(\${CMAKE_INSTALL_PREFIX}/${QUMULUS}.exe 
            WINDOWS_LIBRARIES 1 1 \"\" \"\")
        
        foreach(lib \${WINDOWS_LIBRARIES})
            find_program(lib_path_\${lib} \${lib})
            if(NOT (\"\${lib_path_\${lib}}\" MATCHES \"NOTFOUND\"))
                file(INSTALL \"\${lib_path_\${lib}}\" 
                    DESTINATION \${CMAKE_INSTALL_PREFIX}/${BINARY_DEST})
            endif()
        endforeach()

        " COMPONENT RUNTIME)

    install(FILES ${QT5_LIBRARY_DIR}/libEGL.dll DESTINATION .)
elseif(UNIX AND NOT APPLE)
# Fix library references
    install(CODE "
        file(GLOB_RECURSE QTPLUGINS
            \"\${CMAKE_INSTALL_PREFIX}/${QT_PLUGIN_DEST_DIR}/*${CMAKE_SHARED_LIBRARY_SUFFIX}\")
        include(BundleUtilities)
        fixup_bundle(\${CMAKE_INSTALL_PREFIX}/${BINARY_DEST}/${QUMULUS} 
            \"\${QTPLUGINS}\" 
            \"${QT5_LIBRARY_DIR};${LIBAVOID_LIBRARY_DIR}\")
        " COMPONENT Runtime)
        foreach(plugin ${QTPLUGINS})
            execute_process(COMMAND chrpath -r '$ORIGIN/../..' "${plugin}")
            message(STATUS "Fixing rpath for plugin ${plugin}")
        endforeach()
endif()

