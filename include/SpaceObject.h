#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <Vector.h>

class SpaceObject
{
    public:
        SpaceObject();

    private:
        Vector position;
        float mass;
        Vector speed;
        Vector acceleration;
};

#endif // SPACEOBJECT_H
