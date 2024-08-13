#include <iostream>
#include <fstream>
#include <Windows.h>

std::ofstream OpenDataBaseW;
std::string clogin, cpassword;

bool loginlen = true;
bool passwordlen = true;

void createuser() {
	while (loginlen) {
		std::cout << "\nRegistry \n";
		std::cout << "Provide Login: ";
		std::cin >> clogin;

		if (clogin.size() >= 4) {
			break;
		}
		else {
			std::cout << "\nLogin must have more than 4 char.\n";
		}

	}

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
