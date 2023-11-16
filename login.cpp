#include "API.cpp"
#include "login.h" 
#include "menu.cpp"
#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for string

using namespace std;

// Generalized login function
void loginPage(int y) {
    string username, password;

string currentUser = "Bob123";


    bool validUsername = false;
    bool validPassword = false;

    while (!validUsername) {
        cout << "Enter your username: ";
        cin >> username;

        if (findUsername(username)) {
            validUsername = true;
        } else {
            cout << "Username not found. Please try again.\n";
        }
    }

    while (!validPassword) {
        cout << "Enter your password: ";
        cin >> password;

        if (y == 0 && verifyPassword(password, username)) {
            validPassword = true;
        } else if (y == 1 && verifyPassword(password,username)) {
            validPassword = true;
        } else {
            if (y == 0) {
                cout << "Incorrect password. Please try again.\n";
            } 
            else if (y == 1) {
                cout << "Invalid password. Account deletion failed.\n";
            }
        }
    }


    if (y == 0) {
        cout << "Login successful! Welcome, " << username << "!\n";
        menu();
    } else if (y == 1) {
        cout << "_______________________________\n";
        // Additional logic if needed after account deletion
    }
}
