#include<iostream>
using namespace std;
void update(int *p){
    *p = *p * 2;
}
void increment(int **p){
    ++(**p);
}
int main(){
    /*int first = 8;
    int second = 19;
    int *ptr = &second;
    *ptr = 9;
    cout << first << " " << second << endl;*/
    // ans is --> 8 9

    /*int first = 6;
    int *p = &first;
    int *q = p;
    (*q)++;
    cout << first << endl;*/
    // ans is --> 7

    /*int first = 8;
    int *p = &first;
    cout << (*p)++ (// post increment) << " " << first << endl;*/
    // ans is --> 8 9 

    /*int *p = 0; // null pointer
    int first = 110;
    *p = first;
    cout << *p << endl;*/
    // ans is --> segmentation fault

    /*int *p = 0;
    int first = 100;
    p = &first;
    cout << *p << endl; */
    // ans is --> 100

    /*int first = 8;
    int second = 11;
    int *third = &first;
    first = *third;
    *third = *third + 2;
    cout << first << " " << second << endl;*/
    // ans is --> 10 11

    /*float f = 12.5;
    float p = 21.5;
    float *ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr << " " << f << " " << p << endl; */
    // ans is --> 21.5 21.5 21.5

    /*int arr[5];
    int *ptr;
    cout << sizeof(arr) << " " << sizeof(*ptr) << endl;*/
    // ans is --> 20 4

    /*int arr[] = {11, 21, 34, 56}; '*(arr) refers to the number at first index'
    cout << *(arr) << " " << *(arr + 1) << endl;*/
    // ans is --> 11 21

    /*int arr[3] = {11, 21, 31};
    cout << arr << " " << &arr << endl; */
    // ans is --> same address

    /*int arr[5] = {11, 12, 13, 14, 15};
    cout << *arr << " " << *(arr + 2) << endl;*/
    // ans is --> 11 13

    /*int arr[3] = {11, 12, 13};
    int *ptr = (arr)++;
    cout << *ptr << endl;*/
    // ans is --> it gives an error, because we can't use arr++
    // we can only update the pointer

    /*char ch = 'a';
    ch++;
    char *ptr = &ch;
    cout << *ptr << " " << ch << endl;*/
    // ans is --> b b

    /*char arr[] = "abcde";
    char *ptr = &arr[0];
    cout << ptr << endl;*/
    // ans is --> abcde
    // agar *ptr print krate to a print hota

    /*char str[] = "mokshe";
    char *ptr = str;
    cout << str[0] << " " << ptr[0] << endl;*/
    // ans is --> m m

    /*int i = 10;
    update(&i);
    cout << i << endl;*/
    // ans is --> 20

    /*int first = 110;
    int *p = &first;
    int **q = &p;
    int second = (**q)++ + 9;
    cout << first << " " << second << endl;*/
    // ans is --> 111 119

    /*int first = 100;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    cout << first << " " << second << endl;*/
    // ans is --> 102 101

    int first = 100;
    int *p = &first;
    increment(&p);
    cout << first << endl;
    // ans is --> 101
}
