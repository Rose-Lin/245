/*
 * Project 2 -- Shapes classes manually compiled to structs
 ******************
 * 
 * In this file, you should write a version of the class hierarchy in
 * Shapes.h, compiled manually to structs (as we discuss in class)
 * Your job is to finish the implementation of Circle started below
 * and write an implementation for class Rectangle. Use the stubbed
 * out code below and the tests provided as a guide.
 * 
 ******************
 */

/*
 *[[[[0*]]]]
 * Honor pledge (please write your name.)
 *
 * I **firstname lastname** have completed this code myself, without
 * unauthorized assistance, and have followed the academic honor code.
 *
 * Edit the code below to complete your solution.
 *
 *[[[[1*]]]]
 */

#pragma once

struct ShapeVTable
{
    double (*getArea)(const void*);
    double (*getXpos)(const void*);
    double (*getYpos)(const void*);
    void (*scaleBy)(void*, double);
    void (*movePos)(void*, double, double);
     
    ShapeVTable(double (*getArea)(const void*),
                double (*getXpos)(const void*),
                double (*getYpos)(const void*),
                void (*scaleBy)(void*, double),
                void (*movePos)(void*, double, double))
        : getArea(getArea), getXpos(getXpos), getYpos(getYpos), scaleBy(scaleBy), movePos(movePos)
    {
    }
};

// A function for getting the vtable pointer
// of a class-as-a-struct with the proper data layout
// Implicitly assume that obj is a pointer to an object whose
// first element is a vtable
ShapeVTable* vtable(void* obj)
{
    return ((ShapeVTable*)((void**)obj)[0]);
}

/* Circle (implemented with structs)
**************/

struct Circle
{
    ShapeVTable* vtableptr;
    double x, y, r;
};

// Circle's virtual methods    
double getAreaCircle(const void* _ths)
{
    // TODO
    return 0.0;
}

double getXposCircle(const void* _ths)
{
    // TODO
    return 0.0;
}

double getYposCircle(const void* _ths)
{
    // TODO
    return 0.0;
}

void scaleByCircle(void* _ths, double factor)
{
    // TODO
    return;
}   

void movePosCircle(void* _ths, double dx, double dy)
{
    // TODO
    return;
}

// A constructor for rectangles
Circle* newCircle(double x0, double y0, double r0)
{
    return 0;
}

/* Rectangle (implemented as a struct)
**************/

struct Rectangle
{
    ShapeVTable* vtableptr;
    double left, right, top, bottom;
};

// Rectangle methods    
double getAreaRectangle(const void* _ths)
{
    // TODO
    return 0.0;
}

double getXposRectangle(const void* _ths)
{
    // TODO
    return 0.0;
}

double getYposRectangle(const void* _ths)
{
    // TODO
    return 0.0;
}

void scaleByRectangle(void* _ths, double factor)
{
    // TODO
    return;
}   

void movePosRectangle(void* _ths, double dx, double dy)
{
    // TODO
    return;
}

// A constructor for rectangles
Rectangle* newRectangle(double x0, double y0, double x1, double y1)
{
    // TODO
    return 0;
}
