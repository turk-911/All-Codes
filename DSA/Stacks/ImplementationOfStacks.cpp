#include<iostream>
using namespace std;
class Stack{
    public: 
        int top;
        int* arr;
        int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size]; 
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overflow error" << endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "Stack underflow error" << endl;
        }
    }
    int peek(){
        if(top >= 0 && top <= size){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
};
int main(){
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(56);
    st.push(34);
    st.push(78);
    cout << "Trying to push 6th element into stack of size 5: ";
    st.push(90);
    // cout << "Implementation of stack using array successful" << endl;
    // cout << "Size of stack is: " << st.size() << endl;
    cout << "Top element of stack is: " << st.peek() << endl;
    st.pop();
    cout << "Top element of stack after popping is: " << st.peek() << endl;
    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Implementation of stack using array successful" << endl;
    }
    return 0;
}