#include "Logs.h"

void PositionLogs::update(std::vector<SpaceObject*> objs)
{
    timer++;
    if(timer%100 == 0)
    {
        for(auto o : objs)
        {
            f << o->get_position().x() << " " << o->get_position().y() << "\n";
        }
        if(objs.size() > 0)f << "==========================\n";
        timer = 0;
    }
}

void SpeedLogs::update(std::vector<SpaceObject*> objs)
{
    timer++;
    if(timer%100 == 0)
    {
        for(auto o : objs)
        {
            f << o->get_speed().x() << " " << o->get_speed().y() << "\n";
        }
        if(objs.size() > 0)f << "==========================\n";
    }
}
