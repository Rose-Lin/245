#include "../p2.h"
#include <string.h>

int main() {
    Foo f;
    strcpy(f.str, "aaaaa");
    if (getStrLen(&f) != 5) return 1;
    return 0;
}
