#include "customer.h"
#include <iostream>
#include<string>
using namespace std;


customer::customer() : mechanicId(0), appointment({ 0, 0 }) {}

customer::customer(string name, long long id, int age, long long mechanicId, const Appointment& appointment) : 
    person(name, id, age), mechanicId(mechanicId), appointment(appointment) {}

void customer::setMechanicId(long long mechanicId) {
    this->mechanicId = mechanicId;
}

void customer::setAppointment(const Appointment& appointment) {
    this->appointment = appointment;
}

long long customer::getMechanicId(){
    return mechanicId;
}

Appointment customer::getAppointment() const {
    return appointment;
}

void customer::printInfo() const {
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Mechanic ID: " << mechanicId << endl;
    cout << "Appointment Time: " << appointment.hours << ":" << appointment.mins << endl;
}

bool customer::operator<(const customer& other) const {
    if (appointment.hours < other.appointment.hours) {
        return true;
    }
    else if (appointment.hours == other.appointment.hours) {
        return appointment.mins < other.appointment.mins;
    }
    return false;
}

bool customer::operator>(const customer& other) const {
    if (appointment.hours > other.appointment.hours) {
        return true;
    }
    else if (appointment.hours == other.appointment.hours) {
        return appointment.mins > other.appointment.mins;
    }
    return false;
}

bool customer::operator==(const customer& other) const {
    return appointment.hours == other.appointment.hours && appointment.mins == other.appointment.mins;
}
