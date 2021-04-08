#include <stdio.h>

int debug() {
    return 0;
}

int input() {
    char source[1024];
    while(1) {
        printf(">> ");
	scanf("%s",source);
	debug();
    }
    return 0;

}

int brodebug() {
    printf("BRO LANGUAGE\n");
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
