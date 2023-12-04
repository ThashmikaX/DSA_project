#include <iostream>
#include "account_balance.h"
#include "menu.h"
#include "transfer.h"
#include "settings.h"
#include "colour.cpp"


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
            transferPage();
        
            break;
        }
        else if (y == 3) {
            settingsPage();
            break;
        }else{
            cout<<RED<<"try again,input is not correct"<<RESET<<endl;

        }
      

    } while (y < 3 || y >0);
}