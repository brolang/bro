

struct Container {
    int size;
    int memory;
};

struct Value {
    struct Container buffer;
    char identifier[1024];
};

struct Map {
    struct Value key;
    struct Value value;
};

struct Block {
    struct Value identifier;
    struct Value method;
    struct Map   args;
};

struct Record {
    struct Value identifer;
    struct Value type;
    struct Block block;
};

struct Error {
     struct Value reason;
     struct Value solution;
};
