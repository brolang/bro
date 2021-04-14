#include "stdlib.h"

struct Call {
     
     char* identifier;
     
}


struct Call *callstack = NULL;
int top = 0;
int length = 0;

int create_callstack(struct Call *callstackactual) {
    callstack = callstackactual
}

int push(struct Call call) {
    	
    callstack = realloc(callstack, sizeof(struct Call)*length)
    callstack[top] = call;	    
    top = top + 1;
}

struct Call peek() {
    return callStack[top];

}

int pop() {
    callstack = realloc(callstack, sizeof(struct Call)*(top-1))
}
