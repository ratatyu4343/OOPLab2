#include "Space.h"

Space* Space::space;

Space* Space::get_space(float G, float t)
{
    if(Space::space == nullptr)
    {
        Space::space = new Space(G, t);
    }
    else
    {
        Space::space->set_gconst(G);
        Space::space->set_time(t);
    }
    return Space::space;
}

Space::Space(float G, float time)
{
    G_CONST = G;
    this->time = time;
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

void Space::set_time(float t)
{
    time = t;
}

float Space::get_time()
{
    return time;
}

bool Space::colision(SpaceObject* obj1, SpaceObject* obj2)
{
    float leng = Vector::length(obj1->get_position(), obj2->get_position());
    if(leng <= (obj1->get_radius() + obj2->get_radius()))
        return true;
    else
        return false;
}

#define PI 3.14159265
void Space::modeling()
{
    std::cout << objects.size() << "|\n";
    int size_of_p = (int)objects.size();
    int *count_of_planets = &size_of_p;
    for(int i = 0; i < *count_of_planets; i++)
    {
        SpaceObject* obj1 = objects[i];
        for(int j = 0; j < *count_of_planets; j++)
        {
            SpaceObject* obj2 = objects[j];
            if(i != j)
                if(colision(obj1, obj2))
                {
                    if(obj1->get_mass() >= obj2->get_mass())
                    {
                        obj1->marge(obj2);
                        delete obj2;
                        objects.erase(objects.begin()+j);
                        (*count_of_planets)--;
                        if(i > j)
                        {
                            i--;
                        }
                        j = -1;
                    }
                }
                else
                {
                    float fors = force(obj1, obj2);
                    Vector p1 = obj1->get_position();
                    Vector p2 = obj2->get_position();
                    float alpha = std::atan2(p2.y()-p1.y(), p2.x()-p1.x());
                    Vector a(fors*std::cos(alpha)/obj1->get_mass(), fors*std::sin(alpha)/obj1->get_mass());
                    obj1->set_acceleration(obj1->get_acceleration() += a);
                }
        }
    }
    for(auto obj : objects)
    {
        Vector coord;
        coord.set_x(obj->get_speed().x()*time + obj->get_acceleration().x()*time*time/2);
        coord.set_y(obj->get_speed().y()*time + obj->get_acceleration().y()*time*time/2);
        obj->set_position(obj->get_position() += coord);
        Vector s(obj->get_acceleration().x()*time, obj->get_acceleration().y()*time);
        obj->set_speed(obj->get_speed() += s);
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

void Space::addObject(SpaceObject* obj)
{
    state->clickAdd(obj);
}

void Space::add_obj(SpaceObject* obj)
{
    objects.push_back(obj);
}
