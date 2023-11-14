#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

struct CsvRow {
    string col1, col2, col3, col4, col5;
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
        getline(iss, row.col1, ',');
        getline(iss, row.col2, ',');
        getline(iss, row.col3, ',');
        getline(iss, row.col4, ',');
        getline(iss, row.col5);

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
    file << newRow.col1 << "," << newRow.col2 << "," << newRow.col3 << "," << newRow.col4 << "," << newRow.col5 << "\n";

    file.close();
}

int main() {
    string filename = "database.csv";
    vector<CsvRow> csvData = readCsv(filename);
    appendData(filename, newData);

    // Read and print the updated data
    csvData = readCsv(filename);
    cout << "\nUpdated Data:\n";
    for (const auto& row : csvData) {
        cout << row.col1 << ", " << row.col2 << ", " << row.col3 << ", " << row.col4 << ", " << row.col5 << endl;
    }

    return 0;
}
