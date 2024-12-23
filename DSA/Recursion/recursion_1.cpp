#include<iostream>
using namespace std;
int factorial(int n){
    if(n == 0){
        return 1;
    }
    
    int ans = n * factorial(n - 1);

    return ans;
}


int sum(int n){
    if(n == 0){
        return 0;
    }

    int ans = n + sum(n - 1);
    return ans;
}


int power(int n){
    if(n == 0){
        return 1;
    }
    
    int ans = 2 * power(n - 1);
    return ans;
}


void counting(int n){
    if(n == 0){
        return ;
    }
    counting(n - 1);
    cout << n << " ";
}
int main(){
    cout << "Enter the number: " ;
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    cout << sum(n) << endl;
    cout << power(n) << endl;
    counting(n);
}