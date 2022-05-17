#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <Vector.h>
#include <RGB.h>
#include <vector>
#include <string>

class SpaceObjectType
{
    public:
        SpaceObjectType(float, float, RGB);
        float get_mass();
        float get_radius();
        RGB get_rgb();
    private:
        float mass;
        float radius;
        RGB color;
};

class SpaceObjectFactory
{
public:
    static SpaceObjectType* get_type(float, float, RGB);
private:
    static std::vector<SpaceObjectType*> typeCollection;
};

class SpaceObject
{
public:
    SpaceObject(float, float, RGB);
    void set_speed(Vector);
    void set_position(Vector);
    void set_acceleration(Vector);
    void set_mass(float);
    void set_radius(float);
    void set_color(RGB);
    Vector get_speed();
    Vector get_position();
    Vector get_acceleration();
    float get_mass();
    float get_radius();
    RGB get_rgb();
    virtual void marge(SpaceObject*) = 0;
private:
    SpaceObjectType* type;
    Vector position;
    Vector speed;
    Vector acceleration;
};

class Planet : public SpaceObject
{
public:
    Planet(float, float, RGB);
    void marge(SpaceObject*) override;
};

class BlackHole : public SpaceObject
{
public:
    BlackHole(float, RGB);
    void marge(SpaceObject*) override;
};

class Star : public SpaceObject
{
public:
    Star(float, float, RGB);
    void marge(SpaceObject*) override;
};
#endif // SPACEOBJECT_H
