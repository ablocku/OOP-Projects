#ifndef COADA_H
#define COADA_H
#include "Vector.h"
#include "Complex.h"
#include <iostream>



class Coada: public Vector
{
    public:
        Coada();
        Coada(const Coada& c);
        ~Coada();
        Complex front();
        void pop();
        bool imaginar();
};

#endif // COADA_H
