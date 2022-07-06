#include <iostream>
#include <cstdlib>
#include <cstring>
#include<ctime> //Alows randint();
#include<climits> //Allows INT_MAX
using namespace std;

void initial_1(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total); 
void initial_2(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total); 
bool is_num(char *);
void int_input(string, int *);
bool in_range(int, int, int);
void char_input(char *&str);
bool is_name( char *&str);
void initial(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total);
void scoresheet(char **&player_name, char **&players_scors, int **&player_total, int **&player_round_score, int num_players, int round_num, int player);
void for_1_scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player, int &i); 
void for_2_scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player, bool &break_cycle, int &i); 
void bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, char **&player_name); 
void spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare); 
int add_player_round_score_and_total_score(int &round_num, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total); 
void player_switch(int &player, int num_players); 
void who_won(int **player_total, char **player_name, int num_players); 
bool display_player_round_score(int round_num, int player, bool break_cycle, char **player_scores, int **player_round_score); 
void extra_round(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name); 
void extra_round(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name); 
void extra_round_if_1(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name, int &i, int round1, int round2, bool strike, bool spare); 
void extra_spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare); 
void spin_1(int &spin, int &i, char &char1, char **&player_scores, int &spin_total, int &round_num, int &player); 
void spin_2(int &spin, int &i, char &char1, char **&player_scores, int &spin_total, int &round_num, int &player); 
void delete_everything(int **&player_total, int **&player_round_score, char**&player_name, char **&player_scores, int numb_players); 
//void extra_chance(bool strike, bool spare, int player, int num_players, int round_num, char **player_name, int **&player_total, int **&player_round_score, char **&player_scores); 
//void extra_spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare, int round); 

/*************************************************************************************************
 ** Function: main
 ** Description: Runs a bowling simulation
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditons: none
 ** Return: none
***************************************************************************************************/
int main () {

   //sets time
   srand(time(NULL));

   //Makes variables
   int num_players, round_num = 0, player = 1, **player_total, **player_round_score;
   char **player_name, **player_scores;
   bool strike, spare;
   int spin_total = 0;

   //Initializes variables
   initial(player_name, player_scores, player_round_score, num_players, player_total);


   //Runs all normal rounds
   bowl(player, round_num, num_players, player_scores, player_total, player_round_score, player_name); 


   //Runs all extra rounds
   extra_round(round_num, num_players, player, spin_total, player_scores, player_round_score, player_total, player_name); 

   //Prints the user with the most points
   who_won(player_total, player_name, num_players); 

   //Deletes the rest of my allocated memory
   delete_everything(player_total, player_round_score, player_name, player_scores, num_players); 



}


/*************************************************************************************************
 ** Function: add_player_round_score_and_total_score
 ** Description: Adds the player_round_scores and total scores
 ** Parameters: 
 ** Pre-Conditions: int, char array, int array
 ** Post-Conditons: int array player_round_score, int array total_score
 ** Return: 0
 ***************************************************************************************************/

int add_player_round_score_and_total_score(int &round_num, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total) {

   //If there has been one round, check to see if there was a strike or spare last round. Then add this round score to that round score if there was one
   if (round_num > 0)
      if ( ( player_scores[player - 1][((round_num - 1) * 2) + 1] == '/' ) || ( player_scores[player - 1][(round_num - 1) * 2] == 'X' ) )
	 player_round_score[player - 1][round_num - 1] += spin_total;

   //If there has been two rounds, check to see if there was a strike two rounds ago, then add this round total to that round total if there was one
   if (round_num > 1 )
      if ( player_scores[player - 1][(round_num - 2) * 2] == 'X'){
	 player_round_score[player - 1][(round_num - 2)] += spin_total;
	 player_round_score[player - 1][round_num - 1] += spin_total;
      }

   //This adds the round score and previous round scores to the cureent player round score
   player_round_score[player - 1][round_num] = player_round_score[player - 1][round_num - 1];

   //This adds the spin_total to the current player round score;
   player_round_score[player - 1][round_num] += spin_total;

   //This adds the total to player_total
   player_total[player - 1][0] = player_round_score[player - 1][round_num];

   return 0;

}

/*************************************************************************************************
 ** Function: extra_round_if_1
 ** Description: First if statement for extra_round
 ** Parameters: player, num_players, info arrays
 ** Pre-Conditions: int, int array, char array
 ** Post-Conditons: player_round_score, total_score
 ** Return: none
 ***************************************************************************************************/
void extra_round_if_1(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name, int &i, int round1, int round2, bool strike, bool spare) {

   //Tells user they got an extra turn
   cout << "You got an extra turn! Hit enter to bowl.";
   cin.ignore(INT_MAX, '\n');

   //Runs one bowl
   extra_spin_for_bowl(player, round1, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

   //If the last round can have points added, then add points to that round and the last normal round
   if (player_scores[i][16] == 'X') {
      player_round_score[i][8] += spin_total;
      player_round_score[i][9] += spin_total;
   }
   //Add the points to the last round
   player_round_score[i][9] += spin_total;

   //Tells user they got an extra turn
   cout << "You got an extra turn! Hit enter to bowl.";
   cin.ignore(INT_MAX, '\n');

   //Runs one bowl
   extra_spin_for_bowl(player, round2, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

   //Adds the users bowl
   player_round_score[i][9] += spin_total;
   //Sets the player total
   player_total[i][0] = player_round_score[i][9];
   //Prints the scoresheet one last time
   scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 
}

/*************************************************************************************************
 ** Function: extra_round
 ** Description: Runs rounds 11 and 12 for players with strikes and spares in 10
 ** Parameters: player, round, info arrays
 ** Pre-Conditions: int, char array, int array
 ** Post-Conditons: player_round_score, player_total
 ** Return: none
 ***************************************************************************************************/
void extra_round(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name) {

   bool strike, spare;

   for (int i = 0; i < num_players; i++) {

      //Sets the values for the last rounds
      int round1 = 10, round2 = 11, round3 = 10, player = i + 1;

      //If the last round was a strike, then run two more bowls
      if (player_scores[i][18] == 'X') {
	 extra_round_if_1(round_num, num_players, player, spin_total, player_scores, player_round_score, player_total, player_name, i, round1, round2, strike, spare);
      }
      //If the last round was a spare, then run one more bowl
      else if (player_scores[i][19] == '/') {

	 //Tells user they have an extra turn
	 cout << "You got an extra turn! Hit enter to bowl.";
	 cin.ignore(INT_MAX, '\n');

	 //Runs one bowl
	 extra_spin_for_bowl(player, round3, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

	 //If the second to last normal bowl was a strike, then add the bowl number to the current bowl and the second to last
	 if (player_scores[i][16] == 'X') {
	    player_round_score[i][8] += spin_total;
	    player_round_score[i][9] += spin_total;
	 }

	 //Adds the bowl total to player_round_score
	 player_round_score[i][9] += spin_total;
	 //Adds the player round score to player total
	 player_total[i][0] = player_round_score[i][9];

	 //Runs the scoresheet run more time
	 scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 
      }
   }
} 

/*************************************************************************************************
 ** Function: extra_spin_for_bowl
 ** Description: runs one bowl
 ** Parameters: player, round, info arrays
 ** Pre-Conditions: int, char array, int array
 ** Post-Conditons: player_scores
 ** Return: none
 ***************************************************************************************************/
void extra_spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare) {

   int spin;
   char char1;


   // Sets pins knocked down
   spin = rand() % 11;
   //spin = 10;
   cout << "You bowled a " << spin << "!" << endl;

   // If first spin and strike
   if (spin == 10) {
      spin_total = 10;
      if (round_num == 10)
	 player_scores[player - 1][20] = 'X'; //Need to look at this
      if (round_num == 11)
	 player_scores[player - 1][21] = 'X'; //Need to look at this
   }

   //If first spin is not strike
   else if (spin < 10) {
      spin_total = spin;
      char1 = '0' + spin;
      if (round_num == 10)
	 player_scores[player - 1][20] = char1;
      if (round_num == 11)
	 player_scores[player - 1][21] = char1;
   }
}

/*************************************************************************************************
 ** Function: display_player_round_score
 ** Description: Recursive solution whether to display a player's round score or not
 ** Parameters: round_num, player, player_scores, player_round_score
 ** Pre-Conditions: int, bool, char array, int array
 ** Post-Conditons: player_round_score
 ** Return: true, false
 ***************************************************************************************************/
bool display_player_round_score(int round_num, int player, bool break_cycle, char **player_scores, int **player_round_score) {

   //If the round (round_num) is zero, then there is no
   if (round_num == 0) {
      //If there is a break_cycle, then print the round_score
      if (break_cycle) {
	 if (player_round_score[player - 1][0] > 9)
	    cout << player_round_score[player - 1][0] << "   |  ";
	 else
	    cout << player_round_score[player - 1][0] << "  |    ";
	 return true;
      }
      // If there was no strike or spare in the first round, then print out round_score
      else { 
	 if (player_scores[player - 1][0] != 'X' && player_scores[player - 1][1] != '/') {
	    //cout << "   |    ";
	    if (player_round_score[player - 1][0] > 9)
	       cout << player_round_score[player - 1][0] << "   |  ";
	    else
	       cout << player_round_score[player - 1][0] << "  |  ";
	    break_cycle = true;
	    return true;
	 }
	 //If there can be no rounds printed, then don't print out the first round
	 else {
	    cout << "    |     ";
	    return false;
	 }
      }
   }


   // If the round is greater than 0 and the last round is not a strike or spare, then it's possible to print (break_cycle = true) - All rounds before (including this one) will be able to be printed(All the way to round_num==0
   if (round_num > 0) {
      if ( player_scores[player - 1][(round_num)*2] != 'X' && player_scores[player - 1][(round_num - 1)*2] != 'X' && player_scores[player - 1][(round_num)*2 + 1] != '/' )
	 break_cycle = true;
   }
   // If the round is greater than 1 and the second to last round is not a strike or spare, then it's possible to print(break_cycle=true) - All rounds before (including this one) will be able to be printed(All the way to round_num==0
   else if (round_num > 1)
      if (player_scores[player - 1][(round_num)*2] != 'X' && player_scores[player - 1][(round_num - 1)*2] != 'X' && player_scores[player - 1][(round_num)*2 + 1] != '/'  )
	 break_cycle = true;


   // If the last round was able to print and this round is able to print (break_cycle), then print and return true (next round will be able to print if it's break_cycle is true, meaning no strikes or spares in that or prev rounds
   if (display_player_round_score(--round_num, player, break_cycle, player_scores, player_round_score) && break_cycle) {

      if (player_round_score[player - 1][round_num] > 99)
	 cout << player_round_score[player - 1][round_num+1] << " |  ";
      else if (player_round_score[player - 1][round_num+1] > 9)
	 cout << player_round_score[player - 1][round_num+1] << "  |  ";
      else
	 cout << player_round_score[player - 1][round_num+1] << "   |  ";

      return true;
   }
   //If this round is not able to print, then none of the next rounds will be able to print (because break_cycle must be true and display_player_round_score (this function) must be zero
   else {
      cout << "   |   ";
      return false;
   }



}

/*************************************************************************************************
 ** Function: for_1_scoresheet
 ** Description: first for in scoresheet
 ** Parameters: player_name, info arrays
 ** Pre-Conditions: char array, int array, int
 ** Post-Conditons: player_name
 ** Return: none
 ***************************************************************************************************/
void for_1_scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player, int &i) {

   //Print out the player name
   for (int j = 0; j < 12; j++)
      cout << player_name[i][j];
   for (int j = 0; j <= 9; j++) {
      cout << " |  " << player_scores[i][2*j] << " " << player_scores[i][2*j+1]; 
   }
   cout << " ";

   //Print out the player total
   cout << " |  " << player_total[i][0] << endl;
   cout << "             | ";
}

/*************************************************************************************************
 ** Function: for_2_scoresheet
 ** Description: second for in scoresheet
 ** Parameters: info arrays, round_num, i
 ** Pre-Conditions: char arrays, int arrays, int
 ** Post-Conditons: display_player_round_score
 ** Return: none
 ***************************************************************************************************/
void for_2_scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player, bool &break_cycle, int &i) {

   // If able to print out all values for the player including all player_round_scores and player_total, then do so
   if ( (round_num > 9 && player - 1 >= i) || (round_num >= 9 && player_scores[player - 1][16] == 'X' && player_scores[player - 1][18] != 'X' && player_scores[player - 1][19] != '/') ) {
      for (int k = 0; k < 9; k++) {
	 cout << player_round_score[i][k] << "  |  ";
      }
      cout << player_total[i][0] << "  | ";
   }

   //If we are printing for the current player or a player that has bowled this round, then print out their round_scores and round_total for this round
   else if (i+1 <= player)
      display_player_round_score(round_num, i + 1, break_cycle, player_scores, player_round_score); 
   //If round is 0, then print nothing
   else if (round_num == 0)
      ;
   //else if we are printing for a player for who's turn has not gone this round, then print out their stuff for last round
   else
      display_player_round_score(round_num - 1, i + 1, break_cycle, player_scores, player_round_score); 


   // Print more dashes for the rounds that have not gone
   for (int k = round_num + 1; k <= 9; k++) {
      if (round_num == 9)
	 break;
      cout << "    "
	 << "|   ";
   }
}

/*************************************************************************************************
 ** Function: scoresheet
 ** Description: Displays the scoresheet for the user's scores
 ** Parameters: infor arrays, num_players, player
 ** Pre-Conditions: char array, int array, int
 ** Post-Conditons: player_total
 ** Return: none
 ***************************************************************************************************/
void scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player) {

   // prints out header stuff
   cout << "Name         "; 

   for (int i = 1; i <= 9; i++) {
      cout << "|  " << i << "   ";
   }
   cout << "|  10  ";

   cout << "|" << "  Total" << endl
      << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

   //Prints out player score stuff, round_score, and player_total for each player
   for (int i = 0; i < num_players; i++) {

      for_1_scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player, i); 

      bool break_cycle = false;

      for_2_scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player, break_cycle, i); 

      cout << endl;

      cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << endl;
   }

}

/*************************************************************************************************
 ** Function: initial
 ** Description: Initializes some arrays
 ** Parameters: info arrays
 ** Pre-Conditions: char array, int array
 ** Post-Conditons: player_name, player_scores
 ** Return: none
 ***************************************************************************************************/
void initial(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total) {

   //Set the amount of players to bowl
   do {
      int_input("How many players want to bowl?", &num_players);
   } while (!in_range(1, INT_MAX, num_players));

   //Set the names for each player
   player_name = new char*[num_players];
   for (int i = 0; i < num_players; i++) {
      player_name[i] = new char[13];
   }

   //Run the first initalizations
   initial_1(player_name, player_scores, player_round_score, num_players, player_total); 

   // This creates a dynamic double array for the player scores for each bowl
   player_scores = new char*[num_players];
   for (int i = 0; i < num_players; i++) {
      player_scores[i] = new char[22];
   }

   //Run more initializations
   initial_2(player_name, player_scores, player_round_score, num_players, player_total); 


}

/*************************************************************************************************
 ** Function: delete_everything
 ** Description: gets rid of info array mem leaks
 ** Parameters: info arrays
 ** Pre-Conditions: int array, char array
 ** Post-Conditons: No array pointers
 ** Return: none
 ***************************************************************************************************/
void delete_everything(int **&player_total, int **&player_round_score, char**&player_name, char **&player_scores, int num_players) {

   for (int i = 0; i < num_players; i++) {
      delete []player_name[i];
   }
   delete []player_name;
   player_name = NULL;

   for (int i = 0; i < num_players; i++) {
      delete []player_scores[i];
   }
   delete []player_scores;
   player_scores = NULL;


   for (int i = 0; i < num_players; i++) {
      delete []player_total[i];
   }
   delete []player_total;
   player_total = NULL;


   for (int i = 0; i < num_players; i++) {
      delete []player_round_score[i];
   }
   delete []player_round_score;
   player_round_score = NULL;

}

/*************************************************************************************************
 ** Function: initial_1
 ** Description: Sets the values of some info arrays to nothing
 ** Parameters: info arrays
 ** Pre-Conditions: char array, int array
 ** Post-Conditons: player_name
 ** Return: none
 ***************************************************************************************************/
void initial_1(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total) {

   int length;
   char *name;

   //Set player names
   for (int i = 0; i < num_players; i++) {
      cout << "Enter player " << i + 1 << "'s name: ";
      char_input(name);

      //Only allow length of name 12
      if (strlen(name) > 12)
	 length = 12;
      else
	 length = strlen(name);

      //Input the player names into array
      for (int j = 0; j < length; j++)
	 player_name[i][j] = name[j];
      for (int k = length; k < 12; k++)
	 player_name[i][k] = ' ';
      delete []name;
   }
}


/*************************************************************************************************
 ** Function: initial_2
 ** Description: Initializes player values
 ** Parameters: player names, scores, and totals
 ** Pre-Conditions: character array, int, int array
 ** Post-Conditons: sets all arrays to zero
 ** Return: none
 ***************************************************************************************************/
void initial_2(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total) {

   // This creates a dynamic double array for the player total score
   player_total = new int*[num_players];
   for (int i = 0; i < num_players; i++) {
      player_total[i] = new int[1];
   }

   // This creates a dynamic double array for the player total round score
   player_round_score = new int*[num_players];
   for (int i = 0; i < num_players; i++) {
      player_round_score[i] = new int[12];
   }


   // This initializes the values for the player_total array to 0
   for (int i = 0; i < num_players; i++)
      for (int j = 0; j < 1; j++)
	 player_total[i][j] = 0;

   // This initializes the values for the player_scores array to ' '
   for (int i = 0; i < num_players; i++)
      for (int j = 0; j < 22; j++)
	 player_scores[i][j] = ' ';

   // This initializes the values for the player_round_score array to 0
   for (int i = 0; i < num_players; i++)
      for (int j = 0; j < 12; j++)
	 player_round_score[i][j] = 0;
}


/*************************************************************************************************
 ** Function: spin_for_bowl
 ** Description: Sets the spin_total and player_scores
 ** Parameters: round, player, info arrays
 ** Pre-Conditions: int, char array, int array, bool
 ** Post-Conditons: sets spin_total
 ** Return: none
 ***************************************************************************************************/
void spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare) {

   int spin;
   char char1;

   for (int i = 1; i <= 2; i++) {

      spin_1(spin, i, char1, player_scores, spin_total, round_num, player); 


      // If first spin and strike
      if (spin == 10 && i == 1) {
	 spin_total = 10;
	 player_scores[player - 1][2*round_num] = 'X'; //Need to look at this
	 break;
      }

      spin_2(spin, i, char1, player_scores, spin_total, round_num, player); 

      //Second spin
      if (i == 2) {
	 spin_total += spin;

	 //If second spin is spare
	 if (spin_total == 10) {
	    player_scores[player - 1][2*round_num + 1] = '/';
	    break;
	 }
	 char1 = '0' + spin;
	 player_scores[player - 1][2*round_num + 1] = char1;
	 break;
      }

   }

}

/*************************************************************************************************
 ** Function: spin_1
 ** Description: Runs the second bowl
 ** Parameters: spin, info arrays
 ** Pre-Conditions: int, char array, int array
 ** Post-Conditons: Sets spin
 ** Return: none
 ***************************************************************************************************/
void spin_1(int &spin, int &i, char &char1, char **&player_scores, int &spin_total, int &round_num, int &player) {

   // Sets pins knocked down
   if ( i == 1) {
      spin = rand() % 11;
      //spin = 10;
      cout << "You bowled a " << spin << "!" << endl;
   }
   if ( i == 2) {
      spin = rand() % (11 - spin);
      cout << "You bowled a " << spin << "!" << endl;
   }
}

void spin_2(int &spin, int &i, char &char1, char **&player_scores, int &spin_total, int &round_num, int &player) {
   //If first spin is not strike
   if (spin < 10 && i == 1) {
      spin_total += spin;
      char1 = '0' + spin;
      player_scores[player - 1][2*round_num] = char1;
   }
}


/*************************************************************************************************
 ** Function: bowl
 ** Description: Runs the game
 ** Parameters: player, info arrays
 ** Pre-Conditions: int, char array, int array
 ** Post-Conditons: all array info
 ** Return: none
 ***************************************************************************************************/
void bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, char **&player_name) {

   bool strike = false, spare = false;

   //For 10 rounds
   for (int i = 0; i < 10; i++) {

      //For each player
      for (int j = 0; j < num_players; j++) {

	 //Print player names
	 for (int j = 0; j < 12; j++)
	    cout << player_name[player - 1][j];

	 int spin = 0, spin_total = 0; 

	 cout << endl;

	 cout << "It is your turn. Hit enter to bowl.";

	 cin.ignore(INT_MAX, '\n');

	 //Bowls and sets player_scores
	 spin_for_bowl(player, round_num, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

	 //Adds the scores to player_round_score and total_score
	 add_player_round_score_and_total_score(round_num, player, spin_total, player_scores, player_round_score, player_total); 

	 //Prints the scoresheet
	 scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 

	 //Switches players
	 player_switch(player, num_players); 

      }

      round_num++;

   }

}

/*************************************************************************************************
 ** Function: who_won
 ** Description: Prints who won
 ** Parameters: player_total, player_name, number of players
 ** Pre-Conditions: int array, char array, int
 ** Post-Conditons: Prints winner
 ** Return: none
 ***************************************************************************************************/
void who_won(int **player_total, char **player_name, int num_players) {

   int player = 0;

   //Decides who won the game
   for (int i = 1; i < num_players; i++) {

      if (player_total[i][0] > player_total[player][0])
	 player = i;
   }


   //Prints who one the game
   for (int i = 0; i < 12; i++) {
      if (player_name[player][i] == ' ')
	 break;
      cout << player_name[player][i];
   }
   cout << " won!" << endl;
}




/*************************************************************************************************
 ** Function: player_switch
 ** Description: switches players
 ** Parameters: player, number of players
 ** Pre-Conditions: int, int
 ** Post-Conditons: player++ or player==1
 ** Return: none
 ***************************************************************************************************/
void player_switch(int &player, int num_players) {

   //Switches players
   if (player < num_players)
      player++;
   else
      player = 1;

}


/*************************************************************************************************
 ** Function: char_input
 ** Description: Allows string input
 ** Parameters: char array
 ** Pre-Conditions: char array
 ** Post-Conditons: user_input into char array
 ** Return: none
 ***************************************************************************************************/
void char_input(char *&str) {

   char s;
   char temp[2000]; 
   int num = 0;

   //Allows string input
   cin >> temp;
   cin.ignore(INT_MAX, '\n');
   cin.clear();
   for (int i = 0; i < 2000; i++) {
      num++;
      if (temp[i] == '\0')
	 break;
   }
   str = new char[num];
   for (int i = 0; i < num - 1; i++)
      str[i] = temp[i];
   str[strlen(str)] = '\0';
}


//VALID INPUT CHECKERS


/*************************************************************************************************
 ** Function: is_name
 ** Description: Valid name?
 ** Parameters: char array
 ** Pre-Conditions: char array
 ** Post-Conditons: none
 ** Return: none
 ***************************************************************************************************/
bool is_name(char *&str) {

   // Allows certain characters for name
   for (int i = 0; i < strlen(str); i++) {

      if ( (str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] < 'Z') )
	 return true;
      else
	 return false;

   }

}

/*************************************************************************************************
 ** Function: int_input
 ** Description: Allows integer input
 ** Parameters: prompt, num
 ** Pre-Conditions: int
 ** Post-Conditons: num = input
 ** Return: none
 ***************************************************************************************************/
void int_input(string prompt, int *num) {

   //Allows only integer input
   char *input;
   //char input2[1000];
   while (true) {
      cout << prompt;
      char_input(input);
      if ( is_num(input) ) {
	 *num = atoi(input);
	 delete [] input;
	 return;
      }
      delete [] input;
   }
}

/*************************************************************************************************
 ** Function: is_num
 ** Description: Is it a number
 ** Parameters: char array
 ** Pre-Conditions: char pointer
 ** Post-Conditons: none
 ** Return: true, false
 ***************************************************************************************************/
bool is_num(char *chr) {
   //Is this a number?
   for (int i = 0; i < strlen(chr); i++) {
      if ( (chr[i] < '0' || chr[i] > '9') ) {
	 return false;
      }
      else
	 return true;
   }
}

/*************************************************************************************************
 ** Function: in_range
 ** Description: Is the number in range
 ** Parameters: int
 ** Pre-Conditions: int 
 ** Post-Conditons: none
 ** Return: none
 ***************************************************************************************************/
bool in_range(int start, int end, int input) {

   int beg;

   //Only allows a certain range
   if (end < start) {
      beg = start;
      start = end;
      end = beg;
   }

   //If not in range, false
   if (input < start || input > end) {
      return false;
   }
   //If in range, true
   else {
      return true;
   }
}


















