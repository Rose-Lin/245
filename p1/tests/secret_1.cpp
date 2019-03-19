#include <iostream>

#include "../SArray.h"
#include "../CArray.h"

int main(){
	SArray<int>* arr = new SArray<int>();
    SArray<int>* arr1 = new SArray<int>();

    // a.push_back(2);
    arr->push_back(2);
    for (unsigned i = 0; i < 500; ++i){
    	arr->push_back(i);
    	for (unsigned k = 0; i > 10 && k <10; ++k){
    		if (!arr->contains(k)){
    			return 1;
    		}
    	}
    }
    for (unsigned i = 0; i <499; i++){
    	arr->remove(1,1);
	}
    arr->push_back(4);
    arr->remove(1,1);
    
    arr1->push_back(499);
    arr1->push_front(2);
    arr1->push_back(4);
    arr1->remove(1,1);
    arr1->push_back(5);

    if (arr->size() != 2) return 1;
    if ((*arr) == (*arr1)) return 1;
    // int s = (*arr)[arr->size()];
    // arr->remove(1,3);
    // if (arr->size() != 1) return 1;
    // if ((*arr)[0] != 2) return 1;
    // SArray<int> b(&a);
 	// int s = (*arr)[0];

    // arr = arr1;

    // SArray<int>::Iter it(*b);
    delete arr1;
    delete arr;
    // delete &a;
    return 0;
}