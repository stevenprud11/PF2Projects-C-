/*
 * Creature.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: steven
 */

#include "Creature.h"

Creature::Creature() {
    name = "";
    strength = 0;
    size = 0;
    health = 0;
    location = "";
}

Creature::Creature(string n, int str, int siz, int heal, int xPos, int yPos) {
    name = n;
    strength = str;
    size = siz;
    health = heal;
    x = xPos;
    y = yPos;
    setLocation(x,y);
}

Creature::~Creature() {
}

//get methods
string Creature::getName(){
    return name;
}
string Creature::getLocation(){
    string xPos = to_string(getX());
    string yPos = to_string(getY());
    string output= "("+xPos+","+yPos+")";

    return output;
}
int Creature::getHealth(){
    return health;
}
int Creature::getSize(){
    return size;
}
int Creature::getStrength(){
    return strength;
}
int Creature::getX(){
    return x;
}
int Creature::getY() {
    return y;
}

//set methods
void Creature::setName(string n){
    name = n;
}
void Creature::setHealth(int h){
    health = h;
}
void Creature::setLocation(int xPos, int yPos){
    string xNew = to_string(xPos);
    string yNew = to_string(yPos);
    location= "("+xNew+","+yNew+")";
}
void Creature::setStrength(int s){
    strength = s;
}
void Creature::setSize(int s){
    size = s;
}
void Creature::setX(int xPos) {
    x = xPos;
}
void Creature::setY(int yPos) {
    y = yPos;
}

//3 new methods
void Creature::attack(Creature &monster) {

    int str = strength;
    int a = monster.getHealth()-strength;
    monster.setHealth(a);
    if(a<1) {
        cout << name << " has attacked " <<
        monster.getName() << " with " << strength << " damage and it has died " <<endl;
    } else {
        cout << name << " has attacked " <<
        monster.getName() << " with " << strength << " damage and it now has " << monster.getHealth() << " health "<<endl;
    }


}
void Creature::moveTo(int xPos, int yPos)
{
    string loc = location;
    setLocation(xPos, yPos);
    cout<<name << " has moved from " << loc << " to " << location << endl;
}
void Creature::healing()
{
    int h = getHealth();
    setHealth(h+50);
    cout<< name << " has just healed from " << h << " to " << getHealth() << endl;
}


//print method
void Creature::print(){
    cout<< "Name: " << name << endl
        <<"Size: " << size << endl
        <<"Strength: " << strength << endl
        <<"Health: " << health << endl
        <<"Location: " << location << endl << endl;
}


