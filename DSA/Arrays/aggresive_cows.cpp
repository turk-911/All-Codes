// #include<iostream>
// using namespace std;
// /*Question: There are k number of aggressive cows which fight with each other. There are n number
// of stalls at which the cows can be placed. Calculate the largest minimum distance at which they
// should be placed. */
// bool isPossible(int stalls[], int size, int k, int mid){
//     int cowCount=1;
//     int lastPosition = stalls[0];
//     for(int i=0; i<k; i++){
//         if(stalls[i] - lastPosition >= mid){
//             cowCount++;
            
//             if(cowCount==k){
//                 return true;
//             }
//             lastPosition = stalls[i];
//         }
//     }
//     return false;

// }
// int main(){
//     int stalls[5] = {1, 2, 3, 4, 6};
//     int n=5;
//     int s=0;
//     int maxi = -1;
//     int ans=-1;
//     for(int i=0; i<n; i++){
//         maxi = max(maxi, stalls[i]);
//     }
//     int e = maxi;
//     int mid = s + (e-s)/2;
    
//     while(s<=e){
//         if((isPossible(stalls, 5, 2, mid))){
//             ans = mid;
//             s = mid+1;
//         }
//         else{
//             e=mid-1;
//         }
//     }
//     cout << ans;
// }

// by recursion::

#include<iostream>
using namespace std;
bool isPossible