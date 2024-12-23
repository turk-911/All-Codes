#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int target;
    cout << "Enter the target: ";
    cin >> target;
    vector <int> array;
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    bool found = false;
    for(int i = 0; i < n; i++){
        int low = i + 1;
        int high = n - 1;
        while(low < high){
            int current = array[i] + array[low] + array[high];
            if(current == target){
                found = true;
                cout << "The indices of the elements are: ";
                cout << i << low << high;
                break;
            }
            if(low < high){
                low++;
            }
            else{
                high--;
            }
        }

    }
}