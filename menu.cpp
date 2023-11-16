#include <iostream>
#include "account_balance.cpp"
#include "menu.h"
#include "transfer.cpp"
#include "settings.cpp"
#include "API.cpp"


using namespace std;

void menu() {
    int y;
    do {
        cout<< "---------------------------------------------\n\n";
        cout << "1. Account balance\n";
        cout << "2. Transfer\n";
        cout << "3. settings \n";

        cout << "Enter your option number :";
        cin >> y;

        if (y == 1)
        {

            accountbalancePage();

            break;

        }
        else if (y == 2) {

        
            break;
        }
        else if (y == 3) {
            settingsPage();
            break;
        }else{
            cout<< "try again,input is not correct\n";

        }
      

    } while (y < 3 || y >0);
}