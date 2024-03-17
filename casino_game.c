#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the rules of the game
void displayRules() {
    printf("\t\t======CASINO NUMBER GUESSING RULES!======\n");
    printf("\t1. Choose a number between 1 to 10\n");
    printf("\t2. Winner gets 10 times of the money bet\n");
    printf("\t3. Wrong bet, and you lose the amount you bet\n\n");
}

int main() {
    char playerName[50];
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    
    // Seed the random number generator
    srand(time(0));
    
    printf("\n\t\t========WELCOME TO CASINO WORLD=======\n\n");
    printf("\n\nWhat's your Name : ");
    fgets(playerName, 50, stdin);
    printf("\n\nEnter the starting balance to play game : $");
    scanf("%d", &balance);

    // Main game loop
    while (1) {
        printf("\n\t\t========WELCOME TO CASINO WORLD=======\n\n");
        displayRules();
        printf("\n\nYour current balance is $ %d\n", balance);

        // Get the betting amount from the player
        do {
            printf("Hey, %s, enter amount to bet : $", playerName);
            scanf("%d", &bettingAmount);
            if (bettingAmount > balance)
                printf("Betting balance can't be more than current balance!\nRe-enter balance\n ");
        } while (bettingAmount > balance);

        // Get the player's guess
        do {
            printf("Guess any betting number between 1 & 10 :");
            scanf("%d", &guess);
            if (guess <= 0 || guess > 10)
                printf("\nNumber should be between 1 to 10\nRe-enter number:\n ");
        } while (guess <= 0 || guess > 10);

        // Generate a random number
        dice = rand() % 10 + 1;

        // Check if the guess matches the random number
        if (dice == guess) {
            printf("\n\nYou are in luck!! You have won $%d", bettingAmount * 10);
            balance += bettingAmount * 10;
        } else {
            printf("Oops, better luck next time !! You lost $ %d\n", bettingAmount);
            balance -= bettingAmount;
        }
        
        // Display the winning number and current balance
        printf("\nThe winning number was : %d\n", dice);
        printf("\n%s, You have balance of $ %d\n", playerName, balance);

        // Check if the player has run out of money
        if (balance == 0) {
            printf("You have no money to play ");
            break;
        }

        // Ask the player if they want to play again
        printf("\n\n-->Do you want to play again (y/n)? ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
    }

    printf("\n\nThanks for playing the game. Your balance is $ %d\n\n", balance);
    return 0;
}
