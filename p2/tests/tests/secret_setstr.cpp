#include "../../p2.h"
#include <string.h>
#include <iostream>

char h[] = "hello";
char h2[] = "hello how are you";
char h3[] = "hello how are you are you doing anything tonight i don't know";

int main() {
    Foo f;
    setStr(&f, h);
    if (strcmp(f.str, "hello") != 0) return 1;
    setStr(&f, h2);
    if (strcmp(f.str, "hello how are you") != 0) return 1;
    setStr(&f, h3);
    if (strcmp(f.str, "hello how are you") != 0) return 1;
    return 0;
}
