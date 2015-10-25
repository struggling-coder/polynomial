#include "polynomial.h"

Polynomial::Polynomial()
{
    n=1;
}

//Apparently, they have assured us that the polynomial is in ascending order
void Polynomial::read()
{

    cin >> n;
    double _ak[n]; int _k[n];

    for (int j = 0;j < n; j++)
    {
        cin >> _k[j] >> _ak[j];
        //cout << _k[j] << endl << _ak[j];
    }

    k = _k; ak = _ak;
}

Polynomial::Polynomial(int i_n, int i_k[], double i_ak[])
{
    n = i_n; k = i_k; ak = i_ak;
}

void Polynomial::print()
{
    if(k == 0) cout << ak[0] << endl;
    else cout << ak[0] << "x^" << k[0] << endl;
    for(int j = 1; j < n; j++)
    {
        cout << cout << ak[j] << "x^" << k[j] << endl;
    }
}
