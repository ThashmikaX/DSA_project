#include "API.cpp"
#include "login.h" 
#include "menu.cpp"
#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for string

using namespace std;



void loginPage() {
     string username, password;

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

        if (verifyPassword(password, username)) {
            validPassword = true;
        } else {
            cout << "Incorrect password. Please try again.\n";
            // cout << "Your password is already used by Piwpiw98.\n";
        }
    }

    cout << "Login successful! Welcome, " << username << "!\n";
}
