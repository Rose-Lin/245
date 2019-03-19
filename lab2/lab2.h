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

// Get the maximum of three integers   	
extern "C" int max(int x, int y, int z);   	

// Find the maximum number in an array 
extern "C" int max_arr(int *arr, unsigned int size); 
