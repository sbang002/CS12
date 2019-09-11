/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/main.cpp 
/// @brief Assignment/ for CS 12 Winter2015
///
/// @author Se Hoon Bang [sbang002@ucr.edu]
/// @date Feb 18 2015
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
using namespace std;

int main()
{
    unsigned size = 0;
    int num;
    
    cin >> size  >> num;
    if (size == 0)
    {
        IntVector A;
        cout << A.size() << " " << A.capacity();
        
        cout << endl << "Enter Index ";
        int x;
        cin >> x;
        cout << A.at(x) << endl;
        
    }
    else if(num == 0)
    {
        IntVector A(size);
    
        cout << "Im IN" << A.size() << " " << A.capacity() << endl;
        
        
        
        int K;
        int B;
        
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        
        cin >> K >> B;
        A.insert(K,B);
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        
        A.erase(B);
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        
        cin >> K;
        A.push_back(K);
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        cout << "PLace front and bak " << A.front() << " " << A.back() << endl;
        
        cin >> K >> B;
        A.assign(K, B);
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        cout << "PLace front and bak " << A.front() << " " << A.back() << endl;
        
        cin >> K;
        A.resize(K);
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        cout << "PLace front and bak " << A.front() << " " << A.back() << endl;
        
        cin >> K >> B;
        A.resize(K, B);
        cout << "Cap: " << A.capacity() << endl;
        cout << "Size: " << A.size() << endl;
        cout << "PLace front and bak " << A.front() << " " << A.back() << endl;
        
        
    }
    else
    {
        IntVector A(size, num);
        cout << A.size() << " " << A.capacity();
        
        cout << endl << "Enter Index ";
        int x;
        cin >> x;
        cout << A.at(x);
    }
    
    
    return 0;
}