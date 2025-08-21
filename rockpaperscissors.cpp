#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <Kernel/sys/kernel_types.h>
using namespace std;

class RockPaperScissors {
private:
    int gameMode;
    int numRounds;
    string playerName;
    int *winners;

public:
    RockPaperScissors() : gameMode(0), numRounds(0), playerName("") {
        srand(time(0)); // seed random once in constructor
    }
void start() {
  
	cout <<  "Please choose a game mode:" << 
	" \n" << "1. Player vs. Computer" << "\n" << "2. Computer vs. Computer"
	<< "\n" << "3. Exit" << "\n"; 
	cin >> gameMode;
	
    while (!(gameMode>=1 && gameMode<=3))
	{
		cout << "please enter a valid number: " << "\n"; 
		cin >> gameMode; 
	}
		if (gameMode==3)
        return;
	getGameInfo();
	addWinner();
    results();

	
}
void addWinner()
{
	winners = new int[numRounds];
	int player1=0;
	int player2=0;
	for(int i=0; i<numRounds; i++)
	{
		int result=round(); 
		winners[i]=result; //uses a dynamically allocated array to store the non-draw result of each completed round
		if (winners[i]==1 )
		{
			player1++;
		}
		else if (winners[i]==2)
		{
			player2++;
		}
	}
}
void getGameInfo() 
{
    cout << "Please enter the number of rounds: "; 
	cin >> numRounds;
    while(numRounds %2 == 0 || numRounds <=0)
	{
		cout << "Please enter a correct number of rounds "; 
		cin >>  numRounds;
	}
    if (gameMode==1)
	{
		cout << "Please enter your name: " ; 
		cin >> playerName;
	
	}
    else {
        playerName = "Computer";
    }
}

//Depending on the game mode, this function determines the winner of each round based on whether each player chooses rock, paper, or scissors
int round() {
int choice1, choice2;
	if(gameMode==1)
	{
		cout << "Please enter a number from 1-3. 1=rock, 2=paper, 3=scissors: ";
		cin >> choice1;
		while (!(choice1>=1 && choice1<=3))
		{
			cout << "please enter a valid number: " << "\n"; 
			cin >> choice1; 
		}
	}
	else 
	{
		choice1=rand()%3+1;
	}
	choice2=rand()%3 + 1;
	while (choice1==choice2) //replays all rounds that end in a draw
	{
		choice2=rand()%3 + 1 ; 
	}

	return getOutcome(choice1,choice2);
}

//Determines the outcome of a round based on whether the person chooses rock, paper, or scissors
//Returns the outcome (The number 0 for draw, 2 the second person being the winner, and 1 for the first person being the winner)
int getOutcome(int choice1, int choice2)
{
    if ( (choice1==1 && choice2==2) || (choice1==2 && choice2==3)	|| (choice1==3 && choice2==1))
	{
		return 2; 
	}
	else 
	{
		return 1;
	}
}
void results()
{
    ostringstream out;
    //Creates a table to display the results of each round
    if (gameMode==1)
	{
		out << "Round     | " << playerName << "    |" << "Computer 2 " << "\n" << "-----------------------" << "\n";
	}
	else 
	{
		out << "Round     | " << "Computer 1     |Computer 2" << "\n"<< "--------------------------" << "\n";
	}
    //Counts the number of wins for each player in order to determine the overall winner
    int p1win=0; 
	int p2win=0;
    //Loops through each index of the winners array to print the results of each round
	for(int i=0; i<numRounds; i++)
	{
		if (winners[i]==1)
		{
			out << i+1 << "          | W     " << "   | L  "  << "\n";
			p1win++;
		}
		else
		{
			out << i+1 << "          | L     " << "   | W  "  << "\n";
			p2win++;
		}
	}
	out << "Winner: " ;
    //Determines the overall winner based on the number of wins
	if (p1win>p2win)
	{
		out<<playerName << "\n"; 
	}
	else  
	{
	 out << "Computer" << "\n";
	}
    cout << out.str();
    int save = 0;

    // saving results to file 
    cout << "Would you like to save the results to a file? (1=yes, 0=no): ";
    cin >> save;
    if (save == 1) {
        // Get current time for filename
        time_t timeVar;
	    time(&timeVar);
	    string t=ctime(&timeVar);
	    t=t.substr(0,t.length()-1);
        // Create a filename based on player name and timestamp
        string filename= playerName + "_"  +"Computer2_Results" + t;
        if (gameMode == 1) {
            ofstream File(filename+ ".txt") ;
            File << out.str();
            File.close();
        } else {
            ofstream File("Computer_Results_" + t + ".txt");
            File << out.str();
            File.close();
        }
        cout << "Results saved to file." << endl;
    } else {
        cout << "Results not saved." << endl;
    }
   
}


};
