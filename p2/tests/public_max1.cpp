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
    int y = 0;
    int z = 0;
    void *arr[] = {&x,&y,&z};
    void *m = max(arr, 3, &cmp);
    if (*((int*)m) != z) return 1;
    int a1 = -5;
    int a2 = 5;
    int a3 = 1;
    int a4 = 1;
    int a5 = 3;
    void *arr2[] = {&a1,&a2,&a3,&a4,&a5};
    void *m2 = max(arr2, 5, &cmp);
    if (*((int*)m2) != a2) return 1;
    return 0;
}
