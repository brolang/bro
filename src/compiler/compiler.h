#ifndef COMPILER_H
#define COMPILER_H
#include "types.h"
struct Program program;

int init_module();
int create_block(enum Keyword keyword);
int returnToParentBlock();
int create_expression(struct Token identifier, struct Token functioncall);
#endif
