#include <gtest/gtest.h>
#include "laihzjson.h"
TEST(TEST_PARSE,TEST_PARSE_NULL){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString="null";
    EXPECT_EQ(LAI_PARSE_OK,lai_parse(&value,tempString));

}

TEST(TEST_PARSE,TEST_PARSE_EXPECT_VALUE){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString=" ";
    EXPECT_EQ(LAI_PARSE_EXPECT_VALUE,lai_parse(&value,tempString));

}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}