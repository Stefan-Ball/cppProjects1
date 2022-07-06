#include <iostream>
#include <climits>
#include <cstring>
#include <cstdlib>
int initial_call();
bool valid_input();
bool in_range(int low, int high, int input);
bool in_range();

using namespace std;

int main () {

   initial_call();


   return 0;
}










//This function checks to make sure that the user entered valid input
bool valid_input() {

   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      return false;
   }
   else
      return true;
}

//This function checks to see if the users input is in the range specified
bool in_range(int low, int high, int input) {
   int start;

   if (low > high) {
      low = start;
      low = high;
      high = start;
   }
   if (input < low || input > high) 
