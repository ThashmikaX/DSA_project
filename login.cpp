#include "API_v2.h"
#include "login.h" 
#include "menu.h"
#include "home.h"
#include "class.h"

#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for std::string

PersonLinkedList personList1;

// Generalized login function
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
            std::cout << "Username not found. Please try again.\n";
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
                std::cout << "Incorrect password. Please try again.\n";
            } 
            else if (y == 1) {
                std::cout << "Invalid password. Account deletion failed.\n";
            }
        }
    }


    if (y == 0) {
        std::cout << "Login successful! Welcome, " << username << "!\n";
        menu();
    } else if (y == 1) {
        std::cout << "_______________________________\n";
        // Additional logic if needed after account deletion
    }
}


// int main()
// {
//     //cout << getCurrentUser();
//     //loginPage(0);
//     cout << "test";
// }