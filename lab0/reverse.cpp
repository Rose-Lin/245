/***************************************** 
 * Lab 0 -- Part 1: sort.cpp   	
 *   	
 * The goal of this task is to use an array to sort a sequence of numbers   	
 * and to print the numbers read via STDIN to STDOUT in increasing order (one per line). 
 *   	
 **************************************** 
 */	
   	
#include <iostream>   	

/**************************************** 
 * Honor pledge (please write your name.)
 * 
 * I **Jiayi(Rose) Lin** have completed this code myself, without   	
 * unauthorized assistance, and have followed the academic honor code.	
 *  	
 * Edit the code below to complete your solution. 
 * 
 *****************************************  	
 */   	

int main(int argc, const char** argv)	
{ 
    // Allocate space for up to 500 numbers (no test will exceed this size) 
    int buffer[500];  	
  	
    // Push each integer read into the array, in order Note that   	
    // std::cin >> n reads the next number into variable n and returns   	
    // true or returns false if EOF is reached (really, a falsy 
    // object).	
    int n;
    int end; 
    for (end = 0; std::cin >> n; ++end)
      buffer[end] = n;

    if (end < 1)
	return 0;

    // Small example: find the max value in the array 
    int max = buffer[0]; 
    for (int x = 1; x < end; x++) {  	
	if (max < buffer[x])   	
	    max = buffer[x];	
    } 

    // TODO: Write a loop that reverses all of the numbers in  	
    // buffer. Remember, the variable end represents the number of 
    // numbers stored in the array buffer.   	

    int low = 0;
    int high = end -1; 
    while (low <= high){
      int temp = buffer[low];
      buffer[low] = buffer[high];
      buffer[high] = temp;
      low ++;
      high --;
    }

    
    // Print out integers in sorted order (one per line)  	
    for (int i = 0; i < end; ++i)
	std::cout << buffer[i] << std::endl; 
   	
    // Exit with error code 0 (success)	
    return 0;  	
} 



