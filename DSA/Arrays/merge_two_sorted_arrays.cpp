 #include<iostream>
 #include<vector>
 using namespace std;
 void merge(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m){
        if(arr1[i] >= arr2[j]){
            arr3[k] = arr2[j];
            k++;
            j++;
        }
        else{
            arr3[k] = arr1[i];
            k++;
            i++; 
        }
    }
    while(i < n){
        arr3[k++] = arr1[i++];
    }
    while(j < m){
        arr3[k++] = arr2[j++];
    }
 }
 void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
 }
 int main(){
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[4] = {2, 4, 6 , 8};
    int arr3[9];
    merge(arr1, 5, arr2, 4, arr3);
    cout << "The merged array is: ";
    print(arr3, 9);
 }