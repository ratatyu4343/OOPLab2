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

void SpaceObject::set_mass(float m)
{
    type = SpaceObjectFactory::get_type(get_type_name(), m, get_radius(), get_rgb());
}

void SpaceObject::set_radius(float r)
{
    type = SpaceObjectFactory::get_type(get_type_name(), get_mass(), r, get_rgb());
}

void SpaceObject::set_color(RGB rgb)
{
    type = SpaceObjectFactory::get_type(get_type_name(), get_mass(), get_radius(), rgb);
}

void SpaceObject::set_type_name(std::string name)
{
    type = SpaceObjectFactory::get_type(name, get_mass(), get_radius(), get_rgb());
}

float SpaceObject::get_mass()
{
    return type->get_mass();
}

float SpaceObject::get_radius()
{
    return type->get_radius();
}

std::string SpaceObject::get_type_name()
{
    return type->get_type_name();
}

RGB SpaceObject::get_rgb()
{
    return type->get_rgb();
}
