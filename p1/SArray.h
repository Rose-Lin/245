/* 
 * Project 1 -- SArray reallocating array class
 ****************************************   	
 *  	
 * Your job is to finish writing this class to suit the 
 * set of tests provided. Be sure to read IArray.h and AArray.h
 * before you begin. Your SArray class should improve on the
 * efficiency of the CArray class by allocating a buffer twice 
 * as large when needed. Look for "TODO"s that you must complete.  	
 * 
 ***************************************** 
 */   	

  	
#pragma once 

#include "AArray.h"


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

	
// This is a simple managed array class that will allocate 
// new space to grow/shrink its buffer "under the hood"
template<typename T> 
class SArray 
    : public AArray<T> 
{   	
private: 
    unsigned capacity; 

    // Use a private helper method to resize the current buffer?	
    void reallocate(unsigned cap) 
    { 
        // Write a helper method to determine new size?
        // cap = nextsize(cap);

        // TODO: Reallocate the current buffer to be  	
        //       at least twice as large    
        if (cap == 0){
           cap = 1; 
        }else{
            cap = 2*cap;
        }
        T* newbuffer = new T[cap];
        for (unsigned i = 0; i < this->size(); ++i){
            newbuffer[i] = this->buffer[i];
        }
        delete [] this->buffer;
        this->buffer = newbuffer;	
        capacity = cap;
    } 

public: 
    SArray()   	
        : capacity(0)
    {   	
    }  	

    SArray(const AArray<T>& other) 
        : AArray<T>(other), capacity(0) 
    {
    }  	

    virtual ~SArray()  	
    {  	
    }   	

    virtual void insert(const T& elem, unsigned pos)
    {
        // TODO: write an insert method  
        if (pos > this->size() || pos < 0)  	
            throw IArray<T>::ARRAY_OVERFLOW;  	
        if (this->size() == capacity){
            //need to reallocate 
            reallocate(this->size());
        }
        this->count +=1;
        for (unsigned i = this->size()-1; i > pos; --i)
            this->buffer[i] = this->buffer[i-1];
        this->buffer[pos] = elem;

        // if (pos == this->size()){
        //     ++this->count;
        //     this->buffer[pos] = elem;
        //     return;
        // }

        // T* const newbuffer = new T[capacity]; 
        // for (unsigned i = 0; i < pos; ++i)
        //     newbuffer[i] = this->buffer[i];     
        // newbuffer[pos] = elem;      
        // for (unsigned i = pos+1; i < this->size()+1; ++i)
        //     newbuffer[i] = this->buffer[i-1];   
        // delete [] this->buffer;     
        // this->buffer = newbuffer; 
        // ++this->count; 
    }  	
   	
    virtual void insert(const IArray<T>& other, unsigned pos)   	
    { 
        if (pos > this->size() || pos < 0) 
            throw IArray<T>::ARRAY_OVERFLOW;  	
        if (other.size() + this->size() > capacity){
            //need to reallocate
            unsigned cap = (other.size()+this->size())/2 + 1;
            reallocate(cap);
        }
        T* const newbuffer = new T[capacity];    
        for (unsigned i = 0; i < pos; ++i)      
            newbuffer[i] = this->buffer[i];     
        for (unsigned i = pos; i < pos+other.size(); ++i)   
            newbuffer[i] = other[i-pos];    
        for (unsigned i = pos+other.size(); i < this->size()+other.size(); ++i)     
            newbuffer[i] = this->buffer[i-other.size()];    
        delete [] this->buffer;     
        this->buffer = newbuffer;       
        this->count += other.size(); 
    }

    virtual void remove(unsigned pos, unsigned num = 1) 
    { 
        // TODO: write a remove method 
        if (pos+num > this->size() || pos < 0){
            throw IArray<T>::ARRAY_OVERFLOW;
        }  	
        if (num <= 0) return;   
        for (unsigned i = pos; i < this->size()-num; ++i)
            this->buffer[i] = this->buffer[i+num]; 
        this->count -= num; 
        // T* const newbuffer = new T[this->size() - num];     
        // for (unsigned i = 0; i < pos; ++i) 
        //     newbuffer[i] = this->buffer[i];     
        // for (unsigned i = pos+num; i < this->size(); ++i)
        //     newbuffer[i-num] = this->buffer[i]; 
        // delete [] this->buffer;
        // this->buffer = newbuffer;   
        // this->count -= num; 
    } 

    virtual void clear()  	
    {   	
        // TODO: is this complete?   
        this->AArray<T>::clear();
    }   	

    // An iterator for SArray instances 
    class Iter
        : public AArray<T>::Iter 
    { 
        // TODO: Does more need to be implemented here? 
    public:
        
        Iter(SArray<T> &arr):
            AArray<T>::Iter(arr)
        { 
        }
    }; 
};   	



