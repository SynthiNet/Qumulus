/*
 * Qumulus UML Editor 
 * Author: Frank Erens
 *
 */

#include <gtest/gtest.h>
#include <Lib/Core/All.h>

namespace {

    class TestOptional : public ::testing::Test {

    };

    TEST_F(TestOptional, testConstructEmpty) {
        QuLC::Optional<int> o;
        EXPECT_FALSE((bool)o);
    }

    TEST_F(TestOptional, testConstructValue) {
        QuLC::Optional<int> o(3);
        EXPECT_TRUE((bool)o);
        EXPECT_EQ(3, *o);
    }

    TEST_F(TestOptional, testEmptyThrow) {
        QuLC::Optional<int> o;
        EXPECT_THROW(*o, QuLC::NullException);
    }
} // namespace


