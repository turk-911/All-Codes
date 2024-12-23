#include<iostream>
#define pi 3.14
using namespace std;
int main(){
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    double area = pi * r * r;
    cout << "Area of the circle is: " << area << endl;

    // inline functions
    int a = 1, b = 2;
    int ans = 0;
    // first way of comparison: 
    /*if(a > b){
        ans = a;
    }
    else{
        ans = b;
    }*/

    // second way of comparison by using inline functions
    ans = (a>b) ? : a : b;
    cout << "The greater number is: " << ans << endl;
}