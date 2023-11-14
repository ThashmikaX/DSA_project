#include <iostream>

using namespace std;

int main()
{
    int x;
    do{
        cout << "1. Registration\n ";
        cout << "2. Log-in\n";
        cout << "3. About us \n";
        cout << "Enter your option number :";
        cin >> x;

        if(x==1)
        {
            cout<< "Registration\n";
            break;

        }

    }while(x<4 || x>0);
}