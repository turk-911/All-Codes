#include<iostream>
using namespace std;
class hero{
    private:
    
    public:
        int health;
        char level;
        void print()
        {
            cout << level << endl;
    }
    /*Getters and setters*/
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
};
int main(){
    hero ramesh;
    cout << "Health of Ramesh is: " << ramesh.getHealth() << endl;
    ramesh.setHealth(70);
    ramesh.setLevel('a');
    cout << "New heath of Ramesh is: " << ramesh.getHealth() << endl;
    cout << "New level of Ramesh is: " << ramesh.getLevel() << endl;


    // static alloaction
    hero a;

    // dynamic allocation
    hero *b = new hero;

    cout << a.getLevel() << " is the level of A" << endl;
    cout << "Dynamic allocation: " << endl;
    cout << "Health of a is: " << b->health << endl;
    cout << "Level of a is: " << b->getLevel() << endl;
}