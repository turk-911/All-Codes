#include<iostream>
#include<string>
using namespace std;
void solve(string& str, string output, int index, vector<string>& ans){
    if(index >= str.length()){
        ans.push_back(output);
        return ;
    }
    solve(str, output, index + 1, ans);
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}
vector<string> subsequences(string& str){
    vector<string> ans;
    string output;
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}
int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    vector<string> ans = subsequences(str);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}