#include <iostream>
#include <fstream>

using namespace std;

class Account
{
private:
    char accountNumber[15];
    char firstName[20];
    char lastName[20];
    double totalBalance;
public:
    void readData(); //Receives information from the user
    void getData(); //Prints user data to the screen
    void writeRegister(); //Writes information entered by users into "accountDatabase.txt" file
    void getRegister(); //It takes the data from the "accountDatabase.txt" file and prints the data to the screen by running the getData () function.
    void searchRegister(); //It extracts the number of users in the database and prints the data in the desired order on the screen.
    void setRegister(); //Updates the selected user's data by executing the readData () function.
    void removeRegister(); //Deletes selected user data from the database.
};
