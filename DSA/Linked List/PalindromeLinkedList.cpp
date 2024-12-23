#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
    }
} 
void insertAtHead(Node *&head, int d){
    // pass by reference because we do not want to create a copy
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&tail, Node *&head, int position, int d){
    // insertion at starting position
    if (position == 1){
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1; // we are at first node at the starting
    while (count < position - 1){
        temp = temp->next;
        count++;
    }
    // we also have to update the tail, insertion at the last position
    if (temp->next == NULL){
        insertAtTail(head, d);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void print(Node *&head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
