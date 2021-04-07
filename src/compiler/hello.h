#ifndef HELLO_H
#define HELLO_H

enum Token {
    None, function_keyword, if_keyword, else_keyword, loop_keyword, module_keyword, type_keyword,
    and_operator, or_operator, assign_operator, eq_operator, gt_operator, not_operator, noteq_operator, 
    gteq_operator, lt_operator,	lteq_operator,
    identifier,
    number_literal, string_literal
};

enum Scope {
    Expression, Statement,
    Variable, Operator, Literal, Keyword,
    Module, Function, Block, If, Loop
};

int initParser(char* source);
enum Token parse(char* source);
int seperator(char c);
int eol();

int if_statement();
int module_statement();
int loop_statement();
int function_statement();

#endif
