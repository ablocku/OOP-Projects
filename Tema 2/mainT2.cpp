#include <iostream>
#include <fstream>
#include <new>
#include "Complex.h"
#include "Vector.h"
#include "Stiva.h"
#include "Coada.h"

using namespace std;

void ComplexTests(const Complex x, ostream &g)
{
    g << "-->Constructor: " << x << '\n';
    Complex y(3,5);
    g << "-->Constructor parametrizat: " << y << '\n';
    Complex z(y);
    g << "-->Constructor de copiere: " << z << '\n';
    z = x;
    g << "-->Overload la '=': " << z << '\n';
    g << "-->Metoda getRe: " << z.getRe() << '\n';
    g << "-->Metoda getIm: " << z.getIm() << '\n';
    g << '\n' << '\n';
}

void VectorTests(Vector V, ostream &g)
{
    g << "-->Constructor: " << V << '\n';
    Vector V1(5,2,4);
    g << "-->Constructor parametrizat: " << V1 << '\n';
    Vector V2(V1);
    g << "-->Constructor de copiere: " << V2 << '\n';
    V = V1 = V2;
    g << "-->Overload la '=': " << V << '\n';
    Complex x(2,5);
    V.add(x);
    g << "-->Metoda add: " << V << '\n';
    g << '\n' << '\n';
}

void StivaTests(Stiva S, ostream &g)
{
    g << "-->Constructor: " << S << '\n';
    Stiva S1(S);
    g << "-->Constructor de copiere: " << S1 << '\n';
    /*Complex x(2,5);
    S1.push(x);
    g << "-->Metoda push: " << S1 << '\n';
    S1.pop();
    g << "-->Metoda pop: " << S1 << '\n';
    S = S1;
    g << "-->Overload la '=': " << S << '\n';
    g << "-->Metoda top: " << S.top() << '\n';
    g << "-->Metoda imaginar: " << S.imaginar() << '\n';
    S1.pop();
    S1.pop();
    S1.pop();
    g << "-->Metoda empty: " << S.empty() << '\n';
    g << '\n' << '\n';*/
}

void CoadaTests(Coada C, ostream &g)
{
    g << "-->Constructor: " << C << '\n';
    Coada C1(C);
    g << "-->Constructor de copiere: " << C1 << '\n';
    Complex x(2,5);
    C1.push(x);
    g << "-->Metoda push: " << C1 << '\n';
    C1.pop();
    g << "-->Metoda pop: " << C1 << '\n';
    C = C1;
    g << "-->Overload la '=': " << C << '\n';
    g << "-->Metoda front: " << C.front() << '\n';
    g << "-->Metoda imaginar: " << C.imaginar() << '\n';
    C.pop();
    C.pop();
    C.pop();
    g << "-->Metoda empty: " << C.empty() << '\n';
}

void runTests(ifstream &f, ofstream &g)
{
    int NumberOfTests;
    f >> NumberOfTests;
    for(int i = 0; i < NumberOfTests; ++i)
    {
        Complex x;
        f >> x;
        ComplexTests(x, g);
        Vector V;
        f >> V;
        VectorTests(V, g);
        Stiva S;
        f >> S;
        g << S << '\n';
        StivaTests(S, g);
        //Coada C;
        //f >> C;
        //CoadaTests(C, g);*/
    }
}

int main()
{
    ifstream f;
    ofstream g;
    f.open("date.in");
    g.open("date.out");
    runTests(f, g);
    f.close();
    g.close();
    return 0;
}
