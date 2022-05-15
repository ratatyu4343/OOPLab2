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
        void set_R(int);
        void set_G(int);
        void set_B(int);
        bool operator == (RGB);
    private:
        int R;
        int G;
        int B;
};

#endif // RGB_H
