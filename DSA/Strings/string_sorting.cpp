#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1 = "geeksforgeeks";
    string s2 = "mokshejain";
    cout << s1 << " " << s2 << endl;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << s1 << " " << s2 << endl;
}