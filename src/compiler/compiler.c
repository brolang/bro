#include "compiler.h"
#include "stats.h"


int init(int identifier) { 
    return Ok;
}

int compile() {
    init();
    while(!next())
	check();;	 	
    return 0;
}


