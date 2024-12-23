#include<iostream>
using namespace std;
bool isPresent(int arr[][4], int target, int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
void printColumnSum(int arr[][4], int row, int column){
   
    for(int j = 0; j < column; j++){
        int sum = 0;
        for(int i = 0; i < row; i++){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}
void printRowSum(int arr[][4], int row, int column){
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}
int maximumRowSum(int arr[][4], int row, int column){
    int maximum = INT_MIN;
    int rowIndex = -1;
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < column; j++){
            sum += arr[i][j];
            if(sum > maximum){
                maximum = sum;
                rowIndex = i;
            }
        }
    }
    cout << "The maximum sum is: " << maximum;
    return rowIndex;
}
int main(){
    int arr2[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter the element: ";
    int target;
    cin >> target;
    cout << endl;
    if(isPresent(arr2, target, 3, 4)){
        cout << "The element " << target << "is Present" << endl;
    }
    else{
        cout << "The element " << target << " is Not present" << endl;
    }
    cout << "The row wise sum is: ";
    printRowSum(arr2, 3, 4);
    cout << endl;
    printColumnSum(arr2, 3, 4);
    cout << "The maximum row is at index: " << maximumRowSum(arr2, 3, 4);
}