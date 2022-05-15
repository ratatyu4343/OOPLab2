#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <Vector.h>
#include <RGB.h>
#include <vector>
#include <string>

class SpaceObjectType
{
    public:
        SpaceObjectType(float, float, std::string, RGB);
        float get_mass();
        float get_radius();
        std::string get_type_name();
        RGB get_rgb();
    private:
        std::string type_name;
        float mass;
        float radius;
        RGB color;
};

class SpaceObjectFactory
{
public:
    static SpaceObjectType* get_type(std::string , float, float, RGB);
private:
    static std::vector<SpaceObjectType*> typeCollection;
};

class SpaceObject
{
public:
    SpaceObject(std::string, float, float, RGB);
    void set_speed(Vector);
    void set_position(Vector);
    void set_acceleration(Vector);
    void set_mass(float);
    void set_radius(float);
    void set_color(RGB);
    void set_type_name(std::string);
    Vector get_speed();
    Vector get_position();
    Vector get_acceleration();
    float get_mass();
    float get_radius();
    std::string get_type_name();
    RGB get_rgb();
private:
    SpaceObjectType* type;
    Vector position;
    Vector speed;
    Vector acceleration;
};

#endif // SPACEOBJECT_H
