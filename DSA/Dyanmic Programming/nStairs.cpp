#include<iostream>
using namespace std;
int solve(long long int n, long long int i){
    if(i == n){
        return 1;
    }
    if(i > n){
        return 0;
    }
    return solve(n, i + 1) + solve(n, i + 2);
}
int countDistinctWays(long long int n){
    int i = 0;
    return solve(n, i);
}
int main(){
    int n;
    cout << "Enter the total number of stairs: " ;
    cin >> n;
    long long int totalWays = countDistinctWays(n);
    cout << "The total distinct ways of climbing the stairs is: " << totalWays << endl;
    return 0;
}