#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <Vector.h>
#include <RGB.h>
#include <vector>

class SpaceObjectType
{
    public:
        SpaceObjectType(float, float, string, int, int, int);
        float get_mass();
        float get_radius();
        string get_type_name();
        RGB get_rgb();
    private:
        string type_name;
        float mass;
        float radius;
        RGB color;
};

class SpaceObjectFactory
{
public:
    SpaceObjectType* get_type(string , float, float, RGB);
private:
    std::vector<SpaceObjectType*> typeCollection;
};

class SpaceObject
{
public:
    SpaceObject();
    void set_speed(Vector);
    void set_position(Vector);
    void set_acceleration(Vector);
    Vector get_speed();
    Vector get_position();
    Vector get_acceleration();
private:
    SpaceObjectType* type;
    Vector position;
    Vector speed;
    Vector acceleration;
};

#endif // SPACEOBJECT_H
