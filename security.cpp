#include <iostream>
#include <fstream>
#include <sstream>
#include "API_v2.h"
#include "colour.cpp"

using namespace std;


void PersonLinkedList::encryptAndSaveToCSV() {
    ofstream outputFile("D:/DSA_project/database/list2.csv");
    if (!outputFile.is_open()) {
        cerr <<RED<< "Error opening file for writing."<<RESET<<endl;
        return;
    }

    Person* current = head;
    while (current != nullptr) {
        
        string encryptedFname = "";
        for (char c : current->fname) {
            encryptedFname += static_cast<char>(c + 1); 
        }
        string encryptedLname = "";
        for (char c : current->lname) {
            encryptedLname += static_cast<char>(c + 1);
        }

      
        
        string encryptedId = "";
        for (char c : current->id) {
            encryptedId += static_cast<char>(c + 1);
        }
        string encryptedAddress = "";
        for (char c : current->address) {
            encryptedAddress += static_cast<char>(c + 1);
        }
        string encryptedAccountnumber = "";
        for (char c : current->accountnumber) {
            encryptedAccountnumber += static_cast<char>(c + 1);
        }
        string encryptedUsername = "";
        for (char c : current->username) {
            encryptedUsername += static_cast<char>(c + 1);
        }
        string encryptedPassword = "";
        for (char c : current->password) {
            encryptedPassword += static_cast<char>(c + 1);
        }

        // Save encrypted data to CSV
        outputFile << encryptedFname << "," << encryptedLname << ","
                   << current->age << "," << encryptedId << ","
                   << encryptedAddress << "," << encryptedAccountnumber<< ","
                   << encryptedUsername << "," << encryptedPassword << "," << current->amount << "\n";

        current = current->next;
    }

    
}


void PersonLinkedList::decryptAndSaveToCSV() {
    ofstream outputFile("D:/DSA_project/database/list2.csv");
    if (!outputFile.is_open()) {
        cerr <<RED<< "Error opening file for writing."<<RESET<<endl;
        return;
    }

    Person* current = head;
    while (current != nullptr) {
        
        string decryptedFname = "";
        for (char c : current->fname) {
            decryptedFname += static_cast<char>(c - 1); 
        }

        string decryptedLname = "";
        for (char c : current->lname) {
            decryptedLname += static_cast<char>(c - 1);
        }

        string decryptedId = "";
        for (char c : current->id) {
            decryptedId += static_cast<char>(c - 1);
        }

        string decryptedAddress = "";
        for (char c : current->address) {
            decryptedAddress += static_cast<char>(c - 1);
        }
        string decryptedAccountnumber = "";
        for (char c : current->accountnumber) {
            decryptedAccountnumber += static_cast<char>(c - 1);
        }
        string decryptedUsername = "";
        for (char c : current->username) {
            decryptedUsername += static_cast<char>(c - 1);
        }
        string decryptedPassword = "";
        for (char c : current->password) {
            decryptedPassword += static_cast<char>(c - 1);
        }

        // Save decrypted data to CSV
        outputFile << decryptedFname << "," << decryptedLname << ","
                   << current->age << "," << decryptedId << ","
                   << decryptedAddress << "," << decryptedAccountnumber << ","
                   << decryptedUsername << "," << decryptedPassword << "," << current->amount << "\n";

        current = current->next;
    }

    
}

