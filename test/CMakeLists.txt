###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
#
###############################################################################

include(SourcesList.txt)
include(AddFileDependencies)

include_directories(${CMAKE_SOURCE_DIR}/src/Qumulus 
        ${CMAKE_SOURCE_DIR}/deps/gtest/include)

# Use this for building gtest with clang
add_definitions(
    -DGTEST_USE_OWN_TR1_TUPLE
    -DGTEST_HAS_TR1_TUPLE
)

add_executable(
    QumulusTestExe EXCLUDE_FROM_ALL ${QUMLTEST_ALL_SRC}
)

target_link_libraries(
    QumulusTestExe quml gtest
)

qt5_use_modules(QumulusTestExe Core)

add_custom_target(test QumulusTestExe DEPENDS QumulusTestExe)
