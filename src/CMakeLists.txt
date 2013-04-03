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

# quml library
add_library(quml STATIC ${QUML_ALL_SRC})
qt5_use_modules(quml Core)

# Qumulus application
add_executable(${QUMULUS} MACOSX_BUNDLE main.cpp ${QUMULUS_GUI_ALL_SRC})
target_link_libraries(${QUMULUS} quml)
qt5_use_modules(${QUMULUS} Widgets)

if(APPLE)
    set_target_properties(${QUMULUS} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${PLIST_PATH})
endif()

# Installation
if(APPLE)
    install(CODE 
        "include(BundleUtilities)
        fixup_bundle(${CMAKE_CURRENT_BINARY_DIR}/${QUMULUS}.app \"\" \"\")
        " COMPONENT Runtime)
endif()

install(TARGETS ${QUMULUS} 
    RUNTIME DESTINATION ${BINARY_PATH} 
    BUNDLE DESTINATION ${BINARY_PATH})
