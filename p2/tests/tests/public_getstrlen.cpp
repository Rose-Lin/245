#include "../p2.h"
#include <string.h>

int main() {
    Foo f;
    strcpy(f.str, "");
    if (getStrLen(&f) != 0) return 1;
    return 0;
}
