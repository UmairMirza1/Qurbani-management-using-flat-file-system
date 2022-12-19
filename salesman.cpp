#include "salesman.h"



	

void salesman ::view_animals() {

	string line;
	fstream myfile("animal.txt");
	if (myfile.is_open())
	{

		while (getline(myfile, line))
		{


			vector <string> tokens;

			// stringstream class object
			stringstream s(line);

			string intermediate;

			// Tokenizing w.r.t. space ' '
			while (getline(s, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}
			Animal::printAnimal(atoi(tokens[0].c_str()), atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), atoi(tokens[3].c_str()), atoi(tokens[4].c_str()), atoi(tokens[5].c_str()));
		}
	}

	else cout << "Unable to open file";

}

void salesman ::view_available() {

	string line;
	fstream myfile("animal.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{


			vector <string> tokens;

			// stringstream class object
			stringstream s(line);

			string intermediate;

			// Tokenizing w.r.t. space ' '
			while (getline(s, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}
			string a = "0";
			// show only available
			if (tokens[3] == a) {

				cout << line << "\n";

			}

		}





		myfile.close();
	}

	else cout << "Unable to open file";


}

void salesman:: view_detail(int id)
{
	string line;
	fstream myfile("animal.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{


			vector <string> tokens;

			// stringstream class object
			stringstream s(line);

			string intermediate;

			// Tokenizing w.r.t. space ' '
			while (getline(s, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}

			// show details

			if (atoi(tokens[0].c_str()) == id) {

				cout << "Animal Id: " << tokens[0] << "\n";
				if (atoi(tokens[1].c_str()) == 1) { cout << "Type: Goat \n"; }
				else if (atoi(tokens[1].c_str()) == 2) { cout << "Type: Cow \n"; }
				else if (atoi(tokens[1].c_str()) == 3) { cout << "Type: Camel \n"; }
				cout << "Price: " << tokens[2] << "\n";

			}
			else {}

		}





		myfile.close();
	}

	else cout << "Unable to open file";






}



void salesman ::view_schedule(int animal_id)
{

	string line;
	fstream myfile("schedule.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{


			vector <string> tokens;

			// stringstream class object
			stringstream s(line);

			string intermediate;

			// Tokenizing w.r.t. space ' '
			while (getline(s, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}

			// show details

			if (atoi(tokens[0].c_str()) == animal_id) {

				cout << "Animal Id: " << tokens[0] << "\n";
				cout << "Eid Day:" << tokens[2] << "\n";
				cout << "Time :" << tokens[1] << "\n";

			}
			else {}

		}





	}
}
void salesman ::add_customer(int id, string name)
{

	fstream file;
	file.open("customer.txt", ios::app);

	file << id << "," << name << "\n";
	file.close();


}

	int salesman:: check_login(int id, int pass) {
	ifstream file;
	file.open("salesman.txt");
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
void salesman::reserve_share(int animal_id, int cust_id, int numberofshares)
{

	fstream file;

	if (!(Animal::decreaseAnimalshare(animal_id, numberofshares))) { cout << "Not enough shares\n"; };

	file.open("shares.txt", ios::app);

	file << animal_id << "," << cust_id << "," << numberofshares << "\n";

	file.close();
}

void salesman::salesman::view_customer_details(int cust_id) {

	ifstream file("shares.txt");
	vector <int> shares; vector <int> id;
	string line;

	int count = 0;
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

		if (atoi(tokens[1].c_str()) == cust_id)
		{
			id.push_back(atoi(tokens[0].c_str()));
			cout << "Animal id " << tokens[0] << "  " << " Shares: " << tokens[2] << "\n";
			shares.push_back(atoi(tokens[2].c_str()));
			count++;
		}



	}

	int totalamount = 0;
	for (int i = 0; i < count; i++)
	{

		int price = Animal::getprice(id[i]);
		totalamount = totalamount + Animal::calculatetotal(shares[i], price);

	}
	cout << "Total amount :" << totalamount << "\n";
}
	void salesman::showmenu() {
	cout << "Press 1 to view animals \n Press 2 to view available animals \n Press 3 to view animal detail \n Press 4 to view schedule \n";
	cout << "Press 5 to add customer \n Press 6 to reserve share \n Press 7 to view customer details ";

}


void salesman::change_status(int animal_id, int newstatus) {
	//0 for not slaughtered// 1 for delivered // 2 for slaughtered // 3 for slaughtered but not delivered // 4  distributed among poors

	ifstream filein("animal.txt"); //File to read from

	vector <string> fileline;
	string temp;
	int count = 0;
	while (filein >> temp) {

		fileline.push_back(temp);
		count++;
	}
	filein.close();

	ofstream fileout("animal.txt", ios::trunc);



	for (int i = 0; i < count; i++) {

		vector <string> tokens;

		// stringstream class object
		stringstream s(fileline[i]);

		string intermediate;

		// Tokenizing w.r.t. space ','
		while (getline(s, intermediate, ','))
		{
			tokens.push_back(intermediate);
		}
		if (atoi(tokens[0].c_str()) == animal_id) {

			fileout << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << "0" << "," << tokens[4] << "," << newstatus << "\n";
		}
		else
		{
			fileout << fileline[i] << "\n";
		}

	}
}
