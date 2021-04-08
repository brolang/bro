#ifndef HELLO_H
#define HELLO_H

#define elif else if

enum Token {
    None, function_keyword, case_keyword, loop_keyword, module_keyword, type_keyword,
    and_operator, or_operator, assign_operator, eq_operator, gt_operator, not_operator, noteq_operator, 
    gteq_operator, lt_operator,	lteq_operator,
    identifier,
    number_literal, string_literal
};

enum Type {
    Expression, Statement,
    Variable, Operator, Literal, Keyword,
    Module, Function, Block, Case, Loop
};

int initParser(char* source);
enum Token parse();
enum Token peek();
int checkSeperator(char c);
int checkEol();

int case_statement();
int module_statement();
int loop_statement();
int function_statement();

#endif
