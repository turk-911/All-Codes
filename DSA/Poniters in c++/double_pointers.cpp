#include<iostream>
using namespace std;
int main(){
    int value = 5;
    int *ptr = &value;
    int **ptr2 = &ptr;
    cout << value << endl;
    cout << *ptr << endl;
    cout << **ptr2 << endl;

    cout << &value << endl;
    cout << ptr << endl;
    cout << *ptr2 << endl;

    ptr2 = ptr2 + *ptr;
    cout << ptr2 << endl;
}