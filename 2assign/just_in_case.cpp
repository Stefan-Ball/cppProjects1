#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {

   int choice1, choice2, x;
   srand(time(0));
   int randomint = rand() % 2 + 1, randomint2 = rand() % 2 + 1, randomint3 = rand() % 2 + 1, randomint4 = rand() % 2 + 1;
   
   cout << "You are a budding space explorer in the year 2167. Many years of hard work has allowed you to build a private spaceship and find a skilled crew to explore the vastly unexplored galaxy with you. To embark on your journey, hit <enter>";
   cin.ignore();
   cout << "You need to land on a base outside of Earth's atmosphere to begin your journey. Do you go to Moon Base or Mars Base? Enter '1' for Moon Base and '2' for Mars Base. ";
   cin >> choice1; 
   if (choice1 == 1) {
      cout << "You're in luck! ";
      if (randomint == 1) {
         cout << "You've come across a very valuable asteriod. After mining the asteriod, you and your crew become extremely wealthy and decide to live the good life one Earth." << endl;
      }
      else if (randomint == 2) {
         cout << "On base, you pick up a new highly skilled crew member that claims to have extensive knowledge of the galaxy. Do you follow her plan (1) or stick with your original plan (2)? ";
         cin >> choice1;
         if (choice1 == 1) {
            cout << "You decide to stick with your original plan for exploring the galaxy. You find a new dwarf planet, but it doesn't hold much significance. You may be able to plan a new journey in a few years." << endl;
         } 
         else if (choice1 == 2) {
            cout << "You take a chance and decide to trust your new crew member with her well thought out yet ambitious travel plan. Switching plans works out great for you because you discover a new solar system that is similar to our own! This discovery is regarded as one of the most prominent in the decade." << endl;
         }
      }
   }
   else if (choice1 == 2) {
      cout << "Oh no!" << endl;
      if (randomint2 == 1) {
         cout << "You have a sick crewmate:( He infects the entire crew with an unkown virus and you are forced to cancel the trip. You may be able to plan another trip in a couple of years." << endl;
      }
      else if (randomint2 == 2) {
         cout << "Your fuel tank has been damaged by an asteriod. To continue on your journey, you can either sell your assets (1) or work on the Mars Base (2): ";
         cin >> choice1;
         if (choice1 == 1) {
            cout << "You sell your house to fund your journey. After searching the galaxy for many months, you return to refuel and find that ";
            if (randomint3 == 1) {
               cout << "your investments back home have greatly decreased. Most of your money has disappeared. However, a wealthy businessman agrees to fund a new journey if you bring his daughter along, as she desperately wants to start exploring. You agree and discover a new moon in another solar system." << endl;
            }
            else if (randomint3 == 2) {
               cout << "your investments back home have grown significantly. You are able to immediately embark on another journey. Halfway through the new journey, you find yourself in an asteriod field.";
               if (randomint == 1) {
                  cout << " However, you are able to hide in a large asteriod to escape being destroyed. While stuck in the asteriod, you discover a metal that is a perfect conductor at zero degrees celcius. You are greatly rewarded for your discovery." << endl;
               }
               else if (randomint == 2) {
                  cout << " You are forced to navigate your way through the asteriod field. Your ship is greatly damaged and you are forced to go home." << endl;
               }
            }
         }
         else if (choice1 == 2) {
            cout << "You and your crew decide to work on the Mars Base to earn enough money to fund your journey. After acquiring the necessary amount relatively quickly due to your hard work and skill, you begin your journey again. After a couple months, you run across a new planet that seems habitable. Do you explore it (1) or report it to the Internation Space Organization (IPO) (2)? ";
            cin >> choice1;
            if (choice1 == 1) {
               cout << "Your ship becomes damaged in a storm. As you repair it, another crew spots the planet, and you return home to fight over claiming discovery of the planet." << endl;
            }
            else if (choice1 == 2) {
            cout << "The IPO sends a crew to investigate the planet. You and your crew receive credit for being the first ship to discover a habitable planet and become instant celebrities." << endl;
            }
         }
      }
   }
}

