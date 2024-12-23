#include<iostream>
using namespace std;
int factorial(long long n){
    long long product = 1;
    for(int i = 1; i <= n; i++){
        product = product * i;
    }
    return product;
}
int main(){
    long long n;
    cout << "Enter: ";
    cin >> n;
    cout << factorial(n) << endl;
}