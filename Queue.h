//
//  Queue.h
//  assignment 2
//
//  Created by Farah Mahmoud on 05/10/2022.
//

#ifndef Queue_h
#define Queue_h
#include <vector>
#include <iostream>
template<class T>
class Queue
{
public:
    Queue();
    ~Queue();
    void push(T item);
    T pop();
    void display();
    bool empty();
    
    
private:
    vector<T> container;
};

template<class T>
bool Queue<T>::empty()
{
    return container.empty();
}
template<class T>
Queue<T>::Queue()
{
    
}

template<class T>
Queue<T>::~Queue()
{
    container.clear();
}
template<class T>
void Queue<T>::push(T item)
{
    container.push_back(item);
}
template<class T>
T Queue<T>::pop()
{
    
    if(!container.empty())
    {
        T popped = container.at(0);
        container.erase(container.begin());
        return popped;
    }
    cout<<"QUEUE is EMPTY"<<endl;
    return T();
    
}
template<class T>
void Queue<T>::display()
{
    for(int i=0;i<container.size();i++)
    {
        cout<<container.at(i)<<',';
    }
    cout<<endl;
}


#endif 
