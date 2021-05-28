#include "stats.h"

int is(enum Kind kind) {
    if(last == variable)
        next = functioncall;
    elif(last = functioncall)
        next = variable;
    elif(last == module)
        next = identifier;
    elif(last == case_kind)
        next = condition;
    elif(last == loop)
        next = condition;
}