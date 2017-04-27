#include "user.h"

User::User()
{
	system("cls");
	start_work();
}

User::User(std::string login) : userlist("db.txt", std::ios_base::app)
{
	system("cls");
	std::cout << "Hi, " << login << '!' << std::endl << std::endl;

	std::cout << "Press \"0\" to log out..." << std::endl;
	int menu = -1;
	while (menu != 2)
	{
		system("cls");
		std::cout << "1. Rozpocznij prace" << std::endl << "2. Wyloguj" << std::endl;
		std::cin >> menu;
		std::cin.get();

		switch (menu)
		{
		case 1: start_work(); system("pause"); break;
		case 2: break;
		default: break;
		}
	}
}

User::~User()
{
	endTime = std::chrono::system_clock::now();
	std::cout << "Log out time:   " << std::chrono::system_clock::to_time_t(endTime) << std::endl;
	elapsed_seconds = endTime - startTime;
	std::cout << "Work duration:   " << elapsed_seconds.count() << " secs.." << std::endl;
}

void User::start_work()
{
	startTime = std::chrono::system_clock::now();
	std::cout << "Log in time:   " << std::chrono::system_clock::to_time_t(startTime) << std::endl;
}

//for testing
int User::summ(int a, int b)
{
	return a + b;
}