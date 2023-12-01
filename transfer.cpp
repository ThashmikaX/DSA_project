#include "transfer.h"
#include <iostream>
#include <limits> 
#include <string>
#include "API_v2.h"
#include "class.h"
#include "menu.h"
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
    if(1==personList1.updateBalance(x,amount)){
        cout << "Invalid Account number\n";
        y= true;

    }
    else if(2==personList1.updateBalance(x,amount)){
        cout << "invalid Account Number\n";
        y=true;

    }
    else {
        while(true){
        cout << "Enter Amount : ";
        cin >> amount;
        if(3==personList1.updateBalance(x,amount)){
            int z;
            cout<< "Account balance is less than zero\n";
            cout << "------------------------------------------------\n";
            while(true){
            cout << "\nDo you continue?\n";
            cout <<"1.Yes\n";
            cout <<"2.No\n";
            cout <<"Select your option: ";
            cin >>z;
            if(z<3 || z>0){
                if(z==1){
                    menu();

                }else{
                    
                }
            }
            }
            

        }
        else if (4==personList1.updateBalance(x,amount)){
            cout << "Succefully Transfer \n ";
            cout << "--------Thanks for using ---------\n";
            while(true){
            int z;
            cout << "\nDo you continue?\n";
            cout <<"1.Yes\n";
            cout <<"2.No\n";
            cout <<"Select your option: ";
            cin >>z;
            if(z<3 || z>0){
                if(z==1){
                    menu();

                }else{
                    break;
                    
                }
            }
            }
            
        }
    }
        
    }
    }
    
}