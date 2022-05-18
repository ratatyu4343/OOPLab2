#include "Space.h"

Space::Space(float G, float time)
{
    G_CONST = G;
    this->time = time;
    stoped = true;
    state = new PauseState(this);
}

float Space::force(SpaceObject* obj1, SpaceObject* obj2)
{
    float leng = Vector::length(obj1->get_position(), obj2->get_position());
    return (G_CONST*obj1->get_mass()*obj2->get_mass())/(leng*leng);
}

bool Space::colision(SpaceObject* obj1, SpaceObject* obj2)
{
    float leng = Vector::length(obj1->get_position(), obj2->get_position());
    if(leng <= (obj1->get_radius() + obj2->get_radius()))
        return true;
    else
        return false;
}

void Space::modeling()
{

}

void Space::clickModeling()
{
    state.clickModeling();
}

void Space::clickPause()
{
    state.clickPause();
}

void Space::changeState(State* new_state)
{
    delete state;
    state = new_state;
}

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
    space->set_stoped(true);
    space->changeState(new PauseState(space));
}

PauseState::PauseState(Space* s) : State(s)
{
    if(!space->is_stoped())
    {
        space->changeState(new ModelingState(space));
    }
}

void PauseState::clickPause()
{
    space->set_stoped(true);
}

