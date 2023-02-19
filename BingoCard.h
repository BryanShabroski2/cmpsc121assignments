//
// Created by georg on 11/15/2021.
// *** DO NOT MODIFY THIS FILE ***
#ifndef ASSIGNMENT019_BINGOCARD_OBJECT_BINGOCARD_H
#define ASSIGNMENT019_BINGOCARD_OBJECT_BINGOCARD_H
#include <string>
using namespace std;
// =================================================
// Prototype
// =================================================
class BingoCard{
private:
    const static int COLS = 5, ROWS = 5;
    int cardNumbers[ROWS][COLS];       // The numbers appearing on each card
    bool marks[ROWS][COLS] = {false};  // Array to hold marks when the number was called
    bool hasHorizontalBingo();
    bool hasVerticalBingo();
    bool hasDiagonalBingo();
public:
    // Constructor should create a new Bingo Card with a set of random numbers on it.
    BingoCard();
    // Update the card marks when a number is called.
    // Put a 'true' into the right spot in the marks array
    void updateCard(int numberCalled);
    // check if the card has a Bingo
    bool hasBingo();  // Returns true if any of the 3 private "has____Bingo" functions returns true.
    // clear card
    void clearCard();  // Resets the marks[][] array to all false.
    // Checks to see if a number has already been assigned to this card
    bool numberTaken(int);
    // Print the card to a given file
    // These functions are provided for you, and do not need to be changed
    void printCard(); // Prints to screen for troubleshooting
    void printCard(ofstream&); // prints to log file for final answers
};
#endif //ASSIGNMENT019_BINGOCARD_OBJECT_BINGOCARD_H