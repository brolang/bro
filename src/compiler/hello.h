#ifndef HELLO_H
#define HELLO_H

#define elif else if

enum Token {
    None, function_keyword, case_keyword, loop_keyword, module_keyword, type_keyword,
    catch_keyword, macro_keyword, identifier,
    integer_literal, double_literal, float_literal, string_literal, boolean_literal
};

enum Type {
    Expression, Statement,
    Variable, Operator, Literal, Keyword,
    Module, Function, Block, Case, Loop
};
enum Seperator { 
    NoneSeperator, COLON, COMMA, SPACE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, LEFT_CURLY_BRACE, RIGHT_CURLY_BRACE,
    SQUARE_BRACKET, NEWLINE                                                                                 };

int initParser(char* source, int source_length);
int insert(enum Token token);
int next();
enum Token parse();
enum Token peek();
int noMoreTokens();
int checkSeperator(char c);
int checkEol();


void module_statement();
void loop_statement();
void function_statement();

#endif
