/* Name: Sabrina Pinera
Date: October 23, 2018
Section: 5
Assignment: 4
Due Date: October 22, 2018
About this project: (A game created for a user to pick one door out of three doors and have a losing door open.
Then the user is asked to pick one of the last two doors and see if they win or lose)
Assumptions: (The code will run a random number for the prize) 

All work below was performed by Sabrina Pinera */

//Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib> // for srand and rand
#include <ctime>  // for time

using namespace std;

//Function declaration.
void printDoors();
int randDoors();
void seeStats(int wins, int losses);


int main()
{
	//Variable declaration
    	int num, choice;
	int wins = 0, losses = 0;
	int goat, doorChoice, secondChoice;

	srand ((unsigned int)time(0)); //seeding function, called only ONCE. @ the beginning

	cout << "Welcome to the Monty Hall Let's Make a Deal Simulator!\n\n";

	do
	{
	    //Display game choices
	    cout << "Choose one of the Following:\n";
	    cout << "1 Play the Game\n";
	    cout << "2 See Stats\n";
	    cout << "3 Reset Stats\n";
	    cout << "4 Quit\n";
	    cout << "> ";
	    cin >> choice;

	    //Creating restrictions
	    while(choice >= 5 || choice <= 0)
	    {
	    	cout << "Invalid option, please retry > ";
                cin >> choice;
	    }

	    //switch statement to create the list
	    switch(choice)
	    {
	        case 1 :
		{
			cout << "Pick a Door, 1, 2, or 3!\n\n";
	              		printDoors();
	               		int car = randDoors();

	    		cout << "\nChoice > ";
			cin >> doorChoice;
 			cout << "You chose door #" << doorChoice <<"!\n";
			cout << "I'll now open a door for you randomly that you didn't choose!\n";


    			//created to figure out what happens if goat is a certain door
			if (car != 1 && 1 != doorChoice)
        		{
            			goat = 1;
        		}
     			else if (car != 2 && 2 != doorChoice)
        		{
             			goat = 2;
        		}
        		else if (car != 3 && 3 != doorChoice)
        		{
            			goat = 3;
        		}

   	 		cout << "Opening door " << goat << " and it's a GOAT!\n";
   			cout << "Now, I'll be a kind host and give you the chance to switch your door!\n";

			//goat will then output the users door and a second door.
                        if(goat == 1)
                        {
                                 cout << "Would you like door #2 or #3 > ";
                        }
                        else if( goat == 2)
                        {
                                cout << "Would you like door #1 or #3 > ";
                        }
                        else if (goat == 3)
                        {
                                cout << "Would you like door #1 or #2 > ";

                        }

			cin >> secondChoice;
   		 	cout << "Opening door #" << secondChoice << ".....\n";

			//Output is the user picked the winning or losing door
			if(secondChoice != car)
			{
	        		cout << "baaaaaaaaaaaaa.... it's a GOAT!!!! You LOSE!\n\n";
	    			losses++;
			}
   	 		else
    			{
       				cout << "it's a BRAND NEW CAR!!!! YOU WIN!!!!\n\n";
    				wins++;
			}

	        break;}
	        case 2 :
			//Calculate the amount played, the wins and losses, and the percent of wins and losses
			seeStats(wins, losses);

	        break;
	        case 3 :
		      {
			//Stats are reset to zero
		 	wins = 0;
			losses = 0;
			cout << "... Statistics Reset!\n\n\n";

	        break;}
	        case 4 :
			//case 4 is to quit the loop
			cout << "Goodbye!\n";

	        break;

	    }

	}while(choice!=4);



   return 0;
}

/*ASCII Art doors*/
/*THIS FUNCTION PRINTDOORS IS PROVIDED (graciously by ascii artist Melina) by the student wherever needed.*/
void printDoors()
{
        cout << "---------    ---------    ---------- \n";
        cout << "|       |    |  ____ |    |  _____ | \n";
        cout << "|   |   |    |     | |    |      | | \n";
        cout << "|   |   |    |  ___| |    |   ___| | \n";
        cout << "|   |   |    | |     |    |      | | \n";
        cout << "|   |   |    | |____ |    |  ____| | \n";
        cout << "---------    ---------    ---------- \n";

        return;
}
//Generates random car
int randDoors()
{
	int car = (rand() % 3) + 1;
	return car;
}

void seeStats(int wins, int losses)
{
    double winP, lossP;
    double  totalplays;

    //Equations
    totalplays = (wins + losses);
    winP = (wins/totalplays) * 100;
    lossP = (losses/totalplays) * 100;

    if (totalplays  == 0)
    {
        cout << "No Stats to Display, 0 games played.\n";
    }
    else
    {
   	 //output for wins/losses and stats
   	 cout << "Results after " << totalplays << " games:\n";
    	 cout << "Wins: " << wins << "\t\tLosses: " << losses << endl;
   	 cout << fixed << setprecision(1) << "Win %: " << winP << "\t\tLoss %: " << lossP << "\n\n";
    }
}
