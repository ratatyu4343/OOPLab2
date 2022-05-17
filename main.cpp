#include <iostream>
#include <Vector.h>
#include <SpaceObject.h>

using namespace std;

int main()
{
    SpaceObject* obj1 = new Planet(100, 20, RGB(10, 10, 10));
    obj1->set_speed(Vector(100, 220));
    SpaceObject* obj2 = new Star(100, 20, RGB(10, 10, 10));
    obj2->set_speed(Vector(-100, 0));
    obj1->marge(obj2);
    cout << obj1->get_speed().x() << " " << obj1->get_speed().y() << " " << obj1->get_mass()<< "\n";
}
