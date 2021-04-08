#include "hello.h"
#include "compiler.h"
#include <stdio.h>

int eval(char* source) {
    initParser(source);
    compile();
    return 0;
}

int input() {
    char source[1024];
    while(1) {
      printf(">> ");
      scanf("%s",source);
    }
}

int broeval() {
    printf("BRO LANGUAGE \n");
    printf("VADAPALLI KRISHNA SATYA");
    printf("\n");
    printf("\n");
    printf("\n");
}

int main() {
    broeval();
    input();
}
