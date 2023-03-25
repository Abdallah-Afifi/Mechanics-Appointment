#ifndef PERSON_H
#define PERSON_H



#include<iostream>
#include<string>
using namespace std;


struct Appointment {
	int hours;
	int mins;
public:
	Appointment(int h, int m)
	{
		hours = h;
		mins = m;
	}
	Appointment()
	{
		hours = 0;
		mins = 0;
	}
	void Print() {
		cout << hours << " " << mins << endl;
	}
};

class person
{
	protected:
		string name;
		long long id;
		int age;

	public:
		person();
		person(string name, long long id, int age);
		void setName(string name);
		void setAge(int age);
		void setId(long long id); 
		string getName()const;
		int getAge()const;
		long long getId()const;
		virtual void printInfo()const;

};

#endif 