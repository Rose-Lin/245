#include <iostream>
#include "../ShapesStructs.h"

int main()
{
    void* rect = newRectangle(0,0,50,100);
    if (vtable(rect)->getXpos(rect) != 25) return 1;
    if (vtable(rect)->getYpos(rect) != 50) return 1;
    if (vtable(rect)->getArea(rect) != 5000) return 1;
    return 0;
}
