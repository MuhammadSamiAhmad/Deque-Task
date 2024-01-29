#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
        Node(int x){
        data=x;
        next=prev=NULL;
    }
};