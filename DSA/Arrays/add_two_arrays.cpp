#include<iostream>
#include<vector>
using namespace std;
vector <int> reverse(vector <int> v){
    int s = 0;
    int e = v.size() - 1;
    while(s < e){
        swap(v[s++], v[e--]);
    }
    return v;
}
int main(){
    vector <int> a;
    vector <int> b;
    vector <int> ans;
    a.push_back(4);
    a.push_back(5);
    a.push_back(7);
    a.push_back(9);
    b.push_back(5);
    b.push_back(0);
    b.push_back(9);
    b.push_back(1);
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    cout << "The first array is: ";
    for(int k : a){
        cout << k << " ";
    }
    cout << endl;
    cout << "The second array is: ";
    for(int k : b){
        cout << k << " ";
    }
    while(i >= 0 && j >= 0){
        int value_1 = a[i];
        int value_2 = b[j];
        int sum = value_1 + value_2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
        i--;
    }
    while(i >= 0){
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0){
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while(carry != 0){
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    cout << endl;
    cout << "The sum of elements stored in array is as follows: ";
    vector <int> n = reverse(ans);
    for(int k : n){
        cout << k << " ";
    }
}