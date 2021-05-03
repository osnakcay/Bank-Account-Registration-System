#include <iostream>

#include "account.h"

using namespace std;

int main()
{
    Account account;
    int choice;
    cout<<"\n---Wecome to Wafture Bank---\n\n"<<endl;

    while(true)
    {
        cout<<"Choose what you want to do "<<endl;
        cout<<"1--> Create bank account"<<endl;
        cout<<"2--> View registered bank accounts"<<endl;
        cout<<"3--> Search for a bank account"<<endl;
        cout<<"4--> Update bank account"<<endl;
        cout<<"5--> Delete bank account"<<endl;
        cout<<"6--> Quit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            account.writeRegister();
            cout<<"The bank account has been successfully created\n"<<endl;
            break;
        case 2:
            account.getRegister();
            break;
        case 3:
            account.searchRegister();
            break;
        case 4:
            account.setRegister();
            cout<<"The bank account has been successfully updated\n"<<endl;
            break;
        case 5:
            account.removeRegister();
            cout<<"The bank account has been successfully removed\n"<<endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nPlease enter the right choice\n";
            exit(0);
        }
    }
    return 0;
}
