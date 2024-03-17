using System;

class Program {
    static void Main() {
        Console.WriteLine("\n\t\t========WELCOME TO CASINO WORLD=======\n\n");
        Console.WriteLine("What's your Name : ");
        string playerName = Console.ReadLine();
        Console.WriteLine("\n\nEnter the starting balance to play game : $");
        int balance = int.Parse(Console.ReadLine());
        
        // Main game loop
        while (true) {
            Console.WriteLine("\n\t\t========WELCOME TO CASINO WORLD=======\n\n");
            displayRules();
            Console.WriteLine("\n\nYour current balance is $ " + balance + "\n");

            // Get the betting amount from the player
            int bettingAmount = 0;
            while (bettingAmount <= 0 || bettingAmount > balance) {
                Console.Write("Hey, " + playerName + ", enter amount to bet : $");
                bettingAmount = int.Parse(Console.ReadLine());
                if (bettingAmount > balance)
                    Console.WriteLine("Betting balance can't be more than current balance!\nRe-enter balance\n ");
            }

            // Get the player's guess
            int guess = 0;
            while (guess <= 0 || guess > 10) {
                Console.Write("Guess any betting number between 1 & 10 :");
                guess = int.Parse(Console.ReadLine());
                if (guess <= 0 || guess > 10)
                    Console.WriteLine("\nNumber should be between 1 to 10\nRe-enter number:\n ");
            }

            // Generate a random number
            Random random = new Random();
            int dice = random.Next(1, 11);

            // Check if the guess matches the random number
            if (dice == guess) {
                Console.WriteLine("\n\nYou are in luck!! You have won $" + (bettingAmount * 10));
                balance += bettingAmount * 10;
            } else {
                Console.WriteLine("Oops, better luck next time !! You lost $ " + bettingAmount + "\n");
                balance -= bettingAmount;
            }

            // Display the winning number and current balance
            Console.WriteLine("\nThe winning number was : " + dice);
            Console.WriteLine("\n" + playerName + ", You have balance of $ " + balance + "\n");

            // Check if the player has run out of money
            if (balance == 0) {
                Console.WriteLine("You have no money to play ");
                break;
            }

            // Ask the player if they want to play again
            Console.Write("\n\n-->Do you want to play again (y/n)? ");
            char choice = Console.ReadLine().ToLower()[0];
            if (choice != 'y')
                break;
        }

        Console.WriteLine("\n\nThanks for playing the game. Your balance is $ " + balance + "\n\n");
    }

    // Function to display the rules of the game
    static void displayRules() {
        Console.WriteLine("\t\t======CASINO NUMBER GUESSING RULES!======\n");
        Console.WriteLine("\t1. Choose a number between 1 to 10");
        Console.WriteLine("\t2. Winner gets 10 times of the money bet");
        Console.WriteLine("\t3. Wrong bet, and you lose the amount you bet\n");
    }
}
