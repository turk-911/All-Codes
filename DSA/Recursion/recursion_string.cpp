#include<iostream>
#include<string>
using namespace std;
void reverse(string &str, int i, int j){
    if(i > j){
        return ;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    reverse(str, i ,j);

}

int main(){
    string temp = "abcde";
    reverse(temp, 0, 4) ;
    cout << temp << endl;
}
