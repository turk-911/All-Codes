#include<iostream>
#include<stack>
using namespace std;
class NStack{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freeSpot;
    public:
        // Initialise your data structure
        NStack(int N, int S){
            n = N;
            s = S;
            arr = new int[s];
            top = new int[n];
            next = new int[s];

            // Inititalising top
            for(int i = 0; i < n; i++){
                top[i] = -1;
            }

            // Initialising next
            for(int i = 0; i < s; i++){
                next[i] = i + 1;
            }

            // Update value of last index to -1
            next[s - 1] = -1;

            // Initialising freeSpot
            freeSpot = 0;
        }

        // Pushes element x into mth stack, returns true if successful, false otherwise
        bool push(int x, int m){
            // Check for stack Overflow
            if(freeSpot == -1){
                return false;
            }

            // Step 1 : Find index
            int index = freeSpot;

            // Step 2 : Update freeSpot
            freeSpot = next[0];

            // Step 3 : Insert element in array
            arr[index] = x;

            // Step 4: Update next
            next[index] = top[m - 1];

            // Step 5 : Update top
            top[m - 1] = index;

            return true;
        }

        int pop(int m){
            // Check underflow 
            if(top[m - 1] == -1){
                return -1;
            }
            // Go with all steps in reverse order
            int index = top[m - 1];
            top[m - 1] = next[index];
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }
};