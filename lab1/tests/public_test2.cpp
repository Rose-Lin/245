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
    str[i] = 0;
    MyString str2(str);
    for (int x = 0; x < TESTS; x++) {
	str2.size();
    }

    return 0;
}
