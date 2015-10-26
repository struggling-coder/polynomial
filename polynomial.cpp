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
        cout << k[j] << endl << ak[j];
    }

}

Polynomial::Polynomial(int i_n, int i_k[], double i_ak[])
{
    n = i_n; k = i_k; ak = i_ak;
}


void Polynomial::print()
{
    cout << "-------------" << ak[0] << endl;
    if(k == 0) cout << ak[0] << endl;
    else cout  << ak[0] << "x^" << k[0] ;
    for(int q = 1; q < n; q++)
    {
        double _ak = (ak[q]);
        int _k = (k[q]);
        cout << "+" << _ak << "x^" << _k;
    }

}
