#include<iostream>
using namespace std;
void update(int& n){
    n++;
}

int getSum(int* arr, int r){
    int sum = 0;
    for(int i = 0; i < r; i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    /*int n = 5;
    cout << "before " << n << endl;
    update(n);
    cout << "after " << n << endl;

    //creating in dynamic memory

    new char;
    char* ch = new char;
    cout << ch << endl;

    // array of variable size

    int r;
    cout << "Enter size of array: " ;
    cin >> r;
    new int[r];

    int* arr = new int[r];
    cout << "Enter numbers for array: ";
    for(int i = 0; i < r; i++){
        cin >> arr[i];
    }

    cout << getSum(arr, r) << endl;*/

    /*int n;
    cout << "Enter the value of n to create a n x n matrix: " ;
    cin >> n;
    int** arr = new int* [n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    
    // creation done

    //taking input
    cout << "Enter the values: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cout << "The matrix is: " << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";        
        }
        cout << endl;
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum+=arr[i][j];
        }
    }
    cout << "sum of elements of matrix is :" << sum << endl;*/

    int row;
    cout << "Enter the value of rows of the matrix: " ;
    cin >> row;

    int column;
    cout << "Enter the value of columns of the matrix: ";
    cin >> column;

    int** arr = new int* [row];
    for(int i = 0; i < row; i++){
        arr[i] = new int[column];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> arr[row][column];
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << arr[row][column] << " ";
        }
        cout << endl;
    }

    // releasing the memory because we created in heap memory

    for(int i = 0; i < row; i++){
        delete []arr[i];
    }

    delete [arr];
    
    
    return 0;

}