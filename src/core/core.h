#ifndef CORE_H
#define CORE_H

enum Code {
    unit, block, jump, compare,
    declare, alloc,
    callmethod, initvar, initarg,
    get

};

core_declare();
core_init();
core_get();
core_calladd();
core_callmul();
core_calldiv();
core_callsub();
core_block();
core_jump();
core_compare();
#endif
