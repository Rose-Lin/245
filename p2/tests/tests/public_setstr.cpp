#include "../p2.h"
#include <string.h>

int main() {
    Foo f;
    char hello[] = "hello";
    setStr(&f, hello);
    if (strcmp(f.str, "hello") != 0) return 1;
    char hellohow[] = "hello how are you";
    setStr(&f, hellohow);
    if (strcmp(f.str, "hello how are you") != 0) return 1;
    return 0;
}
