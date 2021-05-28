#include "hello.h"
#include "types.h"
#include "../stats/stats.h"

#include <stdio.h>

enum Position {
    module, module_name, case_position, loop, expression, block
};

enum Position current;
enum Kind kind;
int blockIsOpen = 0;
int isPrototypeCall = 0;
int isMethod = 0;
int started = 0;
struct Token currentToken;


int lookup(char buffer[1024]) {
    enum Keyword keyword;
    keyword = returnKeyword(buffer);
}


int interpretSeperator(enum Seperator seperator) {
    if(seperator == LEFT_CURLY_BRACE){
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


int interpret(struct Token token) {
    currentToken = token;
    lookup(token.identifier);
    if(started == 0) {
        started = 1;
        current = module;
    }

    if(current == module)
        interpret_module(token.identifier);
    elif(current == case_position)
        interpret_case(token.identifier);
    elif(current = loop)
        interpret_loop(token.identifier);
}

int interpret_identifier(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != None)
        printf("expected identifier");
}

int interpret_integer(char* buffer) {
    enum Literal literal = returnInteger(buffer,currentToken.length);
    if(literal != integer_literal)
        printf("expected integer");
}

int interpret_string(char* buffer) {
    enum Literal literal = returnString(buffer,currentToken.length);
    if(literal != string_literal)
        printf("expected string");
}

int interpret_boolean(char* buffer) {
    enum Literal literal = returnBoolean(buffer,currentToken.length);
    if(literal != true_literal || literal != false_literal)
        printf("expected boolean");
}

int interpret_expression(char* buffer) {
    if(blockIsOpen) {
        current = Block;
    } else {
        if(kind == variable) 
            interpret_identifier(buffer);
    }
}

int interpret_block(char* buffer) {
    if(!blockIsOpen) {
        
    } else {
        interpret_expression(buffer);
    }
}

int interpret_module(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != module_keyword)
        printf("expected module keyword\n");
    
}

int interpret_case(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != case_keyword)
        printf("expected case keyword\n");
    current = expression;
}

int interpret_loop(char* buffer) {
    enum Keyword keyword = returnKeyword(buffer);
    if(keyword != loop_keyword)
        printf("expected loop keyword");
    current = expression;
}





