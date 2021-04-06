#include "hello.h"
#include <stdio.h>

enum Seperator {
  COLON, COMMA, SPACE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, LEFT_CURLY_BRACE, RIGHT_CURLY_BRACE, SQUARE_BRACKET, NEWLINE
};


int is(enum Token expected) {
  if(currentToken == expected)
    return 0;
  else
    return 1;  
}

int issep() {
    
}

int iseol() {

}

int isoperator() {
   if(is(eq_operator) || is(not_operator) || is(noteq_operator) || is(gt_operator) || is(lt_operator)
	|| is(gteq_operator) || is(lteq_operator))
	   return 0;
   else
	return 1;
     
}

int function_call() {
   while(!eol()) {
      is(identifier);
   }   	   
}

int block() {
   if(is(identifier)) 
     if(is(assign_operator))
       expression();
     else
       function_call();
   else {
     if_statement();
     loop_statement();
     lambda_statement();
   }
}

int if_statement() {
   is(if_keyword);
   condition();
   block();
}

int loop_condition() {
    is(identifier);
}

int loop_statement() {
   is(loop_keyword);
   loop_condition();
   block();
}

int function_prototype() {
   while(!issep(RIGHT_PARENTHESIS)) {
     is(identifier);
     issep(COLON);
     is(identifier);
     issep(COMMA);
   }
   issep(COLON);
   is(identifier);
}

int lambda_statement() {
   is(identifier);
   function_prototype();
   is(assign_operator);
   block();   
}

int function_statement() {
   is(function_keyword);
   function_prototype();
   block();
}

int module_statement() {
   is(module_keyword);
   is(identifier);
   block();
}
