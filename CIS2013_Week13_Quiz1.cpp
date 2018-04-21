#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
	string name;
	int acctNum;
	int savingsBal = 0;
	int phoneNum;
	int balance = 0;
	float rate;
	int withdrawAmount, depositAmount;

	BankAccount() {
		setName();
		setPhone();
		setAcctNum();
		setRate();
	}

	void setName() {
		cout << "What is the name on the account? ";
		cin >> name;
	}
	void setAcctNum() {
		cout << "What is the account number? ";
		cin >> acctNum;
	}
	void setPhone() {
		cout << "What is the phone number on the account? ";
		cin >> phoneNum;
	}
	void setRate() {
		cout << "What is the rate on the account? ";
		cin >> rate;
	}
};

class Savings:public BankAccount {
private:
	int withLimit = 501;
	int minimumBal = 50;
	int overdraft = 15;

public:
	void withdraw() {
		int opt;
		cout << "Do you want to withdraw from your 1 = Checking or 2 = Savings? ";
		cin >> opt;
		cout << "How much would you like to withdraw? ";
		cin >> withdrawAmount;
		if (opt == 1) {
			if (withdrawAmount < withLimit) {
				balance = balance - withdrawAmount;
				if (balance < 0) {
					cout << "You have overdrafted on your account and will be charged a fee of $15" << endl;
					balance = balance - overdraft;

				}
				else if (withdrawAmount >= withLimit) {
					cout << "The withdraw limit is $500" << endl;
				}
			}
		}
		if (opt == 2) {
			if (withdrawAmount < withLimit) {
				savingsBal = savingsBal - withdrawAmount;
				if (savingsBal < 0) {
					cout << "You have overdrafted on your account and will be charged a fee of $15" << endl;
					savingsBal = savingsBal - overdraft;

				}
				else if (withdrawAmount >= withLimit) {
					cout << "The withdraw limit is $500" << endl;
				}
			}
		}
	}

	void deposit() {
		int opt2;
		cout << "Do you want to deposit into your 1 = Checkings or 2 = Savings? ";
		cin >> opt2;
		cout << "How much do you want to deposit? ";
		cin >> depositAmount;
		if (opt2 == 1) {
			balance = balance + depositAmount;
		}
		else if (opt2 == 2) {
			savingsBal = savingsBal + depositAmount;
		}
	}

	void showInfo() {
		cout << "Account Name: " << name << endl;
		cout << "Account Number: " << acctNum << endl;
		cout << "Account Phone Number: " << phoneNum << endl;
		cout << "Current Rate: " << rate << " %" << endl;
		cout << "Current Balance: $" << balance << endl;
		cout << "Current Savings Balance: $" << savingsBal << endl;
	}
};
	
int main() {
	int option;
	bool keepGoing = true;
	BankAccount user;
	Savings user2;

	while (keepGoing == true) {
		cout << "What would you like to do? " << endl;
		cout << "1 = Withdraw" << endl << "2 = Deposit" << endl << "3 = Show Account Info" << endl << "4 = Exit" << endl;
		cin >> option;

		if (option == 1) {
			user2.withdraw();
		}
		else if (option == 2) {
			user2.deposit();
		}
		else if (option == 3) {
			user2.showInfo();
		}
		else if (option == 4) {
			keepGoing = false;
		}
		else { cout << "Please enter a valid option" << endl; }
		cout << endl;
	}

	return 0;
}