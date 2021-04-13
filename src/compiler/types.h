

struct Container {
    int size;
    int memory;
};

struct Value {
    struct Container buffer;
    char identifier[1024];
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


