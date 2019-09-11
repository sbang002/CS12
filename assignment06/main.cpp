/// =============== BEGIN ASSESSMENT HEADER ================
/// @file lab08/IntList. 
/// @brief Assignment/ for CS 12 Winter2015
///
/// @author Se Hoon Bang [sbang002@ucr.edu]
/// @date Feb 25 2015
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
#include "IntList.h"
#include <iostream>

using namespace std;

int main()
{
    IntList A;
    A.display();
    int X;
    cout << endl << "ENTER VALUE: ";
    cin >> X;
    A.push_front(X);
    A.display();
    cout << endl;
    cin >> X;
    A.push_back(X);
    A.display();
    cout << endl;
    A.pop_front();
    A.display();
    cout << endl;
    A.push_front(X);
    cin >> X;
    A.push_front(X);
    cin >> X;
    A.push_front(X);
    cin >> X;
    A.push_front(X);
    cin >> X;
    A.push_front(X);
    cin >> X;
    A.push_front(X);
    A.display();
    cout << endl;
    A.select_sort();
    A.display();
    cout << endl;
    cin >> X;
    A.insert_sorted(X);
    A.display();
    cout << endl;
    // A.remove_duplicates();
    // A.display();
    cout << endl;
    
    
    
    
    
    
    
    return 0;
}