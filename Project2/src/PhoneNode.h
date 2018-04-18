//
// Created by Steven Prudhomme on 1/31/18.
//

#ifndef PROJECT2_PHONENODE_H
#define PROJECT2_PHONENODE_H

#include <cstring>
#include <iostream>


using namespace std;

class PhoneNode {
public:
    //constructors
    PhoneNode();
    PhoneNode(const PhoneNode & p);
    PhoneNode(int id, string number, string owner, string maker);
    ~PhoneNode();
    //setter methods
    int getID();
    string getNumber();
    string getOwner();
    string getMaker();
    PhoneNode *getNext();
    //getter method
    void setID(int id);
    void setNumber(string number);
    void setOwner(string owner);
    void setMaker(string maker);
    void setNext(PhoneNode *next);

private:
    int ID;
    string Number;
    string Owner;
    string Maker;
    PhoneNode *Next;

};


#endif //PROJECT2_PHONENODE_H
