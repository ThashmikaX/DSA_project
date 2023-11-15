#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "registration.cpp"
#include "API.h"

using namespace std;
string filename = "database.csv";


struct CsvRow {
    string F_name, L_name, birth, address, id, username, password;
};

vector<CsvRow> readCsv(const string& filename) {
    vector<CsvRow> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        CsvRow row;

        // Split the line into columns based on commas
        getline(iss, row.F_name, ',');
        getline(iss, row.L_name, ',');
        getline(iss, row.birth, ',');
        getline(iss, row.address, ',');
        getline(iss, row.id, ',');
        getline(iss, row.username, ',');
        getline(iss, row.password);


        data.push_back(row);
    }

    file.close();
    return data;
}

void appendData(const string& filename, const CsvRow& newRow) {
    ofstream file(filename, ios::app); // Open the file in append mode

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Append the new data line with comma separation
    file << newRow.F_name << "," << newRow.L_name << "," << newRow.birth << "," << newRow.address << "," << newRow.id << "," << newRow.username << "," << newRow.password << "\n";

    file.close();
}

void registrationProcess()
{
    string* ptr = registration();
    CsvRow newData = {ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6]};
    // appendData(filename, newData);
    appendData(filename, newData);

}

bool findUsername(string username)
{
    vector<CsvRow> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        CsvRow row;

        // Split the line into columns based on commas
        // Split the line into columns based on commas
        getline(iss, row.F_name, ',');
        getline(iss, row.L_name, ',');
        getline(iss, row.birth, ',');
        getline(iss, row.address, ',');
        getline(iss, row.id, ',');
        getline(iss, row.username, ',');
        getline(iss, row.password);

        //cout << " test1 " << row.username << row.password;

        if(username == row.username)
        {
            return true;
        }
        else{
            return false;
        }

        data.push_back(row);
    }

    file.close();
}

bool verifyPassword(string password, string username)
{
    vector<CsvRow> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        CsvRow row;

        // Split the line into columns based on commas
        // Split the line into columns based on commas
        getline(iss, row.F_name, ',');
        getline(iss, row.L_name, ',');
        getline(iss, row.birth, ',');
        getline(iss, row.address, ',');
        getline(iss, row.id, ',');
        getline(iss, row.username, ',');
        getline(iss, row.password);

        //cout << " test1 " << row.username << row.password;

        if(username == row.username)
        {
            if(password == row.password) return true;
            else return false;
        } 
        else return false;
            
        

        data.push_back(row);
    }

    file.close();
}

// int main() {

//     //registrationProcess();
//     // vector<CsvRow> csvData = readCsv(filename);
//     // cout << "\nUpdated Data:\n";
//     // for (const auto& row : csvData) {
//     //     cout << row.F_name << ", " << row.L_name << ", " << row.birth << ", " << row.address << ", " << row.id << ", "  << row.username << ", "  << row.password<< endl;
//     // }
//     // return 0;
//     cout << findUsername("user1") << endl;
//     cout << verifyPassword("aaaaaaaa", "user1") << endl;
// }
