#include "hello.h"
#include "compiler.h"
#include "../stats/stats.h"
#include "../core/core.h"

#include <stdio.h>
#include <stdlib.h>

struct Program program;
int ismodule = 0;
struct Block* currentBlock;
struct Block scopeStack[10];

int top = 0;

int pushParentToStack(struct Block block) {
    if(top == 10) {
        printf("stack not empty");
        return 0;
    }
    scopeStack[top++] = block;
}

int popFromStack() {
    if(top == 0) {
        printf("empty scope");
        return 0;
    }
    --top;
}

struct Block currentScope() {
    return scopeStack[top];
}

int init_module() {
    program.module.keyword = module_keyword;
    currentBlock = &program.module;
}

int create_block(enum Keyword keyword) {
    if(ismodule == 0)
        ismodule = 1;
    if(currentBlock->numberOfBlocks = 0)
        pushParentToStack(*currentBlock);
    ++currentBlock->numberOfBlocks;

    currentBlock->blocks = malloc(sizeof(struct Block)*currentBlock->numberOfBlocks);
    currentBlock = &currentBlock->blocks[currentBlock->numberOfBlocks-1];
    currentBlock->keyword = keyword;
}

int returnToParentBlock() {
    struct Block scope = currentScope();
    currentBlock = &scope;
}

int create_expression(struct Token identifier, struct Token functioncall) {
    
    if(ismodule == 0 ) {
        struct Expression expression;
        expression.identifier = identifier;
        expression.identifier = functioncall;
        expression.expression = malloc(sizeof(struct Expression));
        program.module.list = expression;
    } else {
        struct Expression* temp = &currentBlock->list;
        while(temp->expression != NULL)
            temp = temp->expression;
        struct Expression* expression = malloc(sizeof(struct Expression));
        expression->identifier = identifier;
        expression->functioncall = functioncall;
        temp->expression = expression;
    }
}
