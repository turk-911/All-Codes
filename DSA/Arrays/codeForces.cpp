#include<iostream>
using namespace std;
int countZeros(string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            count++;
        }
    }
    return count;
}
int countOnes(string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            count++;
        }
    }
    return count;
}
int main(){
    int t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int zeros = countZeros(str);
        int ones = countOnes(str);
        if(zeros >= ones){
            cout << "YES" << endl;
        }
        if(ones == str.length()){
            cout << "NO" << endl;
        }
    }
    
}