#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &InputStack, int element){
    if(InputStack.empty()){
        InputStack.push(element);
        return;
    }
    int num = InputStack.top();
    InputStack.pop();
    insertAtBottom(InputStack, element);
    InputStack.push(num);
}
void reverse(stack<int> &myStack){
    if(myStack.empty()){
        return;
    }
    int num = myStack.top();
    myStack.pop();
    reverse(myStack);
    insertAtBottom(myStack, num);
}
void sortedInsert(stack<int> &s, int num){
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(n);
}
void sortAStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int n = s.top();
    s.pop();
    sortAStack(s);
    sortedInsert(s, n);
}
int main(){
    stack<int> inputStack;
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    inputStack.push(6);
    // reverse(inputStack);
    for(int i = 0; i < 5; i++){
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;
    int element = 7;
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    inputStack.push(6);
    insertAtBottom(inputStack, element);
    for(int i = 0; i < 6; i++){
        cout << inputStack.top() << endl;
        inputStack.pop();
    }
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    inputStack.push(6);
    insertAtBottom(inputStack, element);
    // reverse(inputStack);
    sortAStack(inputStack);
    cout << endl << endl;
    for (int i = 0; i < 6; i++){
        cout << inputStack.top() << endl;
        inputStack.pop();
    }
    return 0;
}