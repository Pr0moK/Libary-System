#include <iostream>
#include <fstream>
#include <Windows.h>


std::string line;

void AssignBook(std::string l, std::string b) {
	std::ifstream CheckIfBookExist;
	std::ofstream CreateBookData;

	CheckIfBookExist.open("BooksInLibary.txt");

	while (getline(CheckIfBookExist, line)) {
		bool found = line.find(b);
		if (!found) {
			CreateBookData.open("Books_" + l + ".txt", std::ios::app);
			if (CreateBookData.is_open()) {
				CreateBookData << b << "\n";
				CreateBookData.close();
			}

		}
		else {
			CreateBookData.open("BooksInLibary_TEMP.txt", std::ios::app);
			if (CreateBookData.is_open()) {
				std::cout << line;
				CreateBookData << line << "\n";
			}
			CreateBookData.close();
		}
	}

	CheckIfBookExist.close();
	remove("BooksInLibary.txt");
	rename("BooksInLibary_TEMP.txt", "BooksInLibary.txt");
}