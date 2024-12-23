#include<iostream>
using namespace std;
void reachHome(int start, int end){
    //base case
    cout << "start point " << start << " end point " << end << endl;
    if(start == end){
        cout << "Reached destination" << endl;
        return ;
    }
    // ek step aage badh gaye h
    start++;
    reachHome(start, end);
}
int main(){
    int start, end;
    cout << "Enter the starting and ending coordinate: ";
    cin >> start >> end;
    reachHome(start, end);
}