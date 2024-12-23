#include<iostream>
#include<set>
using namespace std;
int main(){
    set <int> s;
    s.insert(3);
    s.insert(30);
    s.insert(14);
    s.insert(23);
    cout << "The elements stored is set are: " ;
    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;
    cout << "The set after popping one element is: " ;
    set <int> :: iterator it = s.begin();
    it++;
    s.erase(it);
    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;
    cout << "10 is present or not: " << s.count(10) << endl;

    
}