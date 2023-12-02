#include <iostream>
#include "class.h"
void changePasswordd() {

	std::string value;
	
	std::cout << "Enter new password\n";
	    std::cin >> value;
		personList1.changePersonProperties("password", value);
			
}