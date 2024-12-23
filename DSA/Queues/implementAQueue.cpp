#include<iostream>
using namespace std;
class Queue{
    int* arr;
    int front;
    int rear;
    int size;

    Queue(){
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        return false;
    }
    void enqueue(int data){
        /*This function enqueues or inserts an element in the queue*/
        if(rear == size){
            cout << "Queue is full " << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    int dequeue(){
        /*This function pops the value from queue*/
        if(front == rear){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }     
    }
    int front(){
        if(front == rear){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
};