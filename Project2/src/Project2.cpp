//============================================================================
// Name        : Project2.cpp
// Author      : Steven Prudhomme
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "PhoneList.h"


#include <iostream>
#include <sstream>
using namespace std;

//-----------------------------------------------------------
// Main program
//-----------------------------------------------------------
int main()
{
    // TODO: create empty linked list

    // Initialize arrays of strings for names
    const int SIZE = 10;
    string first[SIZE] = { "John", "Jane", "Steve", "Susan", "Brian",
                           "Betty", "Mark", "Mary", "Craig", "Cindy" };
    string last[SIZE] = { "Smith", "Johnson", "Williams", "Jones", "Brown",
                          "Davis", "Miller", "Wilson", "Moore", "Taylor" };
    string makers[SIZE] = { "Samsung", "Apple", "Huawei", "Oppo", "Vivo",
                            "OnePlus", "Xiaomi", "Lenovo", "LG", "Sony" };
    PhoneList *list;
    // Test insert method
    const int COUNT = 100;
    cout << "\nTesting INSERT\n";
    list = new PhoneList(); //at first I had this in the for loop and it would make a new linked list every iteration of loop so the insertion was clobbered
    for (int count = 0; count < COUNT; count++)
    {
        // Print ID
        int id = rand() % 1000;
        //cout << "ID: " << id << endl;

        // Print Number
        stringstream sout;
        sout << "479-" << 100 + rand() % 900 << "-" << 1000 + rand() % 9000;
        string number = sout.str();
        //cout << "Number: " << number << endl;

        // Print Owner
        string owner = first[rand() % SIZE] + " " + last[rand() % SIZE];
        //cout << "Owner: " << owner << endl;

        // Print Maker
        int num = rand() % SIZE;
        string maker = makers[num];
        //cout << "Maker: " << maker << endl << endl;

        // TODO: insert into phone list (Inserting new Node)
        list->insertHead(id, number, owner, maker);

    }

    // TODO: print current phone list
    list->print();


    // Test search method
    cout << "\nTesting SEARCH\n";
    for (int count = 0; count < 20; count++)
    {// Print ID
        int id = rand() % 1000;
        cout << "ID: " << id << endl;
        // TODO: call search using this ID
        PhoneNode *curr = list->searchFor(id);
        if(curr!=NULL) {
            cout << "Owner with ID " << id << " is " << curr->getOwner() << endl;
        }
    }
    //had issues with cases that I did not account for such as curr->getNext()==NULL never tested for it and for loop would crash
    // Test delete method
    cout << "\nTesting DELETE\n";
    for (int count = 0; count < 20; count++)
    {
        // Print ID
        int id = rand() % 1000;
        cout << "Attempting to delete node with ID: " << id << endl;
        list->deleteNode(id);
        // TODO: call delete using this ID

    }

     //TODO: print final phone list
    list->print();

}
