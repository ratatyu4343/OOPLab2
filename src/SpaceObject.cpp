#include "SpaceObject.h"

SpaceObject::SpaceObject()
{

}

Vector SpaceObject::get_speed()
{
    return speed;
}

Vector SpaceObject::get_position()
{
    return position;
}

Vector SpaceObject::get_acceleration()
{
    return acceleration;
}

float SpaceObject::get_mass()
{
    return mass;
}

void SpaceObject::set_speed(Vector v)
{
    speed = v;
}

void SpaceObject::set_position(Vector v)
{
    position = v;
}

void SpaceObject::set_acceleration(Vector v)
{
    acceleration = v;
}

void SpaceObject::set_mass(float m)
{
    mass = m
}

