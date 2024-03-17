import random  # Import the random module to generate random numbers

def rules():
    """
    Display the rules of the casino number guessing game.
    """
    print("\t\t======CASINO NUMBER GUESSING RULES!======")  # Print the title for the rules
    print("\t1. Choose a number between 1 to 10")  # Print the first rule
    print("\t2. Winner gets 10 times of the money bet")  # Print the second rule
    print("\t3. Wrong bet, and you lose the amount you bet\n")  # Print the third rule

def main():
    playerName = input("\n\nWhat's your Name : ")  # Prompt the user to enter their name
    balance = int(input("\n\nEnter the starting balance to play game : $"))  # Prompt the user to enter their initial balance
    
    while True:  # Start an infinite loop for the game
        print("\n\t\t========WELCOME TO CASINO WORLD=======\n\n")  # Print the welcome message
        rules()  # Call the function to display the game rules
        print("\n\nYour current balance is $", balance)  # Display the current balance
        
        bettingAmount = 0  # Initialize the betting amount variable
        while bettingAmount <= 0 or bettingAmount > balance:  # Start a loop to ensure valid betting amount
            bettingAmount = int(input("Hey, " + playerName + ", enter amount to bet : $"))  # Prompt the user to enter the betting amount
            if bettingAmount > balance:  # Check if the betting amount is greater than the balance
                print("Betting balance can't be more than current balance!\nRe-enter balance")  # Print error message if the betting amount is invalid
        
        guess = 0  # Initialize the guess variable
        while guess <= 0 or guess > 10:  # Start a loop to ensure valid guess
            guess = int(input("Guess any betting number between 1 & 10 :"))  # Prompt the user to enter the guess
            if guess <= 0 or guess > 10:  # Check if the guess is out of range
                print("\nNumber should be between 1 to 10\nRe-enter number")  # Print error message if the guess is invalid
        
        dice = random.randint(1, 10)  # Generate a random number between 1 and 10
        
        if dice == guess:  # Check if the guess matches the random number
            print("\n\nYou are in luck!! You have won $", bettingAmount * 10)  # Print message for winning
            balance += bettingAmount * 10  # Update the balance after winning
        else:
            print("Oops, better luck next time !! You lost $", bettingAmount)  # Print message for losing
            balance -= bettingAmount  # Update the balance after losing
        
        print("\nThe winning number was :", dice)  # Print the winning number
        print("\n", playerName + ", You have balance of $", balance)  # Print the current balance after each round
        
        if balance == 0:  # Check if the balance is zero
            print("You have no money to play ")  # Print message if the balance is zero
            break  # Exit the loop if the balance is zero
        
        choice = input("\n\n-->Do you want to play again (y/n)? ")  # Prompt the user to play again
        if choice.lower() != 'y':  # Check if the user wants to continue playing
            break  # Exit the loop if the user doesn't want to continue playing
    
    print("\n\nThanks for playing the game. Your balance is $", balance, "\n\n")  # Print final message after ending the game

if __name__ == "__main__":
    main()  # Call the main function if the script is executed directly
