#include <iostream>
#include "Message.h"
using namespace std;

Message::Message()
{
    author = "";
    subject = "";
    body = "";
}

      //Constructor with parameters
Message::Message(const string &athr, const string &sbjct, const string &body)
{
    author = athr;
    subject = sbjct;
    this->body = body;
}

      //displays the message in the given format. See output specs.
      //Note: R’Sub will require an endl as the last output of this
      //function.
void Message::display() const
{
    if ((author == "") && (subject == "") && (body == ""))
    {
        cout << "Nothing to Display." << endl;
    }
    
    cout <<  subject << endl << "from " << author << " : " << body << endl;
    
}