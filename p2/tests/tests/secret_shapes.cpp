#include <iostream>
#include "../../ShapesStructs.h"

ShapeVTable* vtbl(void* obj)
{
    return ((ShapeVTable*)((void**)obj)[0]);
}

void* second(void* obj)
{
    return ((void**)obj)[2];
}

int main()
{
    void* circ = newCircle(0,0,50);
    vtbl(circ)->movePos(circ,25,15);
    vtbl(circ)->scaleBy(circ,2.0);
    vtbl(circ)->movePos(circ,-20,-10);
    vtbl(circ)->scaleBy(circ,0.85);
    if (vtbl(circ)->getXpos(circ) != 5) return 1;
    if (vtbl(circ)->getYpos(circ) != 5) return 1;
    double ar = vtbl(circ)->getArea(circ);
    double ar1 = 85.0*85.0*3.14159265;
    if (ar != ar1) return 1;

    void* secval = second(circ);
    if (reinterpret_cast<double&>(secval) != 5.0) return 1;

    void* rect = newRectangle(0,0,50,100);
    vtbl(rect)->movePos(rect,20,10);
    vtbl(rect)->scaleBy(rect,3.0);
    vtbl(rect)->movePos(rect,30,-20);
    if (vtbl(rect)->getXpos(rect) != 75) return 1;
    if (vtbl(rect)->getYpos(rect) != 40) return 1;
    if (vtbl(rect)->getArea(rect) != 45000) return 1;

    secval = second(rect);
    if (reinterpret_cast<double&>(secval) != 150.0) return 1;
    
    return 0;
}
