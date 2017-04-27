#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

class User
{
public:
	User();
	User(std::string login);
	virtual ~User();

	void start_work();

	//for testing
	int summ(int a, int b);

private:
	std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
	std::chrono::duration<double> elapsed_seconds;

protected:
	std::fstream userlist;
};

