#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void segregate(vector <int> arr, int n){
    int left = 0;
    int right = arr.size() - 1;
    while(left < right){
        while(arr[left] == 0 && left < right){
            left++;
        }
        while(arr[right] == 1 && left < right){
            right--;
        }
        if(left < right){
            swap(arr[left], arr[right]);
        }
    }
}
int main(){
    vector <int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    for(int i : v){
        cout << i << " ";
    }
    cout << endl << "Array after segregation: ";
    vector <int> vn = segregate(v, 5);
    for(int i : vn){
        cout << i << " ";
    }
}