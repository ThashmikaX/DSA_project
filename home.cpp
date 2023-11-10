#include "home.h"
#include<iostream>

using namespace std;

void home()
{
    
    int x;
    cout << "1 Registration" << endl;
    cout << "2 Log-in" << endl;
    cout << "3 About us" << endl;
    cout<<"Select the option number : ";
    cin >>x;
    while (x>0 || x<4)
    {
        
        if(x==1){
            cout << "Registration" << endl;
            break;

        }
        else if(x==2){
            cout << "Log-in"<< endl;
            break;

        }
        else if(x==3){
            cout<< " about us " <<endl;
            break;

        }

    
    }

    
  
    

}