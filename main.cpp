#include <iostream>
#include <fstream>
#include<ostream>

using namespace std;

    float* inputTimes(int);
    void sortTimes(float*, int);
    void minMaxAverage(const float*, int);
    ofstream logTimes;
    ifstream runTimes;


//The main function opens the data files and displays the data to the out file. Goes through a loop for the amount
//of races there is.
int main() {
    int numRunners;
    runTimes.open("raceTimes.txt");
    logTimes.open("logTimes.txt");
    for(int numRace = 0; runTimes >> numRunners; numRace++) {
        float* pointerRunTimes = inputTimes(numRunners);
        logTimes << "== Race #" << numRace + 1 << " ==\n";
        logTimes << "Race Times: ";
        for(int timeListCounter = 0; timeListCounter < numRunners; timeListCounter++){
        logTimes  << *(pointerRunTimes + timeListCounter) << " ";}
        logTimes << endl;
        logTimes << "Sorted Race Times: ";
        sortTimes(pointerRunTimes, numRunners);
        logTimes << endl;
        minMaxAverage(pointerRunTimes, numRunners);
    }
    runTimes.close();
    logTimes.close();

}

//Input times creates a new array and points to the values in the array from the in file.
float* inputTimes(int numOfRunners){

    float* pointerTimes = new float[numOfRunners];

    for(int timeCounter = 0; timeCounter < numOfRunners; timeCounter++) {
        runTimes >> *(pointerTimes + timeCounter);
    }
    return pointerTimes;
}

//sortTimes uses insertion sort to sort the times in the race. It also puts the sorted times into the out file.
void sortTimes(float* timesForSort, int numOfRunners){
    int insertionSearcher;
    float valueHolder;
    int previousValue;
    for(insertionSearcher = 1; insertionSearcher < numOfRunners; insertionSearcher++){
        valueHolder = *(timesForSort + insertionSearcher);
        previousValue = insertionSearcher - 1;

        while (previousValue >= 0 && *(timesForSort + previousValue) > valueHolder)
        {
            swap(*(timesForSort + previousValue + 1), *(timesForSort + previousValue));
            previousValue = previousValue - 1;
        }
        *(timesForSort + previousValue + 1) = valueHolder;
    }
    for(int timeSorterIndex = 0; timeSorterIndex < numOfRunners; timeSorterIndex++){
        logTimes << *(timesForSort + timeSorterIndex) << " ";
    }
}

//minMaxAverage will get the min value from the sorted array and the max value. Will also get the average time.
//Stores this information to the log file.
void minMaxAverage(const float* runTimesMMA, int numOfRunners){
    float averageNum = 0;
    float min = *(runTimesMMA);
    float max = *(runTimesMMA + (numOfRunners - 1));
    for(int index = 0; index < numOfRunners; index++){
        averageNum += *(runTimesMMA + index);
    }
    averageNum = averageNum / static_cast<float>(numOfRunners);
    logTimes << "Minimum Time: " << min << endl;
    logTimes << "Maximum Time: " << max << endl;
    logTimes << "Average Time: " << averageNum << endl;
}
