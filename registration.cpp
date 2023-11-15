#include <iostream>
#include <string>
#include "registration.h"



std::string * registration()
{
    std::string * person = new std::string[7];
    std::string confirm_p;

    std::cout << "***Welcome to the Banking App!***" << std::endl;
    std::cout << "please enter your details" << std::endl;
        std::cout << "First_Name : ";
        std::cin >> person[0];
        std::cout << "Last_Name : ";
        std::cin >> person[1];
        std::cout << "Birthdate (YYYY-MM-DD) : ";
        std::cin >> person[2];
        std::cout << "NIC/Passport No : ";
        std::cin >> person[3];
        std::cout << "Address : ";
        std::cin >> person[4];
        std::cout << "Username : ";
        std::cin >> person[5];
        std::cout << "Create your login password" << std::endl;
        std::cout << "Password : ";
        std::cin >> person[6];
        while (person[6].length() < 8) {
            std::cout << "Please enter a strong password (at least 8 characters)" << std::endl;
            std::cout << "Password : ";
            std::cin >> person[6];
        }

        std::cout << "Confirm your password" << std::endl;
        std::cin >> confirm_p;
        while (person[6] != confirm_p) {
            std::cout << "Password does not match. Please try again." << std::endl;
            std::cout << "Confirm your password" << std::endl;
            std::cin >> confirm_p;
        }

        std::cout << "\n" << "Signup successful! Thank you for joining the Banking App." << std::endl;

    return person;
}
