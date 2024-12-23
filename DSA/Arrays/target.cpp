#include<iostream>
using namespace std;
int main(){
    int target;
    cin >> target;
    int n=5;
    bool possible =0;
    //say target = 11; you have to return 1 and 2
    int arr[5] = {3, 5, 6, 8, 0};
    for(int i=0; i<n; i++){
        //j=i+1 sirf aage wala check krega game over
        for(int j=i+1; j<n; j++){
            if((arr[j]+arr[i])==target){
                cout << i << " " << j << endl;
                possible=1;
            } 
        }
        
    }
    if(possible==0){
        cout << "bc";
    }
}