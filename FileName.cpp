#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
int main() {
	string name;
	int level;
	char playAgain;
	int totalGames = 0, totalWins = 0;
	srand(time(0));
	cout << "Welcome to number guessing game!\n";
	cout << "Enter your name:";
	getline(cin, name);

	do {
		cout << "\nHi" << name << "Choose difficulty level:\n";
		cout << "1. Easy(1-20, 6 tries)\n";
		cout << "2. Medium(1-60, 5 tries)\n";
		cout << "3. Hard(1-100, 3 tries)\n";
		cout << "Enter your choice(1-3):";
		cin >> level;

		int maxNumber, maxAttempts;
		if (level == 1) {
			maxNumber = 20;
			maxAttempts = 6;
		}
		else if (level == 2) {
			maxNumber = 60;
			maxAttempts = 5;
		}
		else {
			maxNumber = 100;
			maxAttempts = 3;
		}

		int secretNumber = rand() % maxNumber + 1;

		int guess, attempts = 0;
		bool guessedCorrectly = false;

		cout << "\n I have selected a number between 1 and " << maxNumber << "Can you guess it?\n";

		while (attempts < maxAttempts) {
			cout << "Attempt" << (attempts + 1) << ":";
			cin >> guess;
			attempts++;

			if (guess == secretNumber) {
				guessedCorrectly = true;
				break;
			}
			else if (guess < secretNumber) {
				cout << "Too low!\n";
			}
			else {
				cout << "Too high!\n";
			}
		}
		totalGames++;
		if (guessedCorrectly) {
			totalWins++;
			cout << "\n Congratulations " << name << "! You guessed the number in" << attempts << "attempts. \n";
		}
		else {
			cout << "\n Game over ! The number was: " << secretNumber << " .Better luck next time," << name << "\n";
		}
		cout << " Scoreboard: \n";
		cout << "Games played:" << totalGames << "\n";
		cout << "Games won:" << totalWins << "\n";
		cout << "Games lost:" << (totalGames - totalWins) << "\n";

		cout << "\n Do you want to play again?(Y/N):";
		cin >> playAgain;
		cin.ignore();
	} while (playAgain == 'Y' || playAgain == 'y');
	cout << "\n Thankyou for playing," << name << "! Goodbye ! \n";
	return 0;
}
