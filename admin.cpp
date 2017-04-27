#include "admin.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


Admin::Admin() : User()
{
	std::cout << "You are logged in as an admin" << std::endl;

	int menu = -1;
	while (menu != 0) {
		std::cout << "1. Add new user" << std::endl << "2. Show userlist" << std::endl << "0. Exit" << std::endl;
		std::cin >> menu;
		std::cin.get();

		switch (menu)
		{
		case 1: add_user(); break;
		case 2: show_userlist(); break;
		default:
			break;
		}
	}
}


Admin::~Admin()
{
}

void Admin::add_user()
{
	std::fstream userlist1("db.txt", std::ios_base::app);
	std::string login, password;
	std::cout << "Enter new login: ";
	//std::cin.get();
	std::getline(std::cin, login);
	std::cout << "Enter a password for " << login << ": ";
	std::getline(std::cin, password);
	if (userlist1.is_open()) {
		userlist1 << std::endl << login << ' ' << password << '\n';
		userlist1.close();
	}
	else
		std::cout << "Unable to open file!";
}

void Admin::show_userlist()
{
	std::ifstream db1("db.txt");
	std::string login, password;

	if (db1.is_open()) {
		while (db1 >> login >> password) {
			std::cout << login << ' ' << password << std::endl;
		}
	}
}
