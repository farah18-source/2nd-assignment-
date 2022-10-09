//
//  Mechanic.h
//  assignment 2
//
//  Created by Farah Mahmoud on 05/10/2022.
//

#ifndef Mechanic_h
#define Mechanic_h
#include "Person.h"

class Mechanic: public Person
{
private:
    int counter;
    int actual;
    Appointment* apps;
public:
    Mechanic();
    Mechanic(int count);
    ~Mechanic();
    int getCounter();
    bool isAvailable(Appointment x);
    void addAppointment(Appointment p);


};

Mechanic::Mechanic()
{
    //assumption that no. of appointment is 10
    counter = 10;
    actual =0;
    apps = new Appointment[counter];
}

Mechanic::Mechanic(int count)
{
    counter = count;
    actual =0;
    apps = new Appointment[counter];
}

Mechanic::~Mechanic()
{
    delete[] apps;

}

int Mechanic::getCounter()
{
    return counter;
}

bool Mechanic::isAvailable(Appointment x)
{
    if(actual == counter)
        return false;
    
    bool free = true;
    for (int i = 0; i < counter; i++)
    {
        if (apps[i] == x)
        {
            free = false;
            break;
        }
    }
    return free;
}
void Mechanic::addAppointment(Appointment p)
{
    apps[actual++] = p;
}


#endif 
