#include<iostream>
#include<map>
using namespace std;
int main() {
    int k = 2;
    string s = "aaabbcccdd";
    map<char, int> Map;
    int n = s.length();
    int l = 0, r = 0;
    int len = 0;
    while(r < n) {
        Map[s[r]]++;
        while(Map.size() > k) {
            Map[s[l]]--;
            if(Map[s[l]] == 0) Map.erase(s[l]);
            l++;
        }
        len = max(len, r - l + 1);
        r++;
    }
    cout << len << endl;
}   