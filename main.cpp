//
//  main.cpp
//  assignment 2
//
//  Created by Farah Mahmoud on 05/10/2022.
//

#include <iostream>
#include "Customer.h"
#include "Person.h"
#include "Mechanic.h"
#include "Queue.h"
void display(Customer c, Mechanic* ms,int size)
{
    if(c.getMechanicID() == "not free")
    {
        cout<<c.getName()<<" has not matched an appointment today at this time "<<endl;
        return;
    }
   
    string m_name;
    for(int i=0;i<size;i++)
    {
        if(ms[i].getId() == c.getMechanicID())
        {
            m_name = ms[i].getName();
            break;
        }
        
    }
}




template <typename T>
void swap2(T& x, T& y)
{
    T temp = x;
    x=y;
    y=temp;
}
void sort_customers(Customer* arr,int size)
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
         if(arr[i]<arr[j])
             swap2(arr[i],arr[j]);
        }
    
    
}
int main()
{
    
    //no. of mechanics;
    // for each mechanic:name, id
    // add the data into an array
    int n_mech;
    cout<<"What is the number of mechanics in the workshop today"<<endl;
    cin >> n_mech;
    Mechanic* mechanics = new Mechanic[n_mech];
    string sdata;
    for(int i=0;i<n_mech;i++)
    {
        cout<<"What is the name for"<<(i+1)<<endl;
        cin>>sdata;
        mechanics[i].setName(sdata);
        
        cout<<"What is the id for "<<(i+1)<<endl;
        cin>>sdata;
        mechanics[i].setId(sdata);
    
       
    }
    //get customer data and number of customer
    // appointment hour and minute
    
    int n_cust;
    cout<<"What is the number of customer coming to the workshop today"<<endl;
    cin >> n_cust;
    Customer* customers = new Customer[n_cust];
    Appointment p;
    for(int i=0;i<n_cust;i++)
    {
        cout<<"What is the name for "<<(i+1)<<endl;
        cin>>sdata;
        customers[i].setName(sdata);
        
        
        cout<<"What is the appointment hour for "<<(i+1)<<endl;
        cin>>p.hour;
        
        cout<<"What is the appointment minutes for "<<(i+1)<<endl;
        cin>>p.minute;
        customers[i].setAppointment(p);
    }
    
    // main logic
    
    int m_index = 0;
    for(int i=0;i<n_cust;i++)
    {
        int loops=0;
        while(loops<n_mech && (!mechanics[m_index].isAvailable(customers[i].getAppointment())))
        {
            m_index=(m_index+1)%n_mech;
            loops++;
        }
        if(loops>n_mech)
        {
            //no free mechanic in this appointment
            customers[i].setMechanicID("not free");
        }
        else
        {
            mechanics[m_index].addAppointment(customers[i].getAppointment());
            customers[i].setMechanicID(mechanics[m_index].getId());
            m_index=(m_index+1)%n_mech;
        }
        
    }
    
    
 
    sort_customers(customers, n_cust);
   
    Queue<Customer> ordered_customers;
    for(int i=0;i<n_cust;i++)
        ordered_customers.push(customers[i]);
    
    while(!ordered_customers.empty())
    {
        Customer c = ordered_customers.pop();
        display(c,mechanics,n_mech);
    }


return 0;
}

