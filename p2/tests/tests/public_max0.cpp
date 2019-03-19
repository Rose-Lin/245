#include "../p2.h"
#include <string.h>
#include <iostream>

int cmp(void *x, void *y) {
    int x0 = *((int*)x);
    int y0 = *((int*)y);
    return x0 - y0;
}

int main() {
    int x = 0;
    int y = 1;
    int z = 2;
    void *arr[] = {&x,&y,&z};
    void *m = max(arr, 3, &cmp);
    if (m != &z) return 1;
    return 0;
}
