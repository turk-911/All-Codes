#include<iostream>
using namespace std;
int main(){
    int A[5] = {1, 2, 5, 4, 0};
    int a = 5;
    int B[5] = {2, 4, 5, -9, 1};
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(A[i] >= A[j]){
                int swap = A[i];
                A[i] = A[j];
                A[j] = swap;
            }
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(B[i] >= B[j]){
                int swap = B[i];
                B[i] = B[j];
                B[j] = swap;
            }
        }
    }
    bool equal;
    for(int i = 0; i < a; i++){
        if(A[i] == B[i]){
            equal = 1;
        }
        else{
            equal = 0;
        }
    }
    if(equal == 1){
        cout << "Arrays are equal" << endl;
    }
    else{
        cout << "Arrys are not equal" << endl;
    }
}