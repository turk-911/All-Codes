#include<iostream>
using namespace std;
char lower_case(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
void reverse(char a[], int n){
    int start = 0;
    int end = n - 1;
    while(start < end){
        swap(a[start++], a[end--]);
    }
}
int get_length(char a[]){
    int count = 0;
    for(int i = 0; a[i] != 0; i++){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cout << "Enter your name: " ;
    cin >> name;
    cout << endl;
    // name[4] = '\0'
    cout << "Your name is: " << name << endl;
    int length = get_length(name);
    cout << "Length of your name is: " << length << endl;
    reverse(name, length);
    cout << "Reverse of your name is: " << name << endl;
    bool isPalindrome = 0;
    int st = 0;
    int en = length - 1;
    while(st <= en){
        if(lower_case(name[st++]) == lower_case(name[en--])){
            isPalindrome = 1;
        }
        else{
            isPalindrome = 0;
            break;
        }
    }
    if(isPalindrome == 1){
        cout << "Your name is a palindrome. " << endl;
    }
    else{
        cout << "Your name is not a palindrome. " << endl;
    }
    cout << "Character is: " << lower_case('C') << endl;
}