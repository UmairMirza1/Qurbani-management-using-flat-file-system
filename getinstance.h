#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "interfaces.h"
#include "animal.h"
using namespace std;

class cow : public Animal {
private:


public:
	cow(int id, int price) :Animal(id, price) {}

	void serialize(ofstream& out) {

		out << this->getid() << "," << "2" << "," << this->getprice() << "," << "0" << "," << "7" << "," << "0" << "\n";
	}
	void deserialize(ifstream& in) {

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


static Animal* getinstance(int id, int price, int type) {
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