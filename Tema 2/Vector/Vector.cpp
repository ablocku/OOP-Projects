#include "Vector.h"
#include "Complex.h"
#include <iostream>

Vector::Vector()
{
    dim = 0;
    v = new Complex[dim];
}

Vector::Vector(int dim_, float re, float im)//dim - dimensiunea, (re,im) - parametrii lui Complex c, cu care vom umple vectorul
{
    dim = dim_; //copiem dimensiunea
    v = new Complex[dim]; //alocam spatiu
    Complex c(re,im); //valoarea lui c o vom pune in tot vectorul
    for(int i = 0; i < dim; ++i)
        v[i] = c;
}

Vector::Vector(Vector const &v_)//constructor de copiere
{
    dim = v_.dim;
    v = new Complex[dim];
    for(int i = 0; i < dim; ++i)
        v[i] = v_.v[i];
}

Vector::~Vector()//destructor
{
    dim = 0;
    delete []v;
}

void Vector::add(const Complex x)// adaugarea unui element
{
    Complex *v_;
    v_ = new Complex[this->dim + 1];
    for(int i = 0; i < this->dim; ++i)
        v_[i] = this->v[i];
    v_[this->dim] = x;
    delete []v;
    this->dim++;
    this->v = new Complex[this->dim];
    for(int i = 0; i < this->dim; ++i)
        this->v[i] = v_[i];
    delete []v_;
}

Vector & Vector::operator=(Vector const &v_)//overload la '='
{
    delete []v;
    dim = v_.dim;
    v = new Complex[dim];
    for(int i = 0; i < dim; ++i)
        v[i] = v_.v[i];
    return *this;
}

std::istream& operator >>(std::istream &input, Vector &v_)//overload la '>>'
{
    input >> v_.dim;
    for(int i = 0; i < v_.dim; ++i)
        input >> v_.v[i];
    return input;
}

std::ostream& operator <<(std::ostream &output, Vector const v_)//overload la '<<'
{
    output << v_.dim << '\n';
    output << '[';
    for(int i = 0; i < v_.dim - 1 ; ++i)
        output << v_.v[i] << ',';
    output << v_.v[v_.dim - 1] << ']';
    return output;
}
