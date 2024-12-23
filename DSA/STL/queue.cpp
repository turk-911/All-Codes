#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue <string> q;
    q.push("Mokshe");
    q.push("Jain");
    q.push("Tomato");
    cout << "First element of queue: " << q.front() << endl;
    cout << "The size of queue is: " << q.size() << endl;
    q.push("Undertaker");
    cout << "New element added in the queue is: " << q.back() << endl;
    cout << "Now, the size of queue is: " << q.size() << endl;
    q.pop();
    cout << "First element of queue after popping is: " << q.front() << endl;
    q.reverse();
    for(auto i : q){
        cout << i << " ";
    }
}