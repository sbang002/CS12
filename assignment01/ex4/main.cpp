#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;


double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double rand_mv(double mean, double var)
{
    double b = (.5*((2.0 * mean) + (sqrt(var * 12.0))));
    double a = (2.0 * mean) - b;
    
    cout << a << ' ' << b << endl;
    
    return randFloat(a,b);
}




int main()
{
    double Mean;
    double Var;
    
    cout << "Enter Mean: ";
    cin >> Mean;
    cout << endl;
    
    cout << "Enter Variance: ";
    cin >> Var;
    cout << endl;
    
    rand_mv(Mean, Var);
    
    return 0;
}