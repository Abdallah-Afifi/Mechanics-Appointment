#ifndef CUSTOMER_H
#define CUSTOMER_H



#include "person.h"
#include<iostream>
#include<string>
using namespace std;

class customer : public person
{
private:
    long long mechanicId;
    Appointment appointment;

public:
    customer();
    customer(string name, long long id, int age, long long mechanicId, const Appointment& appointment);
    void setMechanicId(long long mechanicId);
    void setAppointment(const Appointment& appointment);
    long long getMechanicId();
    Appointment getAppointment() const;
    void printInfo() const override;
    bool operator<(const customer& other) const;
    bool operator>(const customer& other) const;
    bool operator==(const customer& other) const;
};

#endif