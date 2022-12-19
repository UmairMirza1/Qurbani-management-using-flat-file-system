#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include"user.h"
#include "Salesman.h"
#include "animal.h"
using namespace std;

class salesman :public user {

private:

	int emp_id;

public:

	salesman(int b) :user(id) {

		this->emp_id = b;
	};

	void view_animals();
	void view_available();

	void view_detail(int id);


	void view_schedule(int animal_id);
	void add_customer(int id, string name);

	static int check_login(int id, int pass);
	void reserve_share(int animal_id, int cust_id, int numberofshares);

	void view_customer_details(int cust_id);
	static 	void showmenu();
		

	void change_status(int animal_id, int newstatus);

};