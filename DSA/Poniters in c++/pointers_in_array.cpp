#include<iostream>
#include<vector>
using namespace std;
void print (int *p) {
    cout << *p << endl;
}

void update (int *p) {
    *p = *p + 1;
}

int getSum(int *arr, int n){ // function takes pointer as argument, benefit will be that 
// only a part of array can also be iterated through it
    cout << "Size is: " << sizeof(arr) << endl; 
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    cout << "Sum is: " << sum;
    return sum;
}
int main(){
    /*
    int arr[10] = {2, 4, 6};
    cout << "Address of the first element of the array is: " << arr << endl;
    cout << "Garbage value inside array at first memory block is: " << arr[0] << endl;
    cout << "Address of first memory block is: " << endl;
    cout << *arr << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    for(int i = 0; i < 3; i++){
        cout << i[arr] << " ";
    }
    cout << endl;
    int temp[10] = {1, 2};
    int *ptr = &temp[0];
    cout << "1st " << sizeof(temp) << endl;
    cout << "2nd " << sizeof(*temp) << endl;
    cout << "3rd " << sizeof(ptr) << endl;
    cout << "4th " << sizeof(*ptr) << endl;
    cout << "5th " << sizeof(&temp) << endl;
    */
    
    /*
    int a[20] = {1, 2, 3, 4, 5, 6};
    cout << a << endl;
    cout << &a[0] << endl;
    cout << &a << endl;
    
    int *p = &a[3];
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;
    */

    /*int arr[10];
    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;

    char ch[6] = "abcde";
    char *pt = &ch[0];
    cout << ch << endl;
    cout << *pt << endl;
    pt = pt + 1;
    cout << *pt << endl;

    char temp = 'z';
    char *p = &temp;
    cout << p << endl;

    char *ch2 = "abcde";
    cout << ch2 << endl; */
    

    /*int value = 5;
    int *pointer = &value;

    print(pointer);
    update(pointer);
    print(pointer);*/

    int arr[5] = {2, 3, 5, 6, 1};
    getSum(arr+3, 2);
}