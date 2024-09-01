#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "check.h"
#include "register.h"
#include "AssignBooksUser.h"
#include "AddBookToLibary.h"

using namespace std;

string login, passwrd;
extern bool dataTrue;
int choice = 0;
bool menu = true;
ofstream wpisz;
string book;

int main()
{		

	//Menu before login//
	do {
		cout << "Log in or Register Account:\n";
		cout << "\n1. Log in";
		cout << "\n2. Register Account\n";
		cout << "\n3. Exit program\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nLoging in\n";
			cout << "Provide login: ";
			cin >> login;
			cout << "\nProvide password: \n";
			cin >> passwrd;
			checkuser(login, passwrd);
			break;
		case 2:		

			createuser();
			break;

		case 3:
			menu = false;
			break;
		default:
			cout << "Choose 1-3 option";
			break;
		}
	} while (menu && !dataTrue);

	// Menu after login //
	while (dataTrue) {
		cout << "\nChoose an acction:\n";
		cout << "1. Add Book to system\n";
		cout << "2. Add Book to user\n";
		cout << "3. Remove book from user";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Add Book to libary: \n";
			cin.ignore();
			getline(cin, book);
			AddBookToLibary(book);
			break;

		case 2:
			cout << "Assign book: \n";
			cin.ignore();
			getline(cin, book);
			AssignBook(login, book);
			break;

		case 3:


			break;
		default:
			cout << "Choose 1-3 option";
			break;
		}



		dataTrue = false;
		break;
	}
}