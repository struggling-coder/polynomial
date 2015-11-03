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
        // Do the copy constructor: Polynomial()

        //Default functions:
        void read();
        void print();
        double valueAt(double x);
        void plot(double xleft, double xright);
        int terms();

        Polynomial derivative();
        Polynomial integral();
        double root();

        Polynomial operator+(Polynomial other);
        Polynomial operator*(Polynomial other);
        Polynomial operator/(Polynomial other);
        Polynomial operator-(Polynomial other);

        //Additional Functions:
        double maximum();
        double maximumAt();
        void sort();
        void process();

    private:
        int n;
        int *k; double *ak;
        double root;
        double precision; //This is the equivalent of 'dx'

};
