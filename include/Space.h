#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include <SpaceObject.h>

class Space
{
public:
    Space(float, float);
    void add_object(SpaceObject*);
    void delete_object(SpaceObject*);
    void set_gconst();
    bool is_stoped();
    void set_stoped(bool);
private:
    float G_CONST;
    float time;
    float force(SpaceObject*, SpaceObject*);
    bool colision(SpaceObject*, SpaceObject*);
    std::vector<SpaceObject*> objects;

    State* state;
    void clickModeling();
    void clickPause();
    void changeState(State*);

    void modeling();
};

class State
{
public:
    State(Space*);
private:
    Space* space;
    virtual void clickModeling(){};
    virtual void clickPause(){};
};

class ModelingState : State
{
public:
    ModelingState(Space*);
private:
    void clickPause() override;
};

class PauseState : State
{
public:
    PauseState(Space*);
private:
    void clickModeling() override;
    void clickPause() override;
};

#endif // SPACE_H
