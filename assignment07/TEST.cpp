#include "Reply.h"
#include <sstream>



int main()
{
    string K = "HI ";
    unsigned J = 1;
    string T;
    stringstream ss;
    ss << J;
    ss >> T;
    K += T;
   
    cout << K << endl;
    string a,b,c;
    int d;
    cin >> a >> b >> c >> d;
    Reply M(a,b,c,d);
    // Reply Y(a,b,c,d+3);
    // Reply X(a,b,c,d+8);
    // M.add_child(Y);
    // M.add_child(X);
    cout << M.to_formatted_string();
    return 0;
}