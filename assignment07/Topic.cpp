/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/Topic.cpp
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

#include "Topic.h"
#include <sstream>
//default constructor
Topic::Topic()
{ 
    author = "";
    subject = "";
    body = "";
    id = 0;
}

//Parameterized constructor
Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned id)
{
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
    
}


bool Topic::is_reply() const  // Returns false
{
    return false;
}


/* to_formatted_string writes the contents of the Topic to a 
* string in the following format:

<begin_topic>
:id: 4
:subject: single line
:from: author
:children: 5 6 [this line should not be printed if there are no children.]
:body: multiple lines - line 1
line 2
line 3
<end>

* line starting with :children: has the id's of all children (See file specs. 
* for details)
* This function should not assume the last character in body is a newline.
* In other words, this function must manually add a newline after the last line
* of the body (line 3 in this example).
* Also, the last character in the string must be a newline.
*/
string Topic::to_formatted_string() const  // New !!
{
    stringstream ss;
    ss << id;
    string ID;
    ss >> ID;
    string K  =  "<begin_topic>\n:id: " + ID;
 
    K = K + "\n:subject: " + subject + "\n:from: "+ author;
    if(child_list.size() > 0)
    {
        K = K + "/n :children: ";
        //insert number of children
        int I = child_list.size();
        for(unsigned i = 1; i <= I; i++ )
        {
            // add the numbers into it 
            ss << child_list.at(i)->get_id();
            ss >> ID;
            K += ID + " ";
        }
        
    }
    
    K = K + "\n:body: " + body + "\n<end>\n";
    return K;
}


//end inc guards
