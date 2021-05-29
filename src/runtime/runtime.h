#ifndef RUNTIME_H
#define RUNTIME_H

struct Memory {
    size_t type;
    int priority;
};

struct Page {
    struct Memory* pointer;
    char* module_name;
    char* function_name;
};

struct Call {   
    char* identifier;
    struct Page root;
};

struct Frame {
    struct Call call;
    struct Frame* next;
};

int frame_hasnext();
int execute_variable();
int execute_operator();
int execute_literal();

int execute_expression();
int execute_block();


#endif
