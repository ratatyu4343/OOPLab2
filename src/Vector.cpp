#include "Vector.h"

Vector::Vector()
{
    set_x(0);
    set_y(0);
}

Vector::Vector(float x, float y)
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

float Vector::length(Vector v1, Vector v2)
{
    v1 -= v2;
    float leng = std::sqrt(v1.x()*v1.x() + v1.y()*v1.y());
    if(leng > 0)
        return leng;
    else
        return 0.00000001;
}

PairVectorAdapter::PairVectorAdapter(std::pair<float, float> P)
{
    p = P;
}

float PairVectorAdapter::x()
{
    return p.first;
}

float PairVectorAdapter::y()
{
    return p.second;
}

void PairVectorAdapter::set_x(float x)
{
    p.first = x;
}

void PairVectorAdapter::set_y(float y)
{
    p.second = y;
}

void PairVectorAdapter::add_x(float x)
{
    p.first += x;
}

void PairVectorAdapter::add_y(float y)
{
    p.second += y;
}

Vector PairVectorAdapter::operator += (Vector v)
{
    add_x(v.x());
    add_y(v.y());
    return *this;
}

Vector PairVectorAdapter::operator -= (Vector v)
{
    add_x(-v.x());
    add_y(-v.y());
    return *this;
}
