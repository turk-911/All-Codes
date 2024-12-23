#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int factorial[N];
int nCr(int n, int r){
    if(r > n || n == 0){
        return 0;
    }
    if(n == r || r == 0){
        return 1;
    }
    return (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}
void preCalculation(){
    factorial[0] = 1;
    for(int i = 1; i < N; i++){
        factorial[i] = (i * 1ll * factorial[i - 1]) % mod;
    }
}
int main(){
    int n, r;
    cin >> n >> r;
    int ans = nCr(n, r);
    cout << ans << endl;
    preCalculation();
    int n_factorial = factorial[n];
    int r_factorial = factorial[r];
    int x = factorial[n - r];
    int denominator = x * 1ll * r_factorial;
    int inv_denominator = pow(denominator, mod - 2);
    int ans2 = (n_factorial * 1ll * inv_denominator) % mod;
    cout << ans2 << endl;
}