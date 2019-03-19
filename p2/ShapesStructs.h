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
 * **************************************** 
 * Honor pledge (please write your name.)  	
 * 
 * I **Rose Lin** have completed this code myself, without  	
 * unauthorized assistance, and have followed the academic honor code. 
 *   	
 * Edit the code below to complete your solution.
 *
 * *****************************************
 */
 
#include <cmath>
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
    ShapeVTable* v = ((ShapeVTable*)((void**)obj)[0]);
    return v;
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
    void* p = const_cast<void*>(_ths);
    Circle* c = static_cast<Circle*>(p);
    double area = 3.14159265 * c->r * c->r;
    return area;	
}

double getXposCircle(const void* _ths)
{	
    // TODO 
    void* p = const_cast<void*>(_ths);
    Circle* r = static_cast<Circle*>(p);
    return r->x;
    //https://stackoverflow.com/questions/48779142/casting-a-const-void
}  	

double getYposCircle(const void* _ths)
{  	
    // TODO
    void* p = const_cast<void*>(_ths);
    Circle* c = static_cast<Circle*>(p);
    return c->y;
}  	

void scaleByCircle(void* _ths, double factor)  	
{  	
    // TODO 
    if (factor < 0){
        factor = -factor;
    }
    Circle* c = (Circle*) (_ths);
    c->r = c->r * factor;
    return;   	
}   	

void movePosCircle(void* _ths, double dx, double dy)
{
    // TODO  	
    Circle* c = (Circle*) (_ths);
    c->x = c->x+dx;
    c->y = c->y+dy;
    return;	
}

// A constructor for rectangles 
Circle* newCircle(double x0, double y0, double r0)
{
    Circle* newCircle = new Circle();
    ShapeVTable v(getAreaCircle,getXposCircle, getYposCircle,scaleByCircle, movePosCircle);
    newCircle->vtableptr = &v;
    newCircle->x = x0;
    newCircle->y = y0;
    newCircle->r = r0;
    return newCircle;
    // return 0;  	
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
    void* p = const_cast<void*>(_ths);
    Rectangle* r = static_cast<Rectangle*>(p);
    double length = r->right - r->left;
    double side = r->top - r->bottom;
    return length*side;   	
}   	

double getXposRectangle(const void* _ths)   	
{   	
    // TODO   	
    void* p = const_cast<void*>(_ths);
    Rectangle* r = static_cast<Rectangle*>(p);
    return (r->left + r->right)/2;  	
} 

double getYposRectangle(const void* _ths)  	
{  	
    // TODO   	
    void* p = const_cast<void*>(_ths);
    Rectangle* r = static_cast<Rectangle*>(p);
    return (r->top+r->bottom)/2;   	
}   	

void scaleByRectangle(void* _ths, double factor)   	
{	
    // TODO	
    if (factor < 0){
        factor = -factor;
    }
    Rectangle* r = (Rectangle*)_ths;
    // double centerx = getXposRectangle(_ths);
    double halflength = (r->right - r->left)*(factor-1)/2;
    // double centery = getYposRectangle(_ths);
    double halfheight = (r->top - r->bottom)*(factor-1)/2;
    r->left = r->left - halflength;
    r->right = r->right + halflength;
    r->top += halfheight;
    r->bottom -= halfheight;
    return; 
}

void movePosRectangle(void* _ths, double dx, double dy)	
{   	
    // TODO 
    Rectangle* r = (Rectangle*)_ths;
    r->left += dx;
    r->right += dx;
    r->top += dy;
    r->bottom += dy;
    return;  	
}	

// A constructor for rectangles   	
Rectangle* newRectangle(double x0, double y0, double x1, double y1)  	
{
    Rectangle* newRec = new Rectangle();
    ShapeVTable v(getAreaRectangle,&getXposRectangle, getYposRectangle,scaleByRectangle, movePosRectangle);
    newRec->vtableptr = &v;
    newRec->left = x0;
    newRec->right = x1;
    newRec->top = y1;
    newRec->bottom = y0;
    return newRec;
    // return 0; 
} 
