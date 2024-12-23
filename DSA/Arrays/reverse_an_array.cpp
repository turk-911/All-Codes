#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> reverse(vector <int> v){
    int s;
    cout << "After which index you want reversing: " ;
    cin >> s;
    int e = v.size() - 1;
    while(s <= e){
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector <int> v;
    v.push_back(4);
    v.push_back(7);
    v.push_back(11);
    v.push_back(12);
    v.push_back(3);
    v.push_back(6);
    vector <int> ans = reverse(v);
    cout << "Reversed vector is: ";
    print(ans);
}