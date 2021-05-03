#include "account.h"

void Account::readData()
{
    cout<<endl;
    cout<<"Enter Account Number: ";
    cin>>accountNumber;
    cout<<"Enter First Name: ";
    cin>>firstName;
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cout<<"Enter Balance: ";
    cin>>totalBalance;
    cout<<endl;
}

void Account::getData()
{
    cout<<endl;
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: "<<totalBalance<<endl;
    cout<<"***************************"<<endl;
}

void Account::writeRegister()
{
    ofstream file;
    file.open("database//accountDatabase.txt",std::ios::binary|std::ios::app);
    readData();
    file.write(reinterpret_cast<char *>(this), sizeof(*this));
    file.close();
}

void Account::getRegister()
{
    ifstream file;
    file.open("database//accountDatabase.txt",std::ios::binary);
    if(!file)
    {
        cout<<"Error in opening. File Not Found!!"<<endl;
        return;
    }
    cout<<"---------------------------"<<endl;
    while(!file.eof())
    {
        if(file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            getData();
        }
    }
    file.close();
}

void Account::searchRegister()
{
    int a;
    ifstream file;
    file.open("database//accountDatabase.txt",std::ios::binary);
    if(!file)
    {
        cout<<"Error in opening. File Not Found!!"<<endl;
        return;
    }
    file.seekg(0,std::ios::end);
    int count = file.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" register in the file";
    cout<<"\n Enter Register Number to Search: ";
    cin>>a;
    file.seekg((a-1)*sizeof(*this));
    file.read(reinterpret_cast<char*>(this), sizeof(*this));
    getData();
    file.close();
}

void Account::setRegister()
{
    int a;
    fstream file;
    file.open("database//accountDatabase.txt",std::ios::in|std::ios::binary);
    if(!file)
    {
        cout<<"Error in opening. File Not Found!!"<<endl;
        return;
    }
    file.seekg(0,std::ios::end);
    int count = file.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" register in the file";
    cout<<"\n Enter Register Number to Edit: ";
    cin>>a;
    file.seekg((a-1)*sizeof(*this));
    file.read(reinterpret_cast<char*>(this),sizeof(*this));
    cout<<"Register "<<a<<" has following data"<<endl;
    getData();
    file.close();
    file.open("database//accountDatabase.txt",std::ios::out|std::ios::in|std::ios::binary);
    file.seekp((a-1)*sizeof(*this));
    cout<<"Enter data to modify "<<endl;
    readData();
    file.write(reinterpret_cast<char*>(this),sizeof(*this));
}

void Account::removeRegister()
{
    int a;
    ifstream file;
    file.open("database//accountDatabase.txt",std::ios::binary);
    if(!file)
    {
        cout<<"Error in opening. File Not Found!!"<<endl;
        return;
    }
    file.seekg(0,std::ios::end);
    int count = file.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" register in the file";
    cout<<"\n Enter Register Number to Remove: ";
    cin>>a;
    fstream tmpFile;
    tmpFile.open("database//tmpFile.txt",std::ios::out|std::ios::binary);
    file.seekg(0);
    for(int i=0; i<count; i++)
    {
        file.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(a-1))
        {
            continue;
        }
        tmpFile.write(reinterpret_cast<char*>(this),sizeof(*this));
    }
    file.close();
    tmpFile.close();
    remove("database//accountDatabase.txt");
    rename("database//tmpFile.txt","database//accountDatabase.txt");
}
