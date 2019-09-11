//inclusion guards
#ifndef Message_H
#define Message_H

  //includes
#include <string>
#include <iostream>
using namespace std;

  class Message
  {
    private:
      string author;
      string subject;
      string body;

    public:
    
      //default constructor
      Message();

      //Constructor with parameters
      Message(const string &athr, 
              const string &sbjct, 
              const string &body);

      //displays the message in the given format. See output specs.
      //Note: R’Sub will require an endl as the last output of this
      //function.
      void display() const;
  };
  //end inc guards
  
#endif