/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/Reply.cpp
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

#include "Reply.h"
#include <sstream>
// no new member variables

//default constructor
Reply::Reply()
{
    author = "";
    subject = "";
    body = "";
    id = 0;
    child_list.resize(0);
   
} 

/* Parameterized constructor - similar to Message's constructor except:
* The subject should be initialized to "Re: <sbjct>" not <sbjct>.
*/
Reply::Reply(const string &athr, const string &sbjct, const string &body, 
        unsigned id)
{
    author = athr;
    subject = "Re: " + sbjct;
    this-> body = body;
    this-> id = id;
    child_list.resize(0);
}




bool Reply::is_reply() const // Returns true
{
    return true;
}

/* to_formatted_string writes the contents of the Reply to a string in the 
* following format:

<begin_reply>
:id: 4
:subject: single line
:from: author
:children: 5 6 [this line should not be printed if there are no children.]
:body: multiple lines
2nd line
<end>

* the line starting with :children: has the list of id's of all children 
* (See file specs. for details)
* This function should not assume the last character in body is a newline.
* In other words, this function must manually add a newline after the last line
* of the body (line 3 in this example).
* Also, the last character in the string must be a newline.
*/
string Reply::to_formatted_string() const // New !!
{
    stringstream ss;
    ss << id;
    string ID;
    ss >> ID;
    string K = "<begin_reply>";
    K += "\n:id: ";
    K += ID;
    K = K + "\n:subject: " + subject +"\n:from: "+author;
    if(child_list.size() > 0)
    {
        K = K + "\n:children: ";
        unsigned POP = child_list.size();
        for(unsigned i = 0; i < POP; i++)
        {
            // need to add #s i + id into string
            if(i != POP -1)
            { 
                ss << child_list.at(i)->get_id();
                ss >> ID;
                K += ID + " ";
            }

        }
    }
    K = K + "\n:body: " + body + "\n";
    K = K + "<end>\n";
    return K;
}


//end inc guards
