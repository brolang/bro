#include "debug.h"
#include <stdio.h>

enum Symbol current;

int enable_debug(enum Symbol symbol){
    current = symbol;
    return 0;
}

int info(char* name, char* value) {
    printf("%d %s = %s",current,name,value);
    return 0;
}
