#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(10);
    q.push(4);
    q.push(12);
    cout << "Printing the queue: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    priority_queue<int,vector<int>,greater<int> > pq;
    pq.push(10);
    pq.push(4);
    pq.push(12);
    cout << "Printing the priority queue: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}