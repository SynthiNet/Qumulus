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
