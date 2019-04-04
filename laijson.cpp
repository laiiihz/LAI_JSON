//
// Created by laihz on 19-4-3.
//

#include "laihzjson.h"
#include <cassert>
#define EXPECT(context,ch) \
do{\
    assert(context[0]==ch);\
    context=context.substr(1,context.length()-1);\
}while(0)

static void lai_parse_whitespace(std::string &context){
    while (context[0]==' '|| context[0]=='\t' || context[0]=='\n' || context[0]=='\r'){
        context=context.substr(1,context.length()-1);
    }
}

static int lai_paese_null(std::string &context,lai_value* value){
    EXPECT(context,'n');
    if(context[0]!='u'||context[1]!='l'||context[2]!='l') return LAI_PARSE_INVALID_VALUE;
    context=context.substr(3,context.length()-1);
    value->type=LAI_NULL;
    return LAI_PARSE_OK;
}

static int lai_parse_value(std::string &context,lai_value* value){
    switch (context[0]){
        case 'n':return lai_paese_null(context,value);
        case '\0':return LAI_PARSE_EXPECT_VALUE;
        default:LAI_PARSE_INVALID_VALUE;
    }
}

int lai_parse(lai_value* value,std::string &context){
    assert(value!=nullptr);
    value->type=LAI_NULL;
    lai_parse_whitespace(context);
    return lai_parse_value(context,value);
}