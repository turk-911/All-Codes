#include<iostream>
#include<queue>
using namespace std;
int main(){
    // maximum value first
    priority_queue <int> p;
    p.push(1);
    p.push(3);
    p.push(6);
    p.push(7);
    int n = p.size();
    cout << "The maximum queue is: ";
    for(int i = 0; i < n; i++){
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
    // minimum value first
    priority_queue <int, vector<int>, greater<int> > mini;
    mini.push(2);
    mini.push(0);
    mini.push(7);
    mini.push(4);
    cout << "The minimum queue is: ";
    int k = mini.size();
    for(int i = 0; i < k; i++){
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
}