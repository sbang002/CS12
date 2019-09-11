/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/BBoard.h
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

#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"


class BBoard {
    public:
        BBoard();
        BBoard(const string &ttl);
        void setup(const string &input_file);
        ~BBoard( );// new
        
        bool load_users(const string &userfile);
        //void setup(const string &input_file); // replaced by ^
        
         bool load_messages(const string& datafile);
         
         bool save_messages(const string& datafile);
        
        void login();//changed
        void run();// changes
    
    private:
        std::string title;
        User* current_user;//changes MAJOR
        vector<Message *>message_list;// major changes
        vector<User>user_list;
};

#endif