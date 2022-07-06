/***********************************************************************************************
**Program: assign1.cpp
**Author: Stefan Ball
**Date: 1/14/2017
**Description: Print the max and min values for a specified number of bits
**Input: An integer value of bits
**Output: The largest and smallest signed and unsigned values for the specified number of bits 
************************************************************************************************/



#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main () {
   int bit;

   // Tells user the max and min signed and unsigned values for an integer
   cout << "Min signed int: " << pow(-2,15) + 1 << endl;
   cout << "Max signed int: " << pow(2,15) - 1 << endl;
   cout << "Min unsigned int: " << 0 << endl;
   cout << "Max unsigned int: " << pow(2,16) - 1 << endl;

   // Tells user the max and min signed and unsigned values for a long
   cout << "Min signed long: " << pow(-2,31) + 1 << endl;
   cout << "Max signed long: " << pow(2,31) - 1 << endl;
   cout << "Min unsigned long: " << 0 << endl;
   cout << "Max unsigned long: " << pow(2, 32) - 1 << endl;

   // Tells user the max and min signed and unsigned values for a short
   cout << "Min signed short: " << pow(-2,15) + 1 << endl;
   cout << "Max signed short: " << pow(2,15) - 1 << endl;
   cout << "Min unsigned short: " << 0 << endl;
   cout << "Max unsigned short: " << pow(2,16) - 1 << endl;

   // Tells user the max and min signed and unsigned values for a byte
   cout << "Min signed byte: " << pow(-2,8 - 1) + 1 << endl;
   cout << "Max signed byte: " << pow(2,8 - 1) - 1 << endl;
   cout << "Min unsigned byte: " << 0 << endl;
   cout << "Max unsigned byte: " << pow(2,8) - 1 << endl; 

   // Tells user the max and min signed and unsigned values for the integer number of bits that they enter
   cout << "Please input the number of bits you want to calculate the max and min valuse for both signed and unsigned numbers: ";
   cin >> bit;
   cout << "The min signed value for your number of bits is " << pow(-2,bit - 1) + 1 << endl;
   cout << "The max signed value for your number of bits is " << pow(2, bit -1) - 1 << endl;
   cout << "The min unsigned value for your number of bits is " << 0 << endl;
   cout << "The max unsigned value for your number of bits is " << pow(2,bit) - 1 << endl;

   return 0;
} 
