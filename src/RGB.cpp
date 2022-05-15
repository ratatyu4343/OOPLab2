#include "RGB.h"

RGB::RGB()
{
    R = 0;
    G = 0;
    B = 0;
}

RGB::RGB(int r, int g, int b)
{
    R = r;
    G = g;
    B = b;
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
