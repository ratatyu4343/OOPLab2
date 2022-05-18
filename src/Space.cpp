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

void Space::set_gconst(float g)
{
    G_CONST = g;
}

float Space::get_gconst()
{
    return G_CONST;
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
    auto it1 = objects.begin();
    while(it1 != objects.end())
    {
        SpaceObject* obj1 = *it1;
        auto it2 = objects.begin();
        while(it2 != objects.end())
        {
            if(it1 == it2) continue;

            SpaceObject* obj2 = *it2;
            if(this->colision(obj1, obj2))
            {
                if(obj1->get_mass() >= obj2->get_mass())
                {
                    obj1->marge(obj2);
                }
                it2 = objects.erase(it2);
            }
            else
            {

            }
        }
    }
}

void Space::clickModeling()
{
    state->clickModeling();
}

void Space::clickPause()
{
    state->clickPause();
}

void Space::changeState(State* new_state)
{
    delete state;
    state = new_state;
}

