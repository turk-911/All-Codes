#include<iostream>
#include<list>
using namespace std;
int main(){
    list <int> l;
    l.push_back(2);
    l.push_front(3);
    l.push_front(9);
    l.push_back(0);
    cout << "The list is: ";
    for(int i : l){
        cout << i << " ";
    }
    cout << endl;
    cout << "The size of list before erasing is: " << l.size() << endl;
    l.erase(l.begin());
    cout << "The list after erasing the first element is: " ;
    for(int i : l){
        cout << i << " ";
    }
    cout << endl;
    cout << "The size of list after erasing is: " << l.size() << endl;
    list <int> l2(10, 5);
    cout << "The new list is: ";
    for(int i : l2){
        cout << i << " ";
    }
    cout << endl;
}