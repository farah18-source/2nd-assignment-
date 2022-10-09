//
//  Person.h
//  assignment 2
//
//  Created by Farah Mahmoud on 05/10/2022.
//

#ifndef Person_h
#define Person_h
#include <iostream>
#include <string>
using namespace std;
struct Appointment
{
    int hour;
    int minute;
    string represent() {
        //24 hour notation
        return to_string(hour) + ":" + to_string(minute);
    }
    bool operator>(const Appointment& x) {
       if (this->hour > x.hour)
            return true;
        else if (this->hour < x.hour)
            return false;
        else
            if (this->minute > x.minute)
                return true;
        else
                return false;
      
    }
    bool operator<(const Appointment& x) {
        return ((this->hour < x.hour) || (this->hour == x.hour && this->minute < x.minute));
    }
    bool operator==(const Appointment& x) {
        return (this->hour == x.hour && this->minute == x.minute);
    }

};
class Person
{
private:
    string name;
    string id;
    int age;
    
public:
    Person();
    Person(string name, string id, int age);
   

    string getName();
    string getId();
    int getAge();
    void setName(string name);
    void setId(string id);
    void setAge(int age);
    void printInfo();



};

void Person::printInfo()
{
    cout << "name: " << name << ", age: " << age << ", id: " << id <<endl;
}

    Person::Person()
{
    name = "";
    age = 0;
    id = "";

}
Person::Person(string x, string y, int z) {
    x = name;
    y = id;
    z = age;
}


string Person::getName()
{
    return name;
}
string Person::getId()
{
    return id;
}
int Person::getAge()
{
    return age;
}
void Person::setName(string name)
{
    this->name = name;
}
void Person::setId(string id)
{
    this->id = id;
}
void Person::setAge(int age)
{
    this->age = age;
}

#endif
