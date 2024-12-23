#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[7] = {2, 0, 1, 3, 0, 0, 12};
    int n = 7;
    int j = 0; //aapki pehli non zero value is index pe aani chahiye
    for(int i = 0; i < n; i++){
        if(arr[i]!=0){
            swap(arr[j], arr[i]);
            j++;
        }
    }
    cout << "The segregated array is: ";
    for(int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }
}