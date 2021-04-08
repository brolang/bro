#include "codegen.h"


int gen_declare_expression(struct Variable variable, struct Record record) {
    core_declare();
    core_alloc();
}



int gen_init_expression(struct Variable variable1) {
    core_init(variable1)
}

int gen_add_expression(struct Variable variable1, struct Variable variable2) {
    core_get(variable1);
    core_get(variable2);
    core_calladd();
}

int gen_mul_expression(struct Variable variable1, struct Variable variable2) {
    core_get(variable1);
    core_get(variable2);
    core_callmul();
}

int gen_sub_expression(struct Variable variable1, struct Variable variable2) {
    core_get(variable1);
    core_get(variable2);
    core_callsub();
}

int gen_div_expression(struct Variable variable1, struct Variable variable2) {
    core_get(variable1);
    core_get(variable2);
    core_callsub();
}



int gen_if_statement(struct Condition condition) {
    core_ifblock();
    core_jump();
    core_compare(condition);

}

int gen_loop_condition_statement(struct Condition condition) {
    core_loopblock();
    core_jump();
    core_compare(condition);
}

int gen_loop_iterator_statement(struct Iterator iterator, struct Variable variable1) {
    core_loopblock();
    core_yield(iterator);
    core_init(variable1);
}

int gen_module_statement() {
    core_moduleblock();
}
