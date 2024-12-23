#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(17);
    q.push(8);
    q.push(7);
    cout << "Size of queue is: " << q.size() << endl;
    // cout << "First: ";
    for(int i = 0; i < 3; i++){
        cout << q.front() << endl;
        cout << "Size : " << q.size() << endl;
        q.pop();
    }
    cout << "Size: " << q.size() << endl;
    // cout << ": Last" << endl;
    return 0;
}