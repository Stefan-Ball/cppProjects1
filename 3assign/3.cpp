/*******************************************************************************************************************
 * *Program Filename: Grade_Calculator.cpp
 * *Author: Stefan Ball
 * *Date: 02/03/2017
 * *Description: Calculates an average for lab, assignments, tests, recitation, and the entire class
 * *Input: Weight, scores, and available points
 * *Output: Average in percentage
*******************************************************************************************************************/
#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
int initial_call();
bool valid_input();
bool in_range(int low, int high, int input);
double same_average(string choice, int n_stuff);
double different_average(string choice, int n_stuff);
int int_input (string prompt); 
bool is_num(string str); 
double lat (string choice);
double rec_average();
double class_average(double lab, double assign, double test, double reci);

/********************************************************************************************************************
 * Function: int main()
 * Description: Tells and saves the users average for lab, assignment, and recitation. Tells the user their class average
 * Parameters: None
 * Pre-Conditions:
 * Post-Conditions:
 * Return: 0
********************************************************************************************************************/ 
int main () {

   int x = -1;
   double lab_average = 0, assign_average = 0, test_average = 0, reci_average = 0;

   while (true) {

      do {
      x = initial_call();
      } while (!in_range(0, 5, x));

      switch (x) {
	 case 0:
	    exit(0);
	 case 1:
	    lab_average = lat("labs");
	    cout << "Your lab average is: " << lab_average << endl;
	    break;
	 case 2:
	    assign_average = lat("assignments");
	    cout << "Your assignment average is: " << assign_average << endl;
	    break;
	 case 3:
	    test_average = lat("tests");
	    cout << "Your test average is: " << test_average << endl;
	    break;
	 case 4:
	    reci_average = rec_average();
	    cout << "Your recitation average is: " << reci_average << endl;
	    break;
	 case 5:
	    cout << "Your class average is : " << class_average(lab_average, assign_average, test_average, reci_average) << endl;
      } 
   }
   return 0;
}


/********************************************************************************************************************
 * Function: class_average(double lab, double assign, double test, double reci) 
 * Description: Takes the weights of lab, assignments, tests, and recitation and calculates class average in accordance to point values they previously inputted into the program
 * Parameters: double lab, double assign, double test, double reci
 * Pre-Conditions:
 * Post-Conditions:
 * Return: Returns the users class average according to the weights of each section
********************************************************************************************************************/ 
double class_average(double lab, double assign, double test, double reci) {

   int lab_weight, assign_weight, test_weight, reci_weight;

   do {
      do {
	 lab_weight = int_input("What is the weight of lab? ");
      } while (!in_range(0, 100, lab_weight));

      do {
	 assign_weight = int_input("What is the weight of assignments? "); 
      } while (!in_range(0, 100, assign_weight));

      do {
	 test_weight = int_input("What is the weight of tests? ");
      } while (!in_range(0, 100, test_weight));

      do {
	 reci_weight = int_input("What is the weight of recitation? ");
      } while (!in_range(0, 100, reci_weight));
   } while (!(lab_weight + test_weight + reci_weight > 0));

   return (lab * lab_weight + assign * assign_weight + test * test_weight + reci * reci_weight) / (lab_weight + assign_weight +test_weight + reci_weight);
}

/********************************************************************************************************************
 * Function: rec_average()
 * Description: Asks for the weight of design, critique, and quiz
 * Parameters: None
 * Pre-Conditions:
 * Post-Conditions:
 * Return: The average weighted value of design, critique, and quiz
********************************************************************************************************************/ 
double rec_average() {

   int design = 0, quiz = 0, critique = 0;
   double design2 = 0, quiz2 = 0, critique2 = 0;

   do { 
      do {
	 design = int_input("What is the design weight? (out of 100) ");
      } while (!in_range(0, 100, design));

      do {
	 critique = int_input("What is the critique weight? (out of 100) ");
      } while (!in_range(0, 100, critique));

      do {
	 quiz = int_input("What is the quiz weight? (out of 100) "); 
      } while (!in_range(0, 100, critique));

      design2 = lat("designs");

      critique2 = lat("critiques");
      
      quiz2 = lat("quizzes");
   } while (!(design + critique + quiz) > 0);


   return (((double) design2 * design) + ((double) critique2 * critique) + ((double) quiz2 * quiz)) / (design + critique + quiz);


}








//Name: same_average(string choice, int n_stuff)
//Description: Asks user How many points is their (choice) worth and takes the average of their (choice)
//Pre Conditions:
//Post Conditions:
//Return: Average of (choice)
/********************************************************************************************************************
 * Function: same_average(string choice, int n_stuff)
 * Description: Asks user How many points is their (choice) worth and how many points they got for each chcoie 
 * Parameters: string choice, int n_stuff
 * Pre-Conditions:
 * Post-Conditions: 
 * Return: The average of their (choice)
********************************************************************************************************************/ 
double same_average(string choice, int n_stuff) {
   int input = -1, z = -1, x = 1, worth, numerator = 0, denominator = 0;
   if (n_stuff == 0) 
      return 0;

   if (choice == "quizzes")
      choice = choice.substr(0, choice.length() - 3);
   else
      choice = choice.substr(0, choice.length() - 1);

   do {
      cout << "How many points is each " << choice << " worth? ";
      z = int_input("");
   } while (!in_range(1, INT_MAX, z));

   do {
      input = -1;
      cout << "How many points did you get for " << choice << " " << x << "? ";
      input = int_input("");
      if (in_range(0, INT_MAX, input)) {
	 numerator += input;
	 ++x;
      }
   } while (x <= n_stuff);

   denominator = n_stuff * z;

   return ((double) numerator / denominator) * 100;
}


/********************************************************************************************************************
 * Function: different_average(string choice, int n_stuff)
 * Description: If the users (choice) differentiates in point values, this string will ask how many points each (choice) is worth, and how many points did the user get for each (choice)
 * Parameters: string choice, int n_stuff
 * Pre-Conditions:
 * Post-Conditions:
 * Return: The average of the users point differentiated (choice) results
********************************************************************************************************************/ 
double different_average(string choice, int n_stuff) {
   int d = -1, n, x = 1, worth, numerator = 0, denominator = 0;

   if (n_stuff == 0) 
      return 0;


   if (choice == "quizzes")
      choice = choice.substr(0, choice.length() - 3);
   else
      choice = choice.substr(0, choice.length() - 1);

   do {
      cout << "How many points is " << choice << " " << x << " worth? ";
      d = int_input("");
      if (in_range(1, INT_MAX, d)) {
	 denominator += d;
      }
      cout << "How many points did you get for " << choice << " " << x << "? ";
      n = int_input("");
      if (in_range(0, INT_MAX, n)) {
	 numerator += n;
	 ++x;
      }
   } while (x <= n_stuff);

   return ((double) numerator / denominator) * 100;
}

/********************************************************************************************************************
 * Function: lat(string choice) //Stands for labs/assignments/tests
 * Description: Asks the user how many (choices) they want to calculate for and whether or not  the point values vary to use as arguments in the next two functions I'm going to run
 * Parameters: string choice
 * Pre-Conditions:
 * Post-Conditions:
 * Return: Returns the function same_average or different_average depending on if they choose that their point values for their (choice) don't range
********************************************************************************************************************/ 
double lat(string choice) {
   int input = -1, yn = -1;

   do {
      cout << "How many " << choice << " have you had?";
      input = int_input(" ");
   } while (!in_range(0, INT_MAX, input));

   do {
      yn = int_input("Do the point values vary? 1) yes, 2) no ");
   } while (!in_range(1, 2, yn));

   switch (yn) {
      case 1:
	 return different_average(choice, input);
      case 2:
	 return same_average(choice, input);
   }



}

//VALID INPUT CHECKERS

//Checks to see if integer input is valid
/********************************************************************************************************************
 * Function: is_num(string str)
 * Description: Checks to make sure a string can be converted into a negative or positive integer
 * Parameters: string str
 * Pre-Conditions:
 * Post-Conditions:
 * Return: Returns true or false depeding on if the string is a valid integer
 ********************************************************************************************************************/ 
bool is_num(string str) {
   for (int i=0; i<str.length(); i++) { // From 0 to the length of string
      if (!(str.at(i)>='0' && str.at(i)<='9') && str.at(0) != '-') //If string at i is not between char 0 and 9, return not a number. Also allow negatives by allow char 0 to be '-'
	 return false;
   }
   return true; //Else the string will be a number
}

//Allows valid input. Takes in prompt as an input and returns the integer the user inputs
/********************************************************************************************************************
 * Function: int_input(string prompt)
 * Description: Takes in the prompt the I want to print to the screen and loops until the user inputs a valid integer
 * Parameters: string prompt
 * Pre-Conditions:
 * Post-Conditions:
 * Return: The valid integer the user inputs
 ********************************************************************************************************************/ 
int int_input (string prompt) {
   bool valid_input = true;
   int num;
   string input;  //C++ style string
   do {
      cout << prompt;
      getline(cin, input);
      if (is_num(input)) {
	 //Convert to integer
	 num = atoi(input.c_str());
	 return num;
      }
      else
	 valid_input = false;
   } while (!valid_input);
}


//This function checks to make sure that the user entered valid input
/********************************************************************************************************************
 * Function: valid_input()
 * Description: Checks to make sure cin input is allowed
 * Parameters: None
 * Pre-Conditions:
 * Post-Conditions:
 * Return: Will return true if cin input is valid, will return false if cin input is not valid
 ********************************************************************************************************************/ 
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
/********************************************************************************************************************
 * Function: in_range(int low, int high, int input)
 * Description: Returns true if input is between low and high and returns false if input is not between low and high
 * Parameters: Takes in two values for a range(int low and int high) and a third to check (int input)
 * Pre-Conditions:
 * Post-Conditions:
 * Return: True or false, depending on if input is between the parameters low and high
 ********************************************************************************************************************/ 
bool in_range(int low, int high, int input) {
   int start;

   if (low > high) {
      low = start;
      low = high;
      high = start;
   }
   if (input < low || input > high) 
      return false;
   else
      return true;
}


//INITIAL CALL

/********************************************************************************************************************
 * Function: initial_call() 
 * Description: This function will cout the initial call and return the users first choice for what they want to calculate.
 * Parameters: None
 * Pre-Conditions:
 * Post-Conditions:
 * Return: 0-5 for lab/assign/test/recitation/the_class
 ********************************************************************************************************************/ 
int initial_call() {
   int input = -1;
   do {
      input = int_input("Would you like to calculate an average for 1) labs, 2) assignments, 3) tests, 4) recitations, 5) the class, or 0) to quit? ");
   } while (!in_range(0, 5, input));
   return input;
} 
