#include "../algo/Str.hpp"
#include "gtest/gtest.h"

namespace Algo {

// fixture
class StringTest: public testing::Test {
    // must make it protected
    protected:
        // setup will be called for each test
        void SetUp() override {
            S01.set("nestor");
            S02.set("sheryl");
        }

        Str S01;
        Str S02;

};

// fixture test
TEST_F(StringTest, Cmp) {
    EXPECT_NE(S01, S02);
}

TEST(CmpTest, Eq) {
    Str S03("nestor");
    Str S01("nestor");
    EXPECT_EQ(S01, S03);
}

} // end algo


int main(int argc, char **argv) {
    // initialize the framework
    testing::InitGoogleTest(&argc, argv);
    // macro
    return RUN_ALL_TESTS();
}