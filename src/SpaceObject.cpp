#include "SpaceObject.h"

SpaceObjectType::SpaceObjectType(float r, float m, string name, int r, int g, int b)
{
    type_name = name;
    mass = m;
    radius = r;
    color.set_R(r);
    color.set_G(g);
    color.set_B(b);
}

float SpaceObjectType::get_mass()
{
    return mass;
}

float SpaceObjectType::get_radius()
{
    return radius;
}

string SpaceObjectType::get_type_name()
{
    return type_name;
}

RGB SpaceObjectType::get_rgb()
{
    return color;
}

SpaceObjectType* SpaceObjectFactory::get_type(string type_name, float mass, float radius, RGB rgb)
{
    int count_of_types = typeCollection.size();
    for(int i = 0; i < count_of_types; i++)
    {
        bool b1 = typeCollection[i]->get_mass() == mass;
        bool b2 = typeCollection[i]->get_type_name() == type_name;
        bool b3 = typeCollection[i]->get_radius() == radius;
        bool b4 = typeCollection[i]->get_rgb() == rgb;
        if(b1&&b2&&b3&&b4)
        {
            return typeCollection[i];
        }
    }
    auto new_type = new SpaceObjectType(radius, mass, type_name, rgb);
    typeCollection.push_back(new_type);
    return new_type;
}

SpaceObject::SpaceObject()
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
