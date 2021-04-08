#include "compiler.h"
#include "stats.h"

enum Pass {
    Ok, Error
};

enum Pass init(int identifier) { 
    return Ok;
}

enum Pass compile() {
    init();
    while(!next())
	check();;	 	
    return Ok;
}


