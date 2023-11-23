#include "transfer.h"
#include <iostream>
#include <limits> 
#include <string>
#include "API_v2.h"
#include "class.h"
using namespace std;

void transferPage(){
    bool y = true;
    while(y){
    float amount;
    string x;
    cout << "------Enter Acount Number-------\n";
    cout <<"To : ";
    cin >> x;
    amount =0.0;
    if(!personList1.updateBalance(x,amount)){
        cout << "Invalid Account number\n";
        y= true;

    }
    else{
        cout << "Enter Amount : ";
        cin >> amount;
        personList1.updateBalance(x,amount);
        cout << "Succefully Transfer\n";
        cout << "-----Thanks for using !--------\n";
        y=false;
    }
    }

   
   
    


    cout<<"Account Balance is 10000$";
}