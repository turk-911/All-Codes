#include<iostream>
#include<string>
using namespace std;
bool check_equal(int a[26], int b[26]){
    for(int i = 0; i < 26; i++){
        if(a[i] != b[i]){
            return 0;
        }
        return 1;
    }
}
bool check_inlcusion(string s, string sub){
    int count[26] = {0};
    // character count array is ready
    for(int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        count[index]++;
    }
    // traverse the array
    int i = 0;
    int windowSize = s.length();
    int newCount[26] = {0};
    // first window
    while(i < windowSize && i < sub.length()){ 
        int index = sub[i] - 'a';
        newCount[index]++;
        i++;
    }
    if(check_equal(count, newCount)){
        return 1;
    }
    while(i < sub.length()){
        char newChar = sub[i];
        int index = newChar - 'a';
        newCount[index]++;

        char oldChar = sub[i - windowSize];
        index = oldChar - 'a';
        newCount[index]--;

        if (check_equal(count, newCount)){
            return 1;
        }
        i++;
    }
    return 0;
}
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << endl;
    string sub;
    cout << "Enter the substring you want to check: ";
    cin >> sub;
    cout << endl;
    if(check_inlcusion(s, sub)){
        cout << "Present " << endl;
    }
    else{
        cout << "Absent " << endl;
    }
}