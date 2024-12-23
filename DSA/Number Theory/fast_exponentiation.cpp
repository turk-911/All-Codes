#include<iostream>
using namespace std;
int modularExponent(int n, int x, int m){
    int result = 1;
    while(n > 0){
        if(n & 1){
            result = (result * (x % m)) % m;
        }
        x = ((x % m) * (x % m))%m;
        n = n>>1;
    }
    return result;
}
int main(){
    cout << "Enter the number, its power and modulus: ";
    int n, x, m;
    cin >> n >> x >> m;
    cout << "Modular exponentiation of the number is: " << modularExponent(n, x, m) << endl;
}