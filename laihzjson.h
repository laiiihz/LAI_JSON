//
// Created by laihz on 19-4-3.
//

#ifndef LAI_JSON_LAIHZJSON_H
#define LAI_JSON_LAIHZJSON_H

#include <iostream>
typedef  enum {
    LAI_NULL,
    LAI_FALSE,LAI_TRUE,
    LAI_NUMBER,
    LAI_STRING,
    LAI_ARRAY,
    LAI_OBJECT

}lai_type;

typedef struct {
    lai_type type;
}lai_value;

enum {
    LAI_PARSE_OK=0,
    LAI_PARSE_EXPECT_VALUE,
    LAI_PARSE_INVALID_VALUE,
    LAI_PARSE_ROOT_NOT_SINGULAR
};

int lai_parse(lai_value* value, std::string &json);
static int lai_parse_value(std::string &context,lai_value* value);
static void lai_parse_whitespace(std::string &context);
static int lai_paese_null(std::string &context,lai_value* value);

#endif //LAI_JSON_LAIHZJSON_H
