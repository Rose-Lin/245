#include "../../p2.h"
#include <string.h>

int main() {
    Foo f;
    strcpy(f.str, "hello");
    if (getStrLen(&f) != 5) return 1;
    strcpy(f.str, "hi");
    if (getStrLen(&f) != 2) return 1;
    strcpy(f.str, "hello how are you");
    if (getStrLen(&f) != 17) return 1;
    return 0;
}
