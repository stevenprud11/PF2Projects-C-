//
// Created by Steven Prudhomme on 1/31/18.
//

#include "PhoneList.h"


PhoneList::PhoneList(){
    Head = NULL;
}
PhoneList::PhoneList(const PhoneList & list){

}
PhoneList::~PhoneList() {

    while(Head!=NULL)
    {
        PhoneNode *ptr = Head;
        Head = ptr->getNext();
        delete ptr;
    }
}
//insert head method ----------------------------------------------------------------------
void PhoneList::insertHead(int id, string number, string owner, string maker) {
    PhoneNode *ptr = new PhoneNode(id, number, owner, maker);
    ptr->setNext(Head);
    Head=ptr;
    Count++;
}
//delete node method -----------------------------------------------------------------------
void PhoneList::deleteNode(int id) {
    PhoneNode *curr=Head;
    PhoneNode *prev=Head;

    //will either set current to the correct node or if = null return "wasn't in linked list"
    while((curr!=NULL) && (curr->getID()!=id))
    {
        prev = curr;
        curr = curr->getNext();
    }
    if(curr==NULL) //meaning id is not in the linked list
        cout << "Phone with ID:: " << id << " is not in the Linked List.\n" << endl;
    else if(curr->getNext()==NULL)//if curr is the last element in the list
    {
        prev->setNext(NULL);
        cout<< "Delete was successful of ID:: " << id << "\n" << endl;
        delete curr;
    }
    else if(curr==Head)//if curr is the head of the linked list
    {
        Head = curr->getNext();
        cout<< "Delete was successful of ID:: " << id << "\n" << endl;
        delete curr;
    }
    else if(curr->getNext()!=NULL)//if curr is in the middle somewhere in the linked list
    {
        prev->setNext(curr->getNext()); //just skips over curr
        cout<< "Delete was successful of ID:: " << id << "\n" << endl;
        delete curr;
    }

}
//had issues with cases that I did not account for such as curr->getNext()==NULL never tested for it and for loop would crash

//searching method -----------------------------------------------
PhoneNode* PhoneList::searchFor(int id) {
    PhoneNode *ptr = Head;
    for(int i =0; i<Count; i++) {
        if (ptr->getID()==id)//checking if id's match
        {
            return ptr;
        }
        else
            ptr=ptr->getNext();
    }
    //if dropping out of for loop no one exist with that id
    cout << "No one has ID:: " << id << endl;
    return NULL;
}

//printing method ------------------------------------------------
void PhoneList::print() {
    PhoneNode *ptr = Head;
    for(int i=0; i<Count;i++)
    {
        cout << "\nID:: " << ptr->getID()
             << "\nOwner:: " << ptr->getOwner()
             << "\nNumer:: " << ptr->getNumber()
             <<  "\nMaker:: " << ptr->getMaker()
             << endl;
        ptr=ptr->getNext();
    }




}
