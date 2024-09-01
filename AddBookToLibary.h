#include <iostream>
#include <fstream>
#include <Windows.h>


void AddBookToLibary(std::string b) {

	std::ofstream CreateBookData; 
	CreateBookData.open("BooksInLibary.txt", std::ios::app);
		if (CreateBookData.is_open()) {
			CreateBookData << b << "\n";
			CreateBookData.close();
	}


}