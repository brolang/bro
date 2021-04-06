#include "compiler.h"

enum Pass {
     Ok, Error
}

enum Pass compile() {
     while(parse())
	 next();
     
     if(error)
	 newError();
	
     return Ok;
}


