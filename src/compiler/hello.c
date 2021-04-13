#include "hello.h"
#include "types.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct {
    FILE* source_file;
    char* source;
    int source_pos;
    char identifier[1024];
    int source_length;
    int line_number;
} Parser;


enum Keyword returnKeyword(char* token){
    if(token[0] == 'c' && token[1] == 'a' && token[2] == 's' && token[3] == 'e')
	    return case_keyword;
    elif(token[0] == 'l' && token[1] == 'o' && token[2] == 'o' && token[3] == 'p')
	    return loop_keyword;
    elif(token[0] == 'c' && token[1] == 'a' && token[2] == 'c' && token[3] == 't' && token[4] == 'c' && token[5] == 'h')
	    return catch_keyword;
    elif(token[0] == 't' && token[1] == 'y' && token[2] == 'p' && token[3] == 'e')
	    return type_keyword;
    elif(token[0] == 'm' && token[1] == 'a' && token[2] == 'c' && token[3] == 'o')
	    return macro_keyword;
    else
	    return None;
}

enum Literal returnInteger(char* buffer,int length) {
	int i = 0;
	while(i < length  && isdigit(buffer[i])) {
            i = i + 1;
	}
	return integer_literal;
}

enum Literal returnString(char* buffer, int length) {
	if(buffer[0] == '"' && buffer[length-1] == '"')
		return string_literal;
}

enum Literal returnBoolean(char* buffer, int length) {
    if(buffer[0] == 't' && buffer[1] == 'r' && buffer[2] == 'u' && buffer[3] == 'e')
        return true_literal;
    elif(buffer[0] == 'f' && buffer[1] == 'a' && buffer[2] == 'l' && buffer[3] == 's' && buffer[4] == 'e')
        return false_literal;
}

struct Token {
   char* identifier;
   int lineno;
   int length;
   int position;
};

struct Token returnToken(char* identifier, int lineno, int length, int position) {
    struct Token token;
    token.identifier = identifier;
    token.lineno = lineno;
    token.length = length;
    token.position = position;
}


struct Token nextToken;


enum Kind getKind(struct Token token) {

}

int setNextToken(struct Token token) {
    nextToken = token;

}

struct Token tokenNext() {
    return nextToken;
}

enum Seperator nextSeperator;

int setNextSeperator(enum Seperator seperator) {
    nextSeperator = seperator;
}

int seperatorNext() {
    return nextSeperator;
}



enum Seperator parseSeperator(char seperator) {
    if(seperator == ' ') 
        setNextSeperator(SPACE);
    elif(seperator == '\n')
        setNextSeperator(NEWLINE);
    elif(seperator == '{')
        setNextSeperator(LEFT_CURLY_BRACE);
    elif(seperator == '}')
	setNextSeperator(RIGHT_CURLY_BRACE);
    elif(seperator == '(')
	setNextSeperator(LEFT_PARENTHESIS);
    elif(seperator == ')')
	setNextSeperator(RIGHT_PARENTHESIS);
    else
        return NoneSeperator;
}

int parse() {
    //printf("%d",Parser.source_pos);
    char buffer[1024]={0};
    int length = 0;
    int flag = 0;
    int position = 0;
    while(Parser.source_pos < Parser.source_length && Parser.source[Parser.source_pos]!='\0') {
	    if(parseSeperator(Parser.source[Parser.source_pos])!=NoneSeperator) {
	        if(flag == 0) {
	            struct Token token = returnToken(buffer,Parser.line_number,length,position - length);		
	            setNextToken(token);
		    flag = 1;
		    length = 0;
		    memset(buffer, 0, sizeof(buffer));
	       }
	       Parser.source_pos = Parser.source_pos + 1;
	   } else {
	       buffer[length] = Parser.source[Parser.source_pos];
	       length = length + 1;
	       Parser.source_pos = Parser.source_pos + 1;
	       if(flag == 1)
	           flag = 0;
	   }
	   position = position + 1;
    }
}

int initParser(char* source, int source_length) {
    Parser.source = source;
    Parser.source_length = source_length;
    Parser.line_number = Parser.line_number + 1;
    return 0;
}

int parseFile(char* name) {
    Parser.source_file = fopen(name, "r");
    char buffer[1024];
    char c = 0;
    int i = 0;
    while((c=fgetc(Parser.source_file))!='\n') {
	buffer[i] = c;
        i = i + 1;
    }
    initParser(buffer,i);
    return 0;
}

struct Value nextValue() {
     struct Value value;
     struct Token token;

     token = tokenNext();

     strcat(value.identifier, token.identifier);
     return value;
}

struct Map nextMap() {
     struct Map map;
     map.key = nextValue();
     map.value = nextValue();
     return map;
}

struct Record nextRecord() {
     struct Record record;
}

//struct List nextList(struct Token token) {
//
//}

