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
    double x = (b-a);
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
    
    double a = 3.0;
    double b = -3.0;
    double c =(-1.0);
    double d =-7.0;
    
    double x[500];
    double y[500];
    
    double meanSmall;
    double meanBig;
    double TMean;
    double TMean2;
    
    double varSmall;
    double varBig;
    double TVar;
    double TVar2;

    
    fill(x, a, b, 500);
    fill(y, c, d, 500);
    
    TMean = TheoMean(a,b);
    TMean2 = TheoMean(c,d);
    meanSmall = PracMean(x,500);
    meanBig = PracMean(y, 500);
    
    TVar = TheoVar(a,b);
    TVar2 = TheoVar(c, d);
    varSmall = PracVar(x, 500, meanSmall);
    varBig = PracVar(y, 500, meanBig);
    
    cout << TMean << ' ' << meanSmall << ' ' << TVar << ' '<<  varSmall << endl;
    cout << TMean2<< ' ' << meanBig << ' ' << TVar2 << ' ' << varBig << endl;
    return 0;
    
}
//need Var of .5 and 2
// need mean of 4