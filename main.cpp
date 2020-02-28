#include <iostream>

using namespace std;

struct tuplu
{
int maxi, poz;
};


class Vector{
    int v[1000001], n;
public:

    Vector(int x, int n);
    Vector();
    Vector(const Vector &v2);
    ~Vector();
    Vector operator = (Vector const &v2);
    Vector update(int n1, int x);
    long long sum(const Vector v1);
    tuplu max(const Vector v1);
    void sort(Vector &v1, int p, int q);
    int partitionare(Vector &v1,int p, int q);
    int operator * (Vector const &v2);
};


Vector::Vector(int x, int n)
{
    int i;
    for(i=1;i<=n;i++)
        v[i]=x;
}

Vector::Vector()
{
    int i;
    n = 1000001;
    for(i=1;i<=n;i++)
        v[i]=0;
}

Vector::Vector(const Vector &v2)
{
    n=v2.n;
    int i;
    for(i=1;i<=n;i++)
        v[i]=v2.v[i];
}

Vector::~Vector()
{
    n=0;
    delete []v;
}

Vector Vector::operator = (Vector const &v2)
{
Vector res;
res.n = v2.n;
int i;
for(i=1;i<=n;i++)
    res.v[i]=v2.v[i];
return res;
}

Vector Vector::update(int n1, int x)
{
delete []v;
n = n1;
int i;
for(i=1;i<=n;i++)
    v[i] = x;
}

long long Vector::sum(const Vector v1)
{
int i;
long long s=0;
for(i=1;i<=v1.n;i++)
    s+=v1.v[i];
return s;
}

tuplu Vector::max(const Vector v1)
{
tuplu rez;
rez.maxi = v1.v[1];
rez.poz = 1;
int i;
for(i=2;i<=v1.n;i++)
    if(v1.v[i]>rez.maxi)
        {
        rez.maxi = v1.v[i];
        rez.poz = i;
        }
return rez;
}

void Vector::sort(Vector &v1, int p, int q)
{
int k = partitionare(v1,p,q);
if (p<k-1)
    sort(v1,p,k-1);
if(k+1<q)
    sort(v1,k+1,q);
}

int Vector::partitionare(Vector &v1, int p, int q)
{
int x = v1.v[p];
int i,j;
i = p+1;
j = q;
while(i<=j)
    {
    if(v1.v[i] <= x)
        i++;
    if(v1.v[j] >= x)
        j--;
    if(v1.v[i] > x and v1.v[j] < x and i < j)
        {
        int aux = v1.v[i];
        v1.v[i] = v1.v[j];
        v1.v[j] = aux;
        i++; j--;
        }
    }
v1.v[p] = v1.v[j];
v1.v[j] = x;
return j;
}

int Vector::operator * (Vector const &v2)
{
int p = 0,i;
if(n > v2.n)
    for(i=1;i<=v2.n;i++)
        p += v[i]*v2.v[i];
else
    for(i=1;i<=n;i++)
        p += v[i]*v2.v[i];
return p;
}

int main()
{
return 0;
}
