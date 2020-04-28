#include "Coada.h"
#include "Vector.h"
#include "Complex.h"
#include <iostream>


Coada::Coada()//constructor
{
    dim = 0;
    v = new Complex[dim];
}

Coada::Coada(const Coada &c)//constructor de copiere
{
    dim = c.dim;
    v = new Complex[dim];
    for(int i = 0; i < dim; ++i)
        v[i] = c.v[i];
}

Coada::~Coada()//destructor
{
    dim = 0;
    delete []v;
}

Complex Coada::front()//primul element
{
    return this->v[0];
}

void Coada::push(const Complex x)//adauga un element
{
    if(this->dim == 0)
    {
        this->dim = 1;
        this->v = new Complex[this->dim];
    }
    this->dim++;
    this->v[this->dim - 1] = x;
}

void Coada::pop()//stergerea
{
    for(int i = 0; i < this->dim - 1; ++i)
        this->v[i] = this->v[i + 1];
    this->dim--;
}

bool Coada::empty()
{
    return (this->dim == 0);
}

bool Coada::imaginar()
{
    float x = 0;
    for(int i = 0; i < this->dim; ++i)
        if(this->v[i].getRe() != x)
            return false;
    return true;
}

Coada & Coada::operator=(Coada const &c)
{
    this->dim = c.dim;
    delete []this->v;
    v = new Complex[dim];
    for(int i = 0; i < this->dim; ++i)
        this->v[i] = c.v[i];
    return *this;
}

std::istream& operator >>(std::istream &input, Coada &c)
{
    input >> c.dim;
    for(int i = 0; i < c.dim; ++i)
        input >> c.v[i];
    return input;
}

std::ostream& operator <<(std::ostream &output, Coada const c)
{
    output << c.dim << '\n';
    for(int i = 0; i < c.dim; ++i)
        output << c.v[i] << ' ';
    return output;
}


