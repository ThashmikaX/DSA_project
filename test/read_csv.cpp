#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>


using namespace std;

int main() {
  // Open the CSV file in read mode.
  ifstream fin("input.csv");

  // Check if the file opened successfully.
  if (!fin.is_open()) {
    cout << "Error opening file." << endl;
    return 1;
  }

  // Create a vector to store the CSV data.
  vector<vector<string>> csv_data;

  // Read the CSV file line by line.
  string line;
  while (getline(fin, line)) {
    // Split the line into fields using a comma as the delimiter.
    vector<string> fields;
    stringstream ss(line);
    string field;
    while (getline(ss, field, ',')) {
      fields.push_back(field);
    }

    // Store the fields in the vector.
    csv_data.push_back(fields);
  }

  // Close the file.
  fin.close();

  // Print the CSV data.
  for (auto& row : csv_data) {
    for (auto& field : row) {
      cout << field << ", ";
    }
    cout << endl;
  }

  return 0;
}
