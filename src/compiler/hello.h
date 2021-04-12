#ifndef HELLO_H
#define HELLO_H

#define elif else if

enum Keyword {
    None, case_keyword, loop_keyword, type_keyword, catch_keyword, macro_keyword
};

enum Literal {
    integer_literal, double_literal, float_literal, string_literal, true_literal, false_literal
};

enum Kind {
    Keyword, Literal, Block
};

enum Seperator { 
    NoneSeperator, COLON, COMMA, SPACE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, LEFT_CURLY_BRACE, RIGHT_CURLY_BRACE,
    SQUARE_BRACKET, NEWLINE                                                               
};

int initParser(char* source, int source_length);
int insert(enum Token token);
int next();
int parse();

//literals
enum Literal returnInteger(char* buffer, int length);
enum Literal returnString(char* buffer, int length);

int noMoreTokens();
int checkSeperator(char c);
int checkEol();


void module_statement();
void loop_statement();
void function_statement();

#endif
