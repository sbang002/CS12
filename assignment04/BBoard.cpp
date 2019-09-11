#include <iostream>
#include "BBoard.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;



BBoard::BBoard()
{
    title = "";
}

BBoard::BBoard(const string &ttl)
{
    title = ttl;
}

// check this one more
void BBoard::setup(const string &input_file)
{
    ifstream fin;
    fin.open(input_file.c_str());
    if (!fin.is_open())
    {
        cout << "Error opening file";
        exit(0);
    }
    
    string uname;
    string pass;
        
    while(fin >> uname)
    {
        // fin >> uname;
        fin >> pass;
        
        User A( uname, pass );
        user_list.push_back(A);
        
    }
    fin.close();
    
}

// still working on it
void BBoard::login()
{
    string uname;
    string pass;
    
    int K = 0;
    cout << " Welcome to " << title << " Amazing Bulletin Board" << endl;
    do{
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> uname;
        cout << endl;
        if (uname != "Q")
        {
            if(uname != "q")
            {
                cout << "Enter your password: ";
                cin >> pass;
                cout << endl;
            }
        }
        
        for(unsigned i = 0; i < user_list.size(); i++)
        {
            if(user_list.at(i).check(uname, pass))
            {
                K = 1;
            }
        }
        
        if (uname == "Q")
        {
            K = 1;
        }else if (uname == "q")
        {
            K = 1;
        }
    }while(K != 1);
    
    //if quit end program
    if((uname == "q") || (uname == "Q"))
    {
        cout << "Bye!" << endl;
        exit(0);
    }
    
    //if user name correct store it
    // this->current_user(uname, pass);
    User A(uname, pass);
    this->current_user = A;
    
    cout << "Welcome back " << current_user.get_username() << "!" << endl;
    
}

void BBoard::run()
{
    int valid = 0;
    for(unsigned i = 0; i < user_list.size(); i++)
    {
        if(current_user.get_username() == user_list.at(i).get_username() )
        {
            valid = 1;
            
        }
    }
    if (valid == 0)
    {
        exit(0);
    }
    
    
    char action;
    
    do
    {
        cout << "Menu \n";
        cout << " - Display Messages ('D' or 'd')" << endl;
        cout << " - Add New Message('N' or 'n')" << endl;
        cout << " - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> action;
        cin.ignore();
        
        //adding new message function
        if((action == 'N') || (action == 'n'))
        {
            string sbjct;
            string bdy;
            
            cout << "Enter Subject: ";
            getline(cin, sbjct);
            
            cout << "Enter Body: ";
            getline(cin, bdy);
            
            // create the message
            Message A(current_user.get_username(), sbjct, bdy);
            
            // adds message to list
            message_list.push_back(A);
            
            cout << "Message Recorded!" << endl;
        }
        else if((action == 'D')||(action == 'd')) // Display function
        {
            if(message_list.size() == 0)
            {
                cout << "Nothing to Display." << endl;
            }
            else
            {
                for(unsigned i = 0; i < message_list.size(); i++)
                {
                    cout << "-----------------------------------------------" 
                        <<endl <<"Message #" << i+1 << ": ";
                    message_list.at(i).display();
                }
                cout << "-----------------------------------------------" 
                    << endl;
            }   
        
        }
        else if((action == 'Q') || (action == 'q'))
        {
            cout << "Bye!" << endl;
            valid = 10;
        }
        
            
    }while(valid != 10);
}