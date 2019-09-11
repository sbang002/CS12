//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#1>/main.cpp 
/// @brief Assignment <#1> for CS 12 <Winter2015>
///
/// @author <Se Hoon Bang> [sbang002@ucr.edu]
/// @date <Current date>
///
/// @par Enrollment Notes 
///     Lecture Section: <e.g. 001>
/// @par
///     Lab Section: <e.g. 021>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

void fill(double A[],double a, double b, int size)
{
    for(int i = 0; i < size; i++)
    {
        A[i] = randFloat(a,b);
    }
}
double TheoMean(double a,double b)
{
    double x = a + b;
    return x/2.0;
}

double PracMean(double A[], int size)
{
    double x = 0;
    for(int i = 0; i < size; i++)
    {
        x = A[i] + x;
    }
    return x/size;
}

double TheoVar(double a,double b)
{
    int x = (b-a);
    x = x*x;
    return x/12.0;
    
}

double PracVar(double A[], double size, double mean)
{
    double x = 0;
    for(int i = 0; i < size; i ++)
    {
        double y = A[i] - mean;
        y = y*y;
        x = y + x;
    }
    return x/size;
}


int main()
{
    srand(333);
    
    double a;
    double b;
    
    double x[1000];
    double y[100000];
    
    double meanSmall;
    double meanBig;
    double TMean;
    
    double varSmall;
    double varBig;
    double TVar;
    
    cout << "Enter two values: ";
    cin >> a;
    cin >> b;
    cout << endl;
    
    fill(x, a, b, 1000);
    fill(y, a, b, 100000);
    
    TMean = TheoMean(a,b);
    meanSmall = PracMean(x,1000);
    meanBig = PracMean(y, 100000);
    
    TVar = TheoVar(a,b);
    varSmall = PracVar(x, 1000, meanSmall);
    varBig = PracVar(y, 100000, meanBig);
    
    cout << TMean << ' ' << meanSmall << ' ' << TVar << ' '<<  varSmall << endl;
    cout << TMean<< ' ' << meanBig << ' ' << TVar << ' ' << varBig << endl;
    return 0;
    
}