#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "Complex.h"

class Complex;

class Vector
{
    protected:
        int dim;//dim - dimensiunea vectorului
        Complex *v;//v - retine elementele
        bool emp; //emp = true daca vectorul e vid
    public:
        Vector();//constructor
        Vector(int dim_, float re_, float im);//constructor parametrizat
        Vector(Vector const &v_);//constructor de copiere
        ~Vector();//destructor
        Vector & operator =(Vector const &v_);//overload la '=', accepta atribuiri inlantuite
        void add(const Complex x);//adaugarea unui element
        virtual std::istream& read(std::istream &input);
        bool empty();
        friend std::istream &operator >>(std::istream &input, Vector &v_);//overload la '>>'
        friend std::ostream &operator <<(std::ostream &output, Vector const v_);//overload la '<<'

};

#endif // VECTOR_H
