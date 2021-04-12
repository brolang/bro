#include "hello.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct {
    FILE* source_file;
    char* source;
    int source_pos;
    char identifier[1024];
    enum Token token;
    int source_length;
    int line_number;
} Parser;


enum Token returnToken(char* token){
    if(token[0] == 'f' && token[1] == 'n')
	    return function_keyword;
    elif(token[0] == 'c' && token[1] == 'a' && token[2] == 's' && token[3] == 'e')
	    return case_keyword;
    elif(token[0] == 'l' && token[1] == 'o' && token[2] == 'o' && token[3] == 'p')
	    return loop_keyword;
    elif(token[0] == 'c' && token[1] == 'a' && token[2] == 'c' && token[3] == 't' && token[4] == 'c' && token[5] == 'h')
	    return catch_keyword;
    elif(token[0] == 'm' && token[1] == 'o' && token[2] == 'd' && token[3] == 'u' && token[4] == 'l' && token[5] == 'e')
	    return module_keyword;
    elif(token[0] == 't' && token[1] == 'y' && token[2] == 'p' && token[3] == 'e')
	    return type_keyword;
    elif(token[0] = 'm' && token[1] == 'a' && token[2] == 'c' && token[3] == 'o')
	    return macro_keyword;
    else
	    return identifier;
}

struct node {
   enum Token token;
   char* identifier;
   enum Type nodeType;
   int lineno;
   int pos;
   struct node* next;
};

struct node table;
enum Token currentToken;


enum Type getType(enum Token current) {
}

int next() {
   if(Parser.token == module_keyword)
       module_statement();
   elif(Parser.token == function_keyword)
       function_statement();
   elif(Parser.token == loop_keyword)
       loop_statement();
   return 0;
}

int insert(enum Token token) {
   struct node *temp = NULL;
   temp = &table;
   if (temp->token == None) {
      temp->token = token;
      return 0;
   }

   while(temp->next != NULL)
      temp = temp->next;
   
   if(temp->next == NULL) {
      temp->next = malloc(sizeof(struct node));
      temp->next->token = token;
      temp->next->nodeType = getType(token);
   }
   return 0;
}

int checkSeperator(char seperator) {
  return 1;
}

int checkEol() {
  return 1;
}


enum Token peek() {
  int before = Parser.source_pos;
  enum Token token = parse();
  Parser.source_pos = before;
  return token;
}

int noMoreTokens() {
  //printf("Tokens %d %d\n",Parser.source_length, Parser.source_pos);
  if (Parser.source_length == Parser.source_pos) 
      return 1;
  else
      return 0;
}

enum Seperator parseSeperator(char seperator) {
    if(seperator == ' ') 
        return SPACE;
    elif(seperator == '\n')
        return NEWLINE;
    elif(seperator == '{')
        return LEFT_CURLY_BRACE;
    elif(seperator == '}')
	return RIGHT_CURLY_BRACE;
    elif(seperator == '(')
	return LEFT_PARENTHESIS;
    elif(seperator == ')')
	return RIGHT_PARENTHESIS;
    elif(seperator == ',')
	return COMMA;
    elif(seperator == ':') 
	return  COLON;
    else
        return NoneSeperator;
}

enum Token parse() {
    //printf("%d",Parser.source_pos);
    char buffer[1024]={0};
    int pos = 0;
    int flag = 0;
    
    while(Parser.source_pos < Parser.source_length && Parser.source[Parser.source_pos]!='\0') {
	if(parseSeperator(Parser.source[Parser.source_pos])!=NoneSeperator) { 
	    if(flag == 0) {
	        //is(buffer);
		flag = 1;
	    }
	    Parser.source_pos = Parser.source_pos + 1;
	} else {
	    buffer[pos] = Parser.source[Parser.source_pos];
	    pos = pos + 1;
	    Parser.source_pos = Parser.source_pos + 1;
	    if(flag == 1)
	        flag = 0;
	}
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

