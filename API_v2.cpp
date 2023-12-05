#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "API_v2.h"
#include "login.h"
#include "registration.h"
#include "home.h"
#include "colour.cpp"

#define MINIMUM_AMOUNT 100.0
bool securityStatus = 1;

std::string current_User = "", database_path = "D:/DSA_project/database/list2.csv";
PersonLinkedList::PersonLinkedList() : head(nullptr) {
    this->loadCsvData();
    if(securityStatus == 1)
    {
        this->decryptAndSaveToCSV();
        this->~PersonLinkedList();
        this->loadCsvData();
        securityStatus = 0;
    }

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
                        
        Person* newPerson = new Person{ fname, lname, age, id, address,  accountnumber, username, password, person_amount_1, nullptr };
        if (head == nullptr) {
            head = newPerson;
        } else {
            newPerson->next = head;
            head = newPerson;
        }
        
    }

void PersonLinkedList::registrationProcess()
    {
        std::string* ptr = registration();  
        this->addPerson(ptr[0], ptr[1], stoi(ptr[2]), ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], 5000.0);

        
        std::cout << "\n" << "\nYour Details " << "\n";
        std::cout << "First Name : " << ptr[0] << "\n";
        std::cout << "Last Name : " << ptr[1] << "\n";
        std::cout << "Age : " << ptr[2] << "\n";
        std::cout << "ID Number : " << ptr[3] << "\n";
        std::cout << "Address : " << ptr[4] << "\n";
        std::cout << "Account Number : " << ptr[5] << "\n";
        std::cout << "Username : " << ptr[6] << "\n" << "_________________________________" << "\n";
        std::cout << "Login your account from here\n";
        this->saveToCSV(database_path);
        this->~PersonLinkedList();
        this->loadCsvData();
        this->encryptAndSaveToCSV();
        loginPage(0);
    }

void PersonLinkedList::deletePerson() {
        if (head == nullptr) {
            std::cout <<RED<< "List is empty. Cannot delete."<<RESET<<std::endl;
            return;
        }

        if (head->username == current_User) {
            Person* temp = head;
            if(head->next == NULL){head = NULL;}
            else{
                head = head->next;
            }
            
            delete temp;
            std::cout <<GREEN<< "Person deleted successfully."<<RESET<<std::endl;
            this->saveToCSV(database_path);
            this->~PersonLinkedList();
            this->loadCsvData();
            this->encryptAndSaveToCSV();
            return;
        }

        Person* current = head;
        while (current->next != nullptr && current->next->username != current_User) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cout <<RED<< "Person not found."<<RESET<<std::endl;
        } else {
            Person* temp = current->next;
            current->next = current->next->next;
            delete temp;
            std::cout <<RED<< "Person deleted successfully."<<RESET<<std::endl;
        }
        this->saveToCSV(database_path);
        this->~PersonLinkedList();
        this->loadCsvData();
        this->encryptAndSaveToCSV();
    }

void PersonLinkedList::changePersonProperties(const std::string& property, const std::string& value) {
        Person* current = head;
        while (current != nullptr && current->username != current_User) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout <<RED<< "Person not found."<<RESET<<std::endl;
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
                std::cout <<RED<< "Invalid property."<<RESET<<std::endl;
                return;
            }
            std::cout <<GREEN<< "Person properties changed successfully."<<RESET<<std::endl;
            this->saveToCSV(database_path);
            this->~PersonLinkedList();
            this->loadCsvData();
            this->encryptAndSaveToCSV();
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
            std::cout << "\nAccount balance is : Rs." <<GREEN<< current->amount << RESET<<std::endl;
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

       
    }

bool PersonLinkedList::findUsername(const std::string& username){
    Person* current = head;
    while (current != nullptr) {
        if (current->username == username) {
            return true; 
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
            return true; 
        }
        current = current->next;
    }
    return false; 
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
        ss.ignore(); 
        getline(ss, id, ',');
        getline(ss, address, ',');
        getline(ss, username, ',');
        getline(ss, accountnumber, ',');
        getline(ss, password, ',');
        ss >> amount_1;
        ss.ignore(); 
        
        this->addPerson(fname, lname, age, id, address, username, accountnumber, password, amount_1);
    }
}

int PersonLinkedList::updateBalance(const std::string toAccountNum, float balance)
{
    Person* current = head;
    if (current == nullptr) return 2;
    std::string acc;

    if(balance == 0.0)
    {
        //looping for find if user entered their own account number. if return 1.
        while (current != nullptr) {
        if (current->username == current_User) {
            acc = current->accountnumber;
        }
        current = current->next;
        }
        if(acc == toAccountNum){
        return 1;
        }

        //looping for find if user entered acc number is in our database. if not return 2.
        current = head;
        int result = 0;
        while(current != nullptr) {
        if (current->accountnumber == toAccountNum) {
            result = 1;
        }
        current = current->next;
        }
        if(result == 0){return 2;}

    }

    current = head;
    while(current != nullptr)
    {  
        if(current->accountnumber == toAccountNum)
        {
            current->amount += balance;
            Person* current1 = head;
            while(current1 != nullptr)
            {
                if(current1->username == current_User)
                {
                    current1->amount -= balance;
                    
                    if(current1->amount < MINIMUM_AMOUNT)
                    {
                        current1->amount += balance;
                        current->amount -= balance;
                        return 3;
                    }
                    if(balance != 0.0)
                    {
                        this->saveToCSV(database_path);
                        this->~PersonLinkedList();
                        this->loadCsvData();
                        this->encryptAndSaveToCSV();
                        return 4;   
                    }
                }
                current1 = current1->next;
            }
        }
        current = current->next;
    }
    return -1;
    
}

