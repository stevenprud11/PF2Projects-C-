//
// Created by Steven Prudhomme on 1/31/18.
//

#ifndef PROJECT2_PHONELIST_H
#define PROJECT2_PHONELIST_H

#include <iostream>
#include <cstring>
#include "PhoneNode.h"


using namespace std;

class PhoneList {
public:
    //constructors
    PhoneList();
    PhoneList(const PhoneList & list);
    ~PhoneList();
    //insert
    void insertHead(int id, string number, string owner, string maker);
    //search returns the object with same id, if none exist prints out none exsits and return type NULL
    PhoneNode* searchFor(int id);
    //delete deletes node with same id. does nothing if none match with id
    void deleteNode(int id);
    //print
    void print();
private:
    PhoneNode *Head;
    int Count;
};


#endif //PROJECT2_PHONELIST_H
