#include <iostream>
#include <string.h>
#include "../lab2.h"

#define SIZE 1000

int main()
{
    int x[SIZE];
    for (int i = 0; i < SIZE; i++) {
	x[i] = i;
    }
    if (max_arr(x,SIZE) != SIZE-1)
	return 1;
    return 0;
}
