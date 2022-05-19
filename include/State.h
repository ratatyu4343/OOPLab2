#ifndef STATE_H
#define STATE_H
#include <Space.h>

class Space;
class State
{
public:
    State(Space*);
    virtual void clickModeling(){};
    virtual void clickPause(){};
    virtual void clickAdd(SpaceObject*){};
    Space* space;
};

class ModelingState : public State
{
public:
    ModelingState(Space*);
    void clickPause() override;
    void clickModeling() override;
    void clickAdd(SpaceObject*) override;
};

class PauseState : public State
{
public:
    PauseState(Space*);
    void clickModeling() override;
    void clickPause() override;
    void clickAdd(SpaceObject*) override;
};

#endif // STATE_H
