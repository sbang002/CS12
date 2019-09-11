/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/
/// @brief Assignment/ for CS 12 Winter2015
///
/// @author Se Hoon Bang [sbang002@ucr.edu]
/// @date March 12 2015
///
/// @par Enrollment Notes 
/// Lecture Section: 001
/// @par
/// Lab Section: 021
/// @par
/// 
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
// ================== END ASSESSMENT HEADER ===============

#include "IntVector.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector::IntVector( unsigned size )
{
    sz = size;
    cap = size;
    data = new int[size];
    for(int i = 0; i < size; i ++)
    {
        data[i] = 0;
    }
    
}

IntVector::IntVector( unsigned size, int value )
{
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < size; i++)
    {
        data[i] = value;
    }
    
}

unsigned IntVector::size( ) const
{
    return sz;
}

unsigned IntVector::capacity( ) const
{
    return cap;
}

bool IntVector::empty( ) const
{
    if(sz == 0)
    {
       return true;
    }
    return false;
}

const int & IntVector::at( unsigned index ) const
{
    if(index < sz)
    {
        return data[index];
    }
    exit(1);
}


IntVector::~IntVector()
{
    delete [] data;
}

void IntVector::expand()
{
    cap = cap * 2;
    int *Data = new int[cap];
    
    for(int i = 0; i < sz; i++)
    {
        Data[i] = data[i];
    }
    
    delete[] data;
    
    data = Data;
}

void IntVector::expand(unsigned X)
{
    cap = cap + X;
    int *Data = new int[cap];

    for(int i = 0; i < sz; i++)
    {
        Data[i] = data[i];
    }
    
    delete[] data;
    
    data = Data;

}

int & IntVector::at( unsigned index )
{
    if(index >= sz)
    {
        exit(1);
    }
    return *(data + index);
}

void IntVector::insert( unsigned index, int value )
{
    if(index > sz)
    {
        exit(1);
    }
    
    if(sz == cap)
    {
        expand();
    }
    
    //this is the insert part
    for(int i = sz; i < index; i --)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    
    sz = sz + 1;
    
}

void IntVector::erase( unsigned index )
{
    if(index >= sz)
    {
        exit(1);
    }
    
    sz = sz -1;
    
    for(int i = index; i < sz; i++)
    {
        data[i] = data[i+1];
    }
    
}

const int & IntVector::front( ) const
{
    return *data;
}

int & IntVector::front( )
{
    return *data;
}

const int & IntVector::back( ) const
{
    return *(data + sz - 1);
}

int & IntVector::back( )
{
    return *(data + sz - 1);
}

void IntVector::assign( unsigned n, int value )
{
    if(n > (2*cap))
    {
        expand(n - cap);
    }
    else if(n > cap) 
    {
        expand();
    }
    
    int *Data = new int[n];
    for(int i=0; i < n; i++)
    {
        *(Data + i) = value; 
    }
    
    delete[] data;
    
    data = Data;
    sz = n;
}

void IntVector::push_back( int value )
{
    if(sz == cap)
    {
        expand();
    }
    *(data + sz) = value;
    sz = sz+1;
}

void IntVector::pop_back( )
{
    if (sz == 0)
    {
        exit(1);
    }
    sz = sz - 1;
}

void IntVector::clear( )
{
    sz = 0;
}

void IntVector::resize( unsigned size )
{
    if(size < sz)
    {
        sz = size;
    }
    else if(size > sz)
    {
        if(size > (2 * cap))
        {
            expand(size - cap);
        }
        else
        {
            expand();
        }
        
        for(int i = sz; i < size; i++)
        {
            *(data + i) = 0;
        }
        sz = size;
    }
}

void IntVector::resize( unsigned size, int value )
{
    if(size < sz)
    {
        sz = size;
    }
    else if(size > sz)
    {
        expand(size - cap);
        for(int i = sz; i < size; i++)
        {
            *(data + i) = value;
        }
        sz = size;
    }
}

void IntVector::reserve( unsigned n )
{
    if(n > cap)
    {
        if((cap * 2) > n )
        {
            expand();
        }
        else
        {
            expand(n);
        }
    }
}
