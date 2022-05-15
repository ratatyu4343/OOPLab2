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
        void set_speed(Vector);
        void set_position(Vector);
        void set_acceleration(Vector);
        void set_mass(float);
    private:
        float mass;
        Vector position;
        Vector speed;
        Vector acceleration;

};

#endif // SPACEOBJECT_H
