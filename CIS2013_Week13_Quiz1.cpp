#include <iostream>
#include <string>
using namespace std;

class accountInfo {
public:
	string name;
	int acctNum;
	int phoneNum;
	int balance;
	float rate;
	int savingsBal =0;

	accountInfo(){
		setName();
		setPhone();
		setAcctNum();
		setBal();
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
	void setBal() {
		cout << "What is the current checking balance on the acount? ";
		cin >> balance;
	}
	void setSave() {
		cout << "How much is in your savings account? ";
		cin >> savingsBal;
	}
	void setRate() {
		cout << "What is the rate on the account? ";
		cin >> rate;
	}
};

class acctActions: public accountInfo {
public:
	int withdrawAmount, depositAmount;
	int withLimit = 501;
	int minimumBal = 50;
	int overdraft = 15;

	void userOption() {
		int option;
			cout << "What would you like to do? " << endl;
			cout << "1 = Deposit" << endl << "2 = Withdraw" << endl << "3 = Show Account Info" << endl << "4 = Create New account" << endl;
			cin >> option;
		if (option == 1) {
			deposit();
		}
		else if (option == 2) {
			withdraw();
		}
		else if (option == 3) {
			showInfo();
		}
		else if (option == 4) {
			accountInfo();
		}

	}
	
	void withdraw() {
		int opt;
		cout << "Do you want to withdraw from your 1 = Checking or 2 = Savings?" << endl;
		cin >> opt;
		cout << "How much would you like to withdraw? ";
		cin >> withdrawAmount;
			if(opt ==1){
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
			if(opt ==2) {
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
		int opt = 0;
		cout << "Do you want to deposit into your 1 = Checkings or 2 = Savings;" << endl;
		cout << "How much do you want to deposit? ";
		cin >> depositAmount;
		if (opt == 1) {
			balance = balance + depositAmount;
		}
		else if (opt == 2) {
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
		if (balance < minimumBal) {
			cout << "Warning, the account has a minimum balanace of $50. Please deposit more" << endl;
		}
	}
};

class savingsAcct : public acctActions {
public:
	savingsAcct() {
		setName();
		setPhone();
		setAcctNum();
		setSave();
		setRate();
	}
};

int main() {
	int firstOpt;
	int option;
	bool keepGoing = true;

	cout << "Do you want to create a 1 = Checkings or 2 = Savings account? ";
	cin >> firstOpt;

	
	if (firstOpt == 1) {
		acctActions user;
		while (keepGoing == true) {
				user.userOption();
				cout << endl;
			}
		}
	else if (firstOpt == 2) {
		while (keepGoing == true) {
			savingsAcct savingsAcct;
			savingsAcct.userOption();
			cout << endl;
			}
		}
	
	
	return 0;
}
