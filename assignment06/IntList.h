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
struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntList
{
    private:
    IntNode* head;
    IntNode* tail;
    
    public:
    IntList();
    ~IntList();
    void display() const;
    void push_front( int value );
    void push_back( int value );
    void pop_front();
    void select_sort();
    void insert_sorted( int value );
    void remove_duplicates();

    
};
