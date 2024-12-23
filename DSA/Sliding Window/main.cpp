#include<iostream>
#include<map>
using namespace std;
int main() {
    string s = "cadbzabcd";
    // write a code to find the longest substring with no repeating characters
    vector<int> Map(256, -1);
    int l = 0, r = 0;
    int n = s.length();
    int len = INT_MIN;
    while(r < n) {
        if(Map[s[r]] != -1) l = max(l, Map[s[r]] + 1);
        Map[s[r]] = r;
        len = max(len, r - l + 1);
        r++;
    }
    cout << len << endl;
}