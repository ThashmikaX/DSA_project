#include "home.h"
#include "login.h" 
#include "login.cpp"
#include "about.h" 
#include "about.cpp"
#include "API.cpp"

#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

void home() {
    int x;
    do{
        cout << "1. Registration\n";
        cout << "2. Log-in\n";
        cout << "3. About us \n";
        cout << "Enter your option number :";
        cin >> x;

        if(x==1)
        {
            cout<< "Registration\n";
            registrationProcess();
            break;

        }
        else if(x==2){
            loginPage();
            break;
        }
        else if(x==3){
            aboutPage();
            break;
        }
        else{
            cout<<"try again,input is not correct\n";
             
        }

    }while(x<4 || x>0);

}