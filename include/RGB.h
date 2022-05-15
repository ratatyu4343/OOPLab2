#ifndef RGB_H
#define RGB_H


class RGB
{
    public:
        RGB();
        RGB(int r, int g, int b);
        int get_R();
        int get_G();
        int get_B();
    private:
        int R;
        int G;
        int B;
};

#endif // RGB_H
