#ifndef STIVA_H
#define STIVA_H
#include "Vector.h"
#include "Complex.h"
#include <iostream>


class Stiva: public Vector
{
    public:
        Stiva();
        Stiva(const Stiva& s);
        ~Stiva();
        Complex top();
        void pop(); //elimina vf stivei
        bool imaginar();
};

#endif // STIVA_H
