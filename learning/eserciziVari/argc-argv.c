// test su argc e argv

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    printf ("argc: %d\n\n", argc);

    for(int i=0; i<argc; i++){
        printf ("Elemento %d: %s\n", i, argv[i]);
    }

    return 0;
}