#include<iostream>
using namespace std;
int minimum_multiplication(int arr[], int n, int start, int end){
    int count;
    int product = 1;
    for(int i = 0; i++){
        product *= arr[i];
        count++;
        if(product == end){
            break;
        }
    }
    return count;
}
int main(){

}