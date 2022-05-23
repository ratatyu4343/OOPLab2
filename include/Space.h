#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>
#include <State.h>
#include <cmath>
#include <iostream>
class State;
class SpaceSnapShot;

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
    void restore();
    void creatSnapShot();
    void clearObjcts();

    State* state;
    void clickModeling();
    void clickPause();
    void addObject(SpaceObject*);
    void changeState(State*);
    void add_obj(SpaceObject*);
    void draw();

private:
    SpaceSnapShot* snap;
    Space(float, float);
    static  Space* space;
    float G_CONST;
    float time;
    float force(SpaceObject*, SpaceObject*);
    bool colision(SpaceObject*, SpaceObject*);
    std::vector<SpaceObject*> objects;
};


struct ObjectSpanShot;
class SpaceSnapShot
{
public:
    SpaceSnapShot(Space*, float, float, std::vector<SpaceObject*>);
    void restore();
private:
    Space* space;
    float G_CONST;
    float time;
    std::vector<ObjectSpanShot> objcs;
};

struct ObjectSpanShot
{
    Vector position;
    Vector speed;
    Vector a;
    SpaceObjectType* type;
};

#endif // SPACE_H
