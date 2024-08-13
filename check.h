#include <iostream>
#include <fstream>
#include <Windows.h>

std::ifstream OpenDataBase;
std::string datauser;
std::string logincheck, passwordcheck;
int pos,newline;
bool dataTrue = false;


void checkuser(std::string user,std::string pass) {




	OpenDataBase.open("database.txt");
	if (OpenDataBase.is_open()) {
		while (getline(OpenDataBase, datauser))
		{

			pos = datauser.find(" ");
			newline = datauser.find("\n");
			logincheck = datauser.substr(0, pos);
			passwordcheck = datauser.substr(pos+1);
			passwordcheck.pop_back();
			if (logincheck == user && passwordcheck == pass) {
					dataTrue = true;
					system("CLS");
					//std::cout << "Data is correct, Welcome!\n";
					break;
			}

		}
		if (dataTrue == 0) {
		std::cout << "Data is wrong, try again\n";
		}
		OpenDataBase.close();
	}

}