/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn7/BBoard.cpp
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
#include "BBoard.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string> 
using namespace std;



BBoard::BBoard()
{
    title = "";
    current_user = 0;
    
}

BBoard::BBoard(const string &ttl)
{
    title = ttl;
    current_user = 0;
}

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


BBoard::~BBoard()
{
    title = "";
    delete current_user;
    current_user = 0;
    
    for(int i = 0; i < message_list.size(); i++)
    {
        delete message_list.at(i);
        message_list.at(i) = 0;
    }
    message_list.resize(0);
    
    for(int i = 0; i < user_list.size(); i++)
    {
        User x;
        user_list.at(i) = x;
    }
  user_list.resize(0);
}


bool BBoard::load_users(const string &userfile) //void BBoard::setup(const string &input_file)
{
    ifstream fin;
    fin.open(userfile.c_str());
    if(!fin.is_open())
    {
        cout << "Error opening file";
        return false;
    }
    
    string uname;
    string pass;
        
    while(fin >> uname)
    {
        
        fin >> pass;
        
        User A( uname, pass );
        user_list.push_back(A);
        
    }
    fin.close();
    return true;
    
}

bool BBoard::load_messages(const string& datafile)
{
  
    
    /*This function gets a filename (datafile) of a file that stores the messages 
    from previous sessions in the given format (See File Format Specs).
    It opens and reads the file, creating Topic and Reply objects as appropriate,
    and fills the message_list vector (note: remember that message_list is a vector 
    of pointers, not messages).
    If an error occurs when opening the file, it returns false. 
    Returns true otherwise.*/
    
    ifstream fin;
    fin.open(datafile.c_str());
    cout << "1 \n";
    if(!fin.is_open())
    {
        cout << "Failed to open file.";
        return false;
    }
    
    int X = 0;
    cout << X;
    fin >> X;
    cout << X; /////
    string Y;
    for(int i = 0; i < X; i++)
    {
        
        fin >> Y;
        unsigned ID;
        int WASCHILD = 0;
        vector <int> children;
        string Art, sbjt, bdy, child;
        if(Y == "<begin_topic>")
        {
            fin >> ID;
            //this includes the :type: part
            getline(fin,sbjt);
            getline(fin, Art);
            fin >> child; 
            if(child == ":children:")
            {
                WASCHILD = 1;
                //ok so there are children
                // how do you look at how many children
                getline(fin,child);
                for(i = 0; i < child.size(); i++)
                {
                    int k;
                    if(isdigit(child.at(i)))
                    {
                        k = i;
                        while(isdigit(child.at(i)))
                        {
                            k = k*10 + child.at(i);
                            i++;
                        }
                        children.push_back(k);
                    }
                }
                //got child done now get body
                //peak checks next word check is <end>
                //use rest to get the line of txt then add it onto bdy
                string peak = " ";
                string rest;
                while(peak != "<end>")
                {
                    if(peak != " ")
                    {
                        for(int i = 0; i < peak.size(); i++)
                        {
                            fin.putback(peak.at((peak.size()-1)-i));
                        }
                    }
                    getline(fin,rest);
                    bdy += rest;
                    fin >> peak;
                    
                }
            }
            else
            {
                //peak checks next word check is <end>
                //use rest to get the line of txt then add it onto bdy
                bdy = ":body:";
                string rest;
                
                string peak = " ";
                while(peak != "<end>")
                {
                    if(peak != " ")
                    {
                        for(int i = 0; i < peak.size(); i++)
                        {
                            fin.putback(peak.at((peak.size()-1)-i));
                        }
                    }
                    getline(fin,rest);
                    bdy += rest;
                    fin >> peak;
                    
                }
                
            }
            Topic K(Art, sbjt, bdy, ID);
            if(WASCHILD == 1)
            {
                //1st check if child is in message list size if not create room for it
                for(int i = 0; i < children.size(); i++)
                {
                    if(children.at(i) > message_list.size())
                    {
                        while(message_list.size() < children.at(i))
                        {
                            Reply* J = new Reply;
                            message_list.push_back(J);
                        }
                    }
                }
                //
                
                //there was child so need to insert the children into vector 
                //children.at(i) = gives id of where child is
                //need to use id to find message of child
                //message_list.at() <- gives pointer to the plae where child is
                // use id from children.at() <- to get the pointer from message
                
                for(int i = 0; i < children.size(); i++)
                {
                    K.add_child(message_list.at(children.at(i)));
                }
                
            }
            //since the message list is filled alrdy gatta delete 
            delete message_list.at(K.get_id());
            message_list.at(K.get_id()) = &K;
        }
        if(Y == "<begin_reply>")
        {
            fin >> ID;
            //this includes the :type: part 
            getline(fin,sbjt);
            getline(fin,Art);
            fin >> child; 
            if(child == ":children:")
            {
                WASCHILD = 1;
                //ok so there are children
                // how do you look at how many children
                getline(fin,child);
                for(i = 0; i < child.size(); i++)
                {
                    int k;
                    if(isdigit(child.at(i)))
                    {
                        k = i;
                        while(isdigit(child.at(i)))
                        {
                            k = k*10 + child.at(i);
                            i++;
                        }
                        children.push_back(k);
                    }
                }
                //got child done now get body
                //peak checks next word check is <end>
                //use rest to get the line of txt then add it onto bdy
                string peak = " ";
                string rest;
                while(peak != "<end>")
                {
                    if(peak != " ")
                    {
                        for(int i = 0; i < peak.size(); i++)
                        {
                            fin.putback(peak.at((peak.size()-1)-i));
                        }
                    }
                    getline(fin,rest);
                    bdy += rest;
                    fin >> peak;
                    
                }
            }
            else
            {
                //peak checks next word check is <end>
                //use rest to get the line of txt then add it onto bdy
                bdy = ":body:";
                string rest;
                
                string peak = " ";
                while(peak != "<end>")
                {
                    if(peak != " ")
                    {
                        for(int i = 0; i < peak.size(); i++)
                        {
                            fin.putback(peak.at((peak.size()-1)-i));
                        }
                    }
                    getline(fin,rest);
                    bdy += rest;
                    fin >> peak;
                    
                }
                
            }
            Reply K(Art, sbjt, bdy, ID );
            if(WASCHILD == 1)
            {
                //1st check if child is in message list size if not create room for it
                for(int i = 0; i < children.size(); i++)
                {
                    if(children.at(i) > message_list.size())
                    {
                        while(message_list.size() < children.at(i))
                        {
                            Reply* J = new Reply;
                            message_list.push_back(J);
                        }
                    }
                }
                //there was child so need to insert the children into vector 
                //children.at(i) = gives id of where child is
                //need to use id to find message of child
                //message_list.at() <- gives pointer to the plae where child is
                // use id from children.at() <- to get the pointer from message
                
                for(int i = 0; i < children.size(); i++)
                {
                    K.add_child(message_list.at(children.at(i)));
                }
            }
            *message_list.at(K.get_id()) = K;
        }
        
    }
    
    fin.close();
    
    return true;
}

bool BBoard::save_messages(const string& datafile)
{
    ofstream fout;
    fout.open(datafile.c_str());
    if(!fout.is_open())
    {
        cout << "Error opening file";
        return false;
    }
    
    
    
    fout << message_list.size() << endl;
    for(unsigned i = 0; i < message_list.size(); i++)
    {
        //it says im accessing the unaccessable
        fout << message_list.at(i)->to_formatted_string();
    }
    fout.close();
    return true;
    
}


// still working on it
void BBoard::login()
{
    string uname;
    string pass;
    unsigned UNAMEPLACE;
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
                UNAMEPLACE = i;
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
    this->current_user = &user_list.at(UNAMEPLACE);
    
    cout << "Welcome back " << current_user->get_username() << "!" << endl;
    
}

void BBoard::run()
{
    int valid = 0;
    for(unsigned i = 0; i < user_list.size(); i++)
    {
        if(current_user->get_username() == user_list.at(i).get_username() )
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
            unsigned ID;
            
            cout << "Enter Subject: ";
            getline(cin, sbjct);
            
            cout << "Enter Body: ";
            getline(cin, bdy);
            
            ID = message_list.size() + 1;
            
            
            // create the message
            Topic A(current_user->get_username(), sbjct, bdy, ID);
            
            // adds message to list
            message_list.push_back(&A);
            
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
                    
                    if(!(message_list.at(i)->is_reply()))
                    {
                        cout << message_list.at(i)->to_formatted_string();
                    }
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