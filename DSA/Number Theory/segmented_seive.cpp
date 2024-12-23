#include<iostream>
using namespace std;
void segmented_seive(int n){
    // n is the number till you want to print primes
    bool mark[n];
    for(int i = 0; i < n; i++){
        mark[i] = true;
    }
    // one by one traverse all numbers so that there 
    // multiples can be marked as composite
    for(int p = 2; p*p < n; p++){
            if(mark[p] == true){
            // update all its multiples
            for(int i = p*p; i < n; i++){
                mark[i] = false;
            }
        }
    }
    for(int i = 2; i < n; i++){
        if(mark[i] == true){
            cout << mark[i] << " ";
        }
    }
}
int main(){
    cout << "Enter a number: ";
    int x;
    cin >> x;
    segmented_seive(x);
}