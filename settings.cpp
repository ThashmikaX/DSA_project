#include "delete_profile.h"
#include "settings.h"
#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

void settingsPage() {
    int x;
    do{
        cout << "1. Delete Profile\n";
        cout << "2. Change user detials\n";
        cout << "3. Change password \n";
        cout << "Enter your option number :";
        cin >> x;

        if(x==1)
        {
            deleteloginPage();
            break;

        }
        else if(x==2){
             
            break;
        }
        else if(x==3){
             
            break;
        }
        else{
            cout<<"try again,input is not correct\n";
             
        }

    }while(x<4 || x>0);

}