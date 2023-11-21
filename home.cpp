#include "home.h"
#include "API_v2.h"
#include "API_v2.cpp"
#include "login.cpp"
#include "about.cpp"

#include <iostream>
#include <limits> // for numeric_limits


void home() {
    int x;
    do{
        std::cout << "1. Registration\n";
        std::cout << "2. Log-in\n";
        std::cout << "3. About us \n";
        std::cout << "Enter your option number :";
        std::cin >> x;

        if(x==1)
        {
            std::cout<< "Registration\n";
            person2.registrationProcess();
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
            std::cout<<"try again,input is not correct\n";
             
        }

    }while(x<4 || x>0);

}

int main()
{
    perosn2.registrationProcess();
}