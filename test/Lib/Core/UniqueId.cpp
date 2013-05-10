/*
 * Qumulus UML Editor 
 * Author: Frank Erens
 *
 */

#include <gtest/gtest.h>
#include <Lib/Core/UniqueId.h>

namespace {

    class TestUniqueId : public ::testing::Test {

    };

    TEST_F(TestUniqueId, testUnique) {
        for(size_t i = 0; i < 1024; ++i) {
            ASSERT_FALSE(QuLC::UniqueId() == QuLC::UniqueId());
        }
    }
} // namespace


