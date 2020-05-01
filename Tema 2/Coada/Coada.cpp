#include "Coada.h"
#include "Vector.h"
#include "Complex.h"
#include <iostream>


Coada::Coada() {}

Coada::Coada(const Coada& c) : Vector(c) {}

Coada::~Coada()
{
    dim = 0;
    delete[] v;
}


Complex Coada::front()
{
    if(!empty())
        return v[0];
    else
        return Complex(-1,-1);
}

void Coada::pop()
{
    if(!empty())
    {
        for(int i = 0; i < dim - 1; ++i)
            v[i] = v[i + 1];
        dim--;
    }
    if(dim == 0)
        {
        emp = true;
        v[0] = Complex(0,0);
        }
}

bool Coada::imaginar()
{
    float x = 0;
    for(int i = 0; i < this->dim; ++i)
        if(this->v[i].getRe() != x)
            return false;
    return true;
}


