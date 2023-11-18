#include "home.h"
#include "login.h"
#include "about.h"
#include "API.h"

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
            loginPage(0);
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