#include<iostream>
#include<string>
#include<vector>
using namespace std;
int compress(vector <char> &chars){
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while(i < n){
        int j = i + 1;
        while(j < n && chars[i] == chars[j]){
            j++;
        }
            // loop will break if either the string is traversed completely
            // or a new character has been encountered.

            // store the old character in the array
            chars[ansIndex++] = chars[i];
            int count = j - i;
            // converting counting into single digit and saving it
            if(count > 1){
                string cnt = to_string(count);
                for(char ch : cnt){
                    char[ansIndex++] = ch;
                }
            }
            i = j;
    }
    return ansIndex;
}
int main(){
    vector <char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('d');
    chars.push_back('d');
    chars.push_back('d');
    chars.push_back('e');
    chars.push_back('e');
    cout << "Length of compressed vector is: " << compress(chars);
}