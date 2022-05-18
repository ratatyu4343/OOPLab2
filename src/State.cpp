#include "State.h"

State::State(Space* s)
{
    space = s;
}

ModelingState::ModelingState(Space* s) : State(s)
{
    space->modeling();
    space->changeState(new PauseState(space));
}

void ModelingState::clickPause()
{
    space->stoped = true;
    space->changeState(new PauseState(space));
}

PauseState::PauseState(Space* s) : State(s)
{
    if(!space->stoped)
    {
        space->changeState(new ModelingState(space));
    }
}

void PauseState::clickPause()
{
    space->stoped = true;
}

void PauseState::clickModeling()
{
    space->changeState(new ModelingState(space));
}
