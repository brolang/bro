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
    block.identifier = nextValue();
    block.method = nextValue();
    if(args)
	  block.args = nextMap();
}

int interpretRecord() {
    struct Record record;
    record.identifier = nextValue();
    record.type = nextValue();
    record.block = interpretBlock();
}


