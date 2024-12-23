#include<iostream>
using namespace std;
int main(){
    int row0[4] = {1, 2, 3, 4};
    int row1[2] = {4, 7};
    int* jaggered[2] = {row0, row1};
    int size[2] = {4, 2}; // array to hold the size of each row
    int k = 0;
    for(int i = 0; i < 2; i++){

        // pointer to hold the address of the row
        int* ptr = jaggered[i];

        for(int j = 0; j < size[k]; j++){
            cout << *ptr << " ";

            //move the pointer to the next element in the row
            ptr++;
        }
        cout << endl;
        k++;

        // move the pointer to the next row
        jaggered[i]++;
    }

    return 0;
}