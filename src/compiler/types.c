#include "types.h"

struct Container {
    int name;
    int size;
    struct Record *record;
}

struct Record {
    int identifier;
    int integer;
    float flot;
    double doubl;
    char* string;
};

struct Variable {
    char* identifier;
    struct Record record;
};

struct Expression {
    struct Variable variable;
    enum Token operator;
    struct Expression next;
};

struct Statement {
    struct Token keyword;
    struct Expression expression;
};

struct Block {
    struct Statement *statements;
};


int new() {
  
}
