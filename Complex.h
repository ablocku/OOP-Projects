#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex
{
    float re, im; //re - partea reala, im - partea imaginara

    public:
        Complex(); //constructor
        Complex(float const re_, float const im_);//constructor parametrizat
        Complex(Complex const &c_);//constructor de copiere
        ~Complex();//destructor
        Complex* operator =(Complex const &c_);//overload la '=', accepta atribuiri inlantuite
        friend std::istream &operator >>(std::istream &input, Complex &c_);//overload la '>>'
        friend std::ostream &operator <<(std::ostream &output, Complex const c_);//overload la '<<'
        float getRe();
        float getIm();
};

#endif // COMPLEX_H
