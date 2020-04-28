#ifndef STIVA_H
#define STIVA_H
#include "Vector.h"
#include "Complex.h"
#include <iostream>

class Stiva : public Vector
{
    public:
        Stiva();//constructor
        Stiva(const Stiva &s);//constructor de copiere
        ~Stiva();//destructor
        Stiva & operator =(Stiva const &s);//supraincarcare '='
        friend std::istream &operator >>(std::istream &input, Stiva &s);//supraincarcare '>>'
        friend std::ostream &operator <<(std::ostream &output, Stiva const s);//supraincarcare '<<'
        Complex top();//returneaza varful stivei
        void pop();//elimina varful stivei
        void push(const Complex x);//adauga un element la stiva
        bool empty();//verificator daca stiva e goala
        bool imaginar();

};

#endif // STIVA_H
