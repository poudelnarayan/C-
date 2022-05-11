#include <iostream>
#include "Account.h"

int main()
{
    Account narayan_account;
    narayan_account.set_balance(1000.0);
    double bal = narayan_account.get_balance();

    std::cout << bal << std ::endl;

    return 0;
}