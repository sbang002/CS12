/// =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/IntVector. 
/// @brief Assignment/ for CS 12 Winter2015
///
/// @author Se Hoon Bang [sbang002@ucr.edu]
/// @date Feb 18 2015
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
class IntVector
{
    private:
    unsigned sz;
    unsigned cap;
    int*data;

    void expand();
    void expand(unsigned);
    
    public:
    IntVector();
    IntVector( unsigned size );
    IntVector( unsigned size, int value );
    unsigned size( ) const;
    unsigned capacity( ) const;
    bool empty( ) const;
    const int & at( unsigned index ) const;
    ~IntVector();
    int & at( unsigned index );
    void insert( unsigned index, int value );
    void erase( unsigned index );
    const int & front( ) const;
    int & front( );
    const int & back( ) const;
    int & back( );
    void assign( unsigned n, int value );
    void push_back( int value );
    void pop_back( );
    void clear( );
    void resize( unsigned size );
    void resize( unsigned size, int value );
    void reserve( unsigned n );


};