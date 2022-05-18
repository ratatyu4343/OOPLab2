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
    Space* space;
};

class ModelingState : public State
{
public:
    ModelingState(Space*);
    void clickPause() override;
};

class PauseState : public State
{
public:
    PauseState(Space*);
    void clickModeling() override;
    void clickPause() override;
};

#endif // STATE_H
