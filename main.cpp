#include <iostream>
#include <fstream>
#include <string>
#include "admin.h"

using namespace std;

class CheckUser
{
private:
	User* user;
	Admin* admin;

public:
	CheckUser() {
		choose_user();
	}

	~CheckUser()
	{
		//		delete admin, user;
	}

	void choose_user()
	{
		ifstream db1("db.txt");
		string line, login, password;
		string log, pass;

		if (db1.is_open()) {
			bool isLoggedIn = false;

			while (true) {
				cout << "Enter your login: " << endl;
				getline(cin, log);
				cout << "Enter your password: " << endl;
				getline(cin, pass);

				db1.clear();
				db1.seekg(0, ios_base::beg);

				while (db1 >> login >> password) {
					if (log == login && pass == password)
					{
						if (login == "admin")
						{
							admin = new Admin;
							return;
						}
						else
						{
							user = new User(login);
							return;
						}
					}
				}
				system("cls");

				cout << "-- Logowanie --" << endl << endl;
				cout << "Wrong login or password!" << endl << endl;
			}
			db1.close();
		}
		else
			cout << "Unable to open db.txt!";
	}
};


int main()
{
	int menu = -1;
	while (menu != 2) {
		system("cls");
		std::cout << "1. Log in" << std::endl << "2. Exit" << endl;
		std::cin >> menu;
		cin.get();

		switch (menu)
		{
		case 1: {
			cout << "-- Logowanie --" << endl << endl;

			CheckUser cu;
			cu.~CheckUser();
		}; break;
		case 2: break;
		default: break;
		}
	}

	system("pause");
	return 0;
};