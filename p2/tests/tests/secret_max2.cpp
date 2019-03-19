#include "../../p2.h"
#include <string.h>
#include <iostream>

int cmp(void *x, void *y) {
    double x0 = *((double*)x);
    double y0 = *((double*)y);
    if (x0 - y0 > 0) return 1;
    if (x0 - y0 < 0) return -1;
    else return 0;
}

int main() {
    double x = 1.0;
    double y = 2.0;
    double z = 2.0;
    double a = -2.0;
    double b = -3.0;
    double c = 6.7;
    double d = 6;
    void *arr[] = {&x,&y,&z,&a,&b,&c,&d};
    void *m = max(arr, 7, &cmp);
    if (m != &c) return 1;
    return 0;
}
