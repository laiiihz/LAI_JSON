#include <gtest/gtest.h>
#include "laihzjson.h"
TEST(TEST_PARSE,TEST_PARSE_NULL){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString="null";
    EXPECT_EQ(LAI_PARSE_OK,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
}

TEST(TEST_PARSE,TEST_PARSE_TRUE){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString="true";
    EXPECT_EQ(LAI_PARSE_OK,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_TRUE,lai_get_type(&value));
}

TEST(TEST_PARSE,TEST_PARSE_FALSE){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString="false";
    EXPECT_EQ(LAI_PARSE_OK,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_FALSE,lai_get_type(&value));
}

TEST(TEST_PARSE,TEST_PARSE_EXPECT_VALUE){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString=" ";
    EXPECT_EQ(LAI_PARSE_EXPECT_VALUE,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));

    value.type=LAI_FALSE;
    std::string tempString1;
    EXPECT_EQ(LAI_PARSE_EXPECT_VALUE,lai_parse(&value,tempString1));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
}

TEST(TEST_PARSE,TEST_PARSE_INVALID_VALUE){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString="nul";
    EXPECT_EQ(LAI_PARSE_INVALID_VALUE,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
    tempString="?";
    EXPECT_EQ(LAI_PARSE_INVALID_VALUE,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
}

TEST(TEST_PARSE,TEST_PARSE_ROOT_NOT_SINGULAR){
    lai_value value;
    value.type=LAI_FALSE;
    std::string tempString="null x";
    EXPECT_EQ(LAI_PARSE_ROOT_NOT_SINGULAR,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
    tempString=" null v";
    EXPECT_EQ(LAI_PARSE_ROOT_NOT_SINGULAR,lai_parse(&value,tempString));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
}



int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}