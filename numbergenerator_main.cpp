#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int secretNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;
    std::cout << "Welcome to the Number Guessing Game By Ayush!\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        }
        attempts++;
    } while (userGuess != secretNumber);
    std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
    return 0;
}
