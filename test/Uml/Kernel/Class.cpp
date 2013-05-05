/*
 * Qumulus UML Editor 
 * Author: Frank Erens
 *
 */

#include <gtest/gtest.h>
#include <Uml/Kernel/Class.h>

namespace {

    class TestClass : public ::testing::Test {

    };

    TEST_F(TestClass, testCreate) {
        QuUK::Class* c = new QuUK::Class;
        delete c;
    }
} // namespace


