#include<iostream>
using namespace std;
void print(int array[], int size){
    cout << "Size of array is: " << size << endl;

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
bool isSorted(int array[], int size) {
    // base case --> agar array ka size 0 ya 1 hai to wo sorted h
    bool ans;
    if(size == 0 || size == 1) {
        return true;
    }
    if(array[0] > array[1]){
        return false;
    }
    else{
        ans = isSorted(array + 1, size - 1);
    }
 
    return ans;
}

int sumOfArray(int array[], int size) {
    print(array, size);
    // base case --> agar array ka size 0 hogya to 0 return krdo
    if(size <= 0){
        return 0;
    }
    int ans = array[0] + sumOfArray(array + 1, size - 1);
    return ans;
}

bool linearSearch(int array[], int size, int target) {
    // base case --> agar array khatam hogya aur element nhi mila
    if (size == 0) {
        return 0;
    }
    if(array[0] == target){
        return true;
    }
    bool remaniningPart = linearSearch(array + 1, size - 1, target);
    return remaniningPart;
}

int main(){
    int array[5] = {1, 3, 4, 4, 5};
    cout << isSorted(array, 5);
    cout << endl;
    cout << sumOfArray(array, 5) << endl;
    int ans = linearSearch(array, 5, 3);
    if(ans){
        cout << "Present" << endl;
    }
    else{
        cout << "Absent" << endl;
    }
}