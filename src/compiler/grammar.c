#include "hello.h"
#include "types.h"

#include <stdio.h>

enum Keyword currentKeyword;

int lookup(char buffer[1024]) {
    enum Keyword keyword;
    keyword = returnKeyword(buffer);
}



int interpret(char buffer[1024]) {
    lookup(buffer);
    
}

int interpretBlock(struct Block block) {
}

int interpretRecord(struct Record record) {
}


