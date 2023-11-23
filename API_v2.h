#ifndef API_v2_H
#define API_v2_H
#include <string>
// Node structure representing a person
struct Person {
    std::string fname;
    std::string lname;
    int age;
    std::string id;
    std::string address;
    std::string accountnumber;
    std::string username;
    std::string password;
    float amount;
    Person* next;
};

class PersonLinkedList {
private:
    Person* head;

public:
    // Constructor
    PersonLinkedList();

    // Destructor to free memory when the program ends
    ~PersonLinkedList();

    // Function to add a new person to the list
    void addPerson(const std::string& fname, const std::string& lname, int age,
                    const std::string& id, const std::string& address, const std::string& username,
                    const std::string& accountnumber, const std::string& password, float person_amount_1);

    void registrationProcess();

    // Function to delete a person from the list
    void deletePerson();

    // Function to change person properties
    void changePersonProperties(const std::string& property, const std::string& value);

    // Function to display person properties
    void showPersonProperties();

    // Function to save the updated data to a CSV file
    void saveToCSV(const std::string& filename);

    bool findUsername(const std::string& username);
    bool verifyPassword(std::string password1, std::string username1);
    void loadCsvData();
    bool updateBalance(const std::string toAccountNum, float balance);


};


#endif