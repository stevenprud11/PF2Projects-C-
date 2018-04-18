//============================================================================
// Name        : Project1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Creature.h"
using namespace std;

int main() {
    //to make creature (name, strength (1-100), size (0-100), health(0-250), location (x,y))
    Creature monsters[10];
    for(int i =0; i<10; i++)
    {
        int str = rand()%100;
        int siz = rand()%100;
        int health = rand()%100;
        int x = rand()%100;
        int y = rand()%100;

        monsters[i] = Creature("Monster"+to_string(i+1), str, siz, health, x,y);
    }
    for(int i =0; i<10; i++)
    {
        monsters[i].print();
    }
    monsters[1].attack(monsters[2]); // ask professor about passing in an object and trying to change new objects instance data
    //I was not passing by reference and was passing a copy of the object
    int a = rand()%100;
    int b = rand()%100;
    monsters[7].moveTo(a,b);
    monsters[2].healing();

    return 0;
}
