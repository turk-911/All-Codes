#include<iostream>
#include<string>
using namespace std;
char get_max(string s){
    int arr[26] = {0};
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <= 'z'){
            number = ch - 'a';
        }
        else{
            number = ch - 'A';
        }
        arr[number]++;
    }
    int maximum = -1;
    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(maximum < arr[i]){
            ans = i;
            maximum = arr[i];
        }
    }
    char ch = 'a' + ans;
    return ch;
}
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << endl << "The maximum character occuring in the string is: " << get_max(s) << endl;
}