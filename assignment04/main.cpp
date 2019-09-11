#include "BBoard.h"
#include <string>
#include <iostream>


int main(int arc, char* argv[])
{
    string user_bb_title = "Jack";
    string File = argv[1];
    
    BBoard bb( user_bb_title );
    
    bb.setup(File);
    
    cout << user_bb_title << endl;
    bb.login();
    bb.run();
    
    return 0;
}