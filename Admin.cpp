#include "Admin.h"



	// admin() {};


	void admin:: add_animal(int id, int type, int price) { //animal  obj.add()

		if (Animal::duplicateid(id) == true) { cout << "duplicate id\n"; return; }

		Animal* a = getinstance(id, price, type);
		ofstream obj;

		obj.open("animal.txt", ios_base::app);
		a->serialize(obj);


	}
	void admin::add_salesman(int id, int password) {

		fstream file;
		file.open("salesman.txt", ios::app);

		file << id << "," << password << "\n";
		file.close();


	}

	void admin::make_schedule(int animal_id) {

		fstream file;
		file.open("schedule.txt", ios::app);
		int schedule = rand() % 24;
		int day = rand() % 3;
		file << animal_id << "," << schedule << ":00," << day << "\n";
		file.close();



	}

void admin:: showmenu() {
		cout << "Press 1 to view animals \t Press 2 to view available animals \n Press 3 to view animal detail \t Press 4 to view schedule \n";
		cout << "Press 5 to add customer \t Press 6 to reserve share \n Press 7 to view customer details \t press 8 to add salesman \n press 9 to make schedule \n press 10 to add animal \n";

	}
	int admin:: check_login(int id, int pass) {
		ifstream file;
		file.open("admin.txt");
		string line;

		while (getline(file, line))
		{


			vector <string> tokens;

			// stringstream class object
			stringstream s(line);

			string intermediate;
			int i = 0;
			// Tokenizing w.r.t. space ' '
			while (getline(s, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}
			if (atoi(tokens[0].c_str()) == id)
			{
				if (atoi(tokens[1].c_str()) == pass)
				{
					return 1;
				}
			}




		}

		return 0;
	}
