#include "hello.h"
#include <stdio.h>

enum Seperator {
  COLON, COMMA, SPACE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, LEFT_CURLY_BRACE, RIGHT_CURLY_BRACE, SQUARE_BRACKET, NEWLINE
};


int is(enum Token expected) {
  if(parse() == expected)
    return 0;
  else
    return 1;  
}

int isoperator() {
   if(is(eq_operator) || is(not_operator) || is(noteq_operator) || is(gt_operator) || is(lt_operator)
	|| is(gteq_operator) || is(lteq_operator))
	   return 0;
   else
	return 1;
     
}

int expression() {
    is(identifier);
    isoperator();
    expression();
}

int declaration() {
    is(identifier);
    checkSeperator(':');
    is(identifier);
}

int condition() {
    is(identifier);
    isoperator();
    condition();
}

int iterator() {
    
    while(!peek(assign_operator))	
       is(identifier);
    is(yield_keyword)
}

int if_block() {

}

int case_statement() {
    is(case_keyword);
    condition();
    if_block();
}

int loop_block() {
    if(peek(identifier))
        
}

int loop_statement() {
    is(loop_keyword);
    condition();
    loop_block();
}



int function_arg() {
    is(identifier);
}

int function_prototype() {
    while(!checkEol())
      function_arg();  
}


int function_block() {
    if(is(identifier))
	expression();
    elif(peek(if_keyword))
	if_statement();
    elif(peek(loop_keyword))
	loop_statement();
}

int function_statement() {
    is(identifier);
    function_prototype();
    function_block();
}

int module_block() {
    if(is(function_keyword))
	function_statement();
}

int module_statement() {
    is(module_keyword);
    is(string_literal);
    module_block();
}

