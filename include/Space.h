#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>

class Space
{
public:
    Space();
    void add_object(SpaceObject*);
    void delete_object(SpaceObject*);

private:
    void modeling();
    float force(SpaceObject*, SpaceObject*);
    bool colision(SpaceObject*, SpaceObject*);
    float G_CONST;
    std::vector<SpaceObject*> objects;
};

#endif // SPACE_H
