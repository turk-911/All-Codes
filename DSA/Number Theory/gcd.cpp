#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int lcm(int a, int b){
    int lcm = (a*b)/gcd(a, b);
    return lcm;
}
int main(){
    cout << "Enter two numbers: ";
    int x, y;
    cin >> x >> y;
    cout << "Greatest common divisor of " << x << " and " << y << " is: " << gcd(x, y) << endl;
    cout << "Least common multiple of " << x << " and " << y << " is: " << lcm(x, y) << endl;
}