#include<iostream>
#include<vector>
using namespace std;
long long factorial(long long n){
        long long product = 1;
        for (long long i = 1; i <= n; i++){
            product = product * i;
        }
        return product;
}
int c(int n, int r){
        long long a = factorial(n);
        long long b = factorial(r);
        long long c = factorial(n - r);
        long long part = b*c;
        long long ans = a / part;
        return ans;
}
vector<int> getRow(int rowIndex){
        vector<int> ans;
        for (int i = 0; i <= rowIndex; i++){
            ans.push_back(c(rowIndex, i));
        }
        return ans;
}
int main(){
    int row = 13;
    vector<int> ans = getRow(13);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << c(13, 1) << endl;
    cout << factorial(13) << endl;
    cout << factorial(1) << endl;
    cout << factorial(12) << endl;
    
}
