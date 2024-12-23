/*Question Statement: Find the first unique character in a string and return the index*/
#include<iostream>
#include<queue>
#include<map>
using namespace std;
int firstNonRepeating(string s){
    unordered_map<char, int> count;
    queue<char> q;
    char ans = '^';
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        count[ch]++;
        if(count[ch] == 1){
            q.push(ch);
        }
    }
    while(!q.empty()){
        if(count[q.front()] > 1){
            q.pop();
        }
        else{
            ans = q.front();
            break;
        }
    }
    for(int i = 0; i < s.length(); i++){
        if(ans == s[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    string s = "leetcodel";
    cout << "String is: " << s << endl;
    int index = firstNonRepeating(s);
    cout << "The index of first non repeating element in the string is: " << index << endl;
    return 0;
}