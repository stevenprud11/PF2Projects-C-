/*
 * Creature.h
 *
 *  Created on: Feb 14, 2018
 *      Author: steven
 */

#ifndef PROJECT1_CREATURE_H
#define PROJECT1_CREATURE_H

#include <iostream>
#include <cstring>
using namespace std;

class Creature {
public:
    Creature();
    Creature(string n, int str, int siz, int heal, int x, int y);
    int getSize();
    int getStrength();
    int getHealth();
    int getX();
    int getY();
    string getName();
    string getLocation();
    void print(); //calls get methods to print out all the stats of a creature
    void setSize(int s);
    void setStrength(int s);
    void setHealth(int h);
    void setName(string n);
    void setLocation(int x, int y);
    void setX(int x);
    void setY(int y);
    //custom methods
    void attack(Creature &monster); //the monster will attack another monster
    void moveTo(int x, int y);
    void healing(); //heals creature 50 health
    //void relocate();
    virtual ~Creature();
private:
    int size;
    int strength;
    int health;
    int x;
    int y;
    string name;
    string location; //should be in the format (x,y)
};


#endif //PROJECT1_CREATURE_H
