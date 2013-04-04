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

# Compiled-in resources
set(QUMULUS_RSC ${CMAKE_SOURCE_DIR}/resources.qrc)
qt5_add_resources(QUMULUS_RSC_RCC ${QUMULUS_RSC})

# quml library
add_library(quml STATIC ${QUML_ALL_SRC})
qt5_use_modules(quml Core)

# Qumulus application
add_executable(${QUMULUS} MACOSX_BUNDLE
    main.cpp
    ${QUMULUS_GUI_ALL_SRC}
    ${QUMULUS_RSC_RCC}
)

target_link_libraries(${QUMULUS} quml)
qt5_use_modules(${QUMULUS} Widgets PrintSupport Svg Xml)

if(APPLE)
    set_target_properties(${QUMULUS} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${PLIST_PATH})
endif()

# Installation
install(TARGETS ${QUMULUS} 
    RUNTIME DESTINATION ${BINARY_DEST} 
    BUNDLE DESTINATION ${BINARY_DEST})

# Deployment
if(APPLE)
    # Install Qt plugins
    install(DIRECTORY "${QT5_PLUGIN_DIR}/imageformats" 
        DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)
    install(DIRECTORY "${QT5_PLUGIN_DIR}/platforms" 
        DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)
    install(DIRECTORY "${QT5_PLUGIN_DIR}/printsupport" 
        DESTINATION ${QT_PLUGIN_DEST_DIR} COMPONENT Runtime)

    # Install qt.conf file
    INSTALL(CODE "
        file(WRITE 
            \"\${CMAKE_INSTALL_PREFIX}/${QT_CONFIG_DEST_DIR}/qt.conf\" 
            \"
            \")
        " COMPONENT Runtime)

    # Fix library references
    install(CODE "
        file(GLOB_RECURSE QTPLUGINS
            \"\${CMAKE_INSTALL_PREFIX}/${QT_PLUGIN_DEST_DIR}/*${CMAKE_SHARED_LIBRARY_SUFFIX}\")
        include(BundleUtilities)
        fixup_bundle(\${CMAKE_INSTALL_PREFIX}/${QUMULUS}.app 
            \"\${QTPLUGINS}\" \"${QT5_LIBRARY_DIR}\")
        " COMPONENT Runtime)
elseif(WIN32)
    # XXX: experimental code!

    install(CODE "
        include(GetPrerequisites)

        get_prerequisites(\${CMAKE_INSTALL_PREFIX}/${QUMULUS}.exe WINDOWS_LIBRARIES 1 1 \"\" \"\")
        install(FILES \${WINDOWS_LIBRARIES} ${BINARY_PATH})
        " COMPONENT Runtime)

endif()


