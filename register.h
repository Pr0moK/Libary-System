#include <iostream>
#include <fstream>
#include <Windows.h>

std::ofstream OpenDataBaseW;
std::ifstream OpendataBaseR;
std::string clogin, cpassword, blogin;

bool loginspec = false;
bool passwordlen = true;

void createuser() {
	do {
	
		std::cout << "\nRegistry \n";
		std::cout << "Provide Login: ";
		std::cin >> clogin;

		if (clogin.size() >= 4) {
			loginspec = true;
			OpendataBaseR.open("database.txt");
			if (OpendataBaseR.is_open()) {
				while (getline(OpendataBaseR, blogin)) {
					int space;
					space = blogin.find(" ");
					blogin = blogin.substr(0, space);
					std::cout << blogin << "\n";
					if (blogin == clogin) {
						std::cout << "Username " << clogin << " is occupuied, try other one.";
						loginspec = false;

						break;
					}
				}
			}
			OpendataBaseR.close();
		}
		else {
			std::cout << "\nLogin must have more than 4 char.\n";
		}

	} while (!loginspec);

	std::cout << "\n";
	while (passwordlen) {
		std::cout << "Provide password: ";
		std::cin >> cpassword;
		std::cout << "\n";

		if (cpassword.size() >= 6) {
			break;
		}
		else {
			std::cout << "\npassword must have more than 6 char.\n";
		}

	}

	OpenDataBaseW.open("database.txt", std::ios::app);
	
	if (OpenDataBaseW.is_open()) {
		OpenDataBaseW << clogin << " " << cpassword << " " << "\n";
		OpenDataBaseW.flush();
		system("CLS");
		std::cout << "Successfully registered \n";
		OpenDataBaseW.close();

	}
	else {
		system("CLS");
		std::cout << "Coudn't save data to database";
	}


}
