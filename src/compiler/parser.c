#include "hello.h"

int main(int argc, char** argv) {
    if(argc > 1)
        parseFile(argv[1]);
}
