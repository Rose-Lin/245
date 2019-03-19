// A test for AssocList
// The test returns exit code 0 for success and 1 for failure


#include "../AssocList.h"
#include <iostream>

using namespace std;

int main()
{
    AssocList<int, int> list;
    int v = 5;

    if (list.size() != 0) return 1;
	list.add(0,&v);
	if (list.size() != 1) return 1;
	list.add(1,&v);
	list.add(2,&v);
	list.add(23,&v);
	list.remove(0);
	list.remove(23);
	if (list.size() != 2) return 1;
	if (!list.remove(2)) return 1;
	if (!list.remove(1)) return 1;
	if (list.size() != 0) return 1;
	if (list.remove(1)) return 1;
    if (list.size() != 0) return 1;
	
	return 0;
}

