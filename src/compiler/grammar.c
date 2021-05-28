#include "hello.h"
#include "types.h"

#include <stdio.h>

enum Position {
    module, module_name, case_position, expression, block
};

enum Position current;
int blockIsOpen = 0;
int isPrototypeCall = 0;
int isMethod = 0;
int started = 0;



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


int interpret(char buffer[1024]) {
    lookup(buffer);
    if(started == 0) {
        started = 1;
        current = module;
    }

    if(current == module)
        interpret_module(buffer);
    elif(current == case_position)
        interpret_case(buffer);
}

int interpret_identifier(char* buffer) {
    int isIdentifier = returnIdentifier();
    if(!isIdentifier)
        printf("expected identifier")
}

int interpret_expression(char* buffer) {
    if(blockIsOpen) {
        current = block;
    } else {
        interpret_identifier(buffer);
    }
}

int interpret_block(char* buffer) {
    if(!blockIsOpen) {
        current = next;
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





