#include <bits/stdc++.h>
using namespace std;
#include "atm.h"
#include "account.h"
#include "proccess.h"
int I,c=0;
bool flag=1;
bool fun()
{
    accounts a;
    cout<<"Please Enter your Name : ";
    string ss;cin>>ss;
    cout<<"please Enter your ID : ";
    cin>>I;
    flag=a.Sreach(I);
    if(flag==0)
    {
        c++;
        cout<<"Your ID is not correct Please enter it again\n";
        if(c==5)cout<<"You have to call customers service thanks to use our service\n";
        if(c<5)fun();
    }
}
int accounts::Money=0;
int ATM :: AMoney=10000;
int main()
{
    cout<<"*******Welcome*******\nDo you have an account?\n"
        <<"If you have press \"Y\"\nIf No press \"N\" : ";
    char yn;
    cin>>yn;
    if(yn=='y'||yn=='Y')
    {
        cout<<"*******Welcome back to our system*******\n";
        fun();
    }
    else
    {
        cout<<"create an account\n";
        cout<<"Please Enter the Name : ";
        string s;
        cin>>s;
        cout<<"Please Enter the ID : ";
        int i,m;
        cin>>i;
        cout<<"Please Enter the Money : ";
        cin>>m;
        accounts Custmer;
        Custmer.SetID(i);
        Custmer.SetN(s);
        Custmer.SetM(m);
        Custmer.addtofile();
        cout<<"Thanks to use our servise\n";
    }
    while(flag)
    {
        cout<<"Please enter your process : \n"
            <<"1) Check your money\n"
            <<"2) Withdraw cash\n"
            <<"3) Deposit\n"
            <<"4) EXist\n";
        int z;
        cin>>z;
        switch(z)
        {
        case 1:
        {
            accounts ob;
            ob.Sreach(I);
            cout<<"****************\nYour name : "<<ob.GetN()<<"\nYour ID : "<<ob.GetID()<<"\nYour Money : "<<ob.GetM()<<"\n****************\n";
        }
        break;
        case 2:
        {
            cout<<"Please Enter the Money : ";
            int M;
            cin>>M;
            accounts ob;
            ob.Sreach(I);
            if(ob.Withdraw(M))
                ob.updatedata(I);
        }
        break;
        case 3:
        {
            accounts ob;
            proccess c;
            ob.Sreach(I);
            cout<<"Please Enter the Money : ";
            int M;
            cin>>M;
            c.Dep(M);
            ob.updatedata(I);
        }
        break;
        default:
            flag=0;
        }
    }
    return 0;
}
