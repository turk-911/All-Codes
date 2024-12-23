/*Design a special stack which finds the minimum element in O(1) time and O(1) space*/
#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;
class SpecialStack{
    stack<int> s;
    int mini = INT_MAX; // gets the minimum element

    public:
    void push(int data){
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = (2 * data) - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }
    int pop(){
        if(s.empty()){
            cout << "Stack underflow error" << endl;
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int val = (2 * mini) - curr;
            mini = val;
            return prevMin;
        }
    }
    int top(){
        if(s.empty()){
            cout << "Stack underflow error" << endl;
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    int getMin(){
        if(s.empty()){
            cout << "Stack underflow error" << endl;
            return -1;
        }
        return mini;
    }
};