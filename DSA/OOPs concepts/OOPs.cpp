/*Object Oriented Programming Skills*/
#include<iostream>
using namespace std;
// defining an object
class Hero{
    public: 
    // defining properties
    char name[100];
    int health;
    char level;
};
class empty{
    // properties do not exist
    // the system still gives one byte of the memory to the class for its identification
};
int main(){
    Hero h1;
    cout << "Size of Hero class is: " << sizeof(h1) << endl;

    empty e1;
    cout << "Size of empty object is: " << sizeof(e1) << endl;

    // to access the property of some object
    // h1.health = 5;
    // h1.level = 'k';
    cout << "Health of ramesh is: " << h1.health << endl;
    cout << "Level of ramesh is: " << h1.level << endl;
    h1.health = 5;
    h1.level = 'k';
    cout << "Health of ramesh is: " << h1.health << endl;
    cout << "Level of ramesh is: " << h1.level << endl;
}