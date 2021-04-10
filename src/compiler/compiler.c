#include "hello.h"
#include "compiler.h"
#include "../stats/stats.h"
#include "../core/core.h"

#include <stdio.h>

int init(int identifier) { 
    
    return 0;
}

int compile() {
    init(0);
    while(!noMoreTokens())
	 parse();
    return 0;
}

int stats_syntax() {
    return 0;     
}

int codegen() {
    return 0;
}
