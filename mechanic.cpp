#include "mechanic.h"


mechanic::mechanic() : person(), counter(0) {
    for (int i = 0; i < 10; i++) {
        appointments[i].hours = 0;
        appointments[i].mins = 0;
    }
}

mechanic::mechanic(string name, long long id, int age): person(name, id, age)
{
    this->counter = 0;
    for (int i = 0; i < 10; i++) {
        appointments[i].hours = 0;
        appointments[i].mins = 0;
    }

}


int mechanic::getCounter() const {
    return counter;
}

void mechanic::setCounter(int count) {
    this->counter = count;
}

bool mechanic::isAvailable(Appointment appt) const {
    for (int i = 0; i < counter; i++) {
        if (appointments[i].hours == appt.hours && appointments[i].mins == appt.mins) {
            return false; // because the mechanic is booked at this time
        }
    }
    return true; // mechanic will be available at this time
}

void mechanic::addAppointment(Appointment appt) {
    appointments[counter++] = appt;
}

Appointment mechanic::getApp(int i) {
    return appointments[i];
}

