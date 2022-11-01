#include "../../include/utils/Rectangle.h"


bool Rectangle::inside(float x, float y) const
{
    // IX.B Implement this function, that returns true if the point <x,y> is inside this rectangle.
    if ((x >= topLeft.x && x <= bottomRight.x) && (y >= topLeft.y && y <= bottomRight.y))
    {
        return true;
    }

    return false; // you can delete this once IX.B is complete.
}

bool Rectangle::intersects(const Rectangle& rect) const
{
    // IX.D Implement this function, that returns true if the rectangle "rect" overlaps with this rectangle.
    if (inside(rect.bottomRight) || inside(rect.topLeft) || rect.inside(bottomRight) || rect.inside(topLeft)) { return true; }

    return false;
}

