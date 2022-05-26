#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
#include <utility>

struct Vector
{
    public:
        Vector();
        Vector(float, float);
        float x();
        float y();
        void set_x(float);
        void set_y(float);
        void add_x(float);
        void add_y(float);
        Vector operator += (Vector);
        Vector operator -= (Vector);
        static float length(Vector, Vector);
    private:
        float coord_x;
        float coord_y;
};

struct PairVectorAdapter : public Vector
{
    public:
        PairVectorAdapter(std::pair<float, float>);
        float x();
        float y();
        void set_x(float);
        void set_y(float);
        void add_x(float);
        void add_y(float);
        Vector operator += (Vector);
        Vector operator -= (Vector);
    private:
        std::pair<float, float> p;
};

#endif // VECTOR_H
