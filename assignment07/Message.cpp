/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/Message.cpp
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
#include "Message.h"
using namespace std;

Message::Message()
{
    author = "";
    subject = "";
    body = "";
    id = 0;
    child_list.resize(0);
}

      //Constructor with parameters
Message::Message(const string &athr, const string &sbjct, const string &body, 
                unsigned id)
{
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
    child_list.resize(0);

    
}

Message::~Message()
{
    author = "";
    subject = "";
    body = "";
    id = 0;
    for(unsigned i = 0; i < child_list.size(); i++)
    {
        for(unsigned j = i+1; j < child_list.size(); j++)
        {
            if(child_list.at(i) == child_list.at(j))
            {
                child_list.at(j) = 0;
            }
        }
        
        if(child_list.at(i) != 0)
        {
            delete child_list.at(i);
            child_list.at(i) = 0;
        }
    
    }
    child_list.resize(0);
}

void Message::print(unsigned indentation) const
{
    for(int i = 1; i <= indentation; i++)
    {
        cout << "  ";
    }
   for(int i = 1; i <= indentation; i++)
    {
        cout << "Re:";
    }
    cout << "subject: " <<  subject << endl;
    cout << "author: " << author << endl;
    cout << "body: " << body;
    for(int i = 0; i < child_list.size(); i++)
    {
        child_list.at(i)->print(indentation + 1);
    }
    
    
}

const string & Message::get_subject() const
{
    return subject;
}

unsigned Message::get_id() const
{
    return id;
}

// Adds a pointer to the child to the parent's child_list. 
void Message::add_child(Message *child)
{
    child_list.push_back(child);
}
    
