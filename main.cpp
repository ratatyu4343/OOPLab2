#include <iostream>
#include <Vector.h>
#include <SpaceObject.h>
#include <Space.h>


using namespace std;

int main()
{
    SpaceObject* obj1 = new Planet(10000, 20, RGB(10, 10, 10));
    obj1->set_position(Vector(0, 0));
    Space s(6, 0.05);
    //s.add_object(obj1);
    for(int i = 0; i < 10000; i++)
    {
        SpaceObject* ppp = new Planet(10, 10, RGB(0, 0 , 0));
        ppp->set_position(Vector(rand()%140000, rand()%220040));
        s.add_object(ppp);
    }
    while(true)
    {
        //Vector v = obj1->get_position();
        //std::cout << v.x() << " " << v.y() << "|\n";
        s.modeling();
    }
}
