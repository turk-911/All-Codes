#include<iostream>
#include<string.h>
using namespace std;
bool checkPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n = 7;
    string s;
    for(char i = 1; i <= '7'; i++){
        s.push_back(i);
    }
    // cout << s << endl;
    // // next_permutation(s.begin(), s.end());
    // cout << s << endl;
    int ans = 0;
    do{
        int num = stoi(s);
        if(checkPrime(num)){
            ans = max(ans, num);
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
}