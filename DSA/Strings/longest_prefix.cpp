#include<iostream>
#include<string>
#include<vector>
using namespace std;
    string longestCommonPrefix(vector<string> &strs)
    {
        string temporary = "";
        int min_size = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            if (min_size > strs[i].length())
            {
                min_size = strs[i].length();
            }
        }
        // int j = 0;
        for (int i = 0; i < min_size; i++)
        {

            if (strs[0][i] == strs[1][i] && strs[0][i] == strs[2][i])
            {
                temporary.push_back(strs[0][i]);
            }
            // else if(j > min_size - 1){
            //     break;
            // }
            else
            {
                break;
            }
            // j++;
        }
        return temporary;
    }
int main(){
    vector<string> strs;
    strs.push_back("floo");
    strs.push_back("flow");
    strs.push_back("floor");
    cout << longestCommonPrefix(strs) << endl;
}