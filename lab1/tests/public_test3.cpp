#include <iostream>
#include <string.h>
#include "../lab1.h"

#define SIZE 200000001

int main()
{
    char *str = new char[SIZE];
    unsigned int i = 0;
    for (i = 0; i < SIZE; i++) {
	str[i] = 'a';
    }
    SharedString str2(str);
    if (strcmp(str2.getCString(),str) != 0) {
	return 1;
    }
    return 0;
}
