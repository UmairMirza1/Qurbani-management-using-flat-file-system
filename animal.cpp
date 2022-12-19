#include "animal.h"

	 void Animal:: printAnimal(int id, int type, int price, int status, int shares, int slaughterstatus)
	{
		cout << "Animal id:" << id << "\n" << "Type:" << type << "\n";
		cout << "Price" << price << "\n";
		if (status == 0) { cout << "Available : Yes\n "; }
		else if (status == 1) { cout << "Available :Np\n "; }
		cout << "Shares :" << shares << "\n";
		//0 for not slaughtered// 1 for delivered // 2 for slaughtered // 3 for slaughtered but not delivered // 4  distributed among poors
		if (slaughterstatus == 1) {
			cout << "Status :Not slaughtered\n";
		}
		if (slaughterstatus == 2) {
			cout << "Status :slaughterstatus Delivered\n";

		}

		if (slaughterstatus == 3) {
			cout << "Status :slaughtered but not delivered\n";

		}

		if (slaughterstatus == 4) {

			cout << "Status :Distributed Among Poor\n";
		}

		cout << endl;

	}
	 int Animal::getprice(int id) {

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
				if (atoi(tokens[0].c_str()) == id)
				{
					return (atoi(tokens[2].c_str()));
				}
			}

		};
	}
	
	 bool Animal::decreaseAnimalshare(int animal_id, int newshares) {
		 bool flag = true;
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
				 if ((atoi(tokens[4].c_str()) - newshares) < 0) { flag = false; return flag; }
				 fileout << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << "0" << "," << (atoi(tokens[4].c_str()) - newshares) << "," << tokens[5] << "\n";
			 }
			 else
			 {
				 fileout << fileline[i] << "\n";
			 }

		 }
		 return flag;
	 }
	 int Animal::calculatetotal(int shares, int price) {
		return shares * price;
	}

	Animal * getinstance(int id, int price, int type) {
		 if (type == 1) {
			 Animal* a = new cow(id, price);
			 return a;
		 }

		 if (type == 2) {
			 Animal* a = new goat(id, price);
			 return a;
		 }

		 if (type == 3) {
			 Animal* a = new camel(id, price);
			 return a;
		 }

	 }

	bool Animal::duplicateid(int id) {
		bool flag = false;



		string line;
		ifstream myfile("schedule.txt");
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
				if (atoi(tokens[0].c_str()) == id) {
					flag = true;
					return flag;

				}
				else
				{
					return flag;
				}

			}

		}

	}

	void Animal::changeavailabe(int id) {

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
			if (atoi(tokens[0].c_str()) == id) {

				fileout << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << "1" << "," << tokens[4] << "," << tokens[5] << "\n";
			}
			else
			{
				fileout << fileline[i] << "\n";
			}

		}




	}

	 void Animal::removefromavailable() {

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
				if (atoi(tokens[4].c_str()) == 0) {


					Animal::changeavailabe(atoi(tokens[0].c_str()));
					return;



				}






			}
		}
	}



	cow::cow(int id, int price) :Animal(id, price) {}

	void cow::serialize(ofstream& out) {

		out << this->getid() << "," << "2" << "," << this->getprice() << "," << "0" << "," << "7" << "," << "0" << "\n";
	}
	void cow::deserialize(ifstream& in) {

	}


		goat::goat(int id, int price) :Animal(id, price) {}

		void goat::serialize(ofstream& out) {

			out << this->getid() << "," << "1" << "," << this->getprice() << "," << "0" << "," << "1" << "," << "0" << "\n";
		}
		void goat::deserialize(ifstream& in) {

		}





	
		camel ::camel(int id, int price) :Animal(id, price) {}

		void camel::serialize(ofstream& out) {

			out << this->getid() << "," << "2" << "," << this->getprice() << "," << "0" << "," << "7" << "," << "0" << "\n";
		}
		void camel::deserialize(ifstream& in) {

		}


