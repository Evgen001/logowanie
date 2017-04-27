#pragma once

#include "user.h"


class Admin : public User
{
public:
	Admin();
	~Admin();

	void add_user();
	void show_userlist();
};

