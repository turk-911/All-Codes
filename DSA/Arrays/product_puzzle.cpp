#include<iostream>
using namespace std;
int main(){
    int arr[5] = {10, 3, 5, 6, 2};
    int n = 5;
    cout << "The array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    int index;
    cout << endl;
    cout << "Enter the index according to zero based indexing: " ;
    cin >> index;
    if(index > n - 1){
        cout << "Enter a valid index. " << endl;
    }
    else{
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product *= arr[i];
        }
        product = product / arr[index];
        cout << endl;
        cout << "The product is: ";
        cout << product;
    }
}