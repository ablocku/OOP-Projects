#ifndef COADA_H
#define COADA_H

#include "Vector.h"
#include "Complex.h"
#include <iostream>

class Coada : public Vector
{
    public:
        Coada();//constructor
        Coada(const Coada &c);//constructor de copiere
        ~Coada();//destructor
        Coada & operator =(Coada const &c);//overload la '='
        friend std::istream &operator >>(std::istream &input, Coada &c);//supraincarcare '>>'
        friend std::ostream &operator <<(std::ostream &output, Coada const c);//supraincarcare '<<'
        Complex front();//returneaza primul element
        void push(const Complex x);//adauga un element
        void pop();//operatia de stergere
        bool imaginar();
        bool empty();
};

#endif // COADA_H
