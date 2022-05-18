#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>
#include <State.h>

class State;

class Space
{
public:
    Space(float, float);
    void add_object(SpaceObject*);
    void delete_object(SpaceObject*);
    void set_gconst(float);
    float get_gconst();
    void modeling();

    State* state;
    bool stoped;
    void clickModeling();
    void clickPause();
    void changeState(State*);
private:
    float G_CONST;
    float time;
    float force(SpaceObject*, SpaceObject*);
    bool colision(SpaceObject*, SpaceObject*);
    std::vector<SpaceObject*> objects;
};

#endif // SPACE_H
