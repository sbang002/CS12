#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>
#include "User.h"
#include "Message.h"


class BBoard {
    public:
        BBoard();
        BBoard(const string &ttl);
        void setup(const string &input_file);
        void login();
        void run();
    
    private:
        std::string title;
        User current_user;
        vector<Message>message_list;
        vector<User>user_list;
};

#endif