#include <stdio.h>

char f(char* s) {
    int i, *p = (int*) s;
    char* q;
    p++;
    q = (char*) p;
    return *q;
}

int main() {
    printf ("%c", f("milano"));
    return 0;
}