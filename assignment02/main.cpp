#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    double top;
    double right;
    double bot;
    double left;
    double T;
    double Diff = 0;
    
    string x;
    ifstream fin;
    
    cout << "Enter input file: ";
    cin >> x;
    
    fin.open(x.c_str());
    
    if(!fin.is_open())
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    
    fin >> top;
    fin >> right;
    fin >> bot;
    fin >> left;
    fin >> T;
   

    cout << "Enter output file: ";
    cin >> x;
    
    ofstream fout;
    fout.open(x.c_str());
    if(!fout.is_open())
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    
    
    
    double K[6][8] = {0};
    //intialize top 
    for(int i = 0; i < 8; i++)
    {
        K[0][i] = top;
    }
    
    // intialize right
    for(int i = 1; i < 5 ; i++)
    {
        K[i][7] = right;
    }
    
    // intialize bot
    for (int i = 0; i < 8; i++)
    {
        K[5][i] = bot;
    }
    
    // intialize left
    for (int i = 1; i < 5; i++)
    {
        K[i][0] = left;
    }
    
    // the thing
    int l = 0;
    do
    {
        double x = 0;
        double y = 0;
        Diff = 0;
        for(int i = 1; i < 5; i++)
        {
            for(int j = 1; j < 7; j++)
            {
                y = K[i][j];
                
                //temp change
                x = (K[i][j+1] + K[i][j-1] + K[i+1][j] + K[i-1][j])/4;
                
                
                K[i][j] = x;
                //diff of temp from original
                y = abs(y - x);
                
                if(y > Diff)
                {
                    Diff = y;
                }
            } 
        }
        
        //cout << x << ' ';
    }while(Diff > T);
    // cout << endl;
    
    for(int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 7; j++)
        {
            //cout << K[i][j] << ' ';    
            fout << K[i][j] << "    ";
        }
        fout << endl;
        //cout << endl;
    }
    
    return 0;
}
