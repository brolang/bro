#ifndef TYPES_H
#define TYPES_H

struct Expression{
    struct Token identifier;
    struct Token functioncall;
    struct Expression* expression;
};

struct Block {
    enum Keyword keyword;
    struct Expression list;
    struct Block* blocks;
};

struct Program {
    struct Block module;
};

#endif
