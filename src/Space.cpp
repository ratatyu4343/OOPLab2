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
    snap = nullptr;
    subscrb = new Subscriber;
    Logs* POS = new PositionLogs("positons");
    Logs* POS_PROX = new LogsProx(POS);
    Logs* SPE = new SpeedLogs("speeds");
    Logs* SPE_PROX = new LogsProx(SPE);
    subscrb->subscribe(POS_PROX);
    subscrb->subscribe(SPE_PROX);
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
    for(int i = 0; i < objects.size(); i++)
    {
        SpaceObject* obj1 = objects[i];
        Vector force_total(0, 0);
        for(int j = 0; j < objects.size(); j++)
        {
            if(i == j) continue;
            SpaceObject* obj2 = objects[j];
            if(colision(obj1, obj2))
            {
                if(obj1->get_mass() >= obj2->get_mass())
                {
                    obj1->marge(obj2, time);
                    delete obj2;
                    objects.erase(objects.begin()+j);
                    if(i > j)
                        i--;
                    j--;
                }
            }
            else
            {
                float fors = force(obj1, obj2);
                Vector p1 = obj1->get_position();
                Vector p2 = obj2->get_position();
                float alpha = std::atan2(p2.y()-p1.y(), p2.x()-p1.x());
                force_total += Vector(fors*std::cos(alpha), fors*std::sin(alpha));
            }
        }
        Vector a(force_total.x()/obj1->get_mass(), force_total.y()/obj1->get_mass());
        obj1->set_acceleration(obj1->get_acceleration() += a);
        obj1->set_acceleration(obj1->get_acceleration() -= Vector(obj1->get_acceleration().x()/8, obj1->get_acceleration().y()/8));
    }
    for(auto obj : objects)
    {
        if(obj->get_name() != "BlackHole")
        {
            Vector coord;
            coord.set_x(obj->get_speed().x()*time + obj->get_acceleration().x()*time*time/2);
            coord.set_y(obj->get_speed().y()*time + obj->get_acceleration().y()*time*time/2);
            obj->set_position(obj->get_position() += coord);
            Vector s(obj->get_acceleration().x()*time, obj->get_acceleration().y()*time);
            obj->set_speed(obj->get_speed() += s);
        }
        else
        {
            obj->set_position(obj->get_position());
            obj->set_speed(Vector(0, 0));
            obj->set_acceleration(Vector(0, 0));
        }
    }
    subscrb->update(objects);
}

void Space::clickModeling()
{
    state->clickModeling();
}

void Space::clickPause()
{
    state->clickPause();
}

void Space::clickSnapShot()
{
    state->clickSnapShot();
}

void Space::clickRestore()
{
    state->clickRestore();
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

void Space::clearObjcts()
{
    for(auto o : objects)
        delete o;
    objects.resize(0);
}

std::vector<SpaceObject*> Space::getObjs()
{
    return objects;
}

void Space::_creatSnapShot()
{
    if(snap)
        delete snap;

    snap = new SpaceSnapShot(this, G_CONST, time, objects);
}

void Space::_restore()
{
    snap->restore();
}

SpaceSnapShot::SpaceSnapShot(Space* s, float G, float t, std::vector<SpaceObject*> vec)
{
    space = s;
    G_CONST = G;
    time = t;
    for(int i = 0; i < vec.size(); i++)
    {
        ObjectSpanShot snap;
        snap.position = vec[i]->get_position();
        snap.speed = vec[i]->get_speed();
        snap.a = vec[i]->get_acceleration();
        snap.type = SpaceObjectFactory::get_type(vec[i]->get_mass(), vec[i]->get_radius(), vec[i]->get_rgb(), vec[i]->get_name());
        objcs.push_back(snap);
    }
}

void SpaceSnapShot::restore()
{
    space->set_gconst(G_CONST);
    space->set_time(time);
    space->clearObjcts();
    for(int i = 0; i < objcs.size(); i++)
    {
        SpaceObject* obj;
        if(objcs[i].type->get_name() == "Planet")
            obj = new Planet(objcs[i].type->get_mass(), objcs[i].type->get_radius(), objcs[i].type->get_rgb());
        else if(objcs[i].type->get_name() == "Star")
            obj = new Star(objcs[i].type->get_mass(), objcs[i].type->get_radius(), objcs[i].type->get_rgb());
        else
            obj = new BlackHole(objcs[i].type->get_radius(), objcs[i].type->get_rgb());
        obj->set_acceleration(objcs[i].a);
        obj->set_speed(objcs[i].speed);
        obj->set_position(objcs[i].position);
        obj->set_mass(objcs[i].type->get_mass());
        obj->set_color(objcs[i].type->get_rgb());
        obj->set_radius(objcs[i].type->get_radius());
        space->addObject(obj);
    }
}

void Subscriber::subscribe(Logs* L)
{
    v.push_back(L);
}

void Subscriber::unsubscribe(Logs* L)
{
    int i = 0;
    while(i < v.size() && v[i]!=L);
    if(i < v.size())
        v.erase(v.begin() + i);
}

void Subscriber::update(std::vector<SpaceObject*> v2)
{
    for(int i = 0; i < v.size(); i++)
        v[i]->update(v2);
}

