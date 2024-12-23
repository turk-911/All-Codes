#include<iostream>
using namespace std;
char lower_case(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool isValid(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
        return 1;
    }
    return 0;
}
bool ispalindrome(string s){
    string temporary = "";
    for(int j = 0; j < s.length(); j++){
        if(isValid(s[j])){
            temporary.push_back(s[j]);
        }
    }
    for(int j = 0; j < temporary.length(); j++){
        temporary[j] = lower_case(temporary[j]);
    }
    int start = 0;
    int end = temporary.length() - 1;
    while(start <= end){
        if(temporary[start++] == temporary[end--]){
            return 1;
        }
        else{
            return 0;
            break;
        }
    }
}
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if(ispalindrome(s)){
        cout << s << " is a valid palindrome. " << endl;
    }
    else{
        cout << s << " is not a valid palindrome. " << endl;
    }
}