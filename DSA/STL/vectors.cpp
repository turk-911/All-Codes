#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v;
    vector <int> a (5, 1);
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
    cout << "Original size: " << v.capacity() << endl;
    v.push_back(0);
    cout << "Capacity after insertion of one element: " << v.capacity() << endl;
    v.push_back(1);
    cout << "Capacity after insertion of 2 elements: " << v.capacity() << endl;
    v.push_back(2);
    cout << "Capacity after insertion of 3 elements: " << v.capacity() << endl;
    cout << "Size of vector: " << v.size() << endl;
    for(int i : v){
        cout << i << " ";
    }
    v.pop_back();
    cout << "Size after one pop back: " << v.capacity() << endl;
    for(int i : v){
        cout << i << " ";
    }
    cout << "Size before clearance: " << v.size() << endl;
    v.clear();
    cout << "Size after clearance: " << v.size() << endl;
}