#include<iostream>
using namespace std;
class TwoStack{
    int* arr;
    int top1;
    int top2;
    int size;
    // insertion in stack 1 will take place from left to right
    // insertion in stack 2 will take place from right to left
    public: 
        TwoStack(int size){
            arr = new int[size];
            int top1 = -1;
            int top2 = size;
        }
        void push1(int element){
            if(top2 - top1 > 1){
                top1++;
                arr[top1] = element;
            }
            else{
                cout << "Stack overflow error" << endl;
            }
        }
        void push2(int element){
            if(top2 - top1 > 1){
                top2--;
                arr[top2] = element;
            }
            else{
                cout << "Stack overflow error" << endl;
            }
        }
        void pop1(){
            if(top1 >= 0){
                int ans = arr[top1];
                top1--;
            }
            else{
                cout << "Stack underflow error" << endl;
            }
        }
        void pop2(){
            if(top2 < size){
                int ans = top2;
                top2++;
            }
            else{
                cout << "Stack underflow error" << endl;
            }
        }
};
int main(){
    // your code here
}