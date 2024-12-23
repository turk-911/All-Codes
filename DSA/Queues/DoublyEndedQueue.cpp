#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    d.push_front(12);
    d.push_back(56);
    cout << "Front element of the deque is: " << d.front() << endl;
    cout << "Back element of the deque is: " << d.back() << endl;
    d.pop_front();
    cout << "Front element of the queue after one pop front is: " << d.front() << endl;
    d.pop_back();
    d.push_back(90);
    if(d.empty()){
        cout << "Deque is empty" << endl;
    }
    else{
        cout << "Deque is not empty" << endl;
        cout << "Front element of the deque is: " << d.front() << endl;
    }
}