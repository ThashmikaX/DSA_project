#include <iostream>
#include "menu.h"
#include "settings.cpp"
#include "API.cpp"


using namespace std;

void menu() {
    int y;
    do {
        cout << "1. Account balance\n";
        cout << "2. Transfer\n";
        cout << "3. settings \n";

        cout << "Enter your option number :";
        cin >> y;

        if (y == 1)
        {
            cout << "Your Account balance is : " << showBalance("user1");
            menu();
            break;

        }
        else if (y == 2) {
            cout << "Transfer\n";
            break;
        }
        else if (y == 3) {
            settingsPage();
            break;
        }
      

    } while (y < 3 || y >0);
}