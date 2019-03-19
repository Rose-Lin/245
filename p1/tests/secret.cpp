#include <iostream>

#include "../SArray.h"
#include "../CArray.h"


int main()
{
    SArray<int> arr;
    CArray<int> arr0;
	arr.push_back(1);
	arr.push_front(2);
	arr.push_back(3);
	arr.push_front(4);
	arr.push_back(5);
	arr.push_front(6);
	arr.push_back(7);
    arr.remove(4);
    int eq[18] = {6,6,4,2,1,5,7,4,2,6,4,2,1,5,7,1,5,7};
    //eq = {6,4,2,1,5,7}

    arr0.insert(arr,0);
    arr0.insert(arr,3);
    arr0.insert(arr,1);

    if (arr.size() != 6) return 1;
  	if (arr0.size() != 18) return 1;

    int i = 0;
    for (CArray<int>::Iter it(arr0); it; ++it)
    {
        if (*it != eq[i])
            return 1;
        ++i;
    }
    if (i != 18) return 1;

  	arr.remove(5,1);

    if (arr[0] != 6 || arr[4] != 5) return 1;
    
    arr0.remove(4,5);
    arr0.remove(10,2);
    arr0.remove(10,1);
    arr0.remove(2,5);
    arr0.remove(0,5);

    if (arr0.size() !=0) return 1;
    return 0;
}
