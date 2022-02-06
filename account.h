#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include "atm.h"
class accounts:public ATM
{
    string Name;
    int ID;
    static int Money;
public:
    accounts()
    {

    }
    bool Sreach(int I)
    {
        bool f=1;
        ifstream ATM_File;
        ATM_File.open("ATM.txt",ios::app);
        bool z=1;
        string s;
        int i,m;
        while(ATM_File>>s>>i>>m )
        {
            ATM_File>>s>>i>>m;
            if(I==i)
            {
                Name=s;
                ID=i;
                Money=m;
                z=0;
                break;
            }
        }
        ATM_File.close();
        if(z)
        {
            cout<<"Not Found!!!!!\n";
            return false;
        }
        return true;
    }
    void updatedata(int I)
    {
        string s;
        int i,m;
        fstream ATM_File;
        fstream temp;
        ATM_File.open("ATM.txt",ios::app);
        temp.open("temp.txt",ios::app);
        while( ATM_File>>s>>i>>m )
        {
            if (  i==I )
            {
                temp<< Name<< "\t"<< ID<<"\t"<< Money<<endl;
            }
            else
            {
                temp<< s<< "\t"<< i<<"\t"<< m<<endl;
            }
        }
        ATM_File.close();
        temp.close();
        remove( "ATM.txt" );
        rename( "temp.txt", "ATM.txt" );
    }
    void SetN(string Name)
    {
        this->Name=Name;
    }
    void SetID(int ID)
    {
        this->ID=ID;
    }
    void SetM(int Money)
    {
        this->Money=Money;
    }
    int GetM()
    {
        return Money;
    }
    string GetN()
    {
        return Name;
    }
    int GetID()
    {
        return ID;
    }
    void addtofile()
    {
        fstream ATM_File;
        ATM_File.open("ATM.txt",ios::app);
        ATM_File<<Name<<"\t"<<ID<<"\t"<<Money<<endl;
        ATM_File.close();
    }
    void operator-=(int b)
    {
        Money-=b;
    }
    void operator+=(int b)
    {
        Money+=b;
    }
    bool Withdraw(int cash)
    {
        int X=GetAM();
        if(cash>Money)
            cout<<"Sorry you do not have enough money\n";
        else if(cash>X)
            cout<<"Sorry ATM do not have enough money\n";
        else
        {
            Money-=cash;
            cout<<"Done -_- your money is : "<<Money<<"\n";
            return true;
        }
        return false;
    }
    void Deposit(int cash)
    {
        Money+=cash;
        cout<<"Done -_-\n you have now : "<<Money<<"\n";
    }
};
#endif // ACCOUNT_H_INCLUDED
