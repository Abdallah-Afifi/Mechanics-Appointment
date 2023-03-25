#ifndef MECHANIC_H
#define MECHANIC_H


#include "person.h"
#include<iostream>
#include<string>
using namespace std;


class mechanic : public person
{
private:
    int counter;
    Appointment appointments[10];
public:
    mechanic();
    mechanic(string name, long long id, int age);
    bool isAvailable(Appointment appt) const;
    void addAppointment(Appointment appt);
    int getCounter() const;
    void setCounter(int count);
    Appointment getApp(int i);


};


#endif