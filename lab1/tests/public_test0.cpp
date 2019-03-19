#include <iostream>
#include <string.h>
#include "../lab1.h"

int main()
{
    MyString str("hello");
    if (strcmp(str.getCString(),"hello") != 0)
	return 1;
    return 0;
}
