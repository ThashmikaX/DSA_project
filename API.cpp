// #include "API.h"
// #include "registration.h"
// #include "login.h"

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <string>

// std::string filename = "database.csv";

// std::vector<CsvRow> readCsv(const std::string& filename) {
//     vector<CsvRow> data;
//     ifstream file(filename);

//     if (!file.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return data;
//     }

//     std::string line;
//     while (getline(file, line)) {
//         istd::stringstream iss(line);
//         CsvRow row;

//         // Split the line into columns based on commas
//         getline(iss, row.F_name, ',');
//         getline(iss, row.L_name, ',');
//         getline(iss, row.birth, ',');
//         getline(iss, row.address, ',');
//         getline(iss, row.id, ',');
//         getline(iss, row.username, ',');
//         getline(iss, row.password, ',');
//         getline(iss, row.balance_str);

//         data.push_back(row);
//     }

//     file.close();
//     return data;
// }

// void appendData(const std::string& filename, const CsvRow& newRow) {
//     ofstream file(filename, ios::app); // Open the file in append mode

//     if (!file.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return;
//     }

//     // Append the new data line with comma separation
//     file << newRow.F_name << "," << newRow.L_name << "," << newRow.birth << "," << newRow.address << "," << newRow.id << "," << newRow.username << "," << newRow.password << "\n";

//     file.close();
// }

// void registrationProcess()
// {
//     std::string* ptr = registration();
//     CsvRow newData = {ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6]};
//     // appendData(filename, newData);
//     appendData(filename, newData);
//     cout << "\n" << "Your Details " << "\n";
//     cout << "First Name : " << ptr[0] << "\n";
//     cout << "Last Name : " << ptr[1] << "\n";
//     cout << "Birthday : " << ptr[2] << "\n";
//     cout << "Address : " << ptr[3] << "\n";
//     cout << "ID Number : " << ptr[4] << "\n";
//     cout << "Username : " << ptr[5] << "\n" << "_________________________________" << "\n";
//     cout << "Login your account from here\n";

//     loginPage(0);


// }

// bool findUsername(std::string username)
// {
//     vector<CsvRow> data;
//     ifstream file(filename);

//     if (!file.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return false;
//     }

//     std::string line;
//     while (getline(file, line)) {
//         istd::stringstream iss(line);
//         CsvRow row;

//         // Split the line into columns based on commas
//         getline(iss, row.F_name, ',');
//         getline(iss, row.L_name, ',');
//         getline(iss, row.birth, ',');
//         getline(iss, row.address, ',');
//         getline(iss, row.id, ',');
//         getline(iss, row.username, ',');
//         getline(iss, row.password, ',');
//         getline(iss, row.balance_str);


//         //cout << " test1 " << row.username << row.password;

//         if(username == row.username)
//         {
//             data.push_back(row);
//             return true;
//         }
//         data.push_back(row);
        
//     }
//     file.close();
//     return false;
// }

// bool verifyPassword(std::string password, std::string username)
// {
//     vector<CsvRow> data;
//     ifstream file(filename);

//     if (!file.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return false;
//     }

//     std::string line;
//     while (getline(file, line)) {
//         istd::stringstream iss(line);
//         CsvRow row;

//         // Split the line into columns based on commas
//         // Split the line into columns based on commas
//         getline(iss, row.F_name, ',');
//         getline(iss, row.L_name, ',');
//         getline(iss, row.birth, ',');
//         getline(iss, row.address, ',');
//         getline(iss, row.id, ',');
//         getline(iss, row.username, ',');
//         getline(iss, row.password, ',');
//         getline(iss, row.balance_str);

//         //cout << " test1 " << row.username << row.password;

//         if(username == row.username)
//         {
//             if(password == row.password)
//             {
//                 data.push_back(row);
//                 return true;
//             }
//         }
//         data.push_back(row);
        
//     }

//     file.close();
//     return false;
// }

// // float showBalance(std::string username)
// // {
// //     vector<CsvRow> data;
// //     ifstream file(filename);

// //     if (!file.is_open()) {
// //         cerr << "Error opening file: " << filename << endl;
// //     }

// //     std::string line;
// //     while (getline(file, line)) {
// //         istd::stringstream iss(line);
// //         CsvRow row;

// //         // Split the line into columns based on commas
// //         getline(iss, row.F_name, ',');
// //         getline(iss, row.L_name, ',');
// //         getline(iss, row.birth, ',');
// //         getline(iss, row.address, ',');
// //         getline(iss, row.id, ',');
// //         getline(iss, row.username, ',');
// //         getline(iss, row.password, ',');
// //         getline(iss, row.balance_str);




// //         float balance = stof(row.balance_str);
        
// //         //cout << " test1 " << row.username << row.password;

// //         if(username == row.username)
// //         {
// //             data.push_back(row);
// //             //cout << "bal" << row.balance_str;
// //             return balance;
// //         }
// //         data.push_back(row);
        
// //     }
// //     file.close();
// //     return -1.2;
// //     cout << "come to end";
// // }
// // int main() {

// //     //registrationProcess();
// //     vector<CsvRow> csvData = readCsv(filename);
// //     cout << "\nUpdated Data:\n";
// //     for (const auto& row : csvData) {
// //         cout << row.F_name << ", " << row.L_name << ", " << row.birth << ", " << row.address << ", " << row.id << ", "  << row.username << ", "  << row.password<< ", "  << row.balance_str<< endl;
// //     }
// //     cout << "finduser " << findUsername("user1") << endl;
// //     cout << "Test2 " << showBalance("user1") << endl;
// //     cout << "Test2 " << showBalance("user4") << endl;
// //     return 0;
// // }
