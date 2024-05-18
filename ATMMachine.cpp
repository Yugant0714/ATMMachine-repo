#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    string username;
    string password;
    double balance;
};

void printIntroMenu();
void printMainMenu();
void start();
void login(unordered_map<string, Account> &accounts);
void createAccount(unordered_map<string, Account> &accounts);
char menuInput;
double balance;
unordered_map<string, Account> accounts;

int main()
{
    cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;
    start();
    return 0;
}

void printIntroMenu()
{
    cout<<endl;
    cout << "Please select an option from the menu below: " << endl;
    cout << "l  -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout<<endl;
    cout << "> ";
}
void printMainMenu()
{
    cout<<endl;
    cout << "d  -> Deposit Money" << endl;
    cout << "w  -> Withdraw Money" << endl;
    cout << "r  -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout<<endl;
    cout << "> ";
}
void start()
{
    printIntroMenu();
    cin >> menuInput;
    switch (menuInput)
    {
    case 'l':
        login(accounts);
        break;
    case 'c':
        createAccount(accounts);
        break;
    case 'q':
        cout << "Exiting program...\n";
        exit(0);
        break;
    default:
        cout << "Invalid choice.\n";
        start();
    }
}
void login(unordered_map<string, Account> &accounts)
{
    string userId;
    string password;
    char choice;
    cout<<endl;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;
    cout<<endl;
    if(accounts.empty()){
        cout << "******** LOGIN FAILED! ********" << endl;
        start();
    }
    auto it = accounts.find(userId);
    if (it->second.username == userId and it->second.password == password)
    {
        cout << "Access Granted!" << endl;
        Account &account = it->second;
        char choice;
        do
        {
            printMainMenu();
            cin >> choice;

            switch (choice)
            {
            case 'd':
                double depositAmount;
                cout<<endl;
                cout << "Amount of deposit: $";
                cin >> depositAmount;
                account.balance += depositAmount;
                break;
            case 'w':
                double withdrawalAmount;
                cout<<endl;
                cout << "Amount of withdrawal: $";
                cin >> withdrawalAmount;
                if (withdrawalAmount <= account.balance)
                {
                    account.balance -= withdrawalAmount;
                }
                else
                {
                    cout<<endl;
                    cout << "Insufficient funds!" << endl;
                }
                break;
            case 'r':
                cout<<endl;
                cout << "Your balance is $" << account.balance << endl;
                break;
            case 'q':
                cout<<endl;
                cout << "Thanks for stopping by!" << endl;
                break;
            default:
                cout<<endl;
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 'q');
    }
    else
    {
        cout << "******** LOGIN FAILED! ********" << endl;
        start();
    }
}
void createAccount(unordered_map<string, Account> &accounts)
{
    string password;
    string username;
    cout<<endl;
    cout << "Please enter your user name: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
    cout<<endl;

    Account newAccount;
    newAccount.username = username;
    newAccount.password = password;
    newAccount.balance = 0.0;

    accounts[username] = newAccount;

    cout << "Thank You! Your account has been created!" << endl;
    start();
}