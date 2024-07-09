#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
 
/*
* @class CardGuessingGame
* Represents a card guessing game where the user can guess the face value, suit, or both of a card.
*/
class CardGuessingGame {
private:
    std::vector<std::string> deck; // Container to store the deck of cards
 
public:
    /*
    * Constructs a CardGuessingGame object and initializes the deck of cards.
    */
    CardGuessingGame() {
        // Initialize the deck of cards
        deck = {
            "Ace of Spades", "2 of Spades", "3 of Spades", "4 of Spades", "5 of Spades", "6 of Spades",
            "7 of Spades", "8 of Spades", "9 of Spades", "10 of Spades", "Jack of Spades", "Queen of Spades", "King of Spades",
            "Ace of Hearts", "2 of Hearts", "3 of Hearts", "4 of Hearts", "5 of Hearts", "6 of Hearts",
            "7 of Hearts", "8 of Hearts", "9 of Hearts", "10 of Hearts", "Jack of Hearts", "Queen of Hearts", "King of Hearts",
            "Ace of Diamonds", "2 of Diamonds", "3 of Diamonds", "4 of Diamonds", "5 of Diamonds", "6 of Diamonds",
            "7 of Diamonds", "8 of Diamonds", "9 of Diamonds", "10 of Diamonds", "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds",
            "Ace of Clubs", "2 of Clubs", "3 of Clubs", "4 of Clubs", "5 of Clubs", "6 of Clubs",
            "7 of Clubs", "8 of Clubs", "9 of Clubs", "10 of Clubs", "Jack of Clubs", "Queen of Clubs", "King of Clubs"
        };
    }
 
/*
* Shuffles the deck of cards using the random_shuffle() function from the <algorithm> library.
*/
void ShuffleDeck() {
        std::random_shuffle(deck.begin(), deck.end());
    }
 
/*
* Prompts the user to guess the face value of a card from the deck.
* Compares the user's guess with the actual face value of the card and displays the result.
*
* @param deck The deck of cards.
*/
void GuessFace(const std::vector<std::string>& deck) {
        std::cout << "Enter the face: ";
        std::string userGuess;
        std::cin >> userGuess;
 
        // Check if the user's guess matches the actual face value of the card
        if (userGuess == deck[0].substr(deck[0].find(" ") + 1)) {
            std::cout << "Congratulations! You guessed the face value correctly.\n";
        }
        else {
            std::cout << "Sorry, you lost. The face value is: " << deck[0].substr(deck[0].find(" ") + 1) << "\n";
        }
    }
 
/*
* Prompts the user to guess the suit of a card from the deck.
* Compares the user's guess with the actual suit of the card and displays the result.
*
* @param deck The deck of cards.
*/
void GuessSuit(const std::vector<std::string>& deck) {
        std::cout << "Enter the suit: ";
        std::string userGuess;
        std::cin >> userGuess;
 
        // Check if the user's guess matches the actual suit of the card
        if (userGuess == deck[0].substr(deck[0].find("of ") + 3)) {
            std::cout << "Congratulations! You guessed the suit correctly.\n";
        }
        else {
            std::cout << "Sorry, you lost. The suit is: " << deck[0].substr(deck[0].find("of ") + 3) << "\n";
        }
    }
 
/*
* Prompts the user to guess both the face value and the suit of a card from the deck.
* Compares the user's guess with the actual face value and suit of the card and displays the result.
*
* @param deck The deck of cards.
*/
void GuessBoth(const std::vector<std::string>& deck) {
        std::cout << "Enter the face: ";
        std::string userFaceGuess;
        std::cin >> userFaceGuess;
 
        std::cout << "Enter the suit: ";
        std::string userSuitGuess;
        std::cin >> userSuitGuess;
 
        // Check if the user's guess matches the actual face value and suit of the card
        if (userFaceGuess == deck[0].substr(deck[0].find(" ") + 1) && userSuitGuess == deck[0].substr(deck[0].find("of ") + 3)) {
            std::cout << "Congratulations! You guessed both the face value and the suit correctly.\n";
        }
        else {
            std::cout << "Sorry, you lost. The card is: " << deck[0] << "\n";
        }
    }
/*
* Runs the card guessing game.
*/
void RunGame() {
        int choice;
        do {
            std::cout << "Want to play?\n";
            std::cout << "1. Guess the face of the card\n";
            std::cout << "2. Guess the suit of the card\n";
            std::cout << "3. Guess both the face and suit\n";
            std::cout << "4. Played enough\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                ShuffleDeck();
                GuessFace(deck);
                break;
            case 2:
                ShuffleDeck();
                GuessSuit(deck);
                break;
            case 3:
                ShuffleDeck();
                GuessBoth(deck);
                break;
            case 4:
                std::cout << "Thank you for playing!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        } while (choice != 4);
    }
};
