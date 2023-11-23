#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "API_v2.h"
#include "login.h"
#include "registration.h"
#include "home.h"

std::string current_User = "", database_path = "D:/DSA_project/database/list2.csv";
PersonLinkedList::PersonLinkedList() : head(nullptr) {
    this->loadCsvData();
}

PersonLinkedList::~PersonLinkedList() {
        while (head != nullptr) {
            Person* temp = head;
            head = head->next;
            delete temp;
        }
    }

void PersonLinkedList::addPerson(const std::string& fname, const std::string& lname, int age,
                                const std::string& id, const std::string& address,
                                const std::string& accountnumber, const std::string& username,
                                const std::string& password, float person_amount_1) {
                        //float person_amount = 0.0;
        Person* newPerson = new Person{ fname, lname, age, id, address,  accountnumber, username, password, person_amount_1, nullptr };
        if (head == nullptr) {
            head = newPerson;
        } else {
            newPerson->next = head;
            head = newPerson;
        }
        std::cout << "Person added successfully.\n";
    }

void PersonLinkedList::registrationProcess()
    {
        std::string* ptr = registration();
        std::cout << typeid(ptr[2]).name();
        this->addPerson(ptr[0], ptr[1], stoi(ptr[2]), ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], 0.0);
        std::cout << "\n" << "Your Details " << "\n";
        std::cout << "First Name : " << ptr[0] << "\n";
        std::cout << "Last Name : " << ptr[1] << "\n";
        std::cout << "Age : " << ptr[2] << "\n";
        std::cout << "ID Number : " << ptr[3] << "\n";
        std::cout << "Address : " << ptr[4] << "\n";
        std::cout << "Account Number : " << ptr[5] << "\n";
        std::cout << "Username : " << ptr[6] << "\n" << "_________________________________" << "\n";
        std::cout << "Login your account from here\n";
        this->saveToCSV(database_path);
        loginPage(0);
    }

void PersonLinkedList::deletePerson() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->username == current_User) {
            Person* temp = head;
            if(head->next == NULL){head = NULL;}
            else{
                head = head->next;
            }
            
            delete temp;
            std::cout << "Person deleted successfully.\n";
            this->saveToCSV(database_path);
            return;
        }

        Person* current = head;
        while (current->next != nullptr && current->next->username != current_User) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cout << "Person not found.\n";
        } else {
            Person* temp = current->next;
            current->next = current->next->next;
            delete temp;
            std::cout << "Person deleted successfully.\n";
        }
        this->saveToCSV(database_path);
    }

void PersonLinkedList::changePersonProperties(const std::string& property, const std::string& value) {
        Person* current = head;
        while (current != nullptr && current->username != current_User) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Person not found.\n";
        } else {
            if (property == "fname") {
                current->fname = value;
            } else if (property == "lname") {
                current->lname = value;
            } else if (property == "age") {
                current->age = stoi(value);
            } else if (property == "id") {
                current->id = value;
            } else if (property == "address") {
                current->address = value;
            } else if (property == "accountnumber") {
                current->accountnumber = value;
            } else if (property == "password") {
                current->password = value;
            } else {
                std::cout << "Invalid property.\n";
                return;
            }

            std::cout << "Person properties changed successfully.\n";
        }
    }

void PersonLinkedList::showAccountBalance() {
        Person* current = head;
        while (current != nullptr && current->username != current_User) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Person not found.\n";
        } else {
            std::cout << "\nAccount balance is : Rs." << current->amount << "\n";
        }
    }

void PersonLinkedList::saveToCSV(const std::string& filename) {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        Person* current = head;
        while (current != nullptr) {
            outputFile << current->fname << "," << current->lname << ","
                       << current->age << "," << current->id << ","
                       << current->address << "," << current->accountnumber << ","
                       << current->username << "," << current->password << "," << std::to_string(current->amount) << "," << "\n";
            current = current->next;
        }

        std::cout << "Data saved to " << filename << " successfully.\n";
    }

bool PersonLinkedList::findUsername(const std::string& username){
    Person* current = head;
    while (current != nullptr) {
        if (current->username == username) {
            return true; // Username found
        }
        current = current->next;
    }
    return false;
}

bool PersonLinkedList::verifyPassword(std::string password, std::string username){
    Person* current = head;
    while (current != nullptr) {
        if (current->username == username && current->password == password) {
            current_User = username;
            return true; // Username and password match found
        }
        current = current->next;
    }
    return false; // Username and password match not found
}

void PersonLinkedList::loadCsvData()
{
    // Read data from CSV file
    std::ifstream inputFile("D:/DSA_project/database/list2.csv");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file.\n";
    }

    std::string line;
    while (getline(inputFile, line)) {
         std::stringstream ss(line);
        std::string fname, lname, id, address, username, accountnumber, password;
        int age;
        float amount_1;

        getline(ss, fname, ',');
        getline(ss, lname, ',');
        ss >> age;
        ss.ignore(); // Ignore the comma
        getline(ss, id, ',');
        getline(ss, address, ',');
        getline(ss, username, ',');
        getline(ss, accountnumber, ',');
        getline(ss, password, ',');
        ss >> amount_1;
        ss.ignore(); // Ignore the comma

        // Add person to the linked list
        this->addPerson(fname, lname, age, id, address, username, accountnumber, password, amount_1);
    }
}

int PersonLinkedList::updateBalance(const std::string toAccountNum, float balance)
{
    Person* current = head;
    if (current == nullptr) return false;
    while(current != nullptr)
    {
        if(current->accountnumber == toAccountNum)
        {
            current->amount += balance;
            current = head;
            while(current != nullptr)
            {
                if(current->username == current_User)
                {
                    current->amount -= balance;
                    this->saveToCSV(database_path);
                    return true;
                }
                current = current->next;
            }
        }
        current = current->next;
    }
    return false;
}

//  int main() {
//     PersonLinkedList p1;
//     p1.addPerson("sp","ss",10,"ss","ss","acc2", "username2", "password2", 500.0);
//     //std::cout << p1.updateBalance("5800", 5000.0);
//     p1.saveToCSV(database_path);
//  }