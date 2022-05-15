#include "Vector.h"

Vector::Vector(float x = 0, float y = 0)
{
    set_x(x);
    set_y(y);
}

float Vector::x()
{
    return coord_x;
}

float Vector::y()
{
    return coord_y;
}

void Vector::set_x(float x)
{
    coord_x = x;
}

void Vector::set_y(float y)
{
    coord_y = y;
}

void Vector::add_x(float x)
{
    coord_x += x;
}

void Vector::add_y(float y)
{
    coord_y += y;
}

Vector Vector::operator += (Vector v)
{
    add_x(v.x());
    add_y(v.y());
    return *this;
}

Vector Vector::operator -= (Vector v)
{
    add_x(-v.x());
    add_y(-v.y());
    return *this;
}
