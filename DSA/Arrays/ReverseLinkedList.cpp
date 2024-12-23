#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> next = NULL;
        this -> data = d;
    }
};

void print(Node* head){
    while(head -> next != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    head -> next = temp;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
