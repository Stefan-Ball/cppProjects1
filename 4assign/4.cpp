#include <iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cctype> //Allows tolower() function
#include<ctime> //Alows randint();
using namespace std;
//int round_1_player(string *phrase, string *message_guessed, string *message, int *round);
/*
int round(string *, string *);
bool guess_letter(string *message_guessed, string, string);
char char_guess(string);
*/
//int round_for_2_player(int round_set, int *p1_total, int *p2_total);
//void initial_p2_round(int *p1_round, int *p2_round, string *used_letters, string *message, string *original_message); 
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
bool spin(int player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0);
bool right_guess(string letter_guess, string *phrase, string *message_guessed, int *dollars, int spin_num);
bool buy_vowel(int player, string *message_guessed, string *message, string *used_letters, int *dollars); 
bool guess_message(int player, string *message, string *message_guessed, string original_message, string *used_letters, int *dollars);
int round_for_1_player(int round_set, int *p1_total);
void round_for_3_player(int round_set, int *p1_total, int *p2_total, int *p3_total);
void who_wins(int *, int *, int *);
void round_with_3_player_switch(int *player, int *p1_round, int *p2_round, int *p3_round, bool *spun_0);
void initial_for_3_player(int *p1_round, int *p2_round, int *p3_round, string *used_letters, int *round_at, string *message, string *original_message, string *message_guessed);
void second_initial_3(int *user_choice, int player, string message_guessed, int *dollars); 
void round_with_3_total(int p1_total, int p2_total, int p3_total); 
void round_with_3_total_add(int *p1_total, int *p1_round, int *p2_total, int *p2_round, int *p3_total, int *p3_round, int player); 
void round_with_3_player_round_score(int p1_round, int p2_round, int p3_round); 
void switch_round_3_player(string *message_guessed, string *message, int *round_set, int *p1_total, int *p2_total, int *p3_total, int *round_at, int *dollars, int *p1_round, int *p2_round, int *p3_round, int *p1_turn, int *p2_turn, int *p3_turn, int *p1_play_again, int *p2_play_again, int *p3_play_again, string *used_letters, string *original_message, bool *spun_21, bool *second_skip, bool *third_skip, bool *spun_0, bool *third_chance, int *player, int user_choice); 
bool case_1_3_player(int *player, int *p1_round, int *p2_round, int *p3_round, int *dollars, string *message_guessed, string *message, bool *spun_21, string *used_letters, bool *spun_0); 
void round_total_to_0(bool *spun_0, int *player, int *p1_round, int *p2_round, int *p3_round); 
bool case_2_3_player(int *player, int *p1_round, int *p2_round, int *p3_round, int *dollars, string *message_guessed, string *message, string *used_letters, int *p1_total, int *p2_total, int *p3_total); 
void initial_p1_round(int *p1_round, string *used_letters, int *round_at, string *message, string *original_message, string *message_guessed); 
void second_initial_p1_round(string *message_guessed, int *player, int *user_choice); 
void case_1_p1_round(int *player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0, int *p1_round); 
void switch_p1_round(int *user_choice, int *player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0, int *p1_round, int *p1_total, string *original_message); 
void round_with_2_player_switch(int *player, int *p1_round, int *p2_round, int *p3_round, bool *spun_0); 
void round_with_2_total(int p1_total, int p2_total, int p3_total); 
void round_with_2_player_round_score(int p1_round, int p2_round, int p3_round); 
void switch_round_2_player(string *message_guessed, string *message, int *round_set, int *p1_total, int *p2_total, int *p3_total, int *round_at, int *dollars, int *p1_round, int *p2_round, int *p3_round, int *p1_turn, int *p2_turn, int *p3_turn, int *p1_play_again, int *p2_play_again, int *p3_play_again, string *used_letters, string *original_message, bool *spun_21, bool *second_skip, bool *third_skip, bool *spun_0, bool *third_chance, int *player, int user_choice); 
void round_for_2_player(int round_set, int *p1_total, int *p2_total, int *p3_total); 
void go_to_zero(bool *spun_0, int *player, int *p1_round, int *p2_round, int *p3_round); 



/*************************************************************************************************
 * Function: Main
 * Description: Runs functions
 * Parameters: None
 * Pre-Conditions: No arguments
 * Post-Conditons: Ouputs winner
 * Return: 0
 ************************************************************************************************/
int main () {

   srand(time(NULL));

   int players, round_set, p1_total = 0, p2_total = 0, p3_total = 0;

   string message_guessed, message;

   initial_call(&players, &round_set);

   if (players == 1)
      round_for_1_player(round_set, &p1_total);

   if (players == 2)
      round_for_2_player(round_set, &p1_total, &p2_total, &p3_total); 


   if (players == 3) 
      round_for_3_player(round_set, &p1_total, &p2_total, &p3_total);

   who_wins(&p1_total, &p2_total, &p3_total);

   return 0;



}	 

/*************************************************************************************************
 * Function: round_for_3_player
 * Description: Runs round for player == 3
 * Parameters: int round_set, int *p1_total, int *p2_total, int *p3_total
 * Pre-Conditions: int, mem location of int, mem location of int, mem location of int
 * Post-Conditons: passes values for player totals in p(1/2/3)_total
 * Return: None
 ************************************************************************************************/
void round_for_3_player(int round_set, int *p1_total, int *p2_total, int *p3_total) {

   int user_choice, player = 1, round_at = 1, dollars = 0, p1_round, p2_round, p3_round;

   int p1_turn = 1, p2_turn = 1, p3_turn = 1, p1_play_again = 0, p2_play_again = 0, p3_play_again = 0;

   string used_letters = "", message_guessed, message, original_message;

   bool spun_21 = false, second_skip = false, third_skip = false, spun_0 = false, third_chance = false;



   while (round_at <= round_set) {

      dollars = 0;

      initial_for_3_player(&p1_round, &p2_round, &p3_round, &used_letters, &round_at, &message, &original_message, &message_guessed); 

      while (message_guessed != message) {

	 second_initial_3(&user_choice, player, message_guessed, &dollars);

	 switch_round_3_player(&message_guessed, &message, &round_set, p1_total, p2_total, p3_total, &round_at, &dollars, &p1_round, &p2_round, &p3_round, &p1_turn, &p2_turn, &p3_turn, &p1_play_again, &p2_play_again, &p3_play_again, &used_letters, &original_message, &spun_21, &second_skip, &third_skip, &spun_0, &third_chance, &player, user_choice); 

	 round_with_3_player_round_score(p1_round, p2_round, p3_round); 

      }

      cout << "Player " << player << " wins this round for correctly guessing the phrase " << message << "!" << endl;

      round_with_3_total_add(p1_total, &p1_round, p2_total, &p2_round, p3_total, &p3_round, player); 

      round_with_3_player_round_score(p1_round, p2_round, p3_round); 

      ++round_at;
   }

   round_with_3_total(*p1_total, *p2_total, *p3_total); 
}

/*************************************************************************************************
 * Function: switch_round_3_player
 * Description: The switch statement for a player = 3
 * Parameters: string *message_guessed, string *message, int *round_set, int *p1_total, int *p2_total, int *p3_total, int *round_at, int *dollars, int *p1_round, int *p2_round, int *p3_round, int *p1_turn, int *p2_turn, int *p3_turn, int *p1_play_again, int *p2_play_again, int *p3_play_again, string *used_letters, string *original_message, bool *spun_21, bool *second_skip, bool *third_skip, bool *spun_0, bool *third_chance, int *player
 * Pre-Conditions: mem location of string, mem location of string, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of string, mem location of string, mem location of bool, mem location of bool, mem location of bool, mem location of bool, mem location of bool, mem location of int
 * Post-Conditons: Changes the contents of the mem locations of the parameters
 * Return: None
 ************************************************************************************************/
void switch_round_3_player(string *message_guessed, string *message, int *round_set, int *p1_total, int *p2_total, int *p3_total, int *round_at, int *dollars, int *p1_round, int *p2_round, int *p3_round, int *p1_turn, int *p2_turn, int *p3_turn, int *p1_play_again, int *p2_play_again, int *p3_play_again, string *used_letters, string *original_message, bool *spun_21, bool *second_skip, bool *third_skip, bool *spun_0, bool *third_chance, int *player, int user_choice) {

   switch (user_choice) {

      case 1: 

	 if (case_1_3_player(player, p1_round, p2_round, p3_round, dollars, message_guessed, message, spun_21, used_letters, spun_0))
	    break;

	 round_with_3_player_switch(player, p1_round, p2_round, p3_round, spun_0); 

	 break;

      case 2:

	 if (case_2_3_player(player, p1_round, p2_round, p3_round, dollars, message_guessed, message, used_letters, p1_total, p2_total, p3_total))
	    break; 

	 round_with_3_player_switch(player, p1_round, p2_round, p3_round, spun_0); 

	 break;

      case 3: 

	 if (guess_message(*player, message, message_guessed, *original_message, used_letters, dollars)) {
	    break;
	 }

	 round_with_3_player_switch(player, p1_round, p2_round, p3_round, spun_0); 

   }


}

/*************************************************************************************************
 * Function: case_2_3_player
 * Description: Runs case 2 for player == 3
 * Parameters: int *player, int *p1_round, int *p2_round, int *p3_round, int *dollars, string *message_guessed, string *message, string *used_letters, int *p1_total, int *p2_total, int *p3_total
 * Pre-Conditions: mem location of int, mem location of int, mem location of int, mem location of int, mem location of string, mem location of string, mem location of string, mem location of int, mem location of int, mem location of int
 * Post-Conditons: Passes values into mem locations of parameters
 * Return: None
 ************************************************************************************************/
bool case_2_3_player(int *player, int *p1_round, int *p2_round, int *p3_round, int *dollars, string *message_guessed, string *message, string *used_letters, int *p1_total, int *p2_total, int *p3_total) {

   *dollars = -10;

   if ( (*player == 1 && (*p1_round < 10)) || (*player == 2 && (*p2_round < 10)) ||  (*player == 3 && (*p3_round < 10)) )
      return true;


   if (*player == 1)
      *p1_round += *dollars;

   if (*player == 2)
      *p2_round += *dollars;

   if (*player == 3)
      *p3_round += *dollars;

   if ((buy_vowel(*player, message_guessed, message, used_letters, dollars))) {
      return true;
   }


   return false;
}

/*************************************************************************************************
 * Function: case_1_3_player
 * Description: Case 1 for 3 players
 * Parameters: int *player, int *p1_round, int *p2_round, int *p3_round, int *dollars, string *message_guessed, string *message, bool *spun_21, string *used_letters, bool *spun_0
 * Pre-Conditions: mem location of int, mem location of int, mem location of int, mem location of int, mem location of string, mem location of string, mem location of bool, mem location of string, mem location of bool
 * Post-Conditons: Mem location parameters change depnding on guess
 * Return: True or false depending on how player guessed
 ************************************************************************************************/
bool case_1_3_player(int *player, int *p1_round, int *p2_round, int *p3_round, int *dollars, string *message_guessed, string *message, bool *spun_21, string *used_letters, bool *spun_0) {

   if (*player == 1 && spin(*player, message_guessed, message, spun_21, used_letters, dollars, spun_0)){
      *p1_round += *dollars;	
      return true;
   }
   if (*player == 2 && spin(*player, message_guessed, message, spun_21, used_letters, dollars, spun_0)){
      *p2_round += *dollars;	  
      return true;
   }

   if (*player == 3 && spin(*player, message_guessed, message, spun_21, used_letters, dollars, spun_0)){
      *p3_round += *dollars;	  
      return true;
   }

   round_total_to_0(spun_0, player, p1_round, p2_round, p3_round);

   return false;
}

/*************************************************************************************************
 * Function: round_total_to_0
 * Description: if a player spins 0, then their total is set to 0
 * Parameters: bool *spun_0, int *player, int *p1_round, int *p2_round, int *p3_round
 * Pre-Conditions: mem location of bool, mem location of int, mem location of int, mem location of int, mem location of int
 * Post-Conditons: 
 * Return: None
 ************************************************************************************************/
void round_total_to_0(bool *spun_0, int *player, int *p1_round, int *p2_round, int *p3_round) {

   if (*spun_0) {
      if (*player == 1)
	 *p1_round = 0;

      if (*player == 2)
	 *p2_round == 0;

      if (*player == 3)
	 *p2_round == 0;
   }


}

/*************************************************************************************************
 * Function: round_with_3_player_round_score
 * Description: Prints players round score to the screen
 * Parameters: int p1_round, int p2_round, int p3_round
 * Pre-Conditions: int, int, int
 * Post-Conditons: Prints to screen
 * Return: None
 ************************************************************************************************/
void round_with_3_player_round_score(int p1_round, int p2_round, int p3_round) {

   cout << "Player 1 round score: " << p1_round << endl;

   cout << "Player 2 round score: " << p2_round << endl;

   cout << "Player 3 round score: " << p3_round << endl;
}



/*************************************************************************************************
 * Function: round_with_3_total_add
 * Description: sets player round to 0 if they don' win
 * Parameters: int *p1_total, int *p1_round, int *p2_total, int *p2_round, int *p3_total, int *p3_round, int player
 * Pre-Conditions: mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, int
 * Post-Conditons: Passes 0 into values depeding on player
 * Return: None
 ************************************************************************************************/
void round_with_3_total_add(int *p1_total, int *p1_round, int *p2_total, int *p2_round, int *p3_total, int *p3_round, int player) {

   if (player == 1) {
      *p2_round = 0;
      *p3_round = 0;
      *p1_total += *p1_round;
   }

   if (player == 2) {
      *p2_total += *p2_round;
      *p1_round = 0;
      *p3_round = 0;
   }

   if (player == 3) {
      *p3_total += *p3_round;
      *p1_round = 0;
      *p2_round = 0;
   }

}

/*************************************************************************************************
 * Function: 
 * Description: 
 * Parameters: 
 * Pre-Conditions: 
 * Post-Conditons: 
 * Return: None
 ************************************************************************************************/
void round_with_3_total(int p1_total, int p2_total, int p3_total) {

   cout << "Player 1 total: " << p1_total << endl;
   
   cout << "Player 2 total: " << p2_total << endl;

   cout << "Player 3 total: " << p3_total << endl;
}

/*************************************************************************************************
 * Function: round_with_3_player_switch
 * Description: switches players 1-2 2-3 3-1
 * Parameters:int *player, int *p1_round, int *p2_round, int *p3_round, bool *spun_0
 * Pre-Conditions: mem location of int, mem location of int, mem location of int, mem location of int, mem location of bool
 * Post-Conditons: Switches *player and sets *round to 0 if *spun_0
 * Return: None
 ************************************************************************************************/
void round_with_3_player_switch(int *player, int *p1_round, int *p2_round, int *p3_round, bool *spun_0) {

   if (*player == 1) {
      go_to_zero(spun_0, player, p1_round, p2_round, p3_round); 
      *player = 2;
      return;
   }

   if (*player == 2) {
      go_to_zero(spun_0, player, p1_round, p2_round, p3_round); 
      *player = 3;
      return;
   }

   if (*player == 3) {
      go_to_zero(spun_0, player, p1_round, p2_round, p3_round); 
      *player = 1; 
   }
}

/*************************************************************************************************
 * Function: go_to_zero
 * Description: sets players scores to zero if *spun_0
 * Parameters: bool *spun_0, int *player, int *p1_round, int *p2_round, int *p3_round
 * Pre-Conditions: mem location of bool mem location of 4 ints
 * Post-Conditons: sets round to 0 if *spun_0
 * Return: None
 ************************************************************************************************/
void go_to_zero(bool *spun_0, int *player, int *p1_round, int *p2_round, int *p3_round) {

   if (*player == 1) {
      if (*spun_0) {
	 *p1_round = 0;
	 *spun_0 = false;
      }
   }

   if (*player == 2) {
      if (*spun_0) {
	 *p2_round = 0;
	 *spun_0 = false;
      }
   }

   if (*player == 3) {
      if (*spun_0) {
	 *p3_round = 0;
	 *spun_0 = false;
      }
   }
}

/*************************************************************************************************
 * Function: initital_for_3_player
 * Description: The initial run if player == 3
 * Parameters: int *p1_round, int *p2_round, int *p3_round, string *used_letters, int *round_at, string *message, string *original_message, string *message_guessed
 * Pre-Conditions: mem location of int, mem location of int, mem location of int, mem location of string, mem location fo int, mem locatino of string, mem location of string, mem location of string
 * Post-Conditons: Prints messages and sets rounds to 0
 * Return: None
 ************************************************************************************************/
void initial_for_3_player(int *p1_round, int *p2_round, int *p3_round, string *used_letters, int *round_at, string *message, string *original_message, string *message_guessed) {

   *p1_round = 0;
   *p2_round = 0;
   *p3_round = 0;

   *used_letters = "";

   cout << "Round " << *round_at << ". "; //Phrase to guess for this round

   *message = string_input("Please enter a phrase to guess for this round: ");

   *original_message = *message;

   message_transfer(message, message_guessed);

   cout << "The message you entered is: " << *message << endl;

   system("clear");


}

/*************************************************************************************************
 * Function: second_intial_3
 * Description: Sets the values for each loop
 * Parameters: int *user_choice, int player, string message_guessed, int *dollars
 * Pre-Conditions: mem location of int, int, string, mem location of int
 * Post-Conditons: Prints messages and passes values into mem locations
 * Return: None
 ************************************************************************************************/
void second_initial_3(int *user_choice, int player, string message_guessed, int *dollars) {

   cout << "The message is << " << message_guessed << endl;

   cout << "Player " << player << ". " << endl;

   *dollars = 0;




   do {
      *user_choice = int_input("Do you want to spin (1), buy a vowel for 10 dollars (2), or solve the puzzle (3): ");
   } while (!in_range(1, 3, *user_choice)); //This allows the user to input their choice to spin, solve or buy

}

/*************************************************************************************************
 * Function: round_with_2_player
 * Description: Plays the round for player == 2
 * Parameters: int round_set, int *p1_total, int *p2_total, int *p3_total
 * Pre-Conditions: int, mem location of int, mem location of int, mem location of int
 * Post-Conditons: Changes the mem location parameters depending on game
 * Return: None
 ************************************************************************************************/
void round_for_2_player(int round_set, int *p1_total, int *p2_total, int *p3_total) {

   int user_choice, player = 1, round_at = 1, dollars = 0, p1_round, p2_round, p3_round;

   int p1_turn = 1, p2_turn = 1, p3_turn = 1, p1_play_again = 0, p2_play_again = 0, p3_play_again = 0;

   string used_letters = "", message_guessed, message, original_message;

   bool spun_21 = false, second_skip = false, third_skip = false, spun_0 = false, third_chance = false;



   while (round_at <= round_set) {

      initial_for_3_player(&p1_round, &p2_round, &p3_round, &used_letters, &round_at, &message, &original_message, &message_guessed); 

      while (message_guessed != message) {

	 second_initial_3(&user_choice, player, message_guessed, &dollars);

	 switch_round_2_player(&message_guessed, &message, &round_set, p1_total, p2_total, p3_total, &round_at, &dollars, &p1_round, &p2_round, &p3_round, &p1_turn, &p2_turn, &p3_turn, &p1_play_again, &p2_play_again, &p3_play_again, &used_letters, &original_message, &spun_21, &second_skip, &third_skip, &spun_0, &third_chance, &player, user_choice); 

	 round_with_2_player_round_score(p1_round, p2_round, p3_round); 

      }

      cout << "Player " << player << " wins this round for correctly guessing the phrase " << message << "!" << endl;

      round_with_3_total_add(p1_total, &p1_round, p2_total, &p2_round, p3_total, &p3_round, player); 

      round_with_2_player_round_score(p1_round, p2_round, p3_round); 

      ++round_at;
   }

   round_with_2_total(*p1_total, *p2_total, *p3_total); 
}

/*************************************************************************************************
 * Function: switch_round_2_player
 * Description: The switch statement for a player = 2
 * Parameters: string *message_guessed, string *message, int *round_set, int *p1_total, int *p2_total, int *p3_total, int *round_at, int *dollars, int *p1_round, int *p2_round, int *p3_round, int *p1_turn, int *p2_turn, int *p3_turn, int *p1_play_again, int *p2_play_again, int *p3_play_again, string *used_letters, string *original_message, bool *spun_21, bool *second_skip, bool *third_skip, bool *spun_0, bool *third_chance, int *player
 * Pre-Conditions: mem location of string, mem location of string, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of int, mem location of string, mem location of string, mem location of bool, mem location of bool, mem location of bool, mem location of bool, mem location of bool, mem location of int
 * Post-Conditons: Changes the contents of the mem locations of the parameters
 * Return: None
 ************************************************************************************************/
void switch_round_2_player(string *message_guessed, string *message, int *round_set, int *p1_total, int *p2_total, int *p3_total, int *round_at, int *dollars, int *p1_round, int *p2_round, int *p3_round, int *p1_turn, int *p2_turn, int *p3_turn, int *p1_play_again, int *p2_play_again, int *p3_play_again, string *used_letters, string *original_message, bool *spun_21, bool *second_skip, bool *third_skip, bool *spun_0, bool *third_chance, int *player, int user_choice) {




   switch (user_choice) {

      case 1: 

	 if (case_1_3_player(player, p1_round, p2_round, p3_round, dollars, message_guessed, message, spun_21, used_letters, spun_0))
	    break;

	 round_with_2_player_switch(player, p1_round, p2_round, p3_round, spun_0); 

	 break;

      case 2:



	 if (case_2_3_player(player, p1_round, p2_round, p3_round, dollars, message_guessed, message, used_letters, p1_total, p2_total, p3_total))
	    break; 


	 round_with_2_player_switch(player, p1_round, p2_round, p3_round, spun_0); 

	 break;


      case 3: 
	 if (guess_message(*player, message, message_guessed, *original_message, used_letters, dollars)) {
	    break;
	 }

	 round_with_2_player_switch(player, p1_round, p2_round, p3_round, spun_0); 

   }


}

/*************************************************************************************************
 * Function: round_with_2_player_round_score
 * Description: Prints the round score for player 1 and 2
 * Parameters: int p1_round, int p2_round, int p3_round
 * Pre-Conditions: int, int, int 
 * Post-Conditons: None
 * Return: None
 ************************************************************************************************/
void round_with_2_player_round_score(int p1_round, int p2_round, int p3_round) {

   cout << "Player 1 round score: " << p1_round << endl;

   cout << "Player 2 round score: " << p2_round << endl;
}

/*************************************************************************************************
 * Function: round_with_2_total
 * Description: Prints thte total for player 1 and 2
 * Parameters: int p1_total, int p2_total, int p3_total
 * Pre-Conditions: int, int, int
 * Post-Conditons: None
 * Return: None
 ************************************************************************************************/
void round_with_2_total(int p1_total, int p2_total, int p3_total) {

   cout << "Player 1 total: " << p1_total << endl;

   cout << "Player 2 total: " << p2_total << endl;
}

/*************************************************************************************************
 * Function: round_with_2_players_switch
 * Description: Switches player 1 to 2 or 2 to 1
 * Parameters: int *player, int *p1_round, int *p2_round, int *p3_round, bool *spun_0
 * Pre-Conditions: mem location of int, mem location of int, mem location of int, mem location of int, mem location of bool
 * Post-Conditons: Makes switches *player from 1 to 2 or 2 to 1
 * Return: 
 ************************************************************************************************/
void round_with_2_player_switch(int *player, int *p1_round, int *p2_round, int *p3_round, bool *spun_0) {

   if (*player == 1) {
      if (*spun_0) {
	 *p1_round = 0;
	 *spun_0 = false;
      }
      *player = 2;
      return;
   }

   if (*player == 2) {
      if (*spun_0) {
	 *p2_round = 0;
	 *spun_0 = false;
      }
      *player = 1;
      return;
   }

}

/*************************************************************************************************
 * Function: round_for_1_player
 * Description: Plays the round for 1 player
 * Parameters: int round_set, int *p1_total
 * Pre-Conditions: int, mem location of int
 * Post-Conditons: Changes the variables it declares to find *p1_total
 * Return: 0
 ************************************************************************************************/
int round_for_1_player(int round_set, int *p1_total) {

   int user_choice, player = 1, round_at = 1, dollars = 0, p1_round = 0;

   string used_letters = "", message_guessed, message, original_message;

   bool spun_21, spun_0 = false;

   while (round_at <= round_set) {

      initial_p1_round(&p1_round, &used_letters, &round_at, &message, &original_message, &message_guessed); 

      while (message_guessed != message) {

	 second_initial_p1_round(&message_guessed, &player, &user_choice); 

	 switch_p1_round(&user_choice, &player, &message_guessed, &message, &spun_21, &used_letters, &dollars, &spun_0, &p1_round, p1_total, &original_message); 

	 cout << "Player 1 round score: " << p1_round << endl;
      }

      cout << "Player " << player << " wins this round for correctly guessing the phrase " << message << "!" << endl;

      *p1_total += p1_round;

      ++round_at;
   }
   cout << "Player 1 total: " << *p1_total << endl;

   return 0;

}

/*************************************************************************************************
 * Function: switch_p1_round
 * Description: The switch statemement for number of players = 1
 * Parameters: int *user_choice, int *player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0, int *p1_round, int *p1_total, string *original_message
 * Pre-Conditions: mem location of int, mem location of int, mem location of string, mem location of string, mem location of bool mem location of string, mem location of int, mem location of bool, mem location of int, mem location of int, mem location of string
 * Post-Conditons: Changes the mem location parameters depending on the *user_choice
 * Return: None
 ************************************************************************************************/
void switch_p1_round(int *user_choice, int *player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0, int *p1_round, int *p1_total, string *original_message) {

   switch (*user_choice) {

      case 1: 

	 case_1_p1_round(player, message_guessed, message, spun_21, used_letters, dollars, spun_0, p1_round); 

	 break;

      case 2:

	 if (*p1_total < 10 && *p1_round < 10)
	    break;

	 buy_vowel(*player, message_guessed, message, used_letters, dollars);

	 *p1_round += *dollars;

	 break;

      case 3: 

	 guess_message(*player, message, message_guessed, *original_message, used_letters, dollars);
   }

}

/*************************************************************************************************
 * Function: case_1_p1_round
 * Description: Runs the choice of 1 for a player of 1
 * Parameters: int *player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0, int *p1_round
 * Pre-Conditions: mem location of int, mem location of string, mem location of string, mem location of bool, mem locatino of string, mem location of int, mem location of bool, mem location of int
 * Post-Conditions: Changes *spun_0 to false if it's true, adds the dollars if right_guess
 * Return: None
 ************************************************************************************************/
void case_1_p1_round(int *player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0, int *p1_round) {

   if (spin(*player, message_guessed, message, spun_21, used_letters, dollars, spun_0)){
      *p1_round += *dollars;	  
   }

   if (*spun_0) {
      *p1_round = 0;
      *spun_0 = false;
   }


}

/*************************************************************************************************
 * Function: second_initial_p1_round
 * Description: Sets the settings for each run of the while loop
 * Parameters: string *message_guessed, int *player, int *user_choice
 * Pre-Conditions: mem location of string, mem location of int, mem location of int
 * Post-Conditons: Prints messages to the screen
 * Return: None
 ************************************************************************************************/
void second_initial_p1_round(string *message_guessed, int *player, int *user_choice) {

   cout << "The message is << " << *message_guessed << endl;

   cout << "Player " << *player << ". " << endl;;

   do {
      *user_choice = int_input("Do you want to spin (1), buy a vowel for 10 dollars (2), or solve the puzzle (3): ");
   } while (!in_range(1, 3, *user_choice)); //This allows the user to input their choice to spin, solve or buy


}

/*************************************************************************************************
 * Function: initial_p1_round
 * Description: Sets the initial circumstances for a game with one player
 * Parameters: int *p1_round, string *used_letters, int *round_at, string *message, string *original_message, string *message_guessed
 * Pre-Conditions: mem location of int, mem location of string, mem location of int, mem location of string, mem location of string, mem location of string
 * Post-Conditons: Prints messages to the screen and modifies *original_message, *message, and *message_guessed
 * Return: None
 ************************************************************************************************/
void initial_p1_round(int *p1_round, string *used_letters, int *round_at, string *message, string *original_message, string *message_guessed) {

   *p1_round = 0;

   *used_letters = "";

   cout << "Round " << *round_at << ". "; //Phrase to guess for this round

   *message = string_input("Please enter a phrase to guess for this round: ");

   *original_message = *message;

   message_transfer(message, message_guessed);

   cout << "The message you entered is: " << *message << endl;

   system("clear");

}

/*************************************************************************************************
 * Function: who_wins
 * Description: Prints who won the game to the screen
 * Parameters: int *p1_total, int *p2_total, int *p3_total
 * Pre-Conditions: mem location of int, mem location of int, mem location of int
 * Post-Conditons: Prints the winner of the game
 * Return: None
 ************************************************************************************************/

void who_wins(int *p1_total, int *p2_total, int *p3_total) {

   if (*p1_total > *p2_total && *p1_total > *p3_total)
      cout << "Player 1 wins the game!" << endl;

   else if (*p2_total > *p1_total && *p2_total > *p3_total)
      cout << "Player 2 wins the game!" << endl;

   else if (*p3_total > *p1_total && *p3_total > *p2_total)
      cout << "Player 3 wins the game!" << endl;

   else if (*p3_total == *p2_total && *p3_total == *p1_total)
      cout << "It's a tie!" << endl;

   else if (*p3_total == *p2_total && *p2_total > *p1_total)
      cout << "Player 2 and 3 tie for first!" << endl;

   else if (*p3_total == *p1_total && *p1_total > *p2_total)
      cout << "Player 1 and 3 tie for first!" << endl;

   else if (*p1_total == *p2_total && *p1_total > *p3_total)
      cout << "Player 1 and 2 tie for first!" << endl;
}

/*************************************************************************************************
 * Function: guess_message
 * Description: Allows the user to guess the message
 * Parameters: int player, string *message, string *message_guessed, string original_message, string *used_letters, int *dollars
 * Pre-Conditions: int, mem location of string, mem location of string, string, mem location of string, memory location of int
 * Post-Conditons: return true or false depeding if right or not
 * Return: True or false
 ************************************************************************************************/
bool guess_message(int player, string *message, string *message_guessed, string original_message, string *used_letters, int *dollars) {

   string guess;

   guess = string_input("Please input your guess: ");

   if (guess == original_message) {
      *message_guessed = *message;
      return true; 
   }

   return false;



}

/*************************************************************************************************
 * Function: buy_vowel
 * Description: Allows the user to buy a vowel and subracts 10 from their round_score
 * Parameters: int player, string *message_guessed, string *message, string *used_letters, int *dollars
 * Pre-Conditions: int, memory location of string, memory location of string, memory location of string, int
 * Post-Conditons: used_letters includes vowel and returns bool
 * Return: True or false depending if guess is right or not
 ************************************************************************************************/
bool buy_vowel(int player, string *message_guessed, string *message, string *used_letters, int *dollars) {

   string vowel = "p";

   bool right_g;

   *dollars = -10;

   int throw_away_dollars;

   vowel = vowel_input("10 dollars has been subracted from your round score. Please guess a vowel: ", used_letters);

   if (right_guess(vowel, message, message_guessed, &throw_away_dollars, 0))
      return true;
   else
      return false;
}

/*************************************************************************************************
 * Function: spin
 * Description: "Spins" the board for a player
 * Parameters: int player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0
 * Pre-Conditions: integer, memory location of string, memory location of string, memory location of bool, memory location of string, memory location of int, memory location of bool
 * Post-Conditons: Returns true or false and prints spin information to user
 * Return:  Treu or false depending on spin or if the guess is correct
 ************************************************************************************************/
bool spin(int player, string *message_guessed, string *message, bool *spun_21, string *used_letters, int *dollars, bool *spun_0) {

   int spin;

   string letter;

   spin = rand() % 22; //change

   cout << "You spun a " << spin << "!" << endl;

   if (spin == 0) { 

      cout << "You spun a zero, so you lose this turn, and your earnings for this round go to zero." << endl;
      *spun_21 = true;
      *spun_0 = true;
      return false;
   }

   if (spin == 21) {

      *spun_21 = true;
      cout << "You spun a 21, so you lose this turn" << endl;
      return false;
   }

   letter = consonant_input("Guess a consonant: ", used_letters);

   if (right_guess(letter, message, message_guessed, dollars, spin))
      return true;



}

//-> (from pointer area (location in memory) go to char, when using function associated with pointer)
/*************************************************************************************************
 * Function: right_guess
 * Description: Checks to make sure that letter_guess is in the *phrase
 * Parameters: string letter_guess, string *phrase, string *message_guessed, int *dollars, int spin_num
 * Pre-Conditions: string, memory location of string, memory location of string, memory location of int, int
 * Post-Conditons: Makes new message_guessed if the letter_guess is in message and adds dollars to players score
 * Return: True if right_guess false if not the right_guess
 ************************************************************************************************/
bool right_guess(string letter_guess, string *phrase, string *message_guessed, int *dollars, int spin_num) {

   string new_message = "";
   int phrase_length = (*phrase).length(), letters_found = 0;

   *dollars = 0; // So I points will be set at zero everytime the function runs

   for (int i = 0; i < phrase_length; i++) {

      if ( letter_guess.at(0) == phrase->at(i) ) {
	 new_message += letter_guess.at(0); //If the letter matches, replace it in the hidden message
	 *dollars += spin_num; //Adds spin number for each right letter 
	 letters_found += 1;
      }
      else {
	 new_message += (*message_guessed).at(i);

      }
   } 

   cout << "You found " << letters_found << " " << letter_guess << "!" << endl;

   if (*dollars > 0 || new_message != *message_guessed) {
      *message_guessed = new_message;
      return true;

   }
   return false;
}

/*************************************************************************************************
 * Function: vowel_input
 * Description: Allows input of vowel
 * Parameters: string prompt, string *used_letters
 * Pre-Conditions: string, memory location of string
 * Post-Conditons: *used_letters includes input of vowel, vowel input is returned 
 * Return: Vowel input
 ************************************************************************************************/
string vowel_input(string prompt, string *used_letters) {

   string letter = "d", letter_input = "t", u2 = *used_letters;

   do {
      cout << prompt;
      getline(cin, letter_input); //Allows me to check that user only entered one character
      if (letter_input.length() == 1 && ((letter_input.at(0) >= 'a' && letter_input.at(0) <= 'z') || (letter_input.at(0) >= 'A' && letter_input.at(0) <= 'Z')))
	 letter = tolower(letter_input.at(0)); //Makes letter lowercase

   } while  (!(letter_input.length() == 1) ||  !( letter.at(0) == 'a' || letter.at(0) == 'e' || letter.at(0) == 'i' || letter.at(0) == 'o' || letter.at(0) == 'u' ) || letter_already_used(letter, &u2) );


   *used_letters += letter; //Adds letters to check if letters have already been inputted

   return letter;
}

/*************************************************************************************************
 * Function: consonant_input
 * Description: takes in valid consonant input
 * Parameters: string prompt, string *used_letters
 * Pre-Conditions: string, memory location of string
 * Post-Conditions: *used_letters has includes input of consonant, letter inputted is return
 * Return: String of consonant
 ************************************************************************************************/
string consonant_input(string prompt, string *used_letters) {

   string letter = "i", u2 = *used_letters, letter_input;

   do {
      cout << prompt;
      getline(cin, letter_input); //Allows me to check that user only entered one character
      if (letter_input.length() == 1 && ((letter_input.at(0) >= 'a' && letter_input.at(0) <= 'z') || (letter_input.at(0) >= 'A' && letter_input.at(0) <= 'Z')))
	 letter = tolower(letter_input.at(0)); //Makes letters lowercase
   } while ( !(letter_input.length() == 1) || !(letter.at(0) >= 'a' && letter.at(0) <= 'z') || ( (letter.at(0) >= 'a' && letter.at(0) <= 'z') && ( letter.at(0) == 'a' || letter.at(0) == 'e' || letter.at(0) == 'i' || letter.at(0) == 'o' || letter.at(0) == 'u' ) ) || letter_already_used(letter, &u2) );


   *used_letters += letter; //Adds letters to check if letters have already been inputted


   return letter;
}

//This will transfer the message someone types in to a hidden message. Only allows strings with letters, ', or spaces
/*************************************************************************************************
 * Function: message_transfer
 * Description: Transfers message to a blank message
 * Parameters: string *message, string *message_guessed
 * Pre-Conditions: Memory location of two strings
 * Post-Conditions: Makes blank *message_guessed same length as *message
 * Return: None
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
 * Function: initial_call
 * Description: The initial call for this program
 * Parameters: int *players, int *round_set
 * Pre-Conditions: Memory location of 2 ints
 * Post-Conditions: Prints to screeen
 * Return: None
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
 * Function: string_input
 * Description: Takes in string input of a line
 * Parameters: string prompt
 * Pre-Conditions: string
 * Post-Conditions: Returns valid string
 * Return: String
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
 * Function: valid_stringput
 * Description: Checks to make sure input is a valid string
 * Parameters: string input
 * Pre-Conditions: String
 * Post-Conditions: True if valid, false if not
 * Return: Bool
 ************************************************************************************************/
bool valid_stringput(string input) {

   for (int i = 0; i < input.size(); i++) {
      if ((input.at(i) < 'a' || input.at(i) > 'z') && (input.at(i) < 'A' || input.at(i) > 'Z') && (input.at(i) != ' ') && (input.at(i) != '\'')) {
	 return false;
      }
   }
   return true;
}



/*************************************************************************************************
 * Function: is_num
 * Description: Checks to see if integer input is valid
 * Parameters: String of an integer
 * Pre-Conditions: String of an integer
 * Post-Conditions: True or False
 * Return: Bool
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
 * Function: int_input
 * Description: Only allows valid integer input
 * Parameters: Allows a string to be prompted
 * Pre-Conditions: Must be a string
 * Post-Conditions: Returns a valid integer
 * Return: Returns a valid integer
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
 * Function: in_range
 * Description: Makes sure an integer is in a specified range
 * Parameters: integer start, integer end, integer input
 * Pre-Conditions: 3 integers
 * Post-Conditions: True or False
 * Return: Bool
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









/*************************************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditons:
 * Return:
 ************************************************************************************************
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
*
* /






















*



bool p2_round_case_2(int *player, int *p1_total, int *p1_round, int *p2_total, int *p2_round, string *message_guessed, string *message, string *used_letters, int *dollars) {

   if (player == 1 && (*p1_total < 10 && p1_round < 10))
      break;
   if (player == 2 && (*p2_total < 10 && p2_round < 10))
      break;
   if (player == 1 && (buy_vowel(player, &message_guessed, &message, &used_letters, &dollars))) {
      p1_round += dollars;
      break;
   }
   if (player == 2 && (buy_vowel(player, &message_guessed, &message, &used_letters, &dollars))) {
      p2_round += dollars;

   }

}



void player_2_round_at(int *p1_round, int *p2_round, string *used_letters, string *message, string *original_message, string *message_guessed, int player, int round_set, int *dollars) {

   do {
      user_choice = int_input("Do you want to spin (1), buy a vowel for 10 dollars (2), or solve the puzzle (3): ");
   } while (!in_range(1, 3, user_choice)); //This allows the user to input their choice to spin, solve or buy

   switch (user_choice) {

      case 1: 
	 if (player == 1 && spin(player, &message_guessed, &message, &spun_21, &used_letters, &dollars, &spun_0)){
	    p1_round += dollars;	  
	    break;
	 }
	 if (player == 2 && spin(player, &message_guessed, &message, &spun_21, &used_letters, &dollars, &spun_0)){
	    p2_round += dollars;	  
	    break;
	 }


	 round_with_2_player_switch(&player, &p1_round, p2_round, &spun_0); 
	 break;


      case 2:

	 p2_round_case_2(&player, p1_total, &p1_round, p2_total, &p2_round, message_guessed, message, used_letters, dollars); 
	 break;

	 round_with_2_player_switch(&player, &p1_round, p2_round, &spun_0); 

	 break;


      case 3: 
	 if (guess_message(player, &message, &message_guessed, original_message, &used_letters, &dollars)) {
	    break;
	 }

	 round_with_2_player_switch(&player, &p1_round, p2_round, &spun_0); 

   }

   cout << "Player 1 round score: " << p1_round << endl;
   cout << "Player 2 round score: " << p2_round << endl;




}

void round_with_2_player_switch(int *player, int *p1_round, int *p2_round, bool *spun_0) {

   if (player == 1) {
      if (spun_0) {
	 p1_round = 0;
	 spun_0 = false;
      }
      player = 2;
   }
   if (player == 2) {
      if (spun_0) {
	 p2_round = 0;
	 spun_0 = false;
      }
      player = 1;
   }
}





void initial_p2_round(int *p1_round, int *p2_round, string *used_letters, string *message, string *original_message) {

   p1_round = 0;
   p2_round = 0;

   used_letters = "";

   cout << "Round " << round_at << ". "; //Phrase to guess for this round

   message = string_input("Please enter a phrase to guess for this round: ");

   original_message = message;

   message_transfer(&message, &message_guessed);

   cout << "The message you entered is: " << message << endl;

   system("clear");

}






int round_for_2_player(int round_set, int *p1_total, int *p2_total) {

   int user_choice, player = 1, round_at = 1, dollars = 0, p1_round, p2_round, p3_round;

   string used_letters = "", message_guessed, message, original_message;


   while (round_at <= round_set) {


      initial_p2_round(&p1_round, &p2_round, &used_letters, &message, &original_message); 

      while (message_guessed != message) {

	 cout << "The message is << " << message_guessed << endl;

	 cout << "Player " << player << ". " << endl;




      }
      cout << "Player " << player << " wins this round for correctly guessing the phrase " << message << "!" << endl;

      if (p1_round > p2_round)
	 *p1_total += p1_round;

      if (p2_round > p1_round)
	 *p2_total += p2_round;


      ++round_at;
   }
   cout << "Player 1 total: " << *p1_total << endl;
   cout << "Player 2 total: " << *p2_total << endl;

}
}


















*/





