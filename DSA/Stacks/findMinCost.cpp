#include<iostream>
#include<stack>
using namespace std;
int findMinCost(string &s){
    int len = s.length();
    if(len & 1){
        return -1;
    }
    stack<char> st;
    for(int i = 0; i < len; i++){
        char ch = s[i];
        if(ch == '('){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    int a = 0, b = 0;
    // a -> opening brace count
    // b -> closing brace count
    while(st.empty() != true){
        if(st.top() == '('){
            a++;
        }
        else{
            b++;
        }
        st.pop();
    }
    int ans = (a + b + 2) / 2;
    return ans;
}
int main(){
    string s = "()()";
    int minCosting = findMinCost(s);
    cout << "minimum cost is : " << minCosting << endl;
}