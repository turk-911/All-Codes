#include<iostream>
using namespace std;
int main(){
    int arr[6] = {2, 4, 5, 8, 9, 11};
    int arrSize = 6;
    cout << "The original array is: ";
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int index;
    cout << "Enter the index about which you want to rotate: ";
    cin >> index;
    cout << endl;
    cout << "The rotated array is: " ;
    int rotated_array[6];
    for(int i = 0; i < arrSize; i++){
        arr[(i + index)%arrSize] = arr[i];
    }
    for(int i = 0; i < 6; i++){
        cout << rotated_array[i] << " ";
    }
    cout << endl;
}