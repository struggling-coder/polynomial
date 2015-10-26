#include "polynomial.h"

Polynomial::Polynomial()
{
    n=1;
}

//Apparently, they have assured us that the polynomial is in ascending order
void Polynomial::read()
{
    cin >> n;
    k = new int[n];
    ak = new double[n];

    for (int j = 0;j < n; j++)
    {
        cin >> k[j] >> ak[j];
    }

}

int Polynomial::terms() { return n;
}

Polynomial::Polynomial(int i_n, int i_k[], double i_ak[])
{
    n = i_n; k = i_k; ak = i_ak;
}


void Polynomial::print()
{
    if(k == 0) cout << ak[0] << endl;
    else cout  << ak[0] << "x^" << k[0] ;
    for(int q = 1; q < n; q++)
    {
        double _ak = (ak[q]);
        int _k = (k[q]);
        cout << "+" << _ak << "x^" << _k;
    }

}

double Polynomial::valueAt(double x)
{
    double sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum = sum + ((ak[0]) * pow(x, k[0]));
    }

    return sum;
}

Polynomial Polynomial::operator+(Polynomial other)
{
    int _size = 0, blank = 0;
    //USE BLANK AS HANDLE TO FIND NEXT;
    for (int j = 0; j < other.terms(); j++)
    {
        for (int l = 0; l < sizeof(k); l++)
        {
            if (other.k[j] == k[l]) _size++;
        }
    }

    _size =  n + other.n - _size;
    int new_k[_size], new_ak[_size];


}
