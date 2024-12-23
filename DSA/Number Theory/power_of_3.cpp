#include<iostream>
using namespace std;
bool check(int n, int index)
{
    cout << "first "<< n << endl;
    if (n == 0)
    {
        return true;
    }
    for (int i = index; i >= 0; i--)
    {
        int x = pow(3, i);
        int y = n - x;
        if (y >= 0)
        {
            if (check(y, i - 1) == true)
            {
                return true;
            }
        }
    }
    cout << "second " << n << endl;
    return false;
}
bool checkPowersOfThree(int n)
{
    if (check(n, 16))
    {
        return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;

    if (checkPowersOfThree(n)){
        cout << "oh yeah" << endl;
    }
    else{
        cout << "chhota bheem" << endl;
    }
}