#include<iostream>
#include<string>
using namespace std;
string remove(string s){
    string resultant;
    for(char current : s){
        //if the result is empty or the current character is different than the last character 
        // in the result, then add the element to the resultant.
        if(resultant.empty() || current != resultant.back()){
            resultant.push_back(current);
        }
    }
    return resultant;
}
int main(){
    string s;
    cout << "Enter a string: " ;
    cin >> s;
    cout << endl << "Modifed string is: " << remove(s) << endl;
}