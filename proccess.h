#ifndef PROCCESS_H_INCLUDED
#define PROCCESS_H_INCLUDED
#include "account.h"
class proccess : public accounts
{
    int n;
public:
    proccess()
    {
        cout<<"Your proccess is\n";
    }
    bool With(int cash)
    {
        if(Withdraw(cash))return true;
        return false;
    }
    void Dep(int cash)
    {
        Deposit(cash);
    }
};

#endif // PROCCESS_H_INCLUDED
