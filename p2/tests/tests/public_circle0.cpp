#include <iostream>
#include "../ShapesStructs.h"

int main()
{
    void* circ = newCircle(20,30,50);
    if (vtable(circ)->getXpos(circ) != 20) return 1;
    if (vtable(circ)->getYpos(circ) != 30) return 1;
    
    return 0;
}
