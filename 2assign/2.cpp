/************************************************************
 **Program: space_adventure.cpp
 **Author: Stefan Ball
 **Date: 1/20/17
 **Description: This program takes you along a text adventure. You are able to choose your own path and therefore choose the outcome. However, there is an element of chance in some of the choices, so are not guruanteed to get the same output every time.
 **Input: The user will input a 1 or 2 to signify which path they want to take
 **Output: The outcome of the choice and a prompt asking what the user wants to do next, if the story is not done, will appear when the user inputs their choice.
************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {

   int choice1, choice2 = 1, x;

   srand(time(NULL));
   
   while (choice2 == 1) { // Allows the user the choice to replay the game by entering 1 into choice2 after the game is over to run the loop again

   int randomint = rand() % 2 + 1, randomint2 = rand() % 2 + 1, randomint3 = rand() % 2 + 1, randomint4 = rand() % 2 + 1;

   cout << "You are a budding space explorer in the year 2167. Many years of hard work has allowed you to build a private spaceship and find a skilled crew to explore the vastly unexplored galaxy with you. To embark on your journey, hit <enter>";
   cin.ignore(); // This ignores any input that the user gives and takes the user to the game after they hit enter

   cout << "You need to land on a base outside of Earth's atmosphere to begin your journey. Do you go to Moon Base or Mars Base? Enter '1' for Moon Base and '2' for Mars Base. ";
   cin >> choice1; 

      if (choice1 == 1) {
         cout << "You're in luck! ";

         // if the random integer between 1 and 2 is one, it will take you here
         if (randomint == 1) {
            cout << "You've come across a very valuable asteriod. After mining the asteriod, you and your crew become extremely wealthy and decide to live the good life one Earth." << endl;
            cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
            cin >> choice2;
            cin.ignore(); // This clears the buffer so that if the user chooses to play again, the initial prompt will be displayed again.
         }

         // if the random integer between 1 and 2 is two, it will take you here
         else if (randomint == 2) {
            cout << "On base, you pick up a new highly skilled crew member that claims to have extensive knowledge of the galaxy. Do you follow your original plan (1) or go with her plan (2)? ";
            cin >> choice1;

            if (choice1 == 1) {
               cout << "You decide to stick with your original plan for exploring the galaxy. You find a new dwarf planet, but it doesn't hold much significance. You may be able to plan a new journey in a few years." << endl;
               cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
               cin >> choice2;
               cin.ignore();
            } 

            else if (choice1 == 2) {
               cout << "You take a chance and decide to trust your new crew member with her well thought out yet ambitious travel plan. Switching plans works out great for you because you discover a new solar system that is similar to our own! This discovery is regarded as one of the most prominent in the decade." << endl;
               cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
               cin >> choice2;
               cin.ignore();
            }
         }
      }

      else if (choice1 == 2) {
         cout << "Oh no!" << endl;

         if (randomint2 == 1) {
            cout << "You have a sick crewmate:( He infects the entire crew with an unkown virus and you are forced to cancel the trip. You may be able to plan another trip in a couple of years." << endl;
            cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
            cin >> choice2;
            cin.ignore();
         }

         else if (randomint2 == 2) {
            cout << "Your fuel tank has been damaged by an asteriod. To continue on your journey, you can either sell your assets (1) or work on the Mars Base (2): ";
            cin >> choice1;

            if (choice1 == 1) {
               cout << "You sell your house to fund your journey. After searching the galaxy for many months, you return to refuel and find that ";

               if (randomint3 == 1) {
                  cout << "your investments back home have greatly decreased. Most of your money has disappeared. However, a wealthy businessman agrees to fund a new journey if you bring his daughter along, as she desperately wants to start exploring. You agree and discover a new moon in another solar system." << endl;
                  cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                  cin >> choice2;
                  cin.ignore();
               }

               else if (randomint3 == 2) {
                  cout << "your investments back home have grown significantly. You are able to immediately embark on another journey. Halfway through the new journey, you find yourself in an asteriod field.";

                  if (randomint == 1) {
                     cout << " However, you are able to hide in a large asteriod to escape being destroyed. While stuck in the asteriod, you discover a metal that is a perfect conductor at zero degrees celcius. You are greatly rewarded for your discovery." << endl;
                     cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                     cin >> choice2;
                     cin.ignore();
                  }

                  else if (randomint == 2) {
                     cout << " You are forced to navigate your way through the asteriod field. Your ship is greatly damaged and you are forced to go home." << endl;
                     cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                     cin >> choice2;
                     cin.ignore();
                  }
               }
            }

            else if (choice1 == 2) {
               cout << "You and your crew decide to work on the Mars Base to earn enough money to fund your journey. After acquiring the necessary amount relatively quickly due to your hard work and skill, you begin your journey again. After a couple months, you run across a new planet that seems habitable. Do you explore it (1) or report it to the Internation Space Organization (IPO) (2)? ";
               cin >> choice1;

               if (choice1 == 1) {
                  cout << "Your ship becomes damaged in a storm. As you repair it, another crew spots the planet, and you return home to fight over claiming discovery of the planet." << endl;
                  cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                  cin >> choice2;
                  cin.ignore();
               }

               else if (choice1 == 2) {
                  cout << "The IPO sends a crew to investigate the planet. You and your crew receive credit for being the first ship to discover a habitable planet and become instant celebrities. Additionally, IPO offers to give you and all of your crew officer postions (1) or a new ship to explore the galaxy (2). Which do you take? "; 
                  cin >> choice1;

                  if (choice1 == 1) {
                     cout << "You and your crew live cushy lives as IPO officers. You don't make any more remarkable discoveries, but you still get your name in the history books." << endl;
                     cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                     cin >> choice2;
                     cin.ignore();
                  }

                  else if (choice1 == 2) {
                     cout << "You and your crew decide to keep living the exploratory life with nobody to listen to. Soon after you embark on your next journey, you come across a planet that looks very promising for scientific exploration, however, it also looks quite dangerous. Do you explore it (1) or move on (2)? ";
                     cin >> choice1;

                     if (choice1 == 1) {
                        cout << "You decide to explore the planet. Within the first couple of hours, there is such a great storm that you are forced to abandon the trip, and you barely make it off the planet. Your ship is greatly damaged, and you will have to return to work to have enough money to repair it." << endl;
                        cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                        cin >> choice2;
                        cin.ignore();
                     }

                     else if (choice1 == 2) {
                        cout << "You decide to leave the planet since it is too dangerous to explore. You move on, but soon find yourself lost in the void of space, and are forced to navigate yourself in a postion to call for help. After finding a signal and finding the correct way to return to Earth, you become scared of the vast void that is space and live out a quiet life." << endl;
                        cout << "Would you like to play again? If so, enter 1. If not, enter 2. ";
                        cin >> choice2;
                        cin.ignore();
                     }
                  }
               }
            }
         }
      }
   }
   return 0;
}

