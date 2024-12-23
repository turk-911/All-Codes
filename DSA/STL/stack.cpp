#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <string> s;
    s.push("Dhoni");
    s.push("Virat Kohli");
    cout << "The element on top is: " << s.top() << endl;
    cout << "The size of stack before popping is: " << s.size() << endl;
    s.pop();
    cout << "The element on top after popping is: " << s.top() << endl;
    cout << "The size of stack after popping is: " << s.size() << endl;
    s.pop();
    cout << "Empty or not, 1 means true: " << s.empty() << endl;
}