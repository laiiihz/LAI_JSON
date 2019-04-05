#include <gtest/gtest.h>
#include "laihzjson.h"

inline void TEST_NUMBER_UNIT(double expect,std::string json){
        lai_value value;
        EXPECT_EQ(LAI_PARSE_OK,lai_parse(&value,json));
        EXPECT_EQ(LAI_NUMBER,lai_get_type(&value));
        EXPECT_EQ(expect,lai_get_number(&value));
}

inline void TEST_ERROR(int error,std::string json) {
    lai_value value;
    value.type=LAI_FALSE;
    EXPECT_EQ(error,lai_parse(&value,json));
    EXPECT_EQ(LAI_NULL,lai_get_type(&value));
}

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

    /* invalid number */
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "+0");
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "+1");
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, ".123"); /* at least one digit before '.' */
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "1.");   /* at least one digit after '.' */
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "INF");
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "inf");
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "NAN");
    TEST_ERROR(LAI_PARSE_INVALID_VALUE, "nan");
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

TEST(TEST_PARSE,TEST_PARSE_NUMBER){
    TEST_NUMBER_UNIT(0.0,"0");
    TEST_NUMBER_UNIT(0.0, "`-0");
    TEST_NUMBER_UNIT(0.0, "-0.0");
    TEST_NUMBER_UNIT(1.0, "1");
    TEST_NUMBER_UNIT(-1.0, "-1");
    TEST_NUMBER_UNIT(1.5, "1.5");
    TEST_NUMBER_UNIT(-1.5, "-1.5");
    TEST_NUMBER_UNIT(3.1416, "3.1416");
    TEST_NUMBER_UNIT(1E10, "1E10");
    TEST_NUMBER_UNIT(1e10, "1e10");
    TEST_NUMBER_UNIT(1E+10, "1E+10");
    TEST_NUMBER_UNIT(1E-10, "1E-10");
    TEST_NUMBER_UNIT(-1E10, "-1E10");
    TEST_NUMBER_UNIT(-1e10, "-1e10");
    TEST_NUMBER_UNIT(-1E+10, "-1E+10");
    TEST_NUMBER_UNIT(-1E-10, "-1E-10");
    TEST_NUMBER_UNIT(1.234E+10, "1.234E+10");
    TEST_NUMBER_UNIT(1.234E-10, "1.234E-10");
    TEST_NUMBER_UNIT(0.0, "1e-10000");
}


int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}