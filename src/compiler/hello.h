#ifndef HELLO_H
#define HELLO_H

#define elif else if

enum Keyword {
    None, case_keyword, loop_keyword, type_keyword, catch_keyword, macro_keyword,
    object_keyword,
    module_keyword, abstract_keyword, design_keyword, code_keyword
};

enum Literal {
    none_literal,integer_literal, double_literal, float_literal, string_literal, true_literal, false_literal
};

enum Seperator { 
    NoneSeperator, SPACE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, 
    LEFT_CURLY_BRACE, RIGHT_CURLY_BRACE, SQUARE_BRACKET, NEWLINE, DOT,
    HASH, COLON
};

int initParser(char* source, int source_length);
int parse();

enum Keyword returnKeyword(char* buffer);
enum Literal returnLiteral(char* buffer, int length);

struct Token {
   char* identifier;
   int lineno;
   int length;
   int position;
};


int interpret(struct Token token);
int interpretSeperator(enum Seperator seperator);


#endif
