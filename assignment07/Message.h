/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/Message.
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

//inclusion guards
#ifndef Message_H
#define Message_H

  //includes
#include <string>
#include <iostream>
#include <vector>
using namespace std;

  class Message
  {
   // allow access to these members by objects of derived classes
   protected:
     string author;
     string subject;
     string body;
     unsigned id;  // New !!
     // This will be the size of the message_list vector to which the
     // newly constructed Message * is being pushed_back
     vector<Message *> child_list; // New !!
     // This is how a Message is able to keep track of its Replies
 
   public:

     // default constructor
     Message();

     // Parameterized constructor; 
     // id will be the size of current Bboard message_list
     Message(const string &athr, 
             const string &sbjct, 
             const string &body, 
             unsigned id);

     // Be very careful here: some Messages will have two pointers to 
     // them, stored in very different places!
     // Where are they, and who should be responsible for deleting 
     // them?
     virtual ~Message();
     
     // returns true if the object is a Reply.
     virtual bool is_reply() const = 0;     //do

     virtual string to_formatted_string() const = 0; // New!!
    
         /* This function is responsible for printing the Message 
          * (whether Topic or Reply), and and all of the Message's 
          * "subtree" recursively:
      * After printing the Message with indentation n and appropriate 
      * format (see output details), it will invoke itself 
      * recursively on all of the Replies in its child_list,
      * incrementing the indentation value at each new level.
      *
      * Note: Each indentation increment represents 2 spaces. e.g. if 
      * indentation == 1, the reply should be indented 2 spaces, if 
      * it's 2, indent by 4 spaces, etc.
      */       
     void print(unsigned indentation) const; // New !!

     //returns the subject string.
     const string & get_subject() const;

     // returns the id.
     unsigned get_id() const; // New !!    

     // Adds a pointer to the child to the parent's child_list. 
     void add_child(Message *child); // New !! 

  };
  //end inc guards
  
#endif

