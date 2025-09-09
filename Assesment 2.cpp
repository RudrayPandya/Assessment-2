#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

// Function to convert choice number into string
string choiceToString(int choice) {
    if (choice == 1) return "Rock";
    else if (choice == 2) return "Paper";
    else if (choice == 3) return "Scissors";
    else return "Invalid";
}

int main() {
    string name;
    int rounds, playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter number of rounds to play: ";
    cin >> rounds;

    // Seed random number generator
    srand(time(0));

    for (int round = 1; round <= rounds; round++) {
        cout << "\n--- Round " << round << " ---\n";
        cout << "1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;

        // Computer generates random choice
        computerChoice = (rand() % 3) + 1;

        cout << name << " chose: " << choiceToString(playerChoice) << endl;
        cout << "Computer chose: " << choiceToString(computerChoice) << endl;

        // Decide winner
        if (playerChoice == computerChoice) {
            cout << "It's a Tie!\n";
        } 
        else if ((playerChoice == 1 && computerChoice == 3) ||
                 (playerChoice == 2 && computerChoice == 1) ||
                 (playerChoice == 3 && computerChoice == 2)) {
            cout << name << " wins this round!\n";
            playerScore++;
        } 
        else {
            cout << "Computer wins this round!\n";
            computerScore++;
        }
    }

    // Final result
    cout << "\n=== Final Result ===\n";
    cout << name << "'s Score: " << playerScore << endl;
    cout << "Computer's Score: " << computerScore << endl;

    if (playerScore > computerScore)
        cout << "🎉 Congratulations " << name << "! You won the game.\n";
    else if (playerScore < computerScore)
        cout << "Computer wins the game! Better luck next time.\n";
    else
        cout << "The game is a Tie!\n";

    return 0;
}
