#include "home.h"
#include "login.h"
#include "API_v2.h"
#include "class.h"

#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for string

using namespace std;

void deleteloginPage() {
    loginPage(1);

    int x;

    do{

    cout << ",Are you Sure to Delete? \n";
    cout << "1. Yes \n";
    cout << "2. No \n";
    cout << "Enter your option; ";
    cin >> x;
    if(x==1){
        personList1.deletePerson();
        cout<<"Account deletion successful! Goodbye\n";
        break;
    }
    else if(x==2){
        cout<<"Thanks !\n";
        cout<<"__________________________________\n\n";
        home();
        break;
    }
    else{
        cout<<"try again,input is not correct\n";
    }

    }
    while(x<3 || x>0);
} 