//
// Created by laihz on 19-4-3.
//

#include "laihzjson.h"
#include <cassert>
#include <sstream>
inline void EXPECT(std::string &context,char ch){
    assert(context[0]==ch);
    context=context.substr(1,context.length()-1);
}

static void lai_parse_whitespace(std::string &context){
    while (context[0]==' '|| context[0]=='\t' || context[0]=='\n' || context[0]=='\r'){
        context=context.substr(1,context.length()-1);
    }
}

static int lai_parse_null(std::string &context,lai_value* value){
    EXPECT(context,'n');
    if(context[0]!='u'||context[1]!='l'||context[2]!='l') return LAI_PARSE_INVALID_VALUE;
    context=context.substr(3,context.length()-1);
    value->type=LAI_NULL;
    return LAI_PARSE_OK;
}

int lai_parse_true(std::string &context, lai_value *value) {
    EXPECT(context,'t');
    if(context[0]!='r'||context[1]!='u'||context[2]!='e') return LAI_PARSE_INVALID_VALUE;
    context=context.substr(3,context.length()-1);
    value->type=LAI_TRUE;
    return LAI_PARSE_OK;
}


int lai_parse_false(std::string &context, lai_value *value) {
    EXPECT(context,'f');
    if(context[0]!='a'||context[1]!='l'||context[2]!='s'||context[3]!='e')
        return LAI_PARSE_INVALID_VALUE;
    context=context.substr(4,context.length()-1);
    value->type=LAI_FALSE;
    return LAI_PARSE_OK;
}

static int lai_parse_value(std::string &context,lai_value* value){
    switch (context[0]){
        case 'n':return lai_parse_null(context,value);
        case 't':return lai_parse_true(context,value);
        case 'f':return lai_parse_false(context,value);
        case '\0':return LAI_PARSE_EXPECT_VALUE;
        default:return LAI_PARSE_INVALID_VALUE;
    }
}

static int lai_parse_number(std::string &context,lai_value* value){
    /*TODO validate numbers*/
    std::string extraString;
    std::istringstream stringStream(context);
    stringStream >> value->num>>extraString;
    if(context==extraString)
        return LAI_PARSE_INVALID_VALUE;
    context=extraString;
    value->type=LAI_NUMBER;
    return LAI_PARSE_OK;
}

int lai_parse(lai_value* value,std::string &context){
    assert(value!=nullptr);
    value->type=LAI_NULL;
    lai_parse_whitespace(context);
    int return_value;
    if((return_value=lai_parse_value(context,value)) == LAI_PARSE_OK){
        lai_parse_whitespace(context);
        if(!context.empty())return_value=LAI_PARSE_ROOT_NOT_SINGULAR;
    }
    return return_value;
}

lai_type lai_get_type(const lai_value* value){
    assert(value!= nullptr);
    return value->type;
}

double lai_get_number(const lai_value* value){
    assert(value!= nullptr && value->type==LAI_NUMBER);
    return value->num;
}


