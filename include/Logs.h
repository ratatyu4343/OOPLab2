#ifndef LOGS_H
#define LOGS_H
#include <vector>
#include <fstream>
#include <SpaceObject.h>
class Logs
{
public:
    Logs(std::string n)
    {
        name = n;
        f.open(n + ".txt");
    };
    virtual void update(std::vector<SpaceObject*>){};
protected:
    int timer = 0;
    std::string name;
    std::ofstream f;
};

class PositionLogs : public Logs
{
public:
    PositionLogs(std::string n):Logs(n){};
    void update(std::vector<SpaceObject*>) override;
};

class SpeedLogs : public Logs
{
public:
    SpeedLogs(std::string n):Logs(n){};
    void update(std::vector<SpaceObject*>) override;
};

#endif // LOGS_H
