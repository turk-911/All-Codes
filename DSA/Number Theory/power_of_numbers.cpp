#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter any number: " ;
    cin >> n;
    int m = n;
    int rem = 0;
    int rev;
    while(n!=0){
        rev = rev * 10;
        rev = rev + (n % 10);
        n = n / 10;    
    }
    
    cout << rev;
    int product = 1;
    for(int i = 0; i < rev; i++){
        product *= m;
    }
    cout << product;
}