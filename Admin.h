#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include"user.h"
#include "Salesman.h"
#include"animal.h"

using namespace std;

class admin :public user, public salesman {

private:
	int emp_no;

public:

	// admin() {};

	admin(int id) :salesman(id), user(id) {
		emp_no = id;
	}

	void add_animal(int id, int type, int price);
	void add_salesman(int id, int password);
	void make_schedule(int animal_id);
	static void showmenu();
	static int check_login(int id, int pass);
};

