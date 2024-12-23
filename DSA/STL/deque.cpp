#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque <int> d;
    d.push_back(1); 
    d.push_front(2);
    cout << "Empty or not: " <<  d.empty() << endl;
    cout << "The deque is: " ;
    for(int i : d){
        cout << i << " " ;
    }
    cout << endl;
    cout << "Element at first index is: " << d.at(1) << endl;
    cout << "Element at front is: " << d.front() << endl;
    cout << "Element at last is: " << d.back() << endl;
    d.pop_back();
    cout << "After popping the back element, deque becomes: " ;
    for(int i : d){
        cout << i << " " ;
    }
    cout << endl;
    d.pop_back();
    for(int i : d){
        cout << i << " ";
    }
    deque <int> d2;
    d2.push_back(4);
    d2.push_front(3);
    cout << "The new deque is: " ;
    for(int i : d2){
        cout << i << " ";
    }
    cout << endl;
    cout << "The size of deque before erasing: " << d2.size() << endl;
    d2.erase(d2.begin(), d2.begin() + 1);
    cout << "The deque after erasing is: ";
    for(int i : d2){
        cout << i << " ";
    }
    cout << endl;
    cout << "The size of deque after erasing is: " << d2.size() << endl;
}
