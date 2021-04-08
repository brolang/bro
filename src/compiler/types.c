#include "types.h"

struct Container {
    int name;
    int size;
    struct Record *record;
}

struct Record {
    int identifier;
    int integer;
    int boolean;
    float flot;
    double doubl;
    size_t size;
    char* string;
};

struct Variable {
    char* identifier;
    struct Record record;
};

struct Expression {
    struct Token token;
    struct Seperator seperator;
    struct Expression expression;
};

struct Statement {
    struct Token keyword;
    struct Expression expression;
    struct Block block;
};

struct Block {
    struct Statement *statements;
};


struct node newModule() {
    
}
