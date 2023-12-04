#include "API_v2.h"
#include "login.h" 
#include "menu.h"
#include "home.h"
#include "class.h"
#include "colour.cpp"

#include <iostream>
#include <limits> 
#include <string> 

PersonLinkedList personList1;


void loginPage(int y) {
    std::string username, password;

    bool validUsername = false;
    bool validPassword = false;

    while (!validUsername) {
        std::cout << "Enter your username: ";
        std::cin >> username;

        if (personList1.findUsername(username)) {
            validUsername = true;
        } else {
            std::cout <<RED<< "Username not found. Please try again."<<RESET<<std::endl;
        }
    }

    while (!validPassword) {
        std::cout << "Enter your password: ";
        std::cin >> password;

        if (y == 0 && personList1.verifyPassword(password, username)) {
            validPassword = true;
        } else if (y == 1 && personList1.verifyPassword(password,username)) {
            validPassword = true;
        } else {
            if (y == 0) {
                std::cout <<RED<< "Incorrect password. Please try again."<<RESET<<std::endl;
            } 
            else if (y == 1) {
                std::cout <<RED<< "Invalid password. Account deletion failed."<<RESET<<std::endl;
            }
        }
    }


    if (y == 0) {
        std::cout <<GREEN<< "Login successful! Welcome, " << username <<RESET<<std::endl;
        menu();
    } else if (y == 1) {
        std::cout << "_______________________________\n";
        
    }
}


