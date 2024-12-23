#include<iostream>
#include<stack>
using namespace std;
int main(){
    // creation of stack
    stack <int> s;
    s.push(2);
    s.push(8);
    cout << "Size of stack is: " << s.size() << endl;
    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "Stack is not empty " << endl;
    }
    cout << "Printing the top element of the stack: " << s.top() << endl;
    cout << "Size of stack before popping : " << s.size() << endl;
    cout << "Popping the top element of the stack and then checking the top element of the stack: " << endl;
    s.pop();
    cout << "Printing the top element of the stack: " << s.top() << endl;
    cout << "Size of stack after popping: " << s.size() << endl;
    cout << "----Popping the element remaining in stack----" << endl;
    s.pop();
    cout << "Size of stack is: " << s.size() << endl;
    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "Stack is not empty " << endl;
    }
    return 0;

}