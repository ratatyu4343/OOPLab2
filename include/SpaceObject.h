#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <Vector.h>

class SpaceObject
{
    public:
        SpaceObject();
        Vector get_speed();
        Vector get_position();
        Vector get_acceleration();
        float get_mass();
        float get_radius();
        void set_speed(Vector);
        void set_position(Vector);
        void set_acceleration(Vector);
        void set_mass(float);
        void get_radius(float);
    private:
        float mass;
        float radius;
        Vector position;
        Vector speed;
        Vector acceleration;
};

#endif // SPACEOBJECT_H
