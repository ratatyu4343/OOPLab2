#include "SpaceObject.h"

SpaceObjectType::SpaceObject()
{

}

Vector SpaceObjectType::get_speed()
{
    return speed;
}

Vector SpaceObjectType::get_position()
{
    return position;
}

Vector SpaceObjectType::get_acceleration()
{
    return acceleration;
}

float SpaceObjectType::get_mass()
{
    return mass;
}

float SpaceObjectType::get_radius()
{
    return radius;
}

void SpaceObjectType::set_speed(Vector v)
{
    speed = v;
}

void SpaceObjectType::set_position(Vector v)
{
    position = v;
}

void SpaceObjectType::set_acceleration(Vector v)
{
    acceleration = v;
}

void SpaceObjectType::set_mass(float m)
{
    mass = m;
}

void SpaceObjectType::set_radius(float r)
{
    radius = r;
}
