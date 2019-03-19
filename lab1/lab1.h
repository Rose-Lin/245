/*  	
 * Lab 1 -- Memory and Subclassing   	
 **************************************** 
 * 
 * This lab will introduce you to inheritance and have you write 
 * several operations that manipulate memory. To do this, we will  	
 * create a "wrapped" string class that provides some operations on  	
 * top of the built in strings. We will just do this for one operation  	
 * (string size), but in general you could add more (e.g., string  	
 * concatenation, etc..).   	
 * 
 ***************************************** 
 */  	
#pragma once   	

#include <iostream>
// Consider using `strlen` from string.h   	
#include <string.h>

/****************************************   	
 * Honor pledge (please write your name.) 
 *   	
 * I **Rose Lin** have completed this code myself, without   	
 * unauthorized assistance, and have followed the academic honor code. 
 * 
 * Edit the code below to complete your solution.  	
 *
 ***************************************** 
 */  	

// Abstract class that supports several types of operations on  	
// strings.   	
class AMyString {  	
    // Get the size of the string   	
    virtual unsigned int size() = 0;
    // Get a C-String representation of the string 
    virtual char *getCString()  = 0; 
};

// 
// Part 1: Basic memory management
//

// A naive implementation of strings that (should) create copies of   	
// the string but stores the size
class MyString : public AMyString {
    // Underlying buffer in memory holding the string	
    char *buffer; 
    unsigned int len; 

    public: 
    MyString(const char *str) {  	
	// TODO: Implement this 
	// Consider using new, strlen, and strcpy.
      len = strlen(str);
      buffer = new char[len+1];
      strcpy(buffer, str);
      buffer[len] = 0;
    } 

    MyString(const MyString &str) {   	
	// TODO: Implement this
      buffer = str.buffer;
      len = str.len;
    }

    // Be careful here: remember that if the `buffer` is pointed at by  	
    // multiple objects, it will be freed multiple times (leading to   	
    // an error). 
    ~MyString() {  	
	delete[] buffer;  	
    }   	

    virtual char *getCString() {  	
	return buffer;
    }  	

    // TODO: fix this method (it is too slow to pass the tests right now).  	
    virtual unsigned int size() { 
      // return strlen(buffer);
      return len;
    }  	
};

//
// Part 2: Reference counting
//   	

// Reference counting is a trick for memory management that allows  	
// several objects to share access to a single piece of data. In the  	
// previous class, this was a potential issue: we had to copy the
// string into a newly-allocated buffer. The reason is that if we
// deleted a pointer to a buffer that someone else was using, it would  	
// cause the program to crash. Using reference counting, we keep track	
// of not just the underlying buffer, but also how many objects are  	
// storing a pointer to it. Whenever another object takes a pointer to 
// the string, the reference count increments by 1. Whenever that  	
// object dies, the reference count then decreases by 1. Finally, when  	
// the reference count is at 0 the string is freed.  	

struct RefCountedString {  	
    char *string; 
    unsigned int size;
    int refCount;  	
    RefCountedString(char *str) : string(str), size(strlen(str)), refCount(1) { } 
};  	

class SharedString : public AMyString { 
    public:   	
    RefCountedString *rString;   	

    SharedString(char *str) { 
      // Create a new reference counted string
      int length = strlen(str);
      char *strc = new char[length+1];  	
      strcpy(strc,str);
      strc[length] = 0;
      rString = new RefCountedString(strc);
    }  	
    
    ~SharedString() {
      rString->refCount -= 1;
      if (rString->refCount == 0){
	delete[] rString->string;
	delete rString;
      }
      // TODO: Decrement the reference count and free if refCount is 0!  	
    } 

    SharedString(const SharedString &other) {
	// TODO: Increment reference count!
      other.rString->refCount += 1;
      rString = other.rString;
    } 
   	
    virtual char *getCString() {   	
	// TODO: Implement this
      return rString->string;
    }   	

    virtual unsigned int size() {	
	// TODO: Implement this
      return rString->size;
    }   	
};   	
