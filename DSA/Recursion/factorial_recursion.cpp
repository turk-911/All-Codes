#include<iostream>
using namespace std;
int factorial(long long n){
    if(n == 1){
        return 1;
    }
    return (n * factorial(n - 1));

}
int main(){
    int n;
    cout << "Enter a number : " ;
    cin >> n;
    cout << "Factorial of the number is: " << factorial(n) << endl;
}