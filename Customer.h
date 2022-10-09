//
//  Customer.h
//  assignment 2
//
//  Created by Farah Mahmoud on 05/10/2022.
//

#ifndef Customer_h
#define Customer_h
#include "Person.h"

class Customer: public Person
{
private:
    string mechanicID;
    Appointment appointment;
public:
    Customer();
    Customer(string mechanicID,Appointment p);
  

    string getMechanicID() ;
    Appointment getAppointment() ;
    void setMechanicID(string MID);
    void setAppointment(Appointment p);
    bool operator>(const Customer& other);
    bool operator<(const Customer& other);
    bool operator==(const Customer& other);


};

Customer::Customer()
{
    mechanicID = "";
    appointment = { 0,0 };
}

Customer::Customer(string mechanicID, Appointment p)
{
    this->mechanicID = mechanicID;
    this->appointment = p;
}



string Customer::getMechanicID()
{
    return this->mechanicID;
}

Appointment Customer::getAppointment()
{
    return this->appointment;
}

void Customer::setMechanicID(string MID)
{
    this->mechanicID = MID;
}

void Customer::setAppointment(Appointment p)
{
    this->appointment = p;
}

bool Customer::operator>(const Customer& other)
{
    return this->appointment > other.appointment;
}

bool Customer::operator<(const Customer& other)
{
    return this->appointment < other.appointment;
}

bool Customer::operator==(const Customer& other)
{
    return this->appointment == other.appointment;
}

#endif 
