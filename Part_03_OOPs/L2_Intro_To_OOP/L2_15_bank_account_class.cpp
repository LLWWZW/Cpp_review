#include <iostream>
#include <string>

class BankAccount
{
  private:
    /* data */
    int account_number = 211;
    std::string owner_name;
    int available_funds{0};

  public:
    int AccountNumber();
    void AccountNumber(int accountnumber)
    {
        account_number = accountnumber;
    }
    std::string OwnerName();
    void OwnerName(std::string ownername)
    {
        owner_name = ownername;
    }
    int GetAccNumber()
    {
        return available_funds;
    }
    void AddFunds(int f);
    void CheckBalance();
};

int BankAccount::AccountNumber()
{
    return account_number;
}

std::string BankAccount::OwnerName()
{
    return owner_name;
}

void BankAccount::AddFunds(int f)
{
    available_funds += f;
}

void BankAccount::CheckBalance()
{
    std::cout << owner_name << " balance is: " << available_funds << "\n";
}

int main()
{
    BankAccount b1;
    b1.AccountNumber(3457);
    b1.OwnerName("Harshad");
    b1.AddFunds(5000);

    BankAccount b2;
    b2.AccountNumber(9871);
    b2.OwnerName("Mehta");
    b2.AddFunds(9000);

    b1.CheckBalance();
    b2.CheckBalance();

    b1.AddFunds(8000);
    b2.AddFunds(10000);

    b1.CheckBalance();
    b2.CheckBalance();
}