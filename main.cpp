#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct tuplu
{
int maxi, poz;
};


class Vector{
    int *v;
    int n;



public:
    void sort()
    {
        sort(0,n-1);
    }

    Vector(int n1, int x = 0);
    Vector();
    Vector(const Vector &v2);
    ~Vector();
    void operator = (Vector const &v2);
    void update(int n1, int x);
    long long sum();
    tuplu max();
    int operator * (Vector const &v2);
    friend istream &operator >>(istream &input,Vector &v1);
    friend ostream &operator <<(ostream &output, Vector v1);
    int len();

private:
    void sort(int p, int q)
    {
    int k = partitionare(p,q);
    if (p<k-1)
        sort(p,k-1);
    if(k+1<q)
        sort(k+1,q);
    }

    int partitionare(int p, int q)
    {
    int x = v[p];
    int i,j;
    i = p+1;
    j = q;
    while(i<=j)
        {
        if(v[i] <= x)
            i++;
        if(v[j] >= x)
            j--;
        if(v[i] > x and v[j] < x and i < j)
            {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++; j--;
            }
        }
    v[p] = v[j];
    v[j] = x;
    return j;
    }


};



Vector::Vector()
{
    n = 10005;
    v = new int[n];
    for(int i = 0; i < n; ++i)
        v[i] = 0;
}

Vector::Vector(const Vector &v2)
{
    n=v2.n;
    v = new int[n];
    int i;
    for(i = 0;i < n; ++i)
        v[i] = v2.v[i];
}

Vector::~Vector()
{
    n=0;
    delete []v;
}

void Vector::operator = (Vector const &v2)
{
    delete []v;
    n = v2.n;
    v = new int[n];
    int i;
    for(i = 0; i < n; ++i)
        v[i] = v2.v[i];
}

void Vector::update(int n1, int x)
{
    delete []v;
    n = n1;
    int i;
    v = new int[n];
    for(i = 0 ;i < n; ++i)
        v[i] = x;
}

long long Vector::sum()
{
    int i;
    long long s=0;
    for(i = 0; i < n; ++i)
        s+= v[i];
    return s;
}

tuplu Vector::max()
{
    tuplu rez;
    rez.maxi = v[0];
    rez.poz = 0;
    int i;
    for(i = 1; i < n; ++i)
        if(v[i]>rez.maxi)
            {
            rez.maxi = v[i];
            rez.poz = i;
            }
    return rez;
}

int Vector::operator * (Vector const &v2)
{
    int p = 0, i;
    int mini;
    if(n > v2.n)
        mini = v2.n;
    else
        mini = n;
    for(i = 0; i < mini; ++i)
            p += v[i] * v2.v[i];

    return p;
}

istream& operator >>(istream &input, Vector &v1)
{
    input>>v1.n;
    int i;
    for(i = 0; i < v1.n; ++i)
        input>>v1.v[i];
    return input;
}

ostream& operator <<(ostream &output, Vector v1)
{
    output<<v1.n<<'\n';
    int i;
    output<<'[';
    for(i = 0; i < v1.n - 1; ++i)
        output<< v1.v[i]<<',';
    output<<v1.v[v1.n-1]<<']';
    output<<'\n';
    return output;
}

int Vector::len()
{
    return n;
}

void runTests()
{
Vector v2;
cout<<"Constructor de copiere:"<<'\n';
Vector v3 = v2;
cout<<v3<<'\n';
cout<<"Constructor de initializare cu un alt vector:"<<'\n';
Vector v4(v2);
cout<<v4<<'\n';
cout<<"Supraincarcare la '=' :"<<'\n';
cin>>v3;
v2 = v3;
cout<<v2<<'\n';
cout<<"Metoda update: "<<'\n';
v2.update(5,5);
cout<<v2<<'\n';
cout<<"Metoda max pt aflarea maximului si pozitiei lui :"<<'\n';
cin>>v2;
tuplu rez = v2.max();
cout<<v2;
cout<<"Maximul este: "<<rez.maxi << " pe pozitia: " << rez.poz<<'\n'<<'\n';;
cout<<"Metoda pt aflarea sumei elementelor vectorului:"<<'\n';
cout<<v2.sum()<<'\n'<<'\n';;
cout<<"Metoda pentru sortarea vectorului: "<<'\n';
v2.sort();
cout<<v2<<'\n';
cout<<"Supraincarcarea lui '*' pt aflarea produsului scalar a 2 vectori"<<'\n';
cout<<v3*v2<<'\n'<<'\n';
cout<<"Constructor pt initializare cu 0 pe toate pozitiile de la 0 la n-1 cu n = 10005:" << '\n';
}


int main()
{
freopen("date.in","r",stdin);
freopen("date.out","w",stdout);
runTests();
return 0;
}
