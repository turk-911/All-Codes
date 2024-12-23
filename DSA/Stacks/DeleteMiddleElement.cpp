#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &inputStack, int count, int size){
    if(count == size / 2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, size);
    inputStack.push(num);
}
void deleteMiddleElement(stack<int> &inputStack, int n){
    int count = 0;
    solve(inputStack, count, n);
}
int main(){
    stack<int> inputStack;
    inputStack.push(4);
    inputStack.push(3);    
    inputStack.push(2);
    inputStack.push(1);
    inputStack.push(0);
    inputStack.push(5);
    deleteMiddleElement(inputStack, 6);

    for(int i = 0; i < 5; i++){
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
}