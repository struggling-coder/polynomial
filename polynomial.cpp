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
    process();
    if (ak[0] != 0 && k[0] == 0) cout << ak[0];
    else if (ak[0] == 1 && k[0] != 0) cout << "x^" << k[0];
    else if (ak[0] == -1 && k[0] != 0) cout << "x^" << k[0];
    else if (ak[0] == 0) { /*Do nothing*/ }
    else cout  << ak[0] << "x^" << k[0] ;
    for(int q = 1; q < n; q++)
    {
        double _ak = (ak[q]);
        int _k = (k[q]);
        if (_ak != 1 && _ak != -1)
        {
            if (_ak > 0)
            {
                if (_k != 1) cout << "+" << _ak << "x^" << _k;
                else cout << "+" << _ak << "x";
            }
            else if (_ak == 0) {  }
            else  {
                if (_k != 1) cout << _ak << "x^" << _k;
                else cout << _ak << "x";
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
        sum = sum + ((ak[j]) * pow(x, k[j]));
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
    tr.process();
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
    tr.process();
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
    tr.process();
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
    tr.process();
    return tr;
}

void Polynomial::plot(double xleft, double xright)
{
    //Initialize and prepare the canvas for the graph
    initCanvas("Polynomial Plot", 1100, 650);
    //O=(50,575)
    //(50+x, -450+y)

    Line x_axis(50,450,1050,450);

    Line x_left(50,25,50,575);
    Line x_right(1050,25,1050,575);
    Text text1(50, 585, xleft);
    Text text2(1050, 585, xright);

    double scaleY = 6.5;
    precision = 350; //Number of parts
    double increment = (xright - xleft) / precision;
    double ex, ex1, why1, why, end;

    end = valueAt(xright);
    ex = 50+xleft; why =  450 - valueAt(xleft);
    Line xp(50, why, 1050, why);
    Line yp(ex, 0, ex, 630);
    xp.setColor(COLOR(128,128,128));
    yp.setColor(COLOR(128,128,128));

    for(int j=0; j < precision; j++)
    {
        if(why < -900) {Text ov(1000,100, "OVERFLOW"); break;  }     //Overflow is not good for health
        if(why > 5000) { Text ov(1000,100, "OVERFLOW"); break; }

        ex1 = 50 + ((xleft + (increment * j)) * (1000/xright));
        why1 = 450 - valueAt(xleft + (increment * j))*(scaleY);
        Line l(ex, why, ex1, why1);
        l.setColor(COLOR("blue"));
        l.imprint();
        xp.move(0,why1 - why);
        yp.move(ex1 - ex, 0);
        ex = ex1; why = why1;
    }

    /* This seems to be a faulty approach
    Turtle t1;
    t1.penUp();
    t1.forward(500); t1.right(90); t1.forward(250); t1.right(90);
    t1.penDown(); t1.forward(1000); t1.left(180);
    Text text1(50, 575, xleft);
    Text text2(1050, 575, xright);
    t1.left(90);

    //Adjust PRECISION == 'dx'
    t1.penUp();
    t1.forward(valueAt(xleft));
    t1.right(90);
    t1.penDown();

    Polynomial dp = derivative();
    dp.print();
    double slope;

    for(int j = 1; (j*precision + xleft) < xright*10; j++)
    {
        slope = atan(dp.valueAt(j*precision + xleft)) * 180 / PI * 100;
        t1.left(slope);
        t1.forward(precision);
        t1.right(slope);
        cout << slope;
    }
    */

    wait(30);
}

//SORTING ALGORITHM
void Polynomial::sort()
{
    int temp;
    double dtemp;
    for(int i = 0; i < n-1;i++)
    {
        for(int j = i+1; j<n ; j++)
        {
            if(k[i] > k[j])
            {
                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
                dtemp = ak[i];
                ak[i] = ak[j];
                ak[j] = dtemp;
            }
        }
    }
}

void Polynomial::process()
{
    sort();
    double zeros, duplicates;

    for(int i1 = 0; i1 < n -1; i1++)
    {

    }
}
