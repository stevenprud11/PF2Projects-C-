//============================================================================
// Name        : Project4.cpp
// Author      : Steven Prudhomme
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <sstream>
#include "Stack.h"
#include <vector>
#include <string>

using namespace std;


int main() {
	Stack stack;
	string temp;
	vector<string> str (1000);
	cout << "Enter, in PostFix notation boolean value to find::" << endl;
	cout << "Separate parameters by a ',' and end statment with a '?'" << endl;
	cout << "True is 1 False is 0" << endl;
	cin >> temp;

	istringstream ss(temp);
	string curr;
	while(getline(ss, curr, ',')){
		str.push_back(curr);
	}



	int i=0;

	while(str.at(i) != "?"){
		//pushing numbers onto stack
		if(i>str.size()){
			cout << "ERROR. Did not enter ? to end statement." << endl;
			return -1;
		}
		if(str.at(i) == " "){
			cout << "ERROR. You used a space while entering in data. Please try again" << endl;
		}
		if((str.at(i) >= "0") && (str.at(i) <= "9")){
			int ptr = stoi(str.at(i));
			//cout << ptr << endl;
			stack.Push(ptr);
		}
		//checking >
		if(str.at(i) == ">"){
			if(stack.getLength()<2){
				cout << "Not enough data in stack to execute" << endl;
				return NULL;
			}
			int num2 = stack.Pop();
			int num1 = stack.Pop();
			if(num2>num1){
				cout << num2 << ">" << num1 <<  " Is true Pushing 1 onto stack..." << endl;
				stack.Push(1);
			}
			else{
				cout << num2 << ">" << num1 <<  " Is false Pushing 0 onto stack..." << endl;
				stack.Push(0);
			}
		}
		//checking <
		else if(str.at(i) == "<"){
			if(stack.getLength()<2){
				cout << "Not enough data in stack to execute" << endl;
				return NULL;
			}
			int num2 = stack.Pop();
			int num1 = stack.Pop();
			if(num2<num1){
				cout << num2 << "<" << num1 <<  " Is true Pushing 1 onto stack..." << endl;
				stack.Push(1);
			}
			else{
				cout << num2 << "<" << num1 <<  " Is false Pushing 0 onto stack..." << endl;
				stack.Push(0);
			}

		}
		//checking =
		else if(str.at(i) == "="){
			if(stack.getLength()<2){
				cout << "Not enough data in stack to execute" << endl;
				return NULL;
			}
			int num2 = stack.Pop();
			int num1 = stack.Pop();
			if(num2==num1){
				cout << num2 << "=" << num1 <<  " Is true Pushing 1 onto stack..." << endl;
				stack.Push(1);
			}
			else{
				cout << num2 << "=" << num1 <<  " Is false Pushing 0 onto stack..." << endl;
				stack.Push(0);
			}
		}
		else if(str.at(i) == "||"){
			if(stack.getLength()<2){
				cout << "Not enough data in stack to execute" << endl;
				return NULL;
			}
			int num2 = stack.Pop();
			int num1 = stack.Pop();
			bool val2;
			bool val1;
			if(num2 == 0)
				val2 = false;
			else if (num2 == 1)
				val2 = true;
			if(num1 == 0)
				val1 = false;
			else if(num1 == 1)
				val1 = true;
			if(val2 || val1){
				cout << val2 << " OR " << val1 << " is true Pushing 1 onto stack..." << endl;
				stack.Push(1);
			}
			else{
				cout << val2 << " OR " << val1 << " is false Pushing 0 onto stack..." << endl;
				stack.Push(0);
			}
		}
		else if(str.at(i) == "&&"){
			if(stack.getLength()<2){
				cout << "Not enough data in stack to execute" << endl;
				return NULL;
			}
			int num2 = stack.Pop();
			int num1 = stack.Pop();
			bool val2;
			bool val1;
			if(num2 == 0)
				val2 = false;
			else if (num2 == 1)
				val2 = true;
			if(num1 == 0)
				val1 = false;
			else if(num1 == 1)
				val1 = true;
			if(val2 && val1){
				cout << val2 << " AND " << val1 << " is true Pushing 1 onto stack..." << endl;
				stack.Push(1);
			}
			else{
				cout << val2 << " AND " << val1 << " is false Pushing 0 onto stack..." << endl;
				stack.Push(0);
			}
		}

		//need to check bool values == >= <= > <
		i++;
	}
	cout << "Stack is:: ";
	stack.Print();
	cout << endl;

	if(stack.Top()==0)
		cout << "Equation is False" << endl;
	else if(stack.Top()==1)
		cout << "Equation is True" << endl;
	else
		cout << "Error Logic. Not enough parameters are in stack to find boolean value." << endl;

	return 0;
}
