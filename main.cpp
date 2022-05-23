#include <iostream>
#include <Vector.h>
#include <SpaceObject.h>
#include <Space.h>


using namespace std;

int main()
{
    Space* s = Space::get_space(6, 0.1);
    Space* g = Space::get_space(2, 0.22);
    for(int i = 0; i < 100; i++)
    {
        SpaceObject* ppp = new Planet(10, 1, RGB(0, 0 , 0));
        ppp->set_position(Vector(rand()%1002, rand()%2202));
        s->addObject(ppp);
    }
    s->creatSnapShot();
    s->set_gconst(122);
    std::cout << s->get_gconst() << " |";
    s->restore();
    std::cout << s->get_gconst() << " |";
    /*while(true)
    {
        s->clickModeling();
        s->addObject(new Planet(10, 1, RGB(0, 0 , 0)));
    }*/
}
