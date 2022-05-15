#include "RGB.h"

RGB::RGB()
{
    R = 0;
    G = 0;
    B = 0;
}

RGB::RGB(int r, int g, int b)
{
    set_R(r);
    set_G(g);
    set_B(b);
}

int RGB::get_R()
{
   return R;
}
int RGB::get_G()
{
   return G;
}
int RGB::get_B()
{
   return B;
}

void RGB::set_R(int c)
{
    R = c;
}

void RGB::set_G(int c)
{
    G = c;
}

void RGB::set_B(int c)
{
    B = c;
}

bool RGB::operator==(RGB rgb2)
{
    if(rgb2.get_B() == B && rgb2.get_G() == G && rgb2.get_R() == R)
        return true;
    else
        return false;
}
