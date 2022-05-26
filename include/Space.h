#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>
#include <State.h>
#include <cmath>
#include <iostream>
#include "SDL2/SDL.h"
#include "SpaceWindow.h"
#include <Logs.h>

class State;
class SpaceSnapShot;
class Subscriber;

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
    std::vector<SpaceObject*> getObjs();

    State* state;
    void clickModeling();
    void clickPause();
    void clickSnapShot();
    void clickRestore();
    void addObject(SpaceObject*);
    void changeState(State*);
    void add_obj(SpaceObject*);
    void _restore();
    void _creatSnapShot();
    void clearObjcts();
private:
    Subscriber* subscrb;
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


class Subscriber
{
public:
    void subscribe(Logs*);
    void unsubscribe(Logs*);
    void update(std::vector<SpaceObject*>);
private:
    std::vector<Logs*> v;
};

#endif // SPACE_H
