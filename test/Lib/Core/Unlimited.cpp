/*
 * Qumulus UML Editor 
 * Author: Frank Erens
 *
 */

#include <gtest/gtest.h>
#include <Lib/Core/Unlimited.h>

namespace {

    class TestUnlimited : public ::testing::Test {

    };

    TEST_F(TestUnlimited, testCreateNumeric) {
        QuLC::Unlimited u = 3;
        EXPECT_EQ((unsigned)u, 3);
        EXPECT_FALSE(QuLC::unltd(u));
    }

    TEST_F(TestUnlimited, testCreateUnlimited) {
        QuLC::Unlimited u = "*";
        EXPECT_TRUE(QuLC::unltd(u));
    }

    TEST_F(TestUnlimited, testCreateQString) {
        QuLC::Unlimited u(QString("33"));
        EXPECT_EQ((unsigned)u, 33);
    }

    TEST_F(TestUnlimited, testCreateQStringUnlimited) {
        QuLC::Unlimited u(QString("*"));
        EXPECT_TRUE(QuLC::unltd(u));
    }

    TEST_F(TestUnlimited, testCreateQStringInvalid) {
        EXPECT_THROW(QuLC::Unlimited(QString("hello!")), 
                QuLC::ArgumentException);
    }

    TEST_F(TestUnlimited, testCreateCharInvalid) {
        EXPECT_THROW(QuLC::Unlimited("3"), 
                QuLC::ArgumentException);
    }

} // namespace


