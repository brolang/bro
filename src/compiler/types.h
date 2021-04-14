
#ifndef TYPES_H
#define TYPES_H

struct Container {
    int size;
    int memory;
};

struct Value {
    struct Container buffer;
    char identifier[1024];
};

struct Variant {

};


struct List {
    struct Value key;
    struct Value value;
};

struct Declaration {
    struct Value type;
    struct Value listofvalues;
};

struct MethodCall {
    struct Value identifier;
    struct Value method;
    struct Value listofargs;
};

struct Case {
    enum Literal result;
};

struct Loop {
     
};

struct Module {

};

#endif
