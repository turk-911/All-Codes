#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector <int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    cout << "Finding 6 by binary search: " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Lower bound: " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << "Upper bound: " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    int a = 3;
    int b = 5;
    cout << "Max of a and b: " << max(a, b) << endl;
    cout << "Min of a and b: " << min(a, b) << endl;
    swap(a, b);
    cout << "Value of a after swapping: " << endl;
    cout << "Value of b after swapping: " << endl;
    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "Reversed string is: " << s << endl;
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "Rotated vector is: " ;
    for(int i : v){
        cout << i  << " ";
    }
    cout << endl;
    sort(v. begin(), v.begin() + 2);
    cout << "Sorted vector is: ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}