#include "SpaceObject.h"

std::vector<SpaceObjectType*> SpaceObjectFactory::typeCollection;

SpaceObjectType::SpaceObjectType(float r, float m, std::string name, RGB rgb)
{
    type_name = name;
    mass = m;
    radius = r;
    color.set_R(rgb.get_R());
    color.set_G(rgb.get_G());
    color.set_B(rgb.get_B());
}

float SpaceObjectType::get_mass()
{
    return mass;
}

float SpaceObjectType::get_radius()
{
    return radius;
}

std::string SpaceObjectType::get_type_name()
{
    return type_name;
}

RGB SpaceObjectType::get_rgb()
{
    return color;
}

SpaceObjectType* SpaceObjectFactory::get_type(std::string type_name, float mass, float radius, RGB rgb)
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

SpaceObject::SpaceObject(std::string s, float m, float r, RGB rgb)
{
    type = SpaceObjectFactory::get_type(s, m, r, rgb);
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
