#include "Stiva.h"
#include "Complex.h"
#include "Vector.h"

Stiva::Stiva()//constructor
{
    dim = 0;
    v = new Complex[dim];
}

Stiva::Stiva(const Stiva &s)//constructorul de copiere
{
    dim = s.dim;
    v = new Complex[dim];
    for(int i = 0; i < dim; ++i)
        v[i] = s.v[i];
}

Stiva::~Stiva()//destructor
{
    dim = 0;
    delete []v;
}

Complex Stiva::top()//returneaza varful stivei
{
    return this->v[0];
}

void Stiva::pop()//elimina varful stivei
{
    for(int i = 0; i < this->dim; ++i)
        this->v[i] = this->v[i+1];
    this->dim--;
}

void Stiva::push(const Complex x)
{
    if(this->dim == 0)
    {
        this->dim = 1;
        v = new Complex[dim];
        v[0] = x;
    }
    else
    {
        int dim_ = this->dim + 1;
        Complex *v_;
        v_ = new Complex[dim_];
        for(int i = this->dim; i >= 0; --i)
            v_[i+1] = this->v[i];
        v_[0] = x;
        delete []this->v;
        this->dim = dim_;
        v = new Complex[dim];
        for(int i = 0; i < this->dim; ++i)
            this->v[i] = v_[i];
        delete []v_;
    }
}

Stiva & Stiva::operator=(Stiva const &s)
{
    this->dim = s.dim;
    delete []this->v;
    v = new Complex[dim];
    for(int i = 0; i < this->dim; ++i)
        this->v[i] = s.v[i];
    return *this;
}

bool Stiva::empty()
{
    return (this->dim == 0);
}

bool Stiva::imaginar()
{
    float x = 0;
    for(int i = 0; i < this->dim; ++i)
        if(this->v[i].getRe() != x)
            return false;
    return true;
}

std::istream& operator >>(std::istream &input, Stiva &s)
{
    input >> s.dim;
    for(int i = s.dim; i >= 0; --i)
        input >> s.v[i];
    return input;
}

std::ostream& operator <<(std::ostream &output, Stiva const s)
{
    output << s.dim << '\n';
    for(int i = 0; i < s.dim; ++i)
        output << s.v[i] << ' ';
    return output;
}
