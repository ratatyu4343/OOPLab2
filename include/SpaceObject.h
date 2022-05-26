#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <Vector.h>
#include <RGB.h>
#include <vector>
#include <string>

using std::string;

class SpaceObjectType
{
    public:
        SpaceObjectType(float, float, RGB, string);
        float get_mass();
        float get_radius();
        RGB get_rgb();
        string get_name();
    private:
        string name;
        float mass;
        float radius;
        RGB color;
};

class SpaceObjectFactory
{
public:
    static SpaceObjectType* get_type(float, float, RGB, string);
private:
    static std::vector<SpaceObjectType*> typeCollection;
};

class SpaceObject
{
public:
    SpaceObject(float, float, RGB, string name);
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
    virtual string get_name(){};
    void marge(SpaceObject*, float time);
private:
    SpaceObjectType* type;
    Vector position;
    Vector speed;
    Vector acceleration;
    virtual float get_m3(SpaceObject*);
    virtual Vector get_speed_by_impuls(SpaceObject*);
    virtual void set_radius_by_marge(SpaceObject*);
};

class Planet : public SpaceObject
{
public:
    Planet(float, float, RGB);
    string get_name(){return "Planet";}
private:
    float get_m3(SpaceObject*)override;
};

class BlackHole : public SpaceObject
{
public:
    BlackHole(float, RGB);
    string get_name(){return "BlackHole";}
private:
    Vector get_speed_by_impuls(SpaceObject*) override;
    void set_radius_by_marge(SpaceObject*) override;
};

class Star : public SpaceObject
{
public:
    Star(float, float, RGB);
    string get_name(){return "Star";}
private:
    float get_m3(SpaceObject*) override;
    void set_radius_by_marge(SpaceObject*) override;
};
#endif // SPACEOBJECT_H
