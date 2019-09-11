/// =============== BEGIN ASSESSMENT HEADER ================
/// @file lab08/IntList. 
/// @brief Assignment/ for CS 12 Winter2015
///
/// @author Se Hoon Bang [sbang002@ucr.edu]
/// @date Feb 25 2015
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
#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
}

IntList::~IntList()
{
    while(head != 0)
    {
        pop_front();
    }
}

void IntList::display() const
{
    for(IntNode * temp = head; temp != 0; temp = temp->next)
    {
        cout << temp->data;
        if(temp -> next != 0)
        { cout << " ";}
    }
}
void IntList::push_front( int value )
{
    IntNode* temp = new IntNode(value);
    temp -> next = head;
    head = temp;
    if(tail == 0)
    {
        tail = head;
    }
}

void IntList::push_back( int value )
{
    IntNode* temp = new IntNode(value);
    if(tail == 0)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        if(head == 0)
        {
            head = tail;
        }
    }
}

void IntList::pop_front()
{
    if(head == 0)
    {
        return;
    }
    IntNode* temp = head;
    head = head -> next;
    delete temp;
    if(head == 0)
    {
        tail = 0;
    }
}

void IntList::select_sort()
{
    IntNode* temp = head;
    
    for(temp = head; temp != tail; temp = temp->next)
    {
        IntNode* place = temp;
        IntNode* Min = temp;
        int I = temp -> data;
        while(Min != 0)
        {
            if(I > Min->data)
            {
                place = Min;
                I = Min->data;
            }
            Min = Min->next;
        }
        place->data = temp->data;
        temp->data = I;
        
        
    }
    
}

void IntList::insert_sorted( int value )
{
    IntNode* New = new IntNode(value);
    IntNode* temp = head;
    int Q = 0;
    //if empty set
    if(head == 0)
    {
        head = New;
        tail = New;
    }
    // if size 1
    else if(head == tail)
    {
        if(head->data < value)
        {
            head->next = New;
            tail = New;
        }
        else
        {
            New->next = tail;
            head = New;
        }
    }
    //if it is last number than
    else if(tail->data <= value)
    {
        tail->next = New;
        tail = New;
    }
    //works if not last number
    else if(value <= head->data)
    {
        New->next = head;
        head = New;
    }
    else 
    {
        for(int I = value; Q != 1; temp = temp->next)
        {
            
            if((I >= (temp->data)) && (I <= ((temp->next)->data)))
            {
                New ->next = temp ->next;
                temp->next = New;
                Q = 1;
            }
        }
    }
}

void IntList::remove_duplicates()
{
    
    
    for(IntNode* Counter = head; Counter != 0; Counter = Counter -> next)
    {
        int NUMBER = Counter -> data;    
        IntNode* temp = Counter -> next;

        
        while(temp != 0)
        {
            if(temp -> data == NUMBER)
            {
                IntNode* temp2 = Counter;
                if(temp == tail)
                {
                    while(temp2->next != tail)
                    {
                        temp2 = temp2 -> next;
                    }
                    delete tail;
                    tail = temp2;
                    tail->next = 0;
                }
                else
                {
                    while(temp2->next != temp)
                    {
                        temp2 = temp2 -> next;
                    }
                    temp2 ->next = temp -> next;
                    temp2 = temp;
                    
                    temp = temp->next;
                    delete temp2;
                }
            }
            else
            {
                temp = temp -> next;
            }
        }
    }
}