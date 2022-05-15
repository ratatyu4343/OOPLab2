#include <iostream>
#include <Vector.h>

using namespace std;

int main()
{
    Vector* a = new Vector(12, 12);
    Vector b(13, 4);
    *a -= b;
    cout << a->x() << " " << a->y() << "\n";
}
