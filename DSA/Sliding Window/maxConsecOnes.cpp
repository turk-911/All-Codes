#include<iostream>
using namespace std;
int main() {
    int arr[9] = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int l = 0, r = 0;
    int n = 9;
    int k = 2;
    int len = 0;
    int zeroCount = 0;
    while(r < n) {
        if(zeroCount <= k) {
            len = max(len, r - l + 1);
            r++;
        }
        
    }
}