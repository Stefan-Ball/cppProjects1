#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
void get_strings(char **&temp_words); 
void nums_for_transfer_strings(char **temp_words, int &num_regular_nouns, int &num_s_nouns, int &num_ing_verbs, int &num_regular_verbs, int &num_adjectives); 
void transfer_nouns(char **temp_words, int num_regular_nouns, int num_s_nouns, char **regular_noun, char **s_noun); 
void transfer_verbs(char **temp_words, int num_regular_verbs, int num_ing_verbs, char **regular_verb, char **ing_verb); 
void transfer_adjectives(char **temp_words, int num_adjectives, char **adjective); 

int main() {

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

}

void transfer_verbs(char temp_words, int num_regular_verbs, int num_ing_verbs, char **regular_verb, char **ing_verb) {

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

void transfer_adjectives(char temp_words, int num_adjectives, char **adjective) {

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


void transfer_nouns(char temp_words, int num_regular_nouns, int num_s_nouns, char **regular_noun, char **s_noun) {

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






//Gets all strings from input
void get_strings(char **&temp_words) {

   temp_words = new char*[50];
   for (int i = 0; i < 50; i++)
      temp_words[i] = new char[31];

   //Puts every string into array that holds all the words temporarily
   for (int i = 0; i < 50; i++)
      cin >> temp_words[i];
}

//Gets the right set of numbers for my dynamic arrays
void nums_for_transfer_strings(char temp_words, int &num_regular_nouns, int &num_s_nouns, int &num_ing_verbs, int &num_regular_verbs, int &num_adjectives) {


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
