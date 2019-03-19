#include <iostream>

#include "../SArray.h"
#include "../CArray.h"

int main(){
	SArray<int>* arr = new SArray<int>();
    SArray<int>* arr1 = new SArray<int>();

    for (unsigned i = 0; i < 1000000; i ++){
        arr->push_back(3);
    }
    arr->push_back(2);

    arr->remove(1,2);
    if (!arr->contains(2)) return 1;
    if (!arr->contains(3)) return 1;
    if ((*arr)[2] != 3) return 1;

    arr->push_back(2);
    if (arr->find(3) != 0) return 1;

    for (unsigned i =0; i <4; i++){
        arr->push_front(2);
    }
    if (arr->find(2) != 0) return 1;

    for (unsigned i =0; i<4; i++){
        arr->insert(7,arr->size());
    }
    
    for (unsigned i =0; i <4; i++){
        arr->insert(5,5);
    }
    
    // arr.push_back(2);

    // arr.push_back(2);

    // arr.push_back(2);

    // arr.push_back(2);


    // arr.push_back(2);


    // arr.push_back(2);
    delete arr;
    delete arr1;
    
}