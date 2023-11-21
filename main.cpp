//#include "home.h" 
#include "API_v2.h"


using namespace std;

int main()
{
    PersonLinkedList p1;
    p1.loadCsvData();
    p1.addPerson("sp1","sp",10,"ss","ss","ss","ss", "ss");
    p1.saveToCSV("data2.csv");
    //home();
    
}