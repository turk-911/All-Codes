#include<iostream>
using namespace std;
int power(int a, int b){
    // base case
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    long long ans = power(a, b/2);
    if(b&1){
        return ans*ans*a;
    }
    else{
        return ans*ans;
    }
}
int main(){
    cout << "Enter 2 nos: " ;
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
}