#include <iostream>
#include <string>
#include "registration.h"

std::string * registration()
{
    std::string * person = new std::string[8];
    std::string confirm_p;
    int age;

    std::cout << "**Welcome to the Banking App!**" << std::endl;
    std::cout << "please enter your details" << std::endl;
        std::cout << "First_Name : ";
        std::cin >> person[0];
        std::cout << "Last_Name : ";
        std::cin >> person[1];
        int integerValue;
        while (true) {
        // Prompt the user for input
        std::cout << "Age: ";
        std::getline(std::cin, person[2]);
        // Attempt to convert the input to an integer
        try {
            integerValue = std::stoi(person[2]);
            break;  // If successful, exit the loop
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Input out of range. Please enter a smaller integer." << std::endl;
            }
        }
        std::cout << "NIC/Passport No : ";
        std::cin >> person[3];
        std::cout << "Address : ";
        std::cin >> person[4];
        std::cout << "Account number : ";
        std::cin >> person[5];
        std::cout << "Username : ";
        std::cin >> person[6];
    do {
        std::cout << "Create your login password (at least 8 characters, no commas): ";
        std::cin >> person[7];

     
        if (person[7].length() < 8) {
            std::cout << "Please enter a strong password (at least 8 characters)" << std::endl;
            continue;
        }

       
        if (person[7].find(',') != std::string::npos) {
            std::cout << "Please enter valid characters." << std::endl;
            continue;
        }
        break; 
    } while (true);

   
    do {
        std::cout << "Confirm your password: ";
        std::cin >> confirm_p;

        if (person[7] != confirm_p) {
            std::cout << "Password does not match. Please try again." << std::endl;
        }

    } while (person[7] != confirm_p);

        std::cout << "\n" << "Signup successful! Thank you for joining the Banking App." << std::endl;

    return person;
}