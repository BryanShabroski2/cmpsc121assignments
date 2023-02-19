// =====================================================
//  Assignment 017 Template
//  Entering Student test scores
// =====================================================
//  G. Buckbee
//  November 2021
// =====================================================
//  Write a program to dynamically allocate an array big enough
//  to hold a user-defined number of test scores.
//  Enter and validate the test scores.
//  Once the array is created, sort in ascending order.
//  Create another function to average the student score.
//  Display the sorted list, and the average score.
// =====================================================
// Use of pointers
//  Preprocessor directives
//  -----------------------
#include <iostream>
#include <string>
using namespace std;
// Global Variable
int amountOfGrades;
// Function prototypes
//  -----------------------
float* studentScores(int);
float averageScore(float *[], int);
// ======================================================
// main()
// ======================================================
int main() {

    // Ask how many scores for this student
    do{
    cout << "How many scores for this student?\n";
    cin >> amountOfGrades;
        // Validate for > 0.
    if(amountOfGrades <= 0){
        cout << "ERROR: Please enter a value greater than 0!\n\n";
    }
    }while(amountOfGrades <= 0);
    // Create the array dynamically, using studentScores()
    float arrGrades[amountOfGrades];
    studentScores(amountOfGrades);

    // Send the array to averageScore() using a pointer



    // Use a function to sort the array
    // Program output scores sorted low to high, and then average:
    // Scores: 65.3, 75.2, 89.6, 98.8, 99.0
    // Average of 5 scores =  85.6
    // Use your own set of numbers
    return 0;
}
// ======================================================
// Functions
// ======================================================
float* studentScores(int numScores){
    // *** You must write this function
    // Inputs: Number of scores
    // Does: Asks user to enter as many scores as in numScores
    //Validates - Only allows scores between 0 and 100.
    // Returns: Pointer to an array of the scores
    // Create the array, big enough for our needs
    float *ptrScores;
    float scoreArr[numScores];
    // Prompt user for scores
    //No need to validate because the for loop will stop accepting scores after the correct number of scores.
    cout << "Please enter your " << numScores << " score(s)\n";
    for(int arrayIndexScores = 0; arrayIndexScores < numScores; arrayIndexScores++) {
        cin >> scoreArr[arrayIndexScores];
        cout << endl;
        ptrScores = scoreArr;
    }
    // i.e. "Please enter score 1:"
    // Once the array is full, return a pointer to the array
    return ptrScores;

}
// *** You must write this function.
float averageScore(float *grades[], int numScores) {
    int averageGrade;
    float totalNumScore;
    for (int arrayIndexAverage = 0; arrayIndexAverage < numScores; arrayIndexAverage++) {
        totalNumScore = totalNumScore + *grades[arrayIndexAverage];
    }
    averageGrade = totalNumScore / numScores;

    return averageGrade;
}
// *** You will need to add a function to sort the scores low to high
void scoreSort(){

}

//Valid Answer Method I made that is used when the character is asked to give a specific answer. Could be used for Y/N for example.
bool validScore(float userInput, float answer1, float answer2){
    bool valid = true;
    if(userInput <= answer1 && userInput >= answer2){
        valid = false;
    }
    return valid;
}