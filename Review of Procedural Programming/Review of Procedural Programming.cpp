// Review of Procedural Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include < ctime>


//Function Prototypes
void DisplayIntro();
int GetUserChoice();
int GenerateComputerChoice();
std::string choice_to_string(int choice);
void DetermineWinner(int, int );

using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

int main()
{
    char playAgain;

    do
    {
        srand(static_cast<unsigned int>(time(0)));

        DisplayIntro();

        int UserChoice = GetUserChoice();
        int ComputerChoice = GenerateComputerChoice();

        cout << "you chose: " << choice_to_string(UserChoice) << endl;
        cout << "computer chose: " << choice_to_string(ComputerChoice) << endl;

        DetermineWinner(UserChoice, ComputerChoice);

        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

//function definitions

void DisplayIntro()
{
    cout << "welcome to Rock Paper Scissors" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
}

int GetUserChoice() 
{
    int choice;
    while (true) 
    {
        cout << "Enter your choice (1-3): ";
        if (!(cin >> choice)) 
        {
            cout << "Invalid input. Please enter a number." << std::endl;
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Discard invalid input
        }
        else if (choice >= 1 && choice <= 3) 
        {
            break;
        }
        else 
        {
            cout << "Invalid choice. Please choose 1, 2, or 3." << std::endl;
        }
    }
    return choice;
}

int GenerateComputerChoice()
{
    return (rand() % 3) + 1;
}


 std::string choice_to_string(int choice) {
    if (choice == ROCK) return "Rock";
    if (choice == PAPER) return "Paper";
    if (choice == SCISSORS) return "Scissors";
    return "Unknown";
}

 void DetermineWinner(int user, int computer)
 {
     if (user == computer)
     {
         cout << "it's a tie" << endl;
     }
     else if ((user == ROCK && computer == SCISSORS) ||
              (user == PAPER && computer == ROCK) ||
              (user == SCISSORS && computer == PAPER))
     {
         cout << "You win!" << endl;
     }
     else
     {
         cout << "Computer wins!" << endl;
     }
 }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
