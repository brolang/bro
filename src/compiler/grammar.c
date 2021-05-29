#include "hello.h"
#include "types.h"
#include "compiler.h"
#include "../stats/stats.h"

#include <stdio.h>

enum Position {
    new_module, name, case_position, loop_block, 
    expression, block, object, type, macro
};

enum Position current;
enum Kind kind;
int blockIsOpen = 0;
int isPrototypeCall = 0;
int isMethod = 0;
int started = 0;
struct Token currentToken;
enum Keyword currentKeyword;

int lookup(char buffer[1024]) {
    enum Keyword keyword;
    keyword = returnKeyword(buffer);
}


int interpretSeperator(enum Seperator seperator) {
    if(seperator == LEFT_CURLY_BRACE){
        current = block;
        blockIsOpen = 1;
    } elif(seperator == RIGHT_CURLY_BRACE) {
        blockIsOpen = 0;
    } elif(seperator == LEFT_PARENTHESIS) {
        isPrototypeCall = 1;
    } elif(seperator == RIGHT_PARENTHESIS) {
        isPrototypeCall = 0;
    } elif(seperator == DOT) {
        isMethod = 1;
    } 
}

int expression_flag = 0;
struct Token expression_identifier;
struct Token expression_functioncall;

int set_expression_identifier(struct Token token) {
    expression_identifier = token;
}

int set_expression_functioncall(struct Token token) {
    expression_functioncall = token;
}

int interpret_identifier(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != None)
        printf("expected identifier");
    if(expression_flag == 0)
        set_expression_identifier(currentToken);
    elif(expression_flag == 1)
        set_expression_functioncall(currentToken);
}

int interpret_literal(char* buffer) {
    enum Literal literal = returnLiteral(buffer,currentToken.length);
    if(literal == none_literal)
        printf("expected literal");
}


int interpret_expression(char* buffer) {
    if(blockIsOpen) {
        create_expression(expression_identifier,expression_functioncall);
        current = block;
    } else {
        if(expression_flag == 0)
            expression_flag = 1;
        else
            expression_flag = 0;
        interpret_identifier(buffer);
    }
}

int interpret_block(char* buffer) {
    if(!blockIsOpen) {
        returnToParentBlock();
    } else {
        interpret_expression(buffer);
    }
}

int interpret_module(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != module_keyword)
        printf("expected module keyword\n");
    current = name;
    init_module();
}

int interpret_case(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != case_keyword)
        printf("expected case keyword\n");
    current = expression;
    currentKeyword = keyword;
    create_block(keyword);
}

int interpret_loop(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != loop_keyword)
        printf("expected loop keyword");
    current = expression;
    currentKeyword = keyword;
    create_block(keyword);
}

int interpret_type(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != type_keyword)
        printf("expected type keyword");
    current = name;
    currentKeyword = keyword;
    create_block(keyword);
}

int interpret_object(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != object_keyword)
        printf("expected object keyword");
    current = name;
    currentKeyword = keyword;
    create_block(keyword);
}

int interpret_macro(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != macro_keyword)
        printf("expected macro keyword");
    current = name;
    currentKeyword = keyword;
    create_block(keyword);
}

int interpret(struct Token token) {
    currentToken = token;
    lookup(token.identifier);
    if(started == 0) {
        started = 1;
        current = module;
    } else {
        enum Keyword keyword = returnKeyword(currentToken.identifier);
        if(keyword == case_keyword)
            current = case_position;
        elif(keyword == loop_keyword)
            current = loop;
        elif(keyword == object_keyword)
            current = object;
        elif(keyword = type_keyword)
            current = type;
        elif(keyword = macro_keyword)
            current = macro;
    }

    if(current == module)
        interpret_module(token.identifier);
    elif(current == case_position)
        interpret_case(token.identifier);
    elif(current == loop)
        interpret_loop(token.identifier);
    elif(current == object)
        interpret_object(token.identifier);
    elif(current == type)
        interpret_type(token.identifier);
    elif(current == macro)
        interpret_macro(token.identifier);
}

