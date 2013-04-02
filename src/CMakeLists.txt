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

add_library(quml STATIC ${QUML_ALL_SRC})
qt5_use_modules(quml Core)

add_executable(qumulus main.cpp ${QUMULUS_GUI_ALL_SRC})
target_link_libraries(qumulus quml)
qt5_use_modules(qumulus Widgets)
