// ROLL NUMBER: 150260005

#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

class Polynomial
{
    public:
        //Constructors:
        Polynomial();
        Polynomial(int _n);
        Polynomial(int i_n, int i_k[], double i_ak[]);
        Polynomial(const Polynomial &source);

        //Default functions:
        void read();
        void print();
        double valueAt(double x);
        void plot(double xleft, double xright);
        int terms();

        Polynomial derivative();
        Polynomial integral();
        double root(double xleft, double xright);

        Polynomial operator+(Polynomial other);
        Polynomial operator*(Polynomial other);
        Polynomial operator/(Polynomial &other);
        Polynomial operator-(Polynomial other);

        //Additional Functions:
        void sort();
        void process();

    private:
        int n;
        int *k; double *ak;
        double precision; //This is the equivalent of 'dx'
};
