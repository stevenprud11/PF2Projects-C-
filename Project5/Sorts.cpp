/*
 * Sorts.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: steven
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <array>


//sort - nr file.txt > file.sort  sorts in reverse order with larger number first
using namespace std;
string *oneWord = new string[1000000];

//------------------------------------------------------------------
// Read a single word from din
//------------------------------------------------------------------
bool read_word_bool(string & word, ifstream & din)
{
   // Initialize variables
   word = "";
   bool found_word = false;

   // Loop reading characters until word is found
   while (!din.fail() && !din.eof() && !found_word)
   {
      // Read next character from file
      char ch;
      din.get(ch);

      // Append lower case letter to word
      if (ch >= 'a' && ch <= 'z')
	 word = word + ch;

      // Convert upper case letter to lower case and append
      else if (ch >= 'A' && ch <= 'Z')
	 word = word + char(ch - 'A' + 'a');

      // Return word if length greater than zero
      else if (word.length() > 0)
	 found_word = true;
   }
   return found_word;
   // Return boolean flag
   return false;
}



void merge_sort(string data[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      merge_sort(data, low, mid);
      merge_sort(data, mid + 1, high);

      // Create temporary array for merged data
      string *copy = new string[range];

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	 if (data[index1] < data[index2])
	    copy[index++] = data[index1++];
	 else
	    copy[index++] = data[index2++];
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
	 copy[index++] = data[index1++];

      // Copy any remaining entries from the second half
      while (index2 <= high)
	 copy[index++] = data[index2++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
    	  	  data[low + index] = copy[index];
      delete[]copy;
   }
}



//---------------------------------------------------------------------
// Main program to read and print words from an ASCII file
//---------------------------------------------------------------------
int main(int argc, char *argv[])
{

   // Get file names
   cout << "Enter name of input file: ";
   string name1;
   cin >> name1;

   // Open files
   ifstream din;
   din.open(name1.c_str());
   //makes sure there is a file with right name
   if(din.fail()){
	   cout << "Error in opening file" << endl;
	   exit(1);
   }
   // Read and inserts words one by one into array
   string word;
   int count=0;
   while (read_word_bool(word, din)){
	   oneWord[count]=word;
	   count++;
   }
   // size of two word array is one less than one word array
   count--;
   string *twoWord = new string[count];
   //inserting words into two word array
   for(int i=0; i<count; i++){
	   twoWord[i] = oneWord[i] + " " + oneWord[i+1];
   }
   //reading out array before merge sort
   cout << "Before Merge Sort" << endl;
   for(int i=0; i<count; i++){
	   cout << i << " " << twoWord[i] << endl;
   }

   merge_sort(twoWord,0,count-1);
   delete [] oneWord;		//creates more space for data in local memory for program

   //reading sorted array
   cout << endl << "After Merge Sort" << endl;
   for(int i=0; i<count; i++){
	   cout << i << " " <<  twoWord[i] << endl;
   }

   //searching unique phrases in the array
   int countArr[count];
   //all values in count Array are 0
   for(int i=0; i<count; i++){
	   countArr[i]=0;
   }
   int index = 0;

   //creates output text file
   ofstream outFile;
   outFile.open("output_Copper.txt");
   //inserting data into text and occurrence of value
   for(int i=0; i<count; i++){
	   if(index < count){
		   string s = twoWord[index];
		   countArr[i]++;
		   //searching array while index is same as original increments count for location i
		   while(s == twoWord[index+1]){
			   countArr[i]++;
			   index++;
		   }
		   if(countArr[i] != 0){ //if the count in location is not = to 0 then adds number of occurrences and value
			   outFile << countArr[i] << " " << twoWord[index] << endl;
		   }
		   index++;
	   }
   }

   outFile.close();

   cout << "Finally finished" << endl;
}



