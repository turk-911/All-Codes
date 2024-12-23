#include<iostream>
#include<string>
using namespace std;
bool validPalindrome(string &str, int i, int j){
    if(i > j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
   
    else{
        return validPalindrome(str, i + 1, j - 1);
    }
    i++;
    j--;
    validPalindrome(str, i, j);
}
int main(){
    string temp = "abababa";
    bool istrue = validPalindrome(temp, 0, temp.length() - 1);
    if(istrue){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not palindrome" << endl;
    }
}