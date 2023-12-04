#include "delete_profile.h"
#include "change_user_details.h"
#include "settings.h"
#include <iostream>
#include <limits> 
#include "colour.cpp"
#include "change_user_details.h"
#include "change_password.h"

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
            changePersonProperty();
            break;
        }
        else if(x==3){
            changePasswordd();
            break;
        }
        else{
            cout<<RED<<"try again,input is not correct"<<RESET<<endl;
             
        }

    }while(x<4 || x>0);

}