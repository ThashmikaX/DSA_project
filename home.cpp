#include "home.h"
#include "login.h"
#include "about.h"
#include "API_v2.h"
#include "class.h"
#include "colour.cpp"


#include <iostream>
#include <limits> 

using namespace std;

void home() {
    int x;
    do{
        cout <<"-----------------------------------------------------------------------------------------------------------------------\n";
        cout << "\033[1m" <<BLUE<< "-------------------------Welcome to Nexgen Finance-------------------------------------------------"<<RESET << "\033[0m" << endl;

        cout << "1. Registration\n";
        cout << "2. Log-in\n";
        cout << "3. About us \n";
        cout << "Enter your option number :";
        cin >> x;

        if(x==1)
        {
            cout<< "Registration\n";
            personList1.registrationProcess();
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
            cout<<RED<<"try again,input is not correct"<<RESET<<endl;
             
        }

    }while(x<4 || x>0);

}