/*Question Statement: Reverse first K elements of a queue*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void print(queue<int> q, int n){
    for(int i = 0; i < n; i++){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
queue<int> modifyQueue(queue<int> q, int k){
    stack<int> s;
    for(int i = 0; i < k; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    int t = q.size() - k;
    while(t--){
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    cout << "The origial queue is: ";
    print(q, 6);
    queue<int> modified;
    modified = modifyQueue(q, 4);
    cout << "The modified queue is: ";
    print(modified, 6);

    return 0;
}