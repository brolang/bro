#include "hello.h"
#include <stdio.h>

enum Keyword currentKeyword;

int lookup(char *Buffer) {
    enum Keyword keyword;
    keyword = returnKeyword(buffer);
}

int interpret(char buffer[1024]) {
    lookup(buffer);
    if(currentKeyword == identifier)
        interpretBlock();
    else 
	interpretRecord();
}

int interpretBlock() {
    struct Block block;
    block.identifier = next();
    block.method = next();
    if(args)
	  block.args = next();  
}

int interpretRecord() {
    struct Record record;
    record.identifier = next();
    record.type = next();
    record.block = interpretBlock();
}


