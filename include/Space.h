#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>

class Space
{
public:
    Space();
private:
   std::vector<SpaceObject*> objects;
};

#endif // SPACE_H
