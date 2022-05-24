#include "State.h"

State::State(Space* s)
{
    space = s;
}

ModelingState::ModelingState(Space* s) : State(s)
{
    space->modeling();
}

void ModelingState::clickPause()
{
    space->changeState(new PauseState(space));
}

void ModelingState::clickModeling()
{
    space->modeling();
}

void ModelingState::clickAdd(SpaceObject*)
{

}

PauseState::PauseState(Space* s) : State(s)
{

}

void PauseState::clickPause()
{

}

void PauseState::clickModeling()
{
    space->changeState(new ModelingState(space));
}

void  PauseState::clickAdd(SpaceObject* obj)
{
    space->add_obj(obj);
}

void PauseState::clickSnapShot()
{
    space->_creatSnapShot();
}

void PauseState::clickRestore()
{
    space->_restore();
}
