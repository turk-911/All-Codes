// doubly linked list just has difference in structure, it has 2 pointers in node, one for previous and one for next
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev; // used to store previous address
    Node* next; // used to store next address

    // constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    return;
}
int getLength(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count = count + 1;
        temp = temp -> next;
    }
    return count;
}
// inserting an element at head position
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}
void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    int count = 1;
    Node* temp = head;
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    (temp -> next) -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}
void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        (temp -> next) -> prev = NULL;
        temp -> next = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position - 1){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    cout << "The original doubly linked list is: ";
    print(head);
    int length = getLength(head);
    cout << "The length of the doubly linked list is: " << length << endl;
    cout << "Inserting another elementat the head of the doubly linked list: ";
    insertAtHead(head, 11);
    print(head);
    insertAtTail(tail, 12);
    cout << "Inserting an element at the end of Doubly linked list is: ";
    print(head);
    cout << "Inserting an element at any position in doubly linked list: ";
    insertAtPosition(head, tail, 2, 100);
    print(head);
    deleteNode(head, 3);
    cout << "New linked list: " ; 
    print(head);
    return 0;
}