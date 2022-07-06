#include <iostream>
#include <cstdlib>
#include <cstring>
#include<ctime> //Alows randint();
#include<climits> //Allows INT_MAX
using namespace std;

bool is_num(char *);
void int_input(string, int *);
bool in_range(int, int, int);
void char_input(char *&str);
bool is_name( char *&str);
void initial(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total);
void scoresheet(char **&player_name, char **&players_scors, int **&player_total, int **&player_round_score, int num_players, int round_num, int player);
void bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, char **&player_name); 
void spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare); 
int add_player_round_score_and_total_score(int &round_num, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total); 
void player_switch(int &player, int num_players); 
void who_won(int **player_total, char **player_name, int num_players); 
bool display_player_round_score(int round_num, int player, bool break_cycle, char **player_scores, int **player_round_score); 
void extra_round(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name); 
//void extra_chance(bool strike, bool spare, int player, int num_players, int round_num, char **player_name, int **&player_total, int **&player_round_score, char **&player_scores); 
//void extra_spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare, int round); 

int main () {

   srand(time(NULL));

   int num_players, round_num = 0, player = 1, **player_total, **player_round_score;
   char **player_name, **player_scores;

   initial(player_name, player_scores, player_round_score, num_players, player_total);


   bool strike, spare;
   int spin_total = 0;

   bowl(player, round_num, num_players, player_scores, player_total, player_round_score, player_name); 


   extra_round(round_num, num_players, player, spin_total, player_scores, player_round_score, player_total, player_name); 

   //extra_chance(strike, spare, player, num_players, round_num, player_name, player_total, player_round_score, player_scores); 

   who_won(player_total, player_name, num_players); 

   //spin_for_bowl(player,round_num, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare); 

   //add_player_round_score_and_total_score(round_num, player, spin_total, player_scores, player_round_score, player_total); 

   //scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player);

}


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

}

void extra_round(int &round_num, int num_players, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total, char **player_name) {

   bool strike, spare;

   for (int i = 0; i < num_players; i++) {

      int round1 = 10, round2 = 11, round3 = 10, player = i + 1;

      if (player_scores[i][18] == 'X') {
	 cout << "You got an extra turn! Hit enter to bowl.";
	 cin.ignore(INT_MAX, '\n');

	 extra_spin_for_bowl(i, round1, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

	 add_player_round_score_and_total_score(round1, player, spin_total, player_scores, player_round_score, player_total);

	 cout << "You got an extra turn! Hit enter to bowl.";
	 cin.ignore(INT_MAX, '\n');

	 scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 

	 extra_spin_for_bowl(i, round2, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

	 add_player_round_score_and_total_score(round2, player, spin_total, player_scores, player_round_score, player_total);
	 scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 

      }
      else if (player_scores[i][19] == '/') {

	 extra_spin_for_bowl(i, round3, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare);

	 add_player_round_score_and_total_score(round3, player, spin_total, player_scores, player_round_score, player_total);

	 scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 
      }



   }
} 

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

   cout << spin_total << endl;//Eventually rid of this

}

void extra_round_scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player) {

   cout << "Name         "; 

   for (int i = 1; i <= 9; i++) {
      cout << "|  " << i << "   ";
   }
   cout << "|  10  ";
   for (int i = 11; i <= 12; i++)
      cout << "| " << i << " ";

   cout << "|" << "  Total" << endl
      << "-------------------------------------------------------------------------------------------------------------------------------" << endl;







   for (int i = 0; i < num_players; i++) {
      for (int j = 0; j < 12; j++)
	 cout << player_name[i][j];
      for (int j = 0; j <= 9; j++) {
	 cout << " |  " << player_scores[i][2*j] << " " << player_scores[i][2*j+1]; 
      }
      cout << " ";
      //for (int j = 10; j < 12; j++) // Need to put something here about extra rounds
	 cout << player_scores[i][20];
	 cout << " |   ";
	 cout << player_scores[i][21];
	 cout << " |   ";
      cout << " |  " << player_total[i][0] << endl;
      cout << "             | ";

      bool break_cycle = false;


      for (int k = 0; k < 10; k++) {
	 cout << player_round_score[i][k] << "   |  ";
      }





      for (int k = round_num + 1; k <= 9; k++) {
	 if (round_num == 9)
	    break;
	 cout << "    "
	    << "|  ";
      }
      //cout << player_scores[i][20];
      cout << "  |   ";

      //cout << player_scores[i][21];
      cout << "   |    ";
      cout << endl;

      cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << endl;
   }
   cout <<  "round_num: " << round_num << endl;
   for (int y = 0; y < num_players; y++) {
      cout << "Player 1" << endl;
      for (int x = 0; x < 10; x++)
	 cout << player_round_score[y][x] << endl;
   }

}


bool display_player_round_score(int round_num, int player, bool break_cycle, char **player_scores, int **player_round_score) {


   if (round_num == 0) {
      if (break_cycle) {
	 if (player_round_score[player - 1][0] > 9)
	    cout << player_round_score[player - 1][0] << "   |  ";
	 else
	    cout << player_round_score[player - 1][0] << "  |    ";
	 return true;
      }
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
	 else {
	    cout << "    |     ";
	    //cout << "HELLO!" << endl;
	    return false;
	 }
      }
   }



   if (round_num > 0) {
      if ( player_scores[player - 1][(round_num)*2] != 'X' && player_scores[player - 1][(round_num - 1)*2] != 'X' && player_scores[player - 1][(round_num)*2 + 1] != '/' )
	 break_cycle = true;
   }
   else if (round_num > 1)
      if (player_scores[player - 1][(round_num)*2] != 'X' && player_scores[player - 1][(round_num - 1)*2] != 'X' && player_scores[player - 1][(round_num)*2 + 1] != '/'  )
	 break_cycle = true;



   if (display_player_round_score(--round_num, player, break_cycle, player_scores, player_round_score) && break_cycle) {

      if (player_round_score[player - 1][round_num] > 99)
	 cout << player_round_score[player - 1][round_num+1] << " |  ";
      else if (player_round_score[player - 1][round_num+1] > 9)
	 cout << player_round_score[player - 1][round_num+1] << "  |  ";
      else
	 cout << player_round_score[player - 1][round_num+1] << "   |  ";

      return true;
   }
   else {
      cout << "   |   ";
      return false;
   }



}



void scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player) {

   cout << "Name         "; //<< "|  1   ";

   for (int i = 1; i <= 9; i++) {
      cout << "|  " << i << "   ";
   }
   cout << "|  10  ";
   for (int i = 11; i <= 12; i++)
      cout << "| " << i << " ";

   cout << "|" << "  Total" << endl
      << "-------------------------------------------------------------------------------------------------------------------------------" << endl;







   for (int i = 0; i < num_players; i++) {
      for (int j = 0; j < 12; j++)
	 cout << player_name[i][j];
      for (int j = 0; j <= 9; j++) {
	 cout << " |  " << player_scores[i][2*j] << " " << player_scores[i][2*j+1]; 
      }
      cout << " ";
      //for (int j = 11; j < 13; j++) // Need to put something here about extra rounds
	 cout << " |   ";
	 cout << " |   ";

      cout << " |  " << player_total[i][0] << endl;
      cout << "             | ";

      bool break_cycle = false;


      if (i+1 <= player)
	 display_player_round_score(round_num, i + 1, break_cycle, player_scores, player_round_score); 
      else if (round_num == 0)
	 ;
      else
	 display_player_round_score(round_num - 1, i + 1, break_cycle, player_scores, player_round_score); 


      for (int k = round_num + 1; k <= 9; k++) {
	 if (round_num == 9)
	    break;
	 cout << "    "
	    << "|   ";
      }
      cout << player_scores[i][20];
      cout << " |   ";
      cout << player_scores[i][21];
      cout << "|    ";
      cout << endl;

      cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << endl;
   }
   cout <<  "round_num: " << round_num << endl;
   for (int y = 0; y < num_players; y++) {
      cout << "Player 1" << endl;
      for (int x = 0; x < 10; x++)
	 cout << player_round_score[y][x] << endl;
   }

}








void initial(char **&player_name, char **&player_scores, int **&player_round_score, int &num_players, int **&player_total) {

   char *name;
   int length;

   int_input("How many players want to bowl?", &num_players);

   player_name = new char*[num_players];
   for (int i = 0; i < num_players; i++) {
      player_name[i] = new char[13];
   }

   for (int i = 0; i < num_players; i++) {
      cout << "Enter player " << i + 1 << "'s name: ";
      char_input(name);

      if (strlen(name) > 12)
	 length = 12;
      else
	 length = strlen(name);

      for (int j = 0; j < length; j++)
	 player_name[i][j] = name[j];
      for (int k = length; k < 12; k++)
	 player_name[i][k] = ' ';
   }

   // This creates a dynamic double array for the player scores for each bowl
   player_scores = new char*[num_players];
   for (int i = 0; i < num_players; i++) {
      player_scores[i] = new char[22];
   }

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

void spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare) {

   int spin;
   char char1;

   for (int i = 1; i <= 2; i++) {

      // Sets pins knocked down
      if ( i == 1) {
	 spin = rand() % 11;
	 cout << "You bowled a " << spin << "!" << endl;
      }
      if ( i == 2) {
	 spin = rand() % (11 - spin);
	 cout << "You bowled a " << spin << "!" << endl;
      }

      // If first spin and strike
      if (spin == 10 && i == 1) {
	 spin_total = 10;
	 player_scores[player - 1][2*round_num] = 'X'; //Need to look at this
	 strike = true;
	 break;
      }

      //If first spin is not strike
      if (spin < 10 && i == 1) {
	 spin_total += spin;
	 char1 = '0' + spin;
	 player_scores[player - 1][2*round_num] = char1;
      }

      //Second spin
      if (i == 2) {
	 spin_total += spin;

	 //If second spin is spare
	 if (spin_total == 10) {
	    player_scores[player - 1][2*round_num + 1] = '/';
	    spare = true;
	    break;
	 }
	 char1 = '0' + spin;
	 player_scores[player - 1][2*round_num + 1] = char1;
	 break;
      }
   }
   cout << spin_total << endl;//Eventually rid of this

}


void bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, char **&player_name) {

   bool strike = false, spare = false;

   for (int i = 0; i < 10; i++) {

      for (int j = 0; j < num_players; j++) {

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













void who_won(int **player_total, char **player_name, int num_players) {

   int player = 0;

   for (int i = 1; i < num_players; i++) {

      if (player_total[i][0] > player_total[player][0])
	 player = i;
   }


   for (int i = 0; i < 12; i++) {
      if (player_name[player][i] == ' ')
	 break;
      cout << player_name[player][i];
   }
   cout << " won!" << endl;
}
/*
   for (int k = 0; k <= round_num; k++) {

   if (k == 10)
   break;

   if (player_round_score[i][k] < 10) 
   cout << "  | ";
   else if (player_round_score[i][k] < 100)
   cout << " |  ";
   else
   cout << "| ";

   if ( !( ((k == round_num) && (player_scores[i][k*2] == 'X' || player_scores[i][k*2 + 1] == '/') ) || ((k == round_num - 1) && player_scores[i][k*2] == 'X') || (i == player && k == round_num) ) ) {
   if ( !((k == round_num) && player_scores[i][(k-1)*2] == 'X') )
   cout << player_round_score[i][k];
   }

   else if (player_round_score[i][k] > 9)
   cout << "  ";
   else if (player_round_score[i][k] > 99)
   cout << "   ";

   if (player_round_score[i][k] == 0)
   cout << " ";

   }
   */
/*
   void extra_chance(bool strike, bool spare, int player, int num_players, int round_num, char **player_name, int **&player_total, int **&player_round_score, char **&player_scores) {

   for (int i = 0; i < num_players; i++) {

   player = i + 1;

   if (player_scores[player - 1][18] == 'X') {

   for (int i = 0; i < 2; i++) {

   for (int j = 0; j < 12; j++)
   cout << player_name[player - 1][j];

   int spin = 0, spin_total = 0; 

   cout << endl;

   cout << "You got an extra turn! Hit enter to bowl.";

   cin.ignore(INT_MAX, '\n');

//Bowls and sets player_scores
//extra_spin_for_bowl(player, round_num, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare, i); 

//Adds the scores to player_round_score and total_score
add_player_round_score_and_total_score(round_num, player, spin_total, player_scores, player_round_score, player_total); 

//Prints the scoresheet
scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, i); 
}
}
else if (player_scores[player - 1][19] == '/') {

for (int j = 0; j < 12; j++)
cout << player_name[player - 1][j];

int spin = 0, spin_total = 0; 

cout << endl;

cout << "You got an extra turn! Hit enter to bowl.";

cin.ignore(INT_MAX, '\n');

//Bowls and sets player_scores
//extra_spin_for_bowl(player, round_num, num_players, player_scores, player_total, player_round_score, spin_total, strike, spare, i); 

//Adds the scores to player_round_score and total_score
add_player_round_score_and_total_score(round_num, player, spin_total, player_scores, player_round_score, player_total); 

//Prints the scoresheet
scoresheet(player_name, player_scores, player_total, player_round_score, num_players, round_num, player); 
}

}



}
*/
/*
   void extra_scoresheet(char **&player_name, char **&player_scores, int **&player_total, int **&player_round_score, int num_players, int round_num, int player) {

   cout << "Name         " << "|  1 ";

   for (int i =2; i <= 10; i++) {
   cout << " |  " << i << " ";
   }

   cout << " |" << "  Total" << endl
   << "---------------------------------------------------------------------------------------" << endl;

   for (int i = 0; i < num_players; i++) {
   for (int j = 0; j < 12; j++)
   cout << player_name[i][j];
   for (int j = 0; j <= 9; j++) {
   cout << " | " << player_scores[i][2*j] << " " << player_scores[i][2*j+1]; 
   }
   cout << "  |  " << player_total[i][0] << endl;
   cout << "             |  ";

   for (int k = 0; k <= round_num; k++) {

   if ( !( ((k == round_num) && (player_scores[i][k*2] == 'X' || player_scores[i][k*2 + 1] == '/') ) || ((k == round_num - 1) && player_scores[i][k*2] == 'X') || (i >= player && k == round_num) ) ) {
   if ( !((k == round_num) && player_scores[i][(k-1)*2] == 'X') )
   cout << player_round_score[i][k];
   }
   else if (player_round_score[i][k] > 9)
   cout << "  ";
   else if (player_round_score[i][k] > 99)
   cout << "   ";

   if (player_round_score[i][k] == 0)
   cout << " ";

   if (player_round_score[i][k] < 10) 
   cout << "  |  ";
   else if (player_round_score[i][k] < 100)
   cout << " |  ";
   else
   cout << "| ";
   }
   for (int k = round_num + 1; k <= 9; k++) {
   cout << "   "
   << "|  ";
   }
   cout << "    |    ";
   cout << endl;

   cout << "---------------------------------------------------------------------------------------" << endl;
   cout << endl;
   }

   }


   void extra_spin_for_bowl(int &player, int &round_num, int num_players, char **&player_scores, int **&player_total, int **&player_round_score, int &spin_total, bool &strike, bool &spare, int round) {

   int spin;
   char char1;

   for (int i = 1; i <= 2; i++) {

// Sets pins knocked down
if ( i == 1) {
spin = rand() % 11;
cout << "You bowled a " << spin << "!" << endl;
}
if ( i == 2) {
spin = rand() % (11 - spin);
cout << "You bowled a " << spin << "!" << endl;
}

// If first spin and strike
if (spin == 10 && i == 1) {
   spin_total = 10;
   player_scores[player - 1][round + 20] = 'X'; //Need to look at this
   strike = true;
   break;
}

//If first spin is not strike
if (spin < 10 && i == 1) {
   spin_total += spin;
   char1 = '0' + spin;
   player_scores[player - 1][round + 20] = char1;
}

//Second spin
if (i == 2) {
   spin_total += spin;

   //If second spin is spare
   if (spin_total == 10) {
      player_scores[player - 1][round + 20] = '/';
      spare = true;
      break;
   }
   char1 = '0' + spin;
   player_scores[player - 1][round + 20] = char1;
   break;
}
}
cout << spin_total << endl;//Eventually rid of this

}

int extra_add_player_round_score_and_total_score(int &round_num, int &player, int spin_total, char **&player_scores, int **&player_round_score, int **&player_total) {

   //If there has been one round, check to see if there was a strike or spare last round. Then add this round score to that round score if there was one
   if (round_num > 0)
      if ( ( player_scores[player - 1][((round_num - 1) * 2) + 1] == '/' ) || ( player_scores[player - 1][(round_num - 1) * 2] == 'X' ) )
	 player_round_score[player - 1][round_num - 1] += spin_total;

   //If there has been two rounds, check to see if there was a strike two rounds ago, then add this round total to that round total if there was one
   if (round_num > 1 )
      if ( player_scores[player - 1][(round_num - 2) * 2] == 'X')
	 player_round_score[player - 1][(round_num - 2)] += spin_total;

   //This adds the round score and previous round scores to the cureent player round score
   for (int i = 0; i < 12; i++)
      player_round_score[player - 1][round_num] = player_round_score[player - 1][i];

   player_round_score[player - 1][round_num] += spin_total;

   //This adds the total to player_total
   for (int i = 0; i < 12; i++)
      player_total[player - 1][0] = player_round_score[player - 1][i];

}
*/





void player_switch(int &player, int num_players) {

   if (player < num_players)
      player++;
   else
      player = 1;

}


void char_input(char *&str) {

   char s;
   char temp[2000]; 
   int num = 0;

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


bool is_name(char *&str) {

   for (int i = 0; i < strlen(str); i++) {

      if ( (str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] < 'Z') )
	 return true;
      else
	 return false;

   }

}

void int_input(string prompt, int *num) {

   char *input = new char[1];
   while (true) {
      cout << prompt;
      char_input(input);
      if ( is_num(input) ) {
	 *num = atoi(input);
	 return;
      }
   }
}

bool is_num(char *chr) {
   for (int i = 0; i < strlen(chr); i++) {
      if ( (chr[i] < '0' || chr[i] > '9') ) {
	 return false;
      }
      else
	 return true;
   }
}

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






















//OLD
/*
   str[0] = '\0';

   cin.get(s);
   while (s != '\n') {

   temp = str;
   str = new char[strlen(temp) + 2];
   strcpy(str, temp);
   str[strlen(temp)] = s;
   str[strlen(temp) + 1] = '\0';
   delete [] temp; // Another way to input a character array
   cin.get(s);
   }
   */

/*
// Initializes single char array to values of player i's first and second bowling score
char1[0] = player_scores[i][2*k+1];
char2[0] = player_scores[i][2*k];

//Inputs the round score of a player into the player_round_score
player_round_score[i][k] = atoi(char1) + atoi(char2);
*/ 
// SHOULDNT NEED THIS BECAUSE ARITHMETIC IS PERFORMED IN FUNCTION bowl(); Don't need this, will not work.

