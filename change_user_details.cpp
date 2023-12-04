#include <iostream>
#include <stdexcept>
#include "class.h"
#include "colour.cpp"

void changePersonProperty() {
	
	int y;
	std::string property;
	std::string value;
	
	do {
		std::cout << "---------------------------------------------\n\n";
		std::cout << "What do you want to change\n";
		std::cout << "1. First_Name\n";
		std::cout << "2. Last_Name\n";
		std::cout << "3. Age\n";
		std::cout << "4. ID\n";
		std::cout << "5. Address\n";
		std::cout << "Enter your option number :";
		std::cin >> y;

		if (y == 1) {
			std::cout << "Enter new first name\n";
			std::cin >> value;
			property = "fname";
			personList1.changePersonProperties(property, value);
            break;
		}
		else if (y == 2) {
			std::cout << "Enter new last name\n";
			std::cin >> value;
			property = "lname";
			personList1.changePersonProperties(property, value);
            break;
		}
		else if (y == 3) {
			std::cout << "Enter new age\n";
			std::cin >> value;
			personList1.changePersonProperties("age", value);
            break;
		}
		else if (y == 4) {
			std::cout << "Enter new ID\n";
			std::cin >> value;
			property = "id";
			personList1.changePersonProperties(property, value);
            break;
		}
		else if (y == 5) {
			std::cout << "Enter new address\n";
			std::cin >> value;
			property = "address";
			personList1.changePersonProperties(property, value);
            break;
		}
		else {
			std::cout <<RED<< "try again,input is not correct"<<RESET<<std::endl;
		}
	} while (y < 5 && y>0);	
}