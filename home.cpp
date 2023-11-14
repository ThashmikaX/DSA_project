#include "home.h"
#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

void home() {
    int x;
    do{
        cout << "1. Registration\n ";
        cout << "2. Log-in\n";
        cout << "3. About us \n";
        cout << "Enter your option number :";
        cin >> x;

        if(x==1)
        {
            cout<< "Registration\n";
            break;

        }
        else if(x==2){
            cout<< "Log-in\n";
            break;
        }
        else if(x==3){
            cout<<"about us \n";
            break;
        }
        else{
            cout<<"try again,input is not correct\n";
             
        }

    }while(x<4 || x>0);

}