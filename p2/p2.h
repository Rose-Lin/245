/**  	
 * Lab 2 header
 *  	
 * This allows the C++ code from the tests to call the assembly
 * functions you implement. The `extern` keyword tells the compiler to 
 * assume that there is some function named `max` / `max_arr`, but to   	
 * wait until the linking phase to actually associate the  	
 * implementation of those functions with their uses. This allows us	
 * to compile our assembly functions separately and then link them   	
 * with the C++-based tests. 
 */   	

struct Foo {  	
    char str[31];  	
    int  x; 
    int  y; 
};  	

// Assume that:
//   - foo is a valid pointer to a Foo struct
//   - `str` is a valid string  	
//  	
// Ensure that:	
//   - If the length of `str` is > 30, do nothing  	
//   - If length of `str` is <= 30, copy into foo.str   	
//   - For credit, this function must call your `getStrLen` function
//     (the TAs will check by  reading your code) 
extern "C" void setStr(Foo *foo, char *str);  	

// Given a pointer to a Foo struct, find out the length of the string
// contained within it.
extern "C" int getStrLen(Foo *foo);   	
  	
// Assume that:
//   - ptr is a pointer to an array of void pointers 
//   - num is the number of elements in that array   	
//   - num >= 1 
//   - cmp is a pointer to a function that returns:
//     0 if its first and second arguments are equal 
//     >0 if its first argument is larger  	
//     <0 if its second argument is larger
//
// Ensure that you return a pointer to the largest element in the   	
// array `ptr`. If the array has multiple elements that are equal, you
// may return a pointer to any of them.  	
extern "C" void *max(void **ptr,unsigned num, int(*cmp)(void *,void *)); 
