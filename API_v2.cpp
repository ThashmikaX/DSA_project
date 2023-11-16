#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "login.cpp"

std::string current_User = getCurrentUser();

// Node structure representing a person
struct Person {
    std::string fname;
    std::string lname;
    int age;
    std::string id;
    std::string address;
    std::string username;
    std::string accountnumber;
    std::string password;
    Person* next;
};

// Linked list class
class PersonLinkedList {
private:
    Person* head;

public:
    // Constructor
    PersonLinkedList() : head(nullptr) {}

    // Destructor to free memory when the program ends
    ~PersonLinkedList() {
        while (head != nullptr) {
            Person* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to add a new person to the list
    void addPerson(const std::string& fname, const std::string& lname, int age,
                    const std::string& id, const std::string& address, const std::string& username,
                    const std::string& accountnumber, const std::string& password) {
        Person* newPerson = new Person{ fname, lname, age, id, address, username, accountnumber, password, nullptr };
        if (head == nullptr) {
            head = newPerson;
        } else {
            newPerson->next = head;
            head = newPerson;
        }
        cout << "Person added successfully.\n";
    }

    // Function to delete a person from the list
    void deletePerson() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->username == current_User) {
            Person* temp = head;
            head = head->next;
            delete temp;
            cout << "Person deleted successfully.\n";
            return;
        }

        Person* current = head;
        while (current->next != nullptr && current->next->username != current_User) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Person not found.\n";
        } else {
            Person* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Person deleted successfully.\n";
        }
    }

    // Function to change person properties
    void changePersonProperties(const std::string& property, const std::string& value) {
        Person* current = head;
        while (current != nullptr && current->username != current_User) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Person not found.\n";
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
                cout << "Invalid property.\n";
                return;
            }

            cout << "Person properties changed successfully.\n";
        }
    }

    // Function to display person properties
    void showPersonProperties() {
        Person* current = head;
        while (current != nullptr && current->username != current_User) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Person not found.\n";
        } else {
            cout << "Username: " << current->username << "\n";
            cout << "First Name: " << current->fname << "\n";
            cout << "Last Name: " << current->lname << "\n";
            cout << "Age: " << current->age << "\n";
            cout << "ID: " << current->id << "\n";
            cout << "Address: " << current->address << "\n";
            cout << "Account Number: " << current->accountnumber << "\n";
            cout << "Password: " << current->password << "\n";
        }
    }

    // Function to save the updated data to a CSV file
    void saveToCSV(const std::string& filename) {
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cerr << "Error opening file for writing.\n";
            return;
        }

        Person* current = head;
        while (current != nullptr) {
            outputFile << current->fname << "," << current->lname << ","
                       << current->age << "," << current->id << ","
                       << current->address << "," << current->username << ","
                       << current->accountnumber << "," << current->password << "\n";
            current = current->next;
        }

        cout << "Data saved to " << filename << " successfully.\n";
    }
};

int main() {
    // Create a linked list to store persons
    PersonLinkedList personList;

    // Read data from CSV file
    ifstream inputFile("data.csv");
    if (!inputFile.is_open()) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string fname, lname, id, address, username, accountnumber, password;
        int age;

        getline(ss, fname, ',');
        getline(ss, lname, ',');
        ss >> age;
        ss.ignore(); // Ignore the comma
        getline(ss, id, ',');
        getline(ss, address, ',');
        getline(ss, username, ',');
        getline(ss, accountnumber, ',');
        getline(ss, password, ',');

        // Add person to the linked list
        personList.addPerson(fname, lname, age, id, address, username, accountnumber, password);
    }

    // Example usage of functions
    //personList.showPersonProperties(); // Display properties of person with username "JohnDoe"
    //personList.deletePerson(); // Delete person with username "AliceSmith"

    // // Add a new person
    //personList.addPerson("Bob", "Johnson", 25, "B123456", "123 Main St", "Bob123", "789012345", "password123");

    // // Change properties of a person
    personList.changePersonProperties("age", "30");
    personList.changePersonProperties("address", "456 Oak St");

    // // Save updated data to CSV file
    personList.saveToCSV("data.csv");

    return 0;
}