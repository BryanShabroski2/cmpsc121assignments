// Template for use in the assignment
// Created by georg on 11/15/2021.
//
//Bryan Shabroski
//Assignment 19
//Cmpsc 121 section 1
//Due date: November 15 2022
// Purpose of this cpp is to create the fucntions needed to make the main.cpp for OOP bingo program work correctly.
#include "BingoCard.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;
// =============================================================
// *** Create the functions definitions here ***
// =============================================================
    //BingoCard constructor function
    bool hasHorizontalBingo();
    bool hasVerticalBingo();
    bool hasDiagonalBingo();
    void updateCard(int numberCalled);
    bool hasBingo();  // Returns true if any of the 3 private "has____Bingo" functions returns true
    void clearCard();  // Resets the marks[][] array to all false.
// There are several utility function provided at the bottom of this file.
// printCard - Prints out the full card to terminal or into log file
// *** CONSTRUCTOR ***
// Constructor should create a new Bingo Card assigned to a player.
// Creates a new Bingo Card, with a set of random numbers
// Store the numbers in private array cardNumbers[][]
// You can assume the random seed was already called.
// B (1-15), I (16-30), N (31-45), G (46-60), O (61-75)
// You can use your code from the previous assignment, but...
// This time, make sure that there are no duplicate numbers on the card!
// Comment: FreeSpace- For the middle cell, cardNumbers[2][2], you can put a number,
//    but it must not affect the hasBingo results when you create those functions.
// *** Call the clearCard function to reset all card marks to false.
//Constructor sets middle to true automatically, and creates the number card and makes sure there is no duplicate.
    BingoCard::BingoCard() {
    marks[2][2] = true;
    for (int rowIndex = 0; rowIndex < ROWS; rowIndex++){
        for (int colIndex = 0; colIndex < COLS ; colIndex++){
            int randomNum = rand() % 15 + 1 + (rowIndex * 15);
            if(numberTaken(randomNum)){
                colIndex--;
            }
            else{
                cardNumbers[colIndex][rowIndex] = randomNum;
            }
        }
    }
    clearCard();
}

// *** updateCard ***
// ----------------------------------------------
// Update the card marks array when a number is called.
//Puts a mark on the number if it is called by bingo
    void BingoCard::updateCard(int numberCalled) {
        for(int rowUpdater = 0; rowUpdater < ROWS; rowUpdater++){
            for(int colUpdater = 0; colUpdater < COLS; colUpdater++){
                if(numberCalled == cardNumbers[rowUpdater][colUpdater]){
                    marks[rowUpdater][colUpdater] = true;
                }
            }
        }
    }
// *** clearCard
// ----------------------------------------------
// clear card
//Clear card goes through the mark array and sets everything equal to false.
    void BingoCard::clearCard() {

        for (int rowClear = 0; rowClear < ROWS; rowClear++) {
            for (int colClear = 0; colClear < COLS; colClear++) {
                marks[colClear][rowClear] = false;
            }
        }
}
// This resets all card marks to 'false'
// *** Checking for Bingo
// *** hasBingo ***
//Has bingo checks the three bingo conditions if any of them are true returns true.
    bool BingoCard::hasBingo() {
        bool win = false;
        if(BingoCard::hasDiagonalBingo() || BingoCard::hasHorizontalBingo() || BingoCard::hasVerticalBingo()){
            win = true;
        }
        return win;
    }
// Check the card to see if it has a Bingo.
// There are 3 types of Bingo:
// * Horizontal Bingo (marks across a whole row)
// * Vertical Bingo (marks down a whole column)
// * Diagonal Bingo (top left to bottom right OR bottom left to top right)
// Remember, that the center 'FREE' spot counts for Bingo in all cases.
// Be sure to return 'true' or 'false'
// *** hasHorizontalBingo
// If any horizontal rows have 5 trues in a row will return true.
    bool BingoCard::hasHorizontalBingo() {
        bool win = false;
        for(int rowFinder = 0; rowFinder < ROWS; rowFinder++){
            if (marks[rowFinder][0] && marks[rowFinder][1] && marks[rowFinder][2] && marks[rowFinder][3] && marks[rowFinder][4])
            {
                win = true;
            }
        }
        return win;
    }
// *** hasVerticalBingo
// If any vertival collumns have 5 trues in a row will return true.
    bool BingoCard::hasVerticalBingo() {
    bool win = false;
    for(int colFinder = 0; colFinder < COLS; colFinder++){
        if (marks[0][colFinder] && marks[1][colFinder] && marks[2][colFinder] && marks[3][colFinder] && marks[4][colFinder])
        {
            win = true;
        }
    }
    return win;
}

// *** hasDiagonalBingo
// Checks the diagonal condition for 5 trues in a row.
    bool BingoCard::hasDiagonalBingo() {
    bool win = false;
    if(marks[0][0] && marks[1][1] && marks[2][2] && marks[3][3] && marks[4][4] ||  marks[4][0] && marks[3][1] && marks[2][2] && marks[1][3]  && marks[0][4] ){
    win = true;
    }
    return win;
    }

// If a number is already present when constructing the card it will return true, if its not present returns false.
    bool BingoCard::numberTaken(int number) {
        bool taken = false;
        for(int rowNum = 0; rowNum < ROWS; rowNum++){
            for(int colNum = 0; colNum < 5; colNum++) {
                if (cardNumbers[rowNum][colNum] == number) {
                    taken = true;
                }
            }

       }
      return taken;
    }
// ============================================================================
// *** Do not modify below this line ***
// ============================================================================
void BingoCard::printCard(){  // *** DO NOT MODIFY ***
    const char TABCHAR = 9;
    cout << "---------------------------------------" << endl;
    // Print the header
    cout << "B" << TABCHAR << "I" << TABCHAR << "N" << TABCHAR << "G" << TABCHAR <<
         "O" << endl;
    // Print each row
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS ; c++){  // for each row, print each column
            if (r==2 && c ==2) cout << "FREE" << TABCHAR ;
            else {
                if (marks[r][c]) cout << "*"; // Add a * if number was called
                cout << cardNumbers[r][c];   // the number
                cout << TABCHAR;
            }
        }
        cout << endl; // end of the row
    }
    cout << "---------------------------------------" << endl;
}
// *** DO NOT MODIFY ***
void BingoCard::printCard(ofstream &logFile){ //Overload function for saving to log file.
    const char TABCHAR = 9;
    logFile << "---------------------------------------" << endl;
    // Print the header
    logFile << "B" << TABCHAR << "I" << TABCHAR << "N" << TABCHAR << "G" << TABCHAR
            << "O" << endl;
    // Print each row
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS ; c++){  // for each row, print each column
            if (r==2 && c ==2) logFile << "FREE" << TABCHAR ;
            else {
                if (marks[r][c]) logFile << "*"; // Add a * if number was called
                logFile << cardNumbers[r][c];   // the number
                logFile << TABCHAR;
            }
        }
        logFile << endl; // end of the row
    }
    logFile << "---------------------------------------" << endl;
}