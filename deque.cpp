#include "deque.h"
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
My_Deque::My_Deque(){
    front=rear=NULL;
    size=0;
}
My_Deque::~My_Deque(){
     rear = NULL;
    // traverse the doubly linked list
    while (front != NULL)
    {
        Node *temp = front;
        // delete all the prev pointers
        front->prev = NULL;
        front = front->next;
        // Deallocate the memory taken by temp
        delete (temp);
    }
    // Set size as 0
    size = 0;
}
int My_Deque:: end(){
        // If there are no elements in deque, return -1
    if (front==NULL)
        return -1;
    return rear->data;
}
int My_Deque:: begin(){
       // If there are no elements in deque, return -1
    if (front==NULL)
        return -1;
    return front->data;
}
int My_Deque:: pop_back(){
       // If there are no elements in deque, we cannot delete 
    // anything
    if (front==NULL)
        return -1;
    // Delete the back node and update the ‘tail’ pointer as  
     // well as update the links
    else
    {
        Node* temp = rear;
        int x=temp->data;
        rear = rear->prev;
        // If only one element was present
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);
        // Decrease ‘size’ by 1
        size--;
        return x;
    }
}
int My_Deque:: pop_front(){
    // If there are no elements in deque, we cannot delete 
    // anything
    if (front==NULL)
        return -1;
    // Delete the front node and update the ‘head’ pointer as  
     // well as update the links 
    else
    {
        Node* temp = front;
        int x=temp->data;
        front = front->next;
        // If only one element was present
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);
        // Decrease ‘size’ by 1
        size--;
        return x;
    }
}
int My_Deque:: get_size(){
    return size;
}
void My_Deque::push_back(int element){
Node* newNode = new Node(element);
    // if newNode is Null then no nodes can be created as 
     // memory is full
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If deque is empty
        if (rear == NULL)
            front = rear = newNode;
        // Inserts an element at the end of the list
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        // Increase size by 1
        size++;
    }
}
void My_Deque::push_front(int element){
     Node* newNode = new Node(element);
    // if newNode is Null then no nodes can be created as 
     // memory is full 
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If deque is empty
        if (front == NULL)
            rear = front = newNode;
        // Inserts an element at the beginning of the list
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        // Increase size by 1
        size++;
    }
}
void My_Deque::print(){
    for(Node* cur{front}; cur; cur =cur->next )
        cout << cur->data << " ";
    cout << "\n";
}
void My_Deque::clear(){
         rear = NULL;
    // traverse the doubly linked list
    while (front != NULL)
    {
        Node *temp = front;
        // delete all the prev pointers
        front->prev = NULL;
        front = front->next;
        // Deallocate the memory taken by temp
        delete (temp);
    }
    // Set size as 0
    size = 0;
}
std::vector<int> My_Deque::toVector(){
    vector<int> v;
    while (!front ==NULL)
    {
        v.push_back(begin());
        pop_front();
    }
    for (int i = 0; i < v.size(); i++)
    {
        push_back(v.at(i));
    }
    return v;
    
}