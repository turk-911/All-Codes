#include<iostream>
#include<vector>
using namespace std;
int countPrimes(int n){
    vector <bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    int count = 0;
    for(int i = 2; i < n; i++){
        if(prime[i]){
            count++;
            for (int j = 2 * i; j < n; j = j + i){
                prime[j] = false;
            }
        }
        
    }
    return count;
}
int main(){
    cout << "Enter a number: ";
    int n;
    cin >> n;
    cout << "The number of prime numbers between 0 and " << n << " are: " << countPrimes(n) << endl;
}