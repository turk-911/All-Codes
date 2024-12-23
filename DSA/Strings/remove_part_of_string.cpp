#include<iostream>
#include<string>
using namespace std;
string remove_occurences(string s, string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main(){
    string s;
    string part;
    cout << "Enter a string: ";
    getline(cin,s);
    cout << endl;
    cout << "Enter the part you want to erase: ";
    cin >> part;
    cout << "According to your requirements " ;
    cout << "the string has been adjusted to:  " << remove_occurences(s, part) << endl;
}