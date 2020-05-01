#include "Stiva.h"
#include "Vector.h"
#include "Complex.h"
#include <iostream>


Stiva::Stiva() {}

Stiva::Stiva(const Stiva& s) : Vector(s) {}

Stiva::~Stiva()
{
    dim = 0;
    delete []v;
}


Complex Stiva::top()
{
    if(!empty())
        return v[dim - 1];
    else
        return Complex(-1,-1);
}


void Stiva::pop()
{
    if(dim == 0)
        emp = true;
    if(!empty())
    {
        Stiva s(*this);
        dim--;
        delete[]v;
        v = new Complex[dim];
        for(int i = 0; i < dim; ++i)
            v[i] = s.v[i];
    }
    else
        ;
}

bool Stiva::imaginar()
{
    float x = 0;
    for(int i = 0; i < this->dim; ++i)
        if(this->v[i].getRe() != x)
            return false;
    return true;
}

