#include <iostream>
#include <fstream>
#include <Windows.h>


std::string line;
bool InLibary = false;

void AssignBook(std::string l, std::string b) {
	std::ifstream CheckIfBookExist;
	std::ofstream CreateBookData;

	CheckIfBookExist.open("BooksInLibary.txt");
	if (CheckIfBookExist.is_open()) {
		while (getline(CheckIfBookExist, line)) {
			bool found = line.find(b);
			if (!found) {
				CreateBookData.open("Books_" + l + ".txt", std::ios::app);
				if (CreateBookData.is_open()) {
					CreateBookData << b << "\n";
					CreateBookData.close();
					InLibary = true;
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

		if (InLibary) {
			std::cout << "Book named: " << b << " was added to user: " << l;
		}
		else {
			std::cout << "There is no book named: " << b << " in libary system";
		}
		CheckIfBookExist.close();
		remove("BooksInLibary.txt");
		rename("BooksInLibary_TEMP.txt", "BooksInLibary.txt");
	}
	else {
		std::cout << "There is no database of Books";
	}
}