#include "SpaceObject.h"

std::vector<SpaceObjectType*> SpaceObjectFactory::typeCollection;

SpaceObjectType::SpaceObjectType(float r, float m, RGB rgb)
{
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

RGB SpaceObjectType::get_rgb()
{
    return color;
}

SpaceObjectType* SpaceObjectFactory::get_type(float mass, float radius, RGB rgb)
{
    int count_of_types = typeCollection.size();
    for(int i = 0; i < count_of_types; i++)
    {
        bool b1 = typeCollection[i]->get_mass() == mass;
        bool b2 = typeCollection[i]->get_radius() == radius;
        bool b3 = typeCollection[i]->get_rgb() == rgb;
        if(b1&&b2&&b3)
        {
            return typeCollection[i];
        }
    }
    auto new_type = new SpaceObjectType(radius, mass, rgb);
    typeCollection.push_back(new_type);
    return new_type;
}

SpaceObject::SpaceObject(float m, float r, RGB rgb)
{
    type = SpaceObjectFactory::get_type(m, r, rgb);
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
    type = SpaceObjectFactory::get_type(m, get_radius(), get_rgb());
}

void SpaceObject::set_radius(float r)
{
    type = SpaceObjectFactory::get_type(get_mass(), r, get_rgb());
}

void SpaceObject::set_color(RGB rgb)
{
    type = SpaceObjectFactory::get_type(get_mass(), get_radius(), rgb);
}

float SpaceObject::get_mass()
{
    return type->get_mass();
}

float SpaceObject::get_radius()
{
    return type->get_radius();
}

RGB SpaceObject::get_rgb()
{
    return type->get_rgb();
}

Planet::Planet(float m, float r, RGB rgb) : SpaceObject(m, r, rgb)
{

}

void Planet::marge(SpaceObject* obj)
{
    float m3 = this->get_mass() + obj->get_mass();
    Vector v;
    v.set_x((this->get_speed().x()*this->get_mass() + obj->get_speed().x()*obj->get_mass())/m3);
    v.set_y((this->get_speed().y()*this->get_mass() + obj->get_speed().y()*obj->get_mass())/m3);
    this->set_mass(m3);
    this->set_radius(this->get_radius() + obj->get_radius()/2);
    this->set_speed(v);
}

BlackHole::BlackHole(float r, RGB rgb) : SpaceObject(2362247, r, rgb)
{

}

void BlackHole::marge(SpaceObject* obj)
{
    this->set_radius(this->get_radius() + obj->get_radius()/2);
}

Star::Star(float m, float r, RGB rgb) : SpaceObject(m, r, rgb)
{

}

void Star::marge(SpaceObject* obj)
{
    float m3 = this->get_mass() + obj->get_mass();
    Vector v;
    v.set_x((this->get_speed().x()*this->get_mass() + obj->get_speed().x()*obj->get_mass())/m3);
    v.set_y((this->get_speed().y()*this->get_mass() + obj->get_speed().y()*obj->get_mass())/m3);
    this->set_speed(v);
}
