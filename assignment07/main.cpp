/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/main.cpp
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

#include "BBoard.h"
#include <string>
#include <iostream>


int main(int arc, char* argv[])
{

    string user_bb_title = "Jack";
    string File;
    
    BBoard bb(user_bb_title.c_str());
    
    cout << "Enter File Name ";
    cin >> File;
    
    bb.load_users(File);
    
    
    cout << "Enter File Name ";
    cin >> File;
    bb.load_messages(File);
    
    cout << user_bb_title << endl;
    bb.login();
    bb.run();
    bb.save_messages("data2.txt");

    return 0;
}