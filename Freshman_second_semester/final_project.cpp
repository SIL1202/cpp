// simulated bank system
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
  string Name;
  int Customer_number;
  int Balance;

  Account(string name, int customer_number, int balance)
      : Name(name), Customer_number(customer_number), Balance(balance) {}

  Account() : Name(""), Customer_number(0), Balance(0) {}

  void save_to_file() {
    string filename = to_string(Customer_number) + ".txt";
    ofstream outfile(filename);
    if (outfile.is_open()) {
      outfile << "Name: " << Name << "\n";
      outfile << "Customer Number: " << Customer_number << "\n";
      outfile << "Balance: " << Balance << "\n";
      outfile.close();
    } else {
      cout << "Failed to create file " << filename << endl;
    }
  }

  bool load_from_file(int customer_number) {
    string filename = to_string(customer_number) + ".txt";
    ifstream infile(filename);
    if (infile.is_open()) {
      string line;
      getline(infile, line);
      Name = line.substr(line.find(": ") + 2);
      getline(infile, line);
      Customer_number = stoi(line.substr(line.find(": ") + 2));
      getline(infile, line);
      Balance = stoi(line.substr(line.find(": ") + 2));
      infile.close();
      return true;
    } else {
      return false;
    }
  }
};

class Bank {
public:
  Bank() {}

  void menu() {
    cout << "\n**** menu ****\n"
         << "----1: balance\n"
         << "----2: deposit\n"
         << "----3: withdraw\n"
         << "----4: create account\n"
         << "----5: transfer\n"
         << "----6: cancel\n";
  }

  void balance(int customer_number) {
    Account account;
    if (account.load_from_file(customer_number)) {
      cout << "Customer " << account.Name << "'s current balance is: $"
           << account.Balance << endl;
    } else {
      cout << "Cannot find account for the customer number.\n";
    }
  }

  void deposit(int customer_number) {
    int amount;
    cout << "Enter deposit amount: $";
    cin >> amount;
    Account account;
    if (account.load_from_file(customer_number)) {
      if (amount > 0) {
        account.Balance += amount;
        account.save_to_file();
        cout << "Deposit successful!\n";
      } else {
        cout << "Invalid amount. Please enter a positive value.\n";
      }
    } else {
      cout << "Cannot find account for the customer number.\n";
    }
  }

  void withdraw(int customer_number) {
    int amount;
    cout << "Enter withdrawal amount: $";
    cin >> amount;
    Account account;
    if (account.load_from_file(customer_number)) {
      if (amount > 0 && amount <= account.Balance) {
        account.Balance -= amount;
        account.save_to_file();
        cout << "Withdrawal successful!\n";
      } else if (amount > account.Balance) {
        cout << "Insufficient balance.\n";
      } else {
        cout << "Invalid amount. Please enter a positive value.\n";
      }
    } else {
      cout << "Cannot find account for the customer number.\n";
    }
  }

  void create_account() {
    string name;
    int customer_number;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your customer number: ";
    cin >> customer_number;
    Account new_account(name, customer_number, 0);
    new_account.save_to_file();
    cout << "Account created successfully!\n";
  }

  void transfer(int from_customer_number, int to_customer_number) {
    int amount;
    cout << "Enter transfer amount: $";
    cin >> amount;
    Account from_account, to_account;
    if (from_account.load_from_file(from_customer_number) &&
        to_account.load_from_file(to_customer_number)) {
      if (amount > 0 && amount <= from_account.Balance) {
        from_account.Balance -= amount;
        to_account.Balance += amount;
        from_account.save_to_file();
        to_account.save_to_file();
        cout << "Transfer successful! $" << amount
             << " transferred from customer " << from_account.Name
             << " to customer " << to_account.Name << endl;
      } else if (amount > from_account.Balance) {
        cout << "Insufficient balance.\n";
      } else {
        cout << "Invalid amount. Please enter a positive value.\n";
      }
    } else {
      if (!from_account.load_from_file(from_customer_number)) {
        cout << "Cannot find account for the transfer out customer number.\n";
      }
      if (!to_account.load_from_file(to_customer_number)) {
        cout << "Cannot find account for the transfer in customer number.\n";
      }
    }
  }

  void cancel() { cout << "Session ended! Goodbye~\n"; }
};

int main() {
  Bank bank;
  int pin, password = 1234;
  cout << "Welcome to your bank account ~\n"
       << "Enter your four digit pin: ";
  while (cin >> pin) {
    if (pin == password)
      break;
    else
      cout << "Access fail!\n\n";
    cout << "Enter your four digit pin: ";
  }

  while (true) {
    bank.menu();
    int instruct, customer_number, to_customer_number;
    cin >> instruct;
    switch (instruct) {
    case 1:
      cout << "Enter your customer number: ";
      cin >> customer_number;
      bank.balance(customer_number);
      break;
    case 2:
      cout << "Enter your customer number: ";
      cin >> customer_number;
      bank.deposit(customer_number);
      break;
    case 3:
      cout << "Enter your customer number: ";
      cin >> customer_number;
      bank.withdraw(customer_number);
      break;
    case 4:
      bank.create_account();
      break;
    case 5:
      cout << "Enter the customer number to transfer from: ";
      cin >> customer_number;
      cout << "Enter the customer number to transfer to: ";
      cin >> to_customer_number;
      bank.transfer(customer_number, to_customer_number);
      break;
    case 6:
      bank.cancel();
      return 0;
    default:
      cout << "Invalid option. Please try again.\n";
    }
  }

  return 0;
}
