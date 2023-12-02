#include "home.h"
#include "login.h"
#include "API_v2.h"
#include "class.h"
#include "colour.cpp"

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
        cout<<GREEN<<"Account deletion successful! Goodbye"<<RESET<<endl;
        break;
    }
    else if(x==2){
        cout<<"Thanks !\n";
        cout<<"__________________________________\n\n";
        home();
        break;
    }
    else{
        cout<<RED<<"try again,input is not correct"<<RESET<<endl;
    }

    }
    while(x<3 || x>0);
} 