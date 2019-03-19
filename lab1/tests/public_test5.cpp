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
    SharedString str3(str2);
    SharedString str4(str2);
    SharedString str5(str4);
    SharedString str6(str4);
    if (str6.rString->refCount != 5)
	return 1;
    {
	SharedString str7(str4);
	SharedString str8(str4);
	if (str6.rString->refCount != 7)
	    return 1;
    }
    if (str6.rString->refCount != 5)
	return 1;
    return 0;
}
