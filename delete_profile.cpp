#include "delete_profile.h" 
#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for string

using namespace std;

bool authenticateUser(const string& username, const string& password) {
    // Replace this with your authentication logic
    return (username == "example" && password == "password");
}

void deleteprofilePage() {
    string username, password;
    bool loggedIn = false;

    do {
        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        if (authenticateUser(username, password)) {
            cout << "Successfully delete \n";
            loggedIn = true;
            // Add logic for successful login
        } else {
            cout << "Invalid username or password. Please try again.\n";
            // Add logic for unsuccessful login
        }
    } while (!loggedIn);
}