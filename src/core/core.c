#include "core.h"
#include "../compiler/compiler.h"
#include "../runtime/runtime.h"

int core_declare(enum Code ir, struct Expression expression) {
    execute_expression(gen_expression(expression));
}

int core_block(enum Code ir, struct Block block) {
    execute_block(gen_block(block));
}

int run() {
    struct Program program;
    core_block(block, program.module);
}
