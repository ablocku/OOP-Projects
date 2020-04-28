#include "Complex.h"
#include <iostream>

Complex::Complex()//constructor
{
    re = 0;
    im = 0;
}

Complex::Complex(float const re_, float const im_)//constructor parametrizat
{
    this->re = re_;
    this->im = im_;
}

Complex::Complex(Complex const &c_)//constructor de copiere
{
    this->re = c_.re;
    this->im = c_.im;
}

Complex::~Complex()//destructor
{
    //dest
}

float Complex::getRe()
{
    return this->re;
}

float Complex::getIm()
{
    return this->im;
}

Complex* Complex::operator=(Complex const &c_)//overload la '='
{
    this->re = c_.re;
    this->im = c_.im;
    return this;
}

std::istream& operator >>(std::istream &input, Complex &c_)//overload la '>>'
{
    input >> c_.re;
    input >> c_.im;
    return input;
}

std::ostream& operator <<(std::ostream &output, Complex const c_)//overload la '<<'
{
    output << '(' << c_.re << ',' << c_.im << ')';
    return output;
}
