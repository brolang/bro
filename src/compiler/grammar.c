#include "hello.h"
#include <stdio.h>



int is(enum Token token) {
  if(parse() == token) {
    insert(token);
    return 0;
  } else {
    return 1;
  }
}

int iscompareoperator() {
    if(is(eq_operator) || is(not_operator) || is(noteq_operator) || is(gt_operator) || is(lt_operator)
	|| is(gteq_operator) || is(lteq_operator))
	   return 0;
    else
	   return 1;
     
}

int ismath_operator() {
   if(is(add_operator) || is(multiplication_operator) || is(division_operator) || is(subtraction_operator))
       return 0;
   else
       return 1;
}



//expression
//identifier operator expression

void declaration() {
    is(identifier);
    if(checkSeperator(':')) {
      is(identifier);
    }
}

void condition() {
    is(identifier);
    iscompareoperator();
    condition();
}

void iterator() {    
    while(!peek(assign_operator))	
       is(identifier);
       checkSeperator(',');
    is(assign_operator);
    
}

void math_expression() {
    is(identifier);
    ismath_operator();
    math_expression();
}


void block () {
    if(peek(identifier))
       math_expression();
    elif(peek(loop_keyword))
       loop_statement();
}

void loop_statement() {
    is(loop_keyword);
    condition();
    block();
}



void function_arg() {
    is(identifier);
}

void function_prototype() {
    while(!checkEol())
      function_arg();  
}

void function_statement() {
    is(identifier);
    function_prototype();
    block();
}


void module_statement() {
    is(module_keyword);
    is(string_literal);
    block();
}

