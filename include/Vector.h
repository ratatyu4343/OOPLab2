#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector(float, float);
        float x();
        float y();
        void set_x(float);
        void set_y(float);
        void add_x(float);
        void add_y(float);
        Vector operator += (Vector);
        Vector operator -= (Vector);
    private:
        float coord_x;
        float coord_y;
};

#endif // VECTOR_H
