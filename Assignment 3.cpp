#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include "queuec.h"

using namespace std;

int main()
{
    // Read mechanics' data from file
    ifstream mechanicsFile("mechanics.txt");
    int numMechanics;
    int numAppointments;
    mechanicsFile >> numMechanics;
    mechanic* mechanics = new mechanic[numMechanics];
    for (int i = 0; i < numMechanics; i++) {
        string name;
        int age; long long id;
        mechanicsFile >> name >> id >> age >> numAppointments;
        mechanics[i] = mechanic(name, id, age);
        for (int j = 0; j < numAppointments; j++) {
            int hours, mins;
            mechanicsFile >> hours >> mins;
            mechanics[i].addAppointment(Appointment(hours, mins));

        }
    }

    mechanicsFile.close();



    // Read customers' data from file and insert into array
    ifstream customersFile("customers.txt");
    int numCustomers;
    customersFile >> numCustomers;
    customer* customers = new customer[numCustomers];
    for (int i = 0; i < numCustomers; i++) {
        string name;
        long long id;
        int age, hours, mins;
        customersFile >> name >> id >> age >> hours >> mins;
        customers[i] = customer(name, id, age, -1, Appointment(hours, mins));// initialize mechanicId to -1
    }
    customersFile.close();




    // Assign customers to mechanics and insert into queue
   

    Queue<customer> customerQueue(numCustomers);
    int x = 0;
    for (int i = 0; i < numCustomers; i++) {
                bool assigned = false;
                int mechanicIndex;
                for (int j = 0; j < numMechanics && !assigned && customers[i].getMechanicId() == -1; j++) {
                    if (mechanics[j].isAvailable(customers[i].getAppointment())) {
                        int mechanicIndex = i % numMechanics; // assign customer to mechanic in the correct order
                        mechanics[mechanicIndex].addAppointment(customers[i].getAppointment()); // add customer's appointment to mechanic's schedule
                        customers[i].setMechanicId(mechanicIndex); // assign customer to mechanic
                        assigned = true; 
                    }
                    
                }
        if (!assigned) {
            cout << "No mechanics available for customer " << customers[i].getId() << endl;
        }
    }
   

   // Print customers in order of appointments and their assigned mechanics
        for (int k = 0; k < numCustomers; k++)
        {
            for (int l = k; l < numCustomers; l++)
            {
                if (customers[k] > customers[l])
                {
                    customer c = customers[k];
                    customers[k] = customers[l];
                    customers[l] = c;
                }
            }
        }
        for (int m = 0; m < numCustomers; m++)
        {
            customerQueue.push(customers[m]);
        }
 
        
        for (int i = 0; i < numMechanics+1; i++) {
            int mechanicIndex = i % numMechanics; // assign customer to mechanic in the correct order
            cout << "Mr./Mrs. " << customerQueue.peek().getName() << " has an appointment at " << customerQueue.peek().getAppointment().hours << ":" << customerQueue.peek().getAppointment().mins << " with " << mechanics[mechanicIndex].getName() << "." << endl;
            customerQueue.pop();
        }


    // Free up memory allocated for arrays
    delete[] mechanics;
    delete[] customers;

    return 0;
} 