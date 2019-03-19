#include <iostream>
#include <string.h>
#include "../lab2.h"

// Assume SIZE is even
#define SIZE 10000

int main()
{
    int max = 0;
    int x[SIZE];
    x[0] = 0;
    for (int i = 1; i < SIZE; i++) {
	int m = rand() % (SIZE * 100);
	if (m > max)
	    max = m;
	x[i] = m;
    }
    if (max_arr(x,SIZE) != max)
	return 1;
    return 0;
}
