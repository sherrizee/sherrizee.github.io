#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

void menu();
void addTransactions(int transactions, const int MAX, string arrayItem[], double arrayPrice[]);
void showTransactions(int transactions, string arrayItem[], double arrayPrice[]);

int main()
{
	cout << setprecision(2) << fixed << showpoint;

	cout << "This program will print out a transaction history of a credit card.\n" << endl;

	int option = 1;
	int transactions = 0;
	const int MAX = 100;
	string arrayItem[MAX];
	double arrayPrice[MAX];

	while (option != 0)
	{
		menu();

		cout << "Option: ";
		cin >> option;

		cout << endl;


		while (option < 0 || option > 2)
		{
			cout << "Invalid, the number needs to be between 0-2: " << endl;
			cout << "Option: ";
			cin >> option;
		}

		switch (option)
		{
		case 1:
			addTransactions(transactions, MAX, arrayItem, arrayPrice);
			transactions++;
			break;
		case 2:
			showTransactions(transactions, arrayItem, arrayPrice);
			break;
		case 0:
			cout << "Goodbye!";
			break;
		}
	}

	return 0;
}

void menu()
{
	cout << "Menu:" << endl;
	cout << "1 - Add a transaction" << endl;
	cout << "2 - Show transactions" << endl;
	cout << "0 - Exit" << endl;
}

void addTransactions(int transactions, const int MAX, string arrayItem[], double arrayPrice[])
{
	if (transactions <= MAX)
	{
		cout << "Description: ";
		cin >> arrayItem[transactions];

		cout << "Amount: ";
		cin >> arrayPrice[transactions];

		cout << endl;
	}
	else
	{
		cout << "Max amount of transactions!" << endl;
	}
}

void showTransactions(int transactions, string arrayItem[], double arrayPrice[])
{
	cout << "Transactions: " << endl;

	for (int i = 0; i < transactions; i++)
	{
		cout << arrayItem[i] << ": $" << arrayPrice[i] << endl;
	}

	cout << endl;
}