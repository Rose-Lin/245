#include <iostream>
#include <string.h>
#include "../lab1.h"

#define SIZE 200000001
#define TESTS 20000000

int main()
{
    char *str = new char[SIZE];
    unsigned int i = 0;
    for (i = 0; i < SIZE; i++) {
	str[i] = 'a';
    }

    SharedString str2(str);
    for (unsigned int i = 0; i < TESTS; i++) {
      SharedString str3(str2);
    }
    return 0;
}
