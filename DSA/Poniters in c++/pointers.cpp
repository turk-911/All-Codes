#include<iostream>
using namespace std;
int main(){
    cout << endl;
    int num = 5;
    int *pointer2 = &num;
    cout << *pointer2 << endl;
    cout << num << endl;
    cout << "Address of num is " << &num << endl;

    int i;
    cout << i << endl;
    i = i + 2;
    cout << "Address of i is: " << &i << endl;
    cout << "Garbage value in i is: " << i << endl;
    
    num = num + 1;
    cout << "New address of num is: " << &num << endl;

    int *pointer = &i;
    cout << *pointer << endl;

    char ch = 'a';
    char *p = &ch;
    cout << "Character " << ch << " has address as " << *p << endl;

    // creating a pointer pointing to some garbage address
    int *garbage;
    cout << *garbage << endl;

    int x = 5;
    int *p2;
    p2 = &x;
    cout << p << *p << endl;
}