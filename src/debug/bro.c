#include <stdio.h>
#include "../compiler/hello.h"
#include "../compiler/compiler.h"

int debug(char* source, int len) {
    initParser(source, len);
    compile();
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
    debug(source,i);
    return 0;

}

int brodebug() {
    printf("PING LANGUAGE\n");
    printf("VADAPALLI KRISHNA SATYA\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("DEBUGGER\n");
    printf("\n");
    return 0;
}

int main() {
    brodebug();
    input();
}
