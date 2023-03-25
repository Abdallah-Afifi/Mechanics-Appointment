#include "person.h"
#include<iostream>
#include<string>
using namespace std;


person::person() {
	name = "";
	age = 0;
	id = 0;
};

person::person(string name, long long id, int age)
{
	this->name = name;
	this->age = age;
	this->id = id;
}

void person::setName(string name) {
	this->name = name;
};
void person::setAge(int age) {
	this->age = age;
};
void person::setId(long long id) {
	this->id = id;
};
string person::getName()const {
	return name;
};
int person::getAge()const {
	return age;
};
long long person::getId()const {
	return id;
};
void person::printInfo()const {
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Age: " << age << endl;
};

	