/*
 * Stack.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: steven
 */

#include "Stack.h"
#include <stdlib.h>
#include <iostream>

namespace std {

Stack::Stack() {
	// TODO Auto-generated constructor stub
	Head = NULL;
	Length = 0;
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

void Stack::Push(int n){
	Length++;
	SNode *temp = new SNode();
	temp->Number=n;
	temp->Next=Head;
	Head=temp;
}
int Stack::Pop(){
	Length--;
	SNode *temp = new SNode();
	temp = Head;
	Head = Head->Next;
	return temp->Number;

}
int Stack::Top(){
	return Head->Number;
}

int Stack::getLength(){
	return Length;
}
bool Stack::IsEmpty(){
	if (Length==0)
		return false;
	return true;
}
bool Stack::IsFull(){
	return false;
}
void Stack::Print(){
	SNode *ptr = Head;
	while(ptr!=NULL){
		cout << ptr->Number << endl;
		ptr = ptr->Next;
	}
}


} /* namespace std */
