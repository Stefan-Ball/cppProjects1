#include <iostream>
#include <cstring>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;
void get_strings(char **&temp_words); 
void nums_for_transfer_strings(char **temp_words, int &num_regular_nouns, int &num_s_nouns, int &num_ing_verbs, int &num_regular_verbs, int &num_adjectives); 
void transfer_nouns(char **temp_words, int num_regular_nouns, int num_s_nouns, char **&regular_noun, char **&s_noun); 
void transfer_verbs(char **temp_words, int num_regular_verbs, int num_ing_verbs, char **&regular_verb, char **&ing_verb); 
void transfer_adjectives(char **temp_words, int num_adjectives, char **&adjective); 
void print_regular_noun(int num_regular_nouns, char **regular_noun); 
void print_s_noun(int num_s_nouns, char **s_noun); 
void print_regular_verb(int num_regular_verbs, char **regular_verb); 
void print_ing_verb(int num_ing_verbs, char **ing_verb); 
void print_adjective(int num_adjectives, char **adjective); 
void story_1(int num_regular_nouns, int num_s_nouns, int num_regular_verbs, int num_ing_verbs, int num_adjectivs, char **regular_noun, char **s_noun, char **regular_verb, char**ing_verb, char **adjective); 
void story_2(int num_regular_nouns, int num_s_nouns, int num_regular_verbs, int num_ing_verbs, int num_adjectives, char **regular_noun, char **s_noun, char **regular_verb, char**ing_verb, char **adjective); 
void story_3(int num_regular_nouns, int num_s_nouns, int num_regular_verbs, int num_ing_verbs, int num_adjectives, char **regular_noun, char **s_noun, char **regular_verb, char**ing_verb, char **adjective); 
bool in_range(int start, int end, int num); 
void int_input(string prompt, int &num); 
int valid_input(int argc, char **argv); 
void delete_temp(char **&temp_words); 
void delete_arrays(int num_adjectives, char **adjective, int num_regular_verbs, char **regular_verb, int num_ing_verbs, char **ing_verb, int num_regular_nouns, char **regular_noun, int num_s_nouns, char **s_noun); 

/*************************************************************************************************
 ** Function: main
 ** Description: Runs mad libs, creates arrays to hold words and counters 
 ** Parameters: argc, argv[][]
 ** Pre-Conditions: int, char **
 ** Post-Conditons: prints mad libs paragraph
 ** Return: 0
 **************************************************************************************************/
int main(int argc, char *argv[]) {

   srand(time(NULL));

   //Var to hold story user chooses
   int user_choice;

   //Temporary array to hold all the input from the input file
   char **temp_words;

   //Dynamic arrays to hold the different types of words for blank spaces
   char **regular_noun, **s_noun, **ing_verb, **regular_verb, **adjective;

   //Integers to hold the number of different types of words to make the dynamic arrays the right size
   int num_regular_nouns=0, num_s_nouns=0, num_ing_verbs=0, num_regular_verbs=0, num_adjectives=0;

   //Get all the strings from input
   get_strings(temp_words);

   //Get the numbers to transfer the strings into dynamic arrays
   nums_for_transfer_strings(temp_words, num_regular_nouns, num_s_nouns, num_ing_verbs, num_regular_verbs, num_adjectives); 

   //Transfers the strings to arrays with the correct place and the exact size
   transfer_nouns(temp_words, num_regular_nouns, num_s_nouns, regular_noun, s_noun); 
   transfer_verbs(temp_words, num_regular_verbs, num_ing_verbs, regular_verb, ing_verb); 
   transfer_adjectives(temp_words, num_adjectives, adjective);
   //deletes temporary array
   delete_temp(temp_words); 

   //Decides which story to run
   user_choice = valid_input(argc, argv);

   switch (user_choice) {

      case 1:
	 story_1(num_regular_nouns, num_s_nouns, num_regular_verbs, num_ing_verbs, num_adjectives, regular_noun, s_noun, regular_verb, ing_verb, adjective); 
	 break;
      case 2:
	 story_2(num_regular_nouns, num_s_nouns, num_regular_verbs, num_ing_verbs, num_adjectives, regular_noun, s_noun, regular_verb, ing_verb, adjective); 
	 break;
      case 3:
	 story_3(num_regular_nouns, num_s_nouns, num_regular_verbs, num_ing_verbs, num_adjectives, regular_noun, s_noun, regular_verb, ing_verb, adjective); 

   }

   delete_arrays(num_adjectives, adjective, num_regular_verbs, regular_verb, num_ing_verbs, ing_verb, num_regular_nouns, regular_noun, num_s_nouns, s_noun); 

   return 0;
}

/*************************************************************************************************
 ** Function: valid input
 ** Description: Makes sure the user entered a valid story
 ** Parameters: argc, argv[][]
 ** Pre-Conditions: int, double char array
 ** Post-Conditons: user_choice is set to command line input or random number if invalid input
 ** Return: user_choice
 **************************************************************************************************/
int valid_input(int argc, char **argv) {

   bool valid_input = true;
   int user_choice = 0;

   //make sure argv[1] exits
   if (argc > 1) {
      for (int i = 0; i < strlen(argv[1]); i++) {
	 //if argv[1] is not a number, there is not valid input
	 if (argv[1][i] > '9' || argv[1][i] < '0')
	    valid_input = false; 
      }
      //if argv[1] is a number and it's not in range, then it's not valid input
      if (valid_input) {
	 user_choice = atoi(argv[1]);
	 if (!in_range(1, 3, user_choice))
	    valid_input = false;
      }
   }
   else {
      //If argv[1] doesn't exist, then there was no input
      valid_input = false;
   }


   if (!valid_input)
      user_choice = (rand() % 3) + 1;
   //int_input("Please choose between story 1, 2, and 3", user_choice);

   return user_choice;
}

/*************************************************************************************************
 ** Function: int_input
 ** Description: Allows an integer to be inputted
 ** Parameters: prompt, num
 ** Pre-Conditions: string, int
 ** Post-Conditons: num is set to number inputted
 ** Return: none
 **************************************************************************************************/
void int_input(string prompt, int &num) {

   //Use to check valid input
   bool valid_input = false;

   //Temporarily store number in char array
   char temp[200];

   while (!valid_input) {
      //Assume valid input
      valid_input = true;
      cout << prompt;
      cin >> temp;
      cin.ignore(INT_MAX, '\n');
      for (int i = 0; i < strlen(temp); i++) {
	 //If invalid input, run loop again to get valid number
	 if (temp[i] > 9 || temp[i] < '0')
	    valid_input = false;
      }
   }

   //Set num equal to input
   num = atoi(temp);

}

/*************************************************************************************************
 ** Function: in_range
 ** Description: Makes sure that a integer is in a range of integers
 ** Parameters: start, end, num
 ** Pre-Conditions: int
 ** Post-Conditons: none
 ** Return: true, false
 **************************************************************************************************/
bool in_range(int start, int end, int num) {

   // if the number is between start and end it's in range
   if (num >= start && num <= end)
      return true;

   //or it's not
   return false;

}

/*************************************************************************************************
 ** Function: story_1
 ** Description: Prints first story
 ** Parameters: Every array of different word, all counters
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: Prints the first story
 ** Return: none
 **************************************************************************************************/
void story_1(int num_regular_nouns, int num_s_nouns, int num_regular_verbs, int num_ing_verbs, int num_adjectives, char **regular_noun, char **s_noun, char **regular_verb, char**ing_verb, char **adjective) {

   cout << "Most doctors agree that ";

   print_ing_verb(num_ing_verbs, ing_verb);

   cout << " is a/an ";

   print_adjective(num_adjectives, adjective);

   cout << " form of exercise. ";

   print_ing_verb(num_ing_verbs, ing_verb);

   cout << " a bicycle enables you to develop your";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " muscles, as well as increase the rate of your ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " beat. More ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " around the world ";

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << " bicycles than drive ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". No matter what kind of ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " you ";

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << ", always be sure to wear a/an ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". Make sure to have ";

   print_adjective(num_adjectives, adjective);

   cout << "reflectors too!" << endl;

}

/*************************************************************************************************
 ** Function: story_2
 ** Description: Prints second story
 ** Parameters: Every array of different word, all counters
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: Prints the second story
 ** Return: none
 **************************************************************************************************/
void story_2(int num_regular_nouns, int num_s_nouns, int num_regular_verbs, int num_ing_verbs, int num_adjectives, char **regular_noun, char **s_noun, char **regular_verb, char**ing_verb, char **adjective) {

   cout << "Yesterday, ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " and I went to the park. On our way to the ";

   print_adjective(num_adjectives, adjective);

   cout << " park, we saw a ";

   print_adjective(num_adjectives, adjective);

   cout << " ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " on a bike. We also saw big ";

   print_adjective(num_adjectives, adjective);

   cout << " balloons tied to a ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". Once we got to the "; 

   print_adjective(num_adjectives, adjective);

   cout << " park, the sky turned ";

   print_adjective(num_adjectives, adjective);

   cout << ". It started to ";

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << " and ";

   print_regular_verb(num_regular_verbs, regular_verb);

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << ". ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " and I ";

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << " all the way home. Tomorrow we will try to go to the ";

   print_adjective(num_adjectives, adjective);

   cout << " park again and hope it doesn't "; 

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << "." << endl;
}

/*************************************************************************************************
 ** Function: story_3
 ** Description: Prints third story
 ** Parameters: Every array of different word, all counters
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: Prints the third story
 ** Return: none
 **************************************************************************************************/
void story_3(int num_regular_nouns, int num_s_nouns, int num_regular_verbs, int num_ing_verbs, int num_adjectives, char **regular_noun, char **s_noun, char **regular_verb, char**ing_verb, char **adjective) {

   cout << "Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some ";

   print_adjective(num_adjectives, adjective);

   cout << " place to spend time with ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". Getting to ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " is going to take ";

   print_adjective(num_adjectives, adjective);

   cout << " hours. My favorite part of spring break is ";

   print_ing_verb(num_ing_verbs, ing_verb);

   cout << " in the ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". During spring break, ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " and I plan to ";

   print_ing_verb(num_ing_verbs, ing_verb);

   cout << " all the way to ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". After spring break, I will be ready to return to ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << " and ";

   print_regular_verb(num_regular_verbs, regular_verb);

   cout << " hard to finish ";

   print_regular_noun(num_regular_nouns, regular_noun);

   cout << ". Thanks spring break 2017!" << endl;
}

/*************************************************************************************************
 ** Function: print_regular_noun
 ** Description: Prints noun not ending in s
 ** Parameters: num_regular_nouns, regular_noun
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: Prints noun not ending in s
 ** Return: none
 **************************************************************************************************/
void print_regular_noun(int num_regular_nouns, char **regular_noun) {

   //Randomly generate a noun to print
   int choice = rand() % num_regular_nouns;   

   cout << regular_noun[choice];
}

/*************************************************************************************************
 ** Function: print_s_noun
 ** Description: Prints noun ending in s
 ** Parameters: num_s_nouns, s_noun
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: Random s noun is printed
 ** Return: none
 **************************************************************************************************/
void print_s_noun(int num_s_nouns, char **s_noun) {

   //Randomly generate an s_noun to print
   int choice = rand() % num_s_nouns;

   cout << s_noun[choice];
}

/*************************************************************************************************
 ** Function: print_regular_verb
 ** Description: Prints a regular verb (non ing ending)
 ** Parameters: num_regular_verbs, regular_verb
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: Prints non ing ending verb
 ** Return: none
 **************************************************************************************************/
void print_regular_verb(int num_regular_verbs, char **regular_verb) {

   //Randomly generate a regular_verb to print
   int choice = rand() % num_regular_verbs;

   cout << regular_verb[choice];
}

void print_ing_verb(int num_ing_verbs, char **ing_verb) {

   // Randomly generate an ing_verb to print
   int choice = rand() % num_ing_verbs;

   cout << ing_verb[choice];
}

/*************************************************************************************************
 ** Function: print_adjective
 ** Description: Prints a random adjective
 ** Parameters: num_adjectives, adjective
 ** Pre-Conditions: int, char double array
 ** Post-Conditons: adjective is printed
 ** Return: none
 **************************************************************************************************/
void print_adjective(int num_adjectives, char **adjective) {

   //Randomly generate an adjective to print
   int choice = rand() % num_adjectives;

   cout << adjective[choice];
}

/*************************************************************************************************
 ** Function: transfer_verb
 ** Description: Transfers all verbs to ing_verb and regular_verb arrays
 ** Parameters: temp_words, verb arrays, verb counters
 ** Pre-Conditions: double char array, int
 ** Post-Conditons: verb arrays intitialized, verb counters set
 ** Return: none
 **************************************************************************************************/
void transfer_verbs(char **temp_words, int num_regular_verbs, int num_ing_verbs, char **&regular_verb, char **&ing_verb) {

   // Allows starting place to transfer array
   int count = 0, count_2 = 0;

   //Set regular_verb equal to num of reg verbs
   regular_verb = new char*[num_regular_verbs];

   //Set ing_verb equal to num of ing verbs
   ing_verb = new char*[num_ing_verbs];

   //Find verbs to transfer
   for (int i = 0; i < 50; i += 2) {

      // if the string is a verb and does not end in "ing" 
      if ( !strcmp(temp_words[i], "verb") && !(temp_words[i+1][strlen(temp_words[i+1]) - 1] == 'g' && temp_words[i+1][strlen(temp_words[i+1]) - 2] == 'n' && temp_words[i+1][strlen(temp_words[i+1]) - 3] == 'i') ) {
	 //Then create the array regular_verb[count] to have the exact length to hold the word
	 regular_verb[count] = new char[strlen(temp_words[i+1]) + 1];
	 //Copy the word
	 strcpy(regular_verb[count], temp_words[i+1]);
	 //Increment count
	 count++;
      }
      // else if it's a verb and does end in "ing", add one to num_ing_verbs
      else if ( !strcmp(temp_words[i], "verb") ) {
	 //Creat array ing_verb[count_2] to have the exact length to hold the word
	 ing_verb[count_2] = new char[strlen(temp_words[i+1]) + 1];
	 //Copy the word
	 strcpy(regular_verb[count_2], temp_words[i+1]);
	 //Increment count_2
	 count_2++;
      }
   }
}

/*************************************************************************************************
 ** Function: delete_array
 ** Description: deletes all arrays
 ** Parameters: arrays, counters
 ** Pre-Conditions: double char array, int
 ** Post-Conditons: All arrays deleted
 ** Return: none
 **************************************************************************************************/
void delete_arrays(int num_adjectives, char **adjective, int num_regular_verbs, char **regular_verb, int num_ing_verbs, char **ing_verb, int num_regular_nouns, char **regular_noun, int num_s_nouns, char **s_noun) {

   //deletes adjective array
   for (int i = 0; i < num_adjectives; i++)
      delete [] adjective[i];
   delete [] adjective;

   //deletes regular_verb array
   for (int i = 0; i < num_regular_verbs; i++)
      delete [] regular_verb[i];
   delete [] regular_verb;

   //deletes ing_verb array
   for (int i = 0; i < num_ing_verbs; i++)
      delete [] ing_verb[i];
   delete ing_verb;

   //deletes regular_noun array
   for (int i = 0; i < num_regular_nouns; i++)
      delete [] regular_noun[i];
   delete [] regular_noun;

   //deletes s_noun array
   for (int i = 0; i < num_s_nouns; i++)
      delete [] s_noun[i];
   delete [] s_noun;


}

/*************************************************************************************************
 ** Function: transfer_adjectives
 ** Description: Transfers all adjectives to adjective array
 ** Parameters: temp_words, adjective array, adjective counter
 ** Pre-Conditions: double char array, int
 ** Post-Conditons: adjective is initialized
 ** Return: none
 **************************************************************************************************/
void transfer_adjectives(char **temp_words, int num_adjectives, char **&adjective) {

   //So I can increment the array temp_words[i]
   int count = 0;

   // set adjective equal to num_adjectives
   adjective = new char*[num_adjectives];

   for (int i = 0; i < 50; i++) {

      // if the string is an adjective
      if ( !strcmp(temp_words[i], "adjective") ) {
	 //Then create the array adjective[count] to have the exact length to hold the word
	 adjective[count] = new char[strlen(temp_words[i+1]) + 1];
	 //copy the word
	 strcpy(adjective[count], temp_words[i+1]);
	 //Increment count
	 count++;
      }
   }

}

/*************************************************************************************************
 ** Function: transfer_nouns
 ** Description: Transfers all nouns to regular_noun and s_noun arrays
 ** Parameters: temp_words, noun counters, noun arrays
 ** Pre-Conditions: double char array, int
 ** Post-Conditons: regular_noun, s_noun initialized
 ** Return: none
 **************************************************************************************************/
void transfer_nouns(char **temp_words, int num_regular_nouns, int num_s_nouns, char **&regular_noun, char **&s_noun) {

   // This number will allow me to put the arrays in their rightful place
   int count = 0, count_2 = 0;

   //Set regular_noun to allow as many regular nouns as I found
   regular_noun = new char*[num_regular_nouns];

   //Set s_noun to allow as many s_nouns as I found
   s_noun = new char*[num_s_nouns];

   //Find the nouns to transfer
   for (int i = 0; i < 50; i += 2) {
      //If it's a regular noun
      if ( !strcmp(temp_words[i], "noun") && temp_words[i+1][strlen(temp_words[i+1]) - 1] != 's') {
	 //then create the dynamic char array regular_noun to have the exact length to hold the word
	 regular_noun[count] = new char[strlen(temp_words[i+1]) + 1];
	 //Copy the word
	 strcpy(regular_noun[count], temp_words[i+1]);
	 //Increment the number for num_regular nouns
	 count++;
      }
      //Else if it's an s_noun
      else if ( !strcmp(temp_words[i], "noun") ) {
	 //Then create the dynamic char array s_noun to have the exact length to hold the word
	 s_noun[count_2] = new char[strlen(temp_words[i+1]) + 1];
	 //Copy the word
	 strcpy(s_noun[count_2], temp_words[i+1]);
	 //Increment the number for num_s_nouns
	 count_2++;
      }
   }
}

/*************************************************************************************************
 ** Function: get_strings
 ** Description: reads in all input from file
 ** Parameters: temp_words
 ** Pre-Conditions: double char array
 ** Post-Conditons: all words from file are read
 ** Return: none
 **************************************************************************************************/
void get_strings(char **&temp_words) {

   temp_words = new char*[200];
   for (int i = 0; i < 200; i++)
      temp_words[i] = new char[31];

   //Puts every string into array that holds all the words temporarily
   //for (int i = 0; i < 50; i++)
   int i = 0;
   while(cin >> temp_words[i++]);
}

/*************************************************************************************************
 ** Function: delete_temp
 ** Description: deletes temp_words
 ** Parameters: temp_words
 ** Pre-Conditions: char double array
 ** Post-Conditons: temp_words is deleted
 ** Return: none
 **************************************************************************************************/
void delete_temp(char **&temp_words) {

   for (int i = 0; i < 200; i++)
      delete [] temp_words[i];
   delete [] temp_words;

}


/*************************************************************************************************
 ** Function: nums_for_transfer_strings
 ** Description: Gets the right set of numbers for my dynamic arrays
 ** Parameters: temp double char array, int counters
 ** Pre-Conditions: int, double char array
 ** Post-Conditons: counters are initialized
 ** Return: none
 **************************************************************************************************/
void nums_for_transfer_strings(char **temp_words, int &num_regular_nouns, int &num_s_nouns, int &num_ing_verbs, int &num_regular_verbs, int &num_adjectives) {


   for (int i = 0; i < 50; i += 2) {

      // if the string is a noun and does not end in s, add one to num_regular_nouns
      if ( !strcmp(temp_words[i], "noun") && temp_words[i+1][strlen(temp_words[i+1]) - 1] != 's')
	 num_regular_nouns++;
      // else if it doesn't end in s and is a noun, add one to num_s_nouns 
      else if ( !strcmp(temp_words[i], "noun") ) {
	 num_s_nouns++;
      }

      // if the string is a verb and does not end in "ing", add one to num_regular_verbs
      if ( !strcmp(temp_words[i], "verb") && !(temp_words[i+1][strlen(temp_words[i+1]) - 1] == 'g' && temp_words[i+1][strlen(temp_words[i+1]) - 2] == 'n' && temp_words[i+1][strlen(temp_words[i+1]) - 3] == 'i') )
	 num_regular_verbs++;
      // else if it's a verb and does end in "ing", add one to num_ing_verbs
      else if ( !strcmp(temp_words[i], "verb") )
	 num_ing_verbs++;

      // if the string is an adjective, then add one to num_adjectives
      if ( !strcmp(temp_words[i], "adjective") )
	 num_adjectives++;
   }

}
