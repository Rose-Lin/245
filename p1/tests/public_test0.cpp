

#include <iostream>

#include "../SArray.h"
#include "../CArray.h"


int main()
{
    SArray<int> arr;
    CArray<int> arr0;
    arr.insert(arr,0);
    arr0.push_back(0);
	arr.insert(arr0,0);
	arr.push_back(1);
	arr.push_front(2);
	arr.push_back(3);
	arr.push_front(4);
	arr.push_back(5);
	arr.push_front(6);
	arr.push_back(7);
    arr.remove(5);
    //int eq[7] = {6,4,2,0,1,5,7};
    
    if (arr.size() != 7) return 1;
  	
  	arr.remove(6,1);

    if (arr[0] != 6 || arr[5] != 5) return 1;
    
    return 0;
}
