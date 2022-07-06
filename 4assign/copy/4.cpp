#include <iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cctype> //Allows tolower() function
#include<ctime>
using namespace std;
//int round_1_player(string *phrase, string *message_guessed, string *message, int *round);
/*
int round(string *, string *);
bool guess_letter(string *message_guessed, string, string);
char char_guess(string);
*/
string letter_input(string);
void message_transfer(string *, string *);
void initial_call(int *, int *);
int int_input(string);
bool in_range(int, int, int);
bool is_num(string);
string string_input(string);
string consonant_input(string, string *);
string vowel_input(string, string *);
bool letter_already_used(string letter, string *);
bool letter_in_range(string);
bool valid_stringput(string);
int round_for_1_player(int, int *p1_total);
bool spin(int player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars);
bool right_guess(string letter_guess, string *phrase, string *message_guessed, int *dollars, int spin_num);
bool buy_vowel(int player, string *message_guessed, string *message, string *used_letters, int *dollars); 



int main () {

   srand(time(NULL));

   int players, round_set, p1_total = 0, p2_total = 0, p3_total = 0;

   string message_guessed, message;

   initial_call(&players, &round_set);

   

   if (players == 1)
      round_for_1_player(round_set, &p1_total);

   if (players == 2)
      ;
      //round_for_2_players(round_set);

   if (players == 3)
      ;
      //round_for_3_players(round_set);

   if (p1_total > p2_total && p1_total > p3_total)
      cout << "Player 1 wins the game!" << endl;

   else if (p2_total > p1_total && p2_total > p3_total)
      cout << "Player 2 wins the game!" << endl;

   else if (p3_total > p1_total && p3_total > p2_total)
      cout << "Player 2 wins the game!" << endl;

   else if (p3_total == p2_total && p3_total == p1_total)
      cout << "It's a 3 way tie!" << endl;

   else if (p3_total == p2_total && p2_total > p1_total)
      cout << "Player 2 and 3 tie for first!" << endl;

   else if (p3_total == p1_total && p1_total > p2_total)
      cout << "Player 1 and 3 tie for first!" << endl;

   else if (p1_total == p2_total && p1_total > p3_total)
      cout << "Player 1 and 2 tie for first!" << endl;

}	 









int round_for_1_player(int round_set, int *p1_total) {

   int user_choice, player = 1, round_at = 1, dollars = 0, p1_round = 0;

   string used_letters = "", message_guessed, message;

   bool spun_21;


   while (round_at <= round_set) {

      cout << "Round " << round_at << ". "; //Phrase to guess for this round

      message = string_input("Please enter a phrase to guess for this round: ");

      message_transfer(&message, &message_guessed);

      cout << "The message you entered is: " << message << endl;

      system("clear");

      while (message_guessed != message) {

	 cout << "The message is << " << message_guessed << endl;

	 cout << "Player " << player << ". " << endl;;

	 do {
	    user_choice = int_input("Do you want to spin (1), buy a vowel for 10 dollars (2), or solve the puzzle (3): ");
	 } while (!in_range(1, 3, user_choice)); //This allows the user to input their choice to spin, solve or buy

	 switch (user_choice) {

	    case 1: 
	       if (spin(player, &message_guessed, &message, &spun_21, &used_letters, &dollars)){
		  p1_round += dollars;	  
	       }
	       break;
	    case 2:
	       if (*p1_total < 10)
		  break;
	       if (buy_vowel(player, &message_guessed, &message, &used_letters, &dollars))
		  p1_round += dollars;
	       break;
	    case 3: 
	       //solve();
	       ;
	 }

	 cout << "Player 1 round score: " << p1_round << endl;


      }

      cout << "Player " << player << " wins this round for correctly guessing the phrase " << message << "!" << endl;

      *p1_total += p1_round;


      ++round_at;
   }
   cout << "Player 1 total: " << *p1_total << endl;

}

bool buy_vowel(int player, string *message_guessed, string *message, string *used_letters, int *dollars) {

   string vowel;

   *dollars = -10;

   int throw_away_dollars;

   vowel = vowel_input("10 dollars has been subracted from your total. Please guess a vowel", used_letters);

   if (right_guess(vowel, message, message_guessed, &throw_away_dollars, 0)) 
      return true;
   else
      return false;
}



bool spin(int player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars) {

   int spin;
   *dollars = 0;

   string letter;

   spin = rand() % 22;

   if (spin == 0) {

      cout << "You spun a zero, so you lose a turn" << endl;
      return false;
   }

   if (spin == 21) {

      *spun_21 = true;
      cout << "You spun a 21, so you lose this turn and two more" << endl;
      return false;
   }

   letter = consonant_input("Guess a consonant: ", used_letters);

   if (right_guess(letter, message, message_guessed, dollars, spin))
      return true;



}


//-> (from pointer area (location in memory) go to char, when using function associated with pointer)
bool right_guess(string letter_guess, string *phrase, string *message_guessed, int *dollars, int spin_num) {

   string new_message = "";
   int phrase_length = (*phrase).length();

   *dollars = 0; // So I points will be set at zero everytime the function runs

   for (int i = 0; i < phrase_length; i++) {

      if ( letter_guess.at(0) == phrase->at(i) ) {
	 new_message += letter_guess.at(0); //If the letter matches, replace it in the hidden message
	 if (spin_num > 0)
	    *dollars += spin_num; //Adds spin number for each right letter 

      }
      else {
	 new_message += (*message_guessed).at(i);

      }
   } 
   if (*dollars > 0) {
      *message_guessed = new_message;
      return true;

   }
   return false;
}






/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
int round(int num_players, string *phrase, string *message_guessed, int num_rounds, int *p1_total, int *p2_total, int *p3_total) {

   int input, p1, p2, p3, player = 1;




   cout << "Player " << player << ". ";

   do {
      input = int_input("Do you want to spin (1), buy a vowel (2), or solve the puzzle (3): ");
   } while (!in_range(1, 3, input)); //This allows the user to input their choice to spin, solve or buy

   //do {
   cout << "The message is " << *message_guessed << endl;

   switch (input) {

      case 1: //Choice == spin
	 //spin();
	 break;
      case 2: // Choice == buy
	 //vowel();
	 break;
      case 3: //Choice == solve
	 //solve();
	 ;
   }

   cout << "Player 1 round total: $" << p1 << endl;

   if (num_players > 1)
      cout << "Player 2 round total: $" << p2 << endl;

   if (num_players > 2)
      cout << "Player 3 round total: $" << p3 << endl;
   //} while (!phrase_guessed(message);

   if (player == 1)
      cout << "Player 1 wins round!" << endl;

   if (player == 2)
      cout << "Player 2 wins round!" << endl;

   if (player == 3)
      cout << "Player 3 wins round!" << endl;



   return 0;

}


int round_num(int num_rounds, int num_players, string *phrase, string *message_guessed, int *p1_total, int *p2_total, int *p3_total, string *already_used) {

   int round_at = 1;

   *p1_total = 0;
   *p2_total = 0;
   *p3_total = 0;

   while (round_at <= num_rounds) {

      cout << "Round " << round << ". Please enter a phrase to guess for this round: "; //Phrase to guess for this round

      *phrase = string_input("");

      //message_transfer(phrase);

      *message_guessed = *phrase;

      *already_used = "";

      round(num_players, phrase, message_guessed, num_rounds, p1_total, p2_total, p3_total);

      cout << "Player 1 total: " << *p1_total << endl;

      if (num_players > 1)
	 cout << "Player 2 total: " << *p2_total << endl;

      if (num_players > 2)
	 cout << "Player 3 total: " << *p3_total << endl;
   }

   if (*p1_total > *p2_total && *p1_total > *p3_total)
      cout << "Player 1 wins the game!" << endl;

   else if (*p2_total > *p1_total && *p2_total > *p3_total)
      cout << "Player 2 wins the game!" << endl;

   else if (*p3_total > *p1_total && *p3_total > *p2_total)
      cout << "Player 2 wins the game!" << endl;

   else if (*p3_total == *p2_total && *p3_total == *p1_total)
      cout << "It's a 3 way tie!" << endl;

   else if (*p3_total == *p2_total && *p2_total > *p1_total)
      cout << "Player 2 and 3 tie for first!" << endl;

   else if (*p3_total == *p1_total && *p1_total > *p2_total)
      cout << "Player 1 and 3 tie for first!" << endl;

   else if (*p1_total == *p2_total && *p1_total > *p3_total)
      cout << "Player 1 and 2 tie for first!" << endl;

}
























































/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
string vowel_input(string prompt, string *used_letters) {

   string letter = "d", letter_input, u2 = *used_letters;

   do {
      cout << prompt;
      getline(cin, letter_input); //Allows me to check that user only entered one character
      letter = tolower(letter_input.at(0)); //Makes letter lowercase

   } while  (!(letter_input.length() == 1) ||  !( letter.at(0) == 'a' || letter.at(0) == 'e' || letter.at(0) == 'i' || letter.at(0) == 'o' || letter.at(0) == 'u' ) || letter_already_used(letter, &u2) );


   *used_letters += letter; //Adds letters to check if letters have already been inputted

   return letter;
}


/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
string consonant_input(string prompt, string *used_letters) {

   string letter = "i", u2 = *used_letters, letter_input;

   do {
      cout << prompt;
      getline(cin, letter_input); //Allows me to check that user only entered one character
      letter = tolower(letter_input.at(0)); //Makes letters lowercase
   } while ( !(letter_input.length() == 1) || !(letter.at(0) >= 'a' && letter.at(0) <= 'z') || ( (letter.at(0) >= 'a' && letter.at(0) <= 'z') && ( letter.at(0) == 'a' || letter.at(0) == 'e' || letter.at(0) == 'i' || letter.at(0) == 'o' || letter.at(0) == 'u' ) ) || letter_already_used(letter, &u2) );


   *used_letters += letter; //Adds letters to check if letters have already been inputted


   return letter;
}



//This will transfer the message someone types in to a hidden message. Only allows strings with letters, ', or spaces
/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
void message_transfer(string *message, string *message_guessed) {

   *message_guessed = "";

   string temp_message = *message;

   *message = "";

   for (int i = 0; i < temp_message.length(); i++) {

      if ((temp_message.at(i) >= 'a' && temp_message.at(i) <= 'z') || (temp_message.at(i) >= 'A' && temp_message.at(i) <= 'Z')) {
	 *message_guessed += " _ "; //If the char is a letter, it will display a _
	 *message += " ";
	 *message += temp_message.at(i);
	 *message += " ";

      }
      else if (temp_message.at(i) == '\'') { //If the char is a ', then it will show a '
	 *message_guessed += "'";
	 *message += "'";

      }
      else if (temp_message.at(i) == ' ') { //If the char is a space, it will show an extra long space (to make for spaces in letters)
	 *message_guessed += "    ";
	 *message += "    ";

      }
   }

}

//This function will welcome the user, Allow them to enter a phrase to guess, ask how many players (1-3) the user wants to have, and asks how many rounds the user would like to play. Uses call by reference to assign variables in main
/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
void initial_call(int *players, int *round_set) {

   cout << "Welcome to Wheel of Fortune! To play, hit enter. "; //Welcomes user
   cin.ignore(INT_MAX, '\n');
   cin.clear();


   do {
      *players = int_input("Would you like to play with 1, 2, or 3 players? "); //Players in the game (1-3)

   } while (!in_range(1, 3, *players));

   do {
      *round_set = int_input("How many rounds would you like to play? "); //Rounds to play (>1)

   } while (!in_range(1, INT_MAX, *round_set));

}





















































// VALID INPUT AND INPUT CHECKERS 


bool letter_already_used(string letter, string *used_letters) {


   for (int i = 0; i < used_letters->length(); i++) {
      if ( letter.at(0) == used_letters->at(i) ) {
	 return true;
      }
   }
   return false;
}

//This function will only allow valid input for a string (in this game) and return the valid string
/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
string string_input(string prompt) {

   string input, temp_input = "";

   do {
      cout << prompt;
      getline(cin, input);
   } while (!valid_stringput(input) || input == "");

   for (int i = 0; i < input.length(); i++) {
      temp_input += tolower(input.at(i));
   }

   return temp_input;
}

//This will check to make sure each char that the user enters is a valid character for the phrase
/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
bool valid_stringput(string input) {

   for (int i = 0; i < input.size(); i++) {
      if ((input.at(i) < 'a' || input.at(i) > 'z') && (input.at(i) < 'A' || input.at(i) > 'Z') && (input.at(i) != ' ') && (input.at(i) != '\'')) {
	 return false;
      }
   }
   return true;
}


//Checks to see if integer input is valid
/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
bool is_num(string str) {
   for (int i = 0; i <str.length(); i++) {
      if ((str.at(i) < '0' || str.at(i) > '9')) {
	 return false;
      }
      else
	 return true;
   }
}

/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
int int_input(string prompt) {
   bool valid_input;
   int num;
   string input;
   while (true) {
      cout << prompt;
      getline(cin, input);
      if (is_num(input)) {
	 num = atoi(input.c_str());
	 return num;
      }
   }
}

/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************/
bool in_range(int start, int end, int input) {

   int beg;


   if (end < start) {
      beg = start;
      start = end;
      end = beg;
   }

   if (input < start || input > end) {
      return false;
   }
   else {
      return true;
   }
}


















































//USELESS



/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************
 bool consonant(string letter_guess) {

 if ( (letter_guess.at(0) >= 'a' && letter_guess.at(0) <= 'z') && !( letter_guess.at(0) == 'a' || letter_guess.at(0) == 'e' || letter_guess.at(0) == 'i' || letter_guess.at(0) == 'o' || letter_guess.at(0) == 'u' ) )
 return true;
 else
 return false;
 }
 */





/*
//Kinda useless
bool letter_in_range(string letter_guess) {

if ((letter_guess.at(0) >= 'a' && letter_guess.at(0) <= 'z') || (letter_guess.at(0) >= 'A' && letter_guess.at(0) <= 'Z')){
return true; //If the guess is a letter, it's valid input
}
else {
return false; //If the guess is not a letter, it's not valid input
}

}
*/



/*
 *************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************
 string letter_input(string prompt) {

 string letter, *used_letters;
 *used_letters = "";

 do {
 cout << prompt;
 getline(cin, letter);

 } while (!(letter.length() == 1) || !( ((letter.at(0) >= 'a') && (letter.at(0) <= 'z')) || !((letter.at(0) <= 'A') && (letter.at(0) >= 'Z')) ) );

 letter = tolower(letter.at(0)); //Makes letters lowercase

 *used_letters += letter; //Adds letters to check if letters have already been inputted


 return letter;
 }
 */



/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************
 bool vowel(string letter_guess) {

 if ( letter_guess.at(0) == 'a' || letter_guess.at(0) == 'e' || letter_guess.at(0) == 'i' || letter_guess.at(0) == 'o' || letter_guess.at(0) == 'u' )
 return true;
 else
 return false;
 }
 */







// Main Garbage





//string message, *message_guessed, used_letters; //Creates message strings. Sets used letters to nothing
/*
 *used_letters = ""; //Need to reset this one each round
 string *message_guessed, *phrase;
 int players, round_set = 1, round_num = 1, player1 = 0, player2 = 0, player3 = 0, *points; //Creates ints. Sets player scores to 0. Need to reset this one each round
 bool play_again = true; //Sets play again to true to run the initial loop

 initial_call(); //This will allow the user to enter a phrase, # players, and # rounds

 cout << "The phrase you entered is: \"" << message << "\". Press enter to continue"; //Tells user the phrase
 cin.ignore(INT_MAX, '\n'); //Ignores any input the user gives, allows the program to show the message before the screen is cleared
 system("clear"); //Command from cstdlib that will clear the output screen so that the user can no longer see the output message.

 *message_guessed = message_transfer(message); //This will initialize the hidden message



 while (round_num <= round_set) {
 round();
 round_num++;
 }

*/











/*
   if (*p1_total > *p2_total && *p1_total > *p3_total)
   cout << "Player 1 wins the game!" << endl;

   else if (*p2_total > *p1_total && *p2_total > *p3_total)
   cout << "Player 2 wins the game!" << endl;

   else if (*p3_total > *p1_total && *p3_total > *p2_total)
   cout << "Player 2 wins the game!" << endl;

   else if (*p3_total == *p2_total && *p3_total == *p1_total)
   cout << "It's a 3 way tie!" << endl;

   else if (*p3_total == *p2_total && *p2_total > *p1_total)
   cout << "Player 2 and 3 tie for first!" << endl;

   else if (*p3_total == *p1_total && *p1_total > *p2_total)
   cout << "Player 1 and 3 tie for first!" << endl;

   else if (*p1_total == *p2_total && *p1_total > *p3_total)
   cout << "Player 1 and 2 tie for first!" << endl;

*/
