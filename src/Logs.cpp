#include "Logs.h"

void PositionLogs::update(std::vector<SpaceObject*> objs)
{
    for(auto o : objs)
    {
        f << o->get_position().x() << " " << o->get_position().y() << "\n";
    }
    if(objs.size() > 0)f << "==========================\n";
}

void SpeedLogs::update(std::vector<SpaceObject*> objs)
{
    for(auto o : objs)
    {
        f << o->get_speed().x() << " " << o->get_speed().y() << "\n";
    }
    if(objs.size() > 0)f << "==========================\n";
}


void LogsProx::update(std::vector<SpaceObject*> v)
{
    if(timer%100 == 0)
    {
        log->update(v);
        timer = 0;
    }
    timer++;
}
