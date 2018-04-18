//
// Created by Steven Prudhomme on 1/31/18.
//

#include "PhoneNode.h"


//constructors-------------------------------------------
PhoneNode::PhoneNode()
{
    ID = 0;
    Number = "";
    Owner = "";
    Maker = "";
    Next = NULL;
}
PhoneNode::PhoneNode(int id, string number, string owner, string maker) {
    ID = id;
    Number= number;
    Owner = owner;
    Maker = maker;
    Next = NULL;

}
PhoneNode::~PhoneNode() {

}

//setting methods----------------------------------------
void PhoneNode::setID(int id){
    ID = id;
}
void PhoneNode::setNumber(string number) {
    Number = number;
}
void PhoneNode::setOwner(string owner) {
    Owner=owner;
}
void PhoneNode::setMaker(string maker) {
    Maker=maker;
}
void PhoneNode::setNext(PhoneNode *next) {
    Next=next;
}

//getter methods------------------------------------------
int PhoneNode::getID() {
    return ID;
}
string PhoneNode::getNumber() {
    return Number;
}
string PhoneNode::getOwner() {
    return Owner;
}
string PhoneNode::getMaker() {
    return Maker;
}
PhoneNode *PhoneNode::getNext() {
    return Next;
}
