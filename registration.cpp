#include <iostream>
#include <string>
using namespace std;

class person {
private:
	string F_name;
	string L_name;
	string birth;
	string address;
	string id;
	string create_p;
	string confirm_p;

public:

	void insert() {
		cout << "***Welcome to the Banking App!***" << endl;
		cout << "please enter your details" << endl;
		cout << "First_Name : ";
		cin >> F_name;
		cout << "Last_Name : ";
		cin >> L_name;
		cout << " Birthdate (YYYY-MM-DD) : ";
		cin >> birth;
		cout << "NIC/Passport No : ";
		cin >> id;
		cout << "Address : ";
		cin >> address;
		cout << "Create your login password" << endl;
		cout << "Password : ";
		cin >> create_p;
		if (create_p.length() < 8) {
			cout << "Please enter a strong password" << endl;
		}
		cout << "Confirm your password" << endl;
		cin >> confirm_p;
		while (create_p == confirm_p) {
			cout << "Password does not match" << endl;
		}
		cout << "Signup successful! Thank you for joining the Banking App." << endl;
		


	}

	
};
int main() {
	person p1;
	p1.insert();
}