#pragma once
#include <iostream>
#include <fstream>


class menu {
public:
	virtual void showmenu() = 0;

};

class login {
public:
	virtual int check_login(int id, int pass) = 0;
};

class serial {

public:
	virtual void serialize(std::ofstream& obj) = 0;
	virtual void deserialize(std::ifstream& obj) = 0;
};