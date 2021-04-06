#define elif else if

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Token {
     None, function_keyword, if_keyword, elif_keyword, else_keyword, for_keyword, while_keyword, module_keyword,
     type_keyword,
     and_operator, or_operator, eq_operator, gt_operator, not_operator, noteq_operator, gteq_operator, lt_operator,
     lteq_operator,
     identifier,
};

enum Scope {
     Block, Expression, Statement,
     Variable, Operator, Literal, Keyword
}


enum Token returnToken(char* token){
    if(token[0] == 'f' && token[1] == 'n')
	    return function_keyword;
    elif(token[0] == 'i' && token[1] == 'f')
	    return if_keyword;
    elif(token[0] == 'e' && token[1] == 'l' && token[2] == 'i' && token[3] == 'f')
	    return elif_keyword;
    elif(token[0] == 'e' && token[1] == 'l' && token[2] == 's' && token[3] == 'e')
	    return else_keyword;
    elif(token[0] == 'f' && token[1] == 'o' && token[2] == 'r')
    	    return for_keyword;
    elif(token[0] == 'w' && token[1] == 'h' && token[2] == 'l' && token[3] == 'e')
	    return while_keyword;
    elif(token[0] == 'm' && token[1] == 'o' && token[2] == 'd' && token[3] == 'u' && token[4] == 'l' && token[5] == 'e')
	    return module_keyword;
    elif(token[0] == 't' && token[1] == 'y' && token[2] == 'p' && token[3] == 'e')
	    return type_keyword;
    elif(token[0] == 'a' && token[1] == 'n' && token[2] == 'd')
	    return and_operator
    elif(token[0] == 'o' && token[1] == 'r')
    	    return or_operator
    elif(token[0] == 'n' && token[1] == 'o' && token[2] == 't')
    	    return not_operator
    elif(token[0] == '=')
    	    return eq_operator
    elif(token[0] == '>')
    	    return gt_operator
    elif(token[0] == '<')
    	    return lt_operator
    elif(token[0] == '>' && token[1] == '=')
	    return gteq_operator
    elif(token[0] == '<' && token[1] == '=')
	    return lteq_operator    
    else
	    return identifier;
}

struct node {
   enum Token token;
   enum Scope scope;
   enum Token nextToken;
   struct node* next;
};

struct node table;
enum Token currentToken;


enum Scope getScope(enum Scope current) {
}

enum Token nextToken(enum Scope scope) {

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
      if (temp->nextToken == token) {
	 temp->next->token = token;
         temp->next->scope = getScope(token);
	 temp->next->nextToken = getNext(temp->next->scope);
      } else {
      	printf("Parsing failed");
	exit(0);
      }
	    
   }

}

int parseFile(FILE* f) {
  char c = 0;
  char buffer[1024];
  int tlen = 0;
  while ((c = fgetc(f))!=EOF){
       printf("%c",c);
       buffer[tlen++] = c;
       if (c == ' ' || c == '\n') {
       	  enum Token token = returnToken(buffer); 
          insert(token);	  
          tlen = 0;
	  memset(buffer, 0, sizeof(buffer));
       }

  }
}

int main(int argc, char** argv){
    FILE* f;
    f = fopen(argv[1], "r");
    if(f == NULL) {
    	printf("Couldnt open file");
	return 0;
    }
    parseFile(f);
}
