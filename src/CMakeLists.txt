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
qt5_use_modules(${QUMULUS} Widgets)

if(APPLE)
    set_target_properties(${QUMULUS} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${PLIST_PATH})
endif()

# Deployment
if(APPLE)
    # Install Qt plugins
    # TODO

    # Fix library references
    install(CODE "
        include(BundleUtilities)
        fixup_bundle(${CMAKE_BINARY_DIR}/src/${QUMULUS}.app \"\" \"\")
        " COMPONENT Runtime)
elseif(WIN32)
    # XXX: experimental code!

    install(CODE "
        include(GetPrerequisites)

        get_prerequisites(${QUMULUS}.exe WINDOWS_LIBRARIES 1 1 \"\" \"\")
        install(FILES $\{WINDOWS_LIBRARIES\} ${BINARY_PATH})
        " COMPONENT Runtime)

endif()

# Installation
install(TARGETS ${QUMULUS} 
    RUNTIME DESTINATION ${BINARY_DEST} 
    BUNDLE DESTINATION ${BINARY_DEST})
