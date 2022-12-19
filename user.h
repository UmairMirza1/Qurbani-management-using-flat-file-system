#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include"interfaces.h"

using namespace std;

class user :public menu, public login {

public:

	int id;
	user(int id);

	virtual void showmenu();
	virtual int check_login(int id , int pass);


};