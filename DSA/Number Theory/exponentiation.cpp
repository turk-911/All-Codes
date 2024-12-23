#include<iostream>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b & 1){
        return (a * power(a, b - 1)) % mod;
    }
    __int128 k = power(a, b / 2);
    return (k * k) % mod;
}
int32_t main(){
    int a, b;
    cin >> a >> b;
    int ans = power(a, b);
    cout << ans % mod << endl;
}