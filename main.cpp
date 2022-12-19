
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include"user.h"
#include "Salesman.h"
#include"animal.h"
#include "Admin.h"
using namespace std;


//ui
int main() {

	string temp;
	//cout << " Welcome to Qurbani management system \n";
	//cout << " For Admin enter 1  , For salesman enter 2 \n";
	int id = 0, pass = 0; int token = 0; int animal_id = 0, cust_id = 0, cust_pass = 0;
	string cust_name;
	int shares = 0;
	int check = 0;
	int type = 0;
	int price = 0;
	while (temp != "exit ") {
	mainloop:
		cout << " Welcome to Qurbani management system \n";
		cout << " For Admin enter 1  , For salesman enter 2 \n";
		cout << "Type exit to close \n";
		cin >> temp;
		if (temp == "exit") {
			return 0;
		}


		if (atoi(temp.c_str()) == 1)
		{
			cout << "Enter id , password \n";
			cin >> id >> pass;
			if (admin::check_login(id, pass) == 0) {
				cout << "login unsuccessful try again ";
				goto mainloop;
			}

			else if (admin::check_login(id, pass) == 1) {

				cout << "Login successful \n";
				admin a(id);
			adminloop:
				cout << " Type logout to logout\n";
				admin::showmenu();



				/*cout << "Press 1 to view animals \n Press 2 to view available animals \n Press 3 to view animal detail \n Press 4 to view schedule \n";
				cout << "Press 5 to add customer \n Press 6 to reserve share \n Press 7 to view customer details ";*/
			adminloop2:
				cin >> token;
				if (token == 1) {
					a.view_animals();
				}
				else if (token == 2) {
					a.view_available();
				}
				else if (token == 3) {
					cout << "enter animal id \n";
					cin >> animal_id;
					a.view_detail(animal_id);
				}
				else if (token == 4) {
					cout << "enter animal id \n";
					cin >> animal_id;
					a.view_schedule(animal_id);
				}
				else if (token == 5) {
					cout << "enter customer id \n";
					cin >> cust_id;
					cout << "enter customer pass\n";
					cin >> cust_name;
					a.add_customer(cust_id, cust_name);
				}
				else if (token == 6) {
					cout << "Enter Animal id \n";
					cin >> animal_id;
					cout << "enter customer id \n";
					cin >> cust_id;
					cout << "enter number of shares \n";
					cin >> cust_name;
					a.reserve_share(animal_id, cust_id, shares);


				}
				else if (token == 7) {
					cout << "enter customer id \n";
					cin >> cust_id;
					a.view_customer_details(cust_id);

				}
				else if (token == 8) {
					cout << "Enter salesman id \n";
					cin >> cust_id;
					cout << "enter salesman pass \n";
					cin >> cust_pass;
					a.add_salesman(cust_id, cust_pass);

				}
				else if (token == 9) {
					cout << "Enter animal id \n";
					cin >> animal_id;
					a.make_schedule(animal_id);

				}
				else if (token == 10) {
					cout << "Enter ID \n";
					cin >> animal_id;
					cout << "Enter price \n";
					cin >> price;
					cout << " Enter type.. 1 for goat , 2 for cow , 3 for goat \n";
					cin >> type;
					a.add_animal(animal_id, type, price);


				}
				if (token < 0 || token>10) {
					cout << "Wrong option \n";
					goto adminloop2;
				}

				Animal::removefromavailable();

			reenter:
				cout << "Do you wanna continue or logout? \n ";
				cin >> temp;
				if (temp == "logout") { goto mainloop; }
				if (temp == "continue") { goto adminloop; }
				if (temp != "logout" || temp != "continue")
				{
					cout << "Wrong option";
					goto reenter;
				}

			}



		}

		else	if (atoi(temp.c_str()) == 2)
		{
			cout << "Enter id , password \n";
			cin >> id, pass;

			if (salesman::check_login(id, pass) == 0) {
				cout << "login unsuccessful try again ";
				goto mainloop;
			}

			if (salesman::check_login(id, pass) == 1) {

				cout << "Login successful \n ";
			salesmanloop:

				salesman::showmenu();

				salesman a(id);

			salesmanloop2:
				cin >> token;
				if (token == 1) {
					a.view_animals();
				}
				else if (token == 2) {
					a.view_available();
				}
				else if (token == 3) {
					cout << "enter animal id \n";
					cin >> animal_id;
					a.view_detail(animal_id);
				}
				else if (token == 4) {
					cout << "enter animal id \n";
					cin >> animal_id;
					a.view_schedule(animal_id);
				}
				else if (token == 5) {
					cout << "enter customer id \n";
					cin >> cust_id;
					cout << "enter customer pass\n";
					cin >> cust_name;
					a.add_customer(cust_id, cust_name);
				}
				else if (token == 6) {
					cout << "Enter Animal id";
					cin >> animal_id;
					cout << "enter customer id \n";
					cin >> cust_id;
					cout << "enter number of shares ";
					cin >> cust_name;
					a.reserve_share(animal_id, cust_id, shares);


				}
				else if (token == 7) {
					cout << "enter customer id \n";
					cin >> cust_id;
					a.view_customer_details(cust_id);

				}
				if (token < 0 || token>10) {
					cout << "Wrong option \n";
					goto salesmanloop2;
				}
				Animal::removefromavailable();
			reenter2:
				cout << "Do you wanna continue or logout? \n ";
				cin >> temp;
				if (temp == "logout") { goto mainloop; }
				if (temp == "continue") { goto salesmanloop; }
				if (temp != "logout" || temp != "continue")
				{
					cout << "Wrong option";
					goto reenter2;
				}


			}

		}






	}

}
