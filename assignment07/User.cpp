/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/User.cpp
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

#include <iostream>

#include <string>
#include "User.h"
using namespace std;

User::User()
{
    username = "";
    password = "";
}

// creates a user with given username and password.
User::User(const string& uname, const string& pass)
{
    username = uname;
    password = pass;
}


//returns the username
string User::get_username() const
{
    return username;
}
// returns true if the stored username/password matches with the
// parameters. Otherwise returns false.
// Note that, even though a User with empty name and password is 
// actually a valid User object (it is the default User), this 
// function must still return false if given a empty uname string.
bool User::check(const string &uname, const string &pass) const
{
    if((username == "")||  (password == ""))
    {
        return false;
    }
    
    if((uname == username) && (password == pass))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// sets a new password. This function will not be used in the 
// current assignment.
void User::set_password(const string &newpass)
{
    password = newpass;
}
