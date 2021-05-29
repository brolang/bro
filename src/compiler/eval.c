#include "hello.h"
#include "compiler.h"
#include <stdio.h>

int eval(char* source,int i) {
    initParser(source,i);
    return 0;
}

int input() {
    char source[1024];
    char c = 0;
    int i = 0;
    printf(">> ");
    while(c!='\n') {
	c=getchar();
	source[i] = c;
	i = i + 1;
    }
    eval(source,i);
}

int info() {
    printf("PING LANGUAGE \n");
    printf("VADAPALLI KRISHNA SATYA");
    printf("\n");
    printf("\n");
    printf("\n");
}

int main() {
    info();
    input();
}
