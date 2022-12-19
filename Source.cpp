#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//interfaces
class menu {
public:
virtual void showmenu() = 0;

};

class login {
public:
virtual int check_login(int id , int pass ) = 0;
};

class serial {

public:
virtual void serialize(ofstream &obj) = 0;
virtual void deserialize(ifstream& obj) = 0;
};


//classes
class Animal :public serial {
private:
int id;
int price;
public:

Animal(int id, int price) { this->id = id;  this->price = price; }
int getid() { return this->id; }
int getprice() { return this->price; }
static void printAnimal(int id, int type, int price, int status, int shares, int slaughterstatus)
{
cout << "Animal id:" << id << "\n" << "Type:" << type << "\n";
cout << "Price" << price << "\n";
if (status == 0) { cout << "Available : Yes\n "; }
else if (status == 1) { cout << "Available :Np\n "; }
cout << "Shares :" << shares << "\n";
//0 for not slaughtered// 1 for delivered // 2 for slaughtered // 3 for slaughtered but not delivered // 4  distributed among poors
if (slaughterstatus==1) {
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
static int getprice(int id ) {

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
void serialize(ofstream &obj) {}
void deserialize(ifstream& obj) {};
static void decreaseAnimalshare(int animal_id, int newshares) {

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

fileout << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << "0" << "," << (atoi(tokens[4].c_str()) - newshares) << "," << tokens[5] << "\n";
}
else
{
fileout << fileline[i] << "\n";
}

}

}
static int calculatetotal(int shares, int price) {
return shares * price;
}
	
~Animal() {}
};




class cow : public Animal {
private:
	
		
public:
cow(int id , int price ):Animal( id ,price) {}
		
void serialize(ofstream &out ) {

out << this->getid() << "," << "2" << "," << this->getprice() << "," << "0" << "," << "7" << "," << "0" << "\n";
}
void deserialize(ifstream &in) {

}
};

class goat : public Animal {

private:

public:
goat(int id, int price) :Animal(id, price) {}

void serialize(ofstream& out) {

out << this->getid() << "," << "1" << "," << this->getprice() << "," << "0" << "," << "1" << "," << "0" << "\n";
}
void deserialize(ifstream& in) {

}


};


class camel : public Animal {
private:

public:
camel(int id, int price) :Animal(id, price) {}

void serialize(ofstream& out) {

out << this->getid() << "," << "2" << "," << this->getprice() << "," << "0" << "," << "7" << "," << "0" << "\n";
}
void deserialize(ifstream& in) {

}


};

	
Animal* getinstance(int id, int price, int type) {
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



class user :public menu, public login {

public:

int id;
user(int id) { this->id = id; }

virtual void showmenu() {};
virtual int check_login(int id, int pass) { return id; }


};
	
class customer :public serial {
private:
int id;
public:


};


class salesman:public user {

private:

int emp_id;

public:

salesman(int b):user(id) {

this->emp_id = b;
};

void view_animals() {

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

void view_available() {

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

void view_detail(int id)
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



void view_schedule(int animal_id)
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
void add_customer(int id, string name)
{

fstream file;
file.open("customer.txt", ios::app);

file << id << "," << name << "\n";
file.close();


}

static int check_login(int id, int pass) {
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
void reserve_share(int animal_id, int cust_id, int numberofshares)
{

fstream file;

Animal::decreaseAnimalshare(animal_id, numberofshares);
			
file.open("shares.txt", ios::app);

file << animal_id << "," << cust_id << "," << numberofshares << "\n";

file.close();
}

void view_customer_details(int cust_id) {

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
	id.push_back (atoi(tokens[0].c_str())) ;
	cout << "Animal id " << tokens[0] << "  " << " Shares: " << tokens[2] <<"\n";
shares.push_back ( atoi(tokens[2].c_str()) ) ;
count++;
}
			    


}

int totalamount = 0;
for (int i = 0; i < count; i++)
{
				
int price = Animal::getprice(id[i]);
totalamount = totalamount+ Animal:: calculatetotal(shares[i], price);

}
cout << "Total amount :" << totalamount << "\n";
}
static 	void showmenu() {
cout << "Press 1 to view animals \n Press 2 to view available animals \n Press 3 to view animal detail \n Press 4 to view schedule \n";
cout << "Press 5 to add customer \n Press 6 to reserve share \n Press 7 to view customer details ";
	
}


void change_status(int animal_id, int newstatus) {
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

fileout << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << "0" << "," << tokens[4] <<"," << newstatus << "\n";
}
else
{
fileout << fileline[i] << "\n";
}

} 
}

};


class admin :public user, public salesman {

private:
int emp_no;

public:

// admin() {};

admin(int id):salesman (id) ,user(id) {
emp_no = id;
}

void add_animal(int id, int type, int price) { //animal  obj.add()


Animal* a = getinstance(id, price,type);
ofstream obj;
			
obj.open("animal.txt", ios_base::app);
a->serialize( obj);
			

}
void add_salesman(int id, int password) {

fstream file;
file.open("salesman.txt", ios::app);

file << id << "," << password << "\n";
file.close();


}

void make_schedule(int animal_id) {

fstream file;
file.open("schedule.txt", ios::app);
int schedule = rand() % 24;
int day = rand() % 3;
file << animal_id << "," << schedule << ":00," << day << "\n";
file.close();



}
static void showmenu() {
cout << "Press 1 to view animals \t Press 2 to view available animals \n Press 3 to view animal detail \t Press 4 to view schedule \n";
cout << "Press 5 to add customer \t Press 6 to reserve share \n Press 7 to view customer details \t press 8 to add salesman \n press 9 to make schedule \n press 10 to add animal \n";

}
static int check_login(int id, int pass) {
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
};





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
cout << "Type exit to close";
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



