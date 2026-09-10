
#include <iostream>
using namespace std;

    void DisplayMenu()
    {
        cout << "Menu:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "4. Quit" << endl;
        cout << endl;
    }

    // 

    int GetPlayerChoice()
    {
        int Choice;
        cout << "Make Your Choice" << endl;
        if (cin >> Choice && Choice >= 1 && Choice <= 4) {
            return Choice;
        }
        else {
            cout << "Invalid, try again with a value between 1 and 4.";
            cin.clear();
            return 4;
        }
    }

    // 

    int GetComputerChoice()
    {
        return (rand() % 3) + 1;
    }

    //

    string ChoiceToString(int Choice)
    {
        if (Choice == 1) return " Rock";
        if (Choice == 2) return " Paper";
        if (Choice == 3) return " Scissors";
        return "What have you Done";
    }

    //

    int DetermineRoundWinner(int PlayerChoice, int ComputerChoice)
    {
        if (PlayerChoice == ComputerChoice){
                return 0;
        }
        //
    
        if ((PlayerChoice == 1 && ComputerChoice == 3) ||
        (PlayerChoice == 2 && ComputerChoice == 1) ||
        (PlayerChoice == 3 && ComputerChoice == 2)) {
                return 1;
        }
        else {
            return 2;
        }
        
    }

    //

    void DisplayRoundResult(int PlayerChoice, int ComputerChoice, int Winner) {
        cout << "You Chose:" << ChoiceToString(PlayerChoice) << endl;
        cout << "Computer Chose:" << ChoiceToString(ComputerChoice) << endl;

        if (Winner == 0) {
            cout << "Result: Tie" << endl;
        }
        else if (Winner == 1) {
            cout << "Result: You've Won" << endl;
        }
        else {
            cout << "Result: You've Lost" << endl;
        }
    }

    //

    void DisplayFinalResult(int PlayerWins, int ComputerWins, int Ties) {
        cout << "Final Results" << endl;
        cout << "Player Wins: " << PlayerWins << endl;
        cout << "Computer Wins: " << ComputerWins << endl;
        cout << "Ties: " << Ties << endl;
        cout << "Goodbye" << endl;
    }

    //


    
        
    int main()
    {
        const int Rock = 1;
        const int Paper = 2;
        const int Scissors = 3;
        const int Quit = 4;

        int PlayerWins = 0;
        int ComputerWins = 0;
        int Ties = 0;


        cout << "Rock, Paper, Scissors. What'll it be?";
        while (true)
        {
            DisplayMenu();
            int PlayerChoice = GetPlayerChoice();
            if (PlayerChoice == 4)
            {
                break;
            }
            int ComputerChoice = GetComputerChoice();
            int Winner = DetermineRoundWinner(PlayerChoice, ComputerChoice);
            if (Winner == 1) {
                PlayerWins++;
            }
            else if (Winner == 2) {
                ComputerWins++;
            }
            else {
                Ties++;
            }
            DisplayRoundResult(PlayerChoice, ComputerChoice, Winner);
        }
        DisplayFinalResult(PlayerWins, ComputerWins, Ties);
        return 0;

    }
