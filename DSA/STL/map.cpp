#include<iostream>
#include<map>
using namespace std;
int main(){
    map <int, string> m;
    m[1] = "Mokshe";
    m[2] = "Jain";
    m[13] = "Kumar";
    m.insert({5, "bheem"});
    for(auto i : m){
        cout << i.first << " ";
    }
    cout << endl;
}