#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>
#include <State.h>
#include <cmath>
#include <iostream>
class State;

class Space
{
public:
    static Space* get_space(float, float);
    void delete_object(SpaceObject*);
    void set_gconst(float);
    float get_gconst();
    void set_time(float);
    float get_time();
    void modeling();

    State* state;
    void clickModeling();
    void clickPause();
    void addObject(SpaceObject*);
    void changeState(State*);
    void add_obj(SpaceObject*);
    void draw();
private:
    Space(float, float);
    static  Space* space;
    float G_CONST;
    float time;
    float force(SpaceObject*, SpaceObject*);
    bool colision(SpaceObject*, SpaceObject*);
    std::vector<SpaceObject*> objects;
};

#endif // SPACE_H
