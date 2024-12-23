#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Original string is: " << str << endl;
    stack <char> st;
    for(int i = 0; i < str.length(); i++){
        st.push(str[i]);
    }
    for(int i = 0; i < str.length(); i++){
        str[i] = st.top();
        st.pop();
    }
    cout << "Reversed string is: " << str << endl;
}