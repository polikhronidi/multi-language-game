#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to display the rules of the game
void displayRules() {
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

int main() {
    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    
    // Seed the random number generator
    srand(time(0));
    
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;

    // Main game loop
    while (true) {
        cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
        displayRules();
        cout << "\n\nYour current balance is $ " << balance << "\n";

        // Get the betting amount from the player
        do {
            cout << "Hey, " << playerName << ", enter amount to bet : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\nRe-enter balance\n ";
        } while (bettingAmount > balance);

        // Get the player's guess
        do {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\nRe-enter number:\n ";
        } while (guess <= 0 || guess > 10);

        // Generate a random number
        dice = rand() % 10 + 1;

        // Check if the guess matches the random number
        if (dice == guess) {
            cout << "\n\nYou are in luck!! You have won $" << bettingAmount * 10;
            balance += bettingAmount * 10;
        } else {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << "\n";
            balance -= bettingAmount;
        }
        
        // Display the winning number and current balance
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n" << playerName << ", You have balance of $ " << balance << "\n";

        // Check if the player has run out of money
        if (balance == 0) {
            cout << "You have no money to play ";
            break;
        }

        // Ask the player if they want to play again
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y')
            break;
    }

    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
