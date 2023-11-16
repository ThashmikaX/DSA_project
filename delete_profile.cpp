#include "delete_profile.h" 
#include "API.cpp"
#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for string

using namespace std;

void deleteloginPage() {
     string username, password;
     int x;

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
        }
    }
    do{

    cout << username << ",Are you Sure to Delete? \n";
    cout << "1. Yes \n";
    cout << "2. No \n";
    cin >> x;
    }while(x<3 || x>0);
    cout << "Successfully Delete, Thanks" <<username<< "\n";


    

}