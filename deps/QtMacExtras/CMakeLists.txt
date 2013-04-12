###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
#
###############################################################################

set(QTMACEXTRAS_SRC
    qmaccocoaviewcontainer.mm
    qmacfunctions.mm
    qmacnativewidget.mm
    qmacpasteboardmime.mm
    qmactoolbardelegate.mm
    qmactoolbutton.mm
    qmacunifiedtoolbar.mm
    qnstoolbar.mm
)

find_library(COCOA_LIBRARIES Cocoa)

include_directories(${Qt5Gui_PRIVATE_INCLUDE_DIRS})
add_library(QtMacExtras SHARED ${QTMACEXTRAS_SRC})
target_link_libraries(QtMacExtras ${COCOA_LIBRARIES})
qt5_use_modules(QtMacExtras Widgets)
