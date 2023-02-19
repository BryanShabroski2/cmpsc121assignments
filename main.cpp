// =====================================================
// Bingo Card Driver Program
// =====================================================
//  G. Buckbee
//  November 2021
// =====================================================
// Used with Assignment XC - Bingo Cards
// =====================================================
// Use of classes
// This driver program creates Bingo Card objects from the
// BingoCard class, tests each function, and creates a log
// file to track the output.
// *******************************************************
// DO NOT MODIFY THIS DRIVER PROGRAM
// *******************************************************
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;
#include "BingoCard.h"
int main() {
    // Initialize
    srand(time(0));
    int NUM_PLAYERS = 6;
    int NUM_GAMES = 5, gamesPlayed = 0;
    string player[NUM_PLAYERS] = {"Alfred", "Betty", "Charlie", "David", "Elaine", "Francis"};
    bool wasCalled [76] = {false};  // Array to keep track of numbers called. Ignore index 0.
    BingoCard playerCard[NUM_PLAYERS];  // Array to keep track of all player cards
    int callsThisGame;
    int newNum; // variable for each new number called.
    bool foundBingo = false;
    ofstream logFile;
    logFile.open("BingoLogFile.txt");  // Place to store results
    logFile << "Creating Bingo Cards." << endl;
    if (logFile) cout << "Log File Open" << endl;
    // Create Bingo Cards for each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        logFile << "Creating Card for " << player[i] << "." << endl;
        playerCard[i] = BingoCard(); // create a BingoCard for each player
    }
    // Play some games - the main loop of this program
    while (gamesPlayed < NUM_GAMES){
        gamesPlayed++;
        logFile << "=================" << endl;
        logFile << " Game " << gamesPlayed << endl;
        logFile << "=================" << endl;
        cout << "*** Game " << gamesPlayed << endl;
        // Initialize each game
        // -----------------------
        logFile << "Resetting called numbers" << endl;
        for (int i = 0; i < 76; i++) wasCalled[i] = false;
        callsThisGame = 0;
        foundBingo = false;
        // Reset player cards
        for (int p = 0; p < NUM_PLAYERS; p++) {
            playerCard[p].clearCard();
        }
        // Start playing the game
        // ----------------------
        logFile << "Calling Numbers" << endl;
        //
        do {
            do {
                newNum = (rand() % 75 +1);
            } while ( wasCalled[newNum] );
            wasCalled[newNum] = true;
            callsThisGame++;
            cout << newNum << " ";
            // Test for Bingo, and print results to screen and log file
            for (int p = 0; p < NUM_PLAYERS; p++){
                playerCard[p].updateCard(newNum);
                if (playerCard[p].hasBingo()) {
                    foundBingo = true;
                    cout << endl;
                    cout << "BINGO Player "<< player[p] << ", ";
                    cout << callsThisGame << " numbers called." << endl;
                    playerCard[p].printCard();
                    logFile << endl;
                    logFile << "BINGO Player " << player[p] << ", " ;
                    logFile << callsThisGame << " numbers called." << endl;
                    playerCard[p].printCard(logFile);
            }
        }
        } while (!foundBingo);  // continue this game
    } // start next game
    logFile.close();
    return 0;
}
// *******************************************************
// DO NOT MODIFY THIS DRIVER PROGRAM
// *******************************************************