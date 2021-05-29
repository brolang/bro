#ifndef CORE_H
#define CORE_H

enum Code {
    unit, block, jump, compare,
    declare, alloc,
    callmethod, initvar, initarg,
    get

};

int core_declare();
int core_init();
int core_get();
int core_calladd();
int core_callmul();
int core_calldiv();
int core_callsub();
int core_block();
int core_jump();
int core_compare();
#endif
