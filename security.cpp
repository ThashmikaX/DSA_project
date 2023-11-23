#include <iostream>
#include <fstream>
#include <sstream>
#include "API_v2.h"

using namespace std;

// Function to encrypt the data and save it to a CSV file
void PersonLinkedList::encryptAndSaveToCSV() {
    ofstream outputFile("D:/DSA_project/database/list2.csv");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    Person* current = head;
    while (current != nullptr) {
        // Encrypting sensitive information (you can use a more secure encryption algorithm)
        string encryptedFname = "";
        for (char c : current->fname) {
            encryptedFname += static_cast<char>(c + 1); // Simple encryption: shift each character by 1
        }
        string encryptedLname = "";
        for (char c : current->lname) {
            encryptedLname += static_cast<char>(c + 1);
        }

        // string encryptedId = "";
        // for (char c : current->age) {
        //     encryptedId += static_cast<char>(c + 1);
        // }
        
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

    cout << "Data encrypted and saved to " << "D:/DSA_project/database/list2.csv" << " successfully.\n";
}

// Function to decrypt the data and save it to a CSV file
void PersonLinkedList::decryptAndSaveToCSV() {
    ofstream outputFile("D:/DSA_project/database/list2.csv");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    Person* current = head;
    while (current != nullptr) {
        // Decrypting sensitive information (you can use a more secure decryption algorithm)
        string decryptedFname = "";
        for (char c : current->fname) {
            decryptedFname += static_cast<char>(c - 1); // Simple decryption: shift each character by 1
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

    cout << "Data decrypted and saved to " << "D:/DSA_project/database/list2.csv"  << " successfully.\n";
}

// int main()
// {
//     PersonLinkedList p1;
//     p1.encryptAndSaveToCSV(database_path);

// }