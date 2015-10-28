#include "polynomial.h"

Polynomial::Polynomial()
{
    n = 1;
}

Polynomial::Polynomial(int _n)
{
    n = _n;
    k = new int[n];
    ak = new double[n];
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

int Polynomial::terms() { return n; }

Polynomial::Polynomial(int i_n, int i_k[], double i_ak[])
{
    n = i_n; k = i_k; ak = i_ak;
}

// Properly formatted print() function
void Polynomial::print()
{
    if (ak[0] != 0 && k[0] == 0) cout << ak[0];
    else if (ak[0] == 1 && k[0] != 0) cout << "x^" << k[0];
    else if (ak[0] == 0) { /*Do nothing*/ }
    else cout  << ak[0] << "x^" << k[0] ;
    for(int q = 1; q < n; q++)
    {
        double _ak = (ak[q]);
        int _k = (k[q]);
        if (_ak != 1)
        {
            if (_ak > 0)
            {
                if (_k != 1) cout << "+" << _ak << "x^" << _k;
                else cout << "+" << _ak << "x";
            }
            else if (_ak == 0) {  }
            else  {
                if (_k != 1) cout << "-" << _ak << "x^" << _k;
                else cout << "-" << _ak << "x";
            }
        }
        else
        {
            if (_ak > 0) {
                if (_k != 1) cout << "+" << "x^" << _k;
                else cout << "+"  << "x";
            }
            else {
                if (_k != 1) cout << "-" << "x^" << _k;
                else cout << "-" << "x";
            }
        }

    }
    cout << endl;
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
    /*int _size = 0, blank = 0;
    //USE BLANK AS HANDLE TO FIND NEXT;
    for (int j = 0; j < other.terms(); j++)
    {
        for (int l = 0; l < sizeof(k); l++)
        {
            if (other.k[j] == k[l]) _size++;
        }
    }

    _size =  n + other.n - _size;

    for (int j = 0; j < other.terms(); j++)
    {
        for (int l = 0; l < sizeof(k); l++)
        {
            if (other.k[j] == k[l])
            {
                new_k[blank] = k[l];
                new_ak[blank] = ak[l] + other.ak[j];
                blank++;
            }
        }
    }
    */

    int *new_k = new int[n + other.n];
    double *new_ak = new double[n + other.n];


    for (int j = 0; j < other.terms(); j++ )
    {
        new_k[j] = other.k[j];
        new_ak[j] = other.ak[j];
    }

    for (int j = 0; j < n; j++)
    {
        new_k[j+other.n] = k[j];
        new_ak[j+other.n] = ak[j];
    }

    Polynomial tr(n + other.n);
    tr.ak = new_ak;
    tr.k = new_k;
    //tr.n = n + other.n;
    return tr;
}

Polynomial Polynomial::operator-(Polynomial other)
{
    int *new_k = new int[n + other.n];
    double *new_ak = new double[n + other.n];


    for (int j = 0; j < other.terms(); j++ )
    {
        new_k[j] = other.k[j];
        new_ak[j] = (-1) * other.ak[j];
    }

    for (int j = 0; j < n; j++)
    {
        new_k[j+other.n] = k[j];
        new_ak[j+other.n] = ak[j];
    }

    Polynomial tr(n + other.n);
    tr.ak = new_ak;
    tr.k = new_k;
    return tr;
}

Polynomial Polynomial::derivative()
{
    int *new_k = new int[n];
    double *new_ak = new double[n];

    for(int j = 0; j < n; j++)
    {
        if(k[j] == 0) { new_k[j] = 0, new_ak[j] = 0; }
        else
        {
            new_k[j] = k[j] - 1;
            new_ak[j] = ak[j] * k[j];
        }
    }

    Polynomial tr(n);
    tr.ak = new_ak;
    tr.k = new_k;
    return tr;
}

Polynomial Polynomial::integral()
{
    int *new_k = new int[n];
    double *new_ak = new double[n];

    for(int j = 0; j < n; j++)
    {
        new_k[j] = k[j] + 1;
        new_ak[j] = ak[j] /(k[j] + 1);
    }

    Polynomial tr(n);
    tr.ak = new_ak;
    tr.k = new_k;
    return tr;
}
