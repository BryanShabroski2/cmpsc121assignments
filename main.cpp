#include <iostream>
#include<string>
#include<fstream>
#include<limits>

using namespace std;

    // Weapon structure that will be used in the character structure
    struct Weapon{
    string weaponType;
    int damageAmount = 0;
    float weightAmount = 0;


};
    // Character structure that will be used to generate characters.
    struct GameCharacter{
    string characterName;
    int age;
    float height = 0;
    float  strength = 0;
    float intelligence = 0;
    string faction;
    Weapon primary;
    Weapon secondary;


};

GameCharacter makeCharacter(Weapon[]);
Weapon makeWeapon();
Weapon selectWeapon(Weapon[]);
void writeWeapons(GameCharacter weapons[], int);
void writeCharacter(GameCharacter characters[], int);
bool validationCheck(int userAnswer, int lowNum, int highNum);
void incorrectInput();

ofstream characterLog;

// The main function uses the other functions to create 5 weapons, and 3 characters then prints 3 to the log file.
int main() {
    Weapon weaponArray[5];
    GameCharacter characterArray[3];

    cout << "Please create 5 weapons.\n";
    for(int weaponCounter = 0; weaponCounter < 5; weaponCounter++){
        weaponArray[weaponCounter] = makeWeapon();
    }
    cout << "Please create 3 characters.\n";
    for(int characterCounter = 0; characterCounter < 3; characterCounter++){
        characterArray[characterCounter] = makeCharacter(weaponArray);
    }

    characterLog.open("CharacterLog.txt");
    characterLog << "=======================================================\n";
    for(int createCharacters = 0; createCharacters < 3; createCharacters++){
        writeCharacter(characterArray, createCharacters);}
    characterLog.close();

}


// Used to validate ints and floats.
bool validationCheck(int userAnswer, int lowNum, int highNum){
    if(userAnswer < lowNum || userAnswer > highNum){
        return false;
    }
    else{ return true;}


}
//makeCharacter will ask the user a series of questions allowing them to create their own character. I will only validate the things that need to be
//validated such as the strength, intelligence, and weapon. I will give the user freedom to make any name, age, and faction they want. Takes in character,
//and weapon array. Returns GameCharacter.
GameCharacter makeCharacter(Weapon weapons[]) {
    GameCharacter character;
    Weapon primary;
    Weapon secondary;
    character.intelligence = 0;
    character.strength = 0;
    float strengthInput;
    cout << "What is your characters name?\n";
    //This cin.ignore will ignore the keyboard buffer that is being inputted after the cout statement.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, character.characterName);
    do {
        cout << "What is your characters age? (Must be between 1-100)\n";
        cin >> character.age;
        if(!validationCheck(character.age,1 , 100)){
            cout << "ERROR: Please enter a value between 1-100!";
            incorrectInput();
        }
    }while(!validationCheck(character.age, 1, 100));
    do {
        cout << "What is your characters height? (In feet (1-10))\n";
        cin >> character.height;
        if(!validationCheck(character.height, 1, 10)){
            cout << "ERROR: Please enter a value between 1-10!\n";
            incorrectInput();
        }
    }while(!validationCheck(character.height, 1, 10));
    cout << "Next you will choose strength and intelligence you have 10 points in total, what you don't spend on strength will be used on intelligence.\n";
    do{
    cout << "What is your characters strength?\n";
    cin >> strengthInput;
    if (!validationCheck(strengthInput, 1, 10)) {
        cout << "ERROR: Please enter a value between 1-10\n";
        incorrectInput();
    }
    } while (!validationCheck(strengthInput, 1, 10));
    character.strength = character.strength + strengthInput;
    character.intelligence = character.intelligence + (10 - strengthInput);
    cout << "What faction is your character a part of?\n";
    //This cin.ignore will ignore the keyboard buffer that is being inputted after the cout statement.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, character.faction);
    cout << "Pick a primary weapon\n";
    primary = selectWeapon(weapons);
        character.primary = primary;
        cout << endl;
    cout << "Pick a secondary weapon\n";
    secondary = selectWeapon(weapons);
        character.secondary = secondary;
        cout << endl;
        return character;

    }

//makeWeapon will allow the user to create their own weapon. I will not verify  the name of the weapon as I want the user to be able to name it whatever
//they want to. I will be verifying the damage and weight though. Takes in a weapon as a parameter and returns a weapon.
Weapon makeWeapon() {
    static int firstWeapon = 0;
    Weapon weapon;
    int damage;
    float weight;
    cout << "Please name your new weapon!\n";
    //This cin.ignore will ignore the keyboard buffer that is being inputted after the cout statement.
    if(firstWeapon != 0){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    getline(cin, weapon.weaponType);
    firstWeapon++;
    do {
        cout << "Please enter a damage amount for this weapon. 1-10\n";
        cin >> damage;

        if (!validationCheck(damage, 1, 10)){
            cout << "ERROR: Please enter a value between 1-10\n";
            incorrectInput();
        }
    } while (!validationCheck(damage, 1, 10));
    weapon.damageAmount = weapon.damageAmount + damage;

    do {

        cout << "Please enter a weight amount for this weapon. 1-10\n";
        cin >> weight;

        if (!validationCheck(weight, 1, 10)) {
            cout << "ERROR: Please enter a value between 1-10\n";
            incorrectInput();
        }
    } while (!validationCheck(weight, 1, 10));
    weapon.weightAmount = weapon.weightAmount + weight;
    return weapon;
}
//Used to select weapons using an integer instead of string.
Weapon selectWeapon(Weapon createdWeapons[]){
    int weaponSelectedNum;
    Weapon weaponSelected;

    do {
        for(int weaponCounter = 0; weaponCounter < 5; weaponCounter++){
            cout << weaponCounter + 1 << ":" << createdWeapons[weaponCounter].weaponType << " ";
        }
        cout << endl;
        cin >> weaponSelectedNum;
        if(!validationCheck(weaponSelectedNum, 1, 5)){
            cout << "ERROR Please pick an value 1-5";
            incorrectInput();
        }
    }while(!validationCheck(weaponSelectedNum, 1, 5));
    weaponSelected = createdWeapons[weaponSelectedNum - 1];
    return weaponSelected;

}

//writeWeapons prints the weapons and their stats to the log file.
void writeWeapons(GameCharacter weapons[], int weaponCounter) {

    characterLog << "Primary weapon: " << weapons[weaponCounter].primary.weaponType;

    characterLog << endl;

    characterLog << "-- Weapon damage = " << weapons[weaponCounter].primary.damageAmount;

    characterLog << endl;

    characterLog << "-- Weapon weight = " << weapons[weaponCounter].primary.weightAmount;

    characterLog << endl;

    characterLog << "----------------------------------------";

    characterLog << endl;

    characterLog << "Secondary weapon: " << weapons[weaponCounter].secondary.weaponType;

    characterLog << endl;

    characterLog << "-- Weapon damage = " << weapons[weaponCounter].secondary.damageAmount;

    characterLog << endl;

    characterLog << "-- Weapon weight = " << weapons[weaponCounter].secondary.weightAmount;

    characterLog << endl;

    characterLog << "=======================================================\n";

    characterLog << endl;




    }

//writeCharacter prints the character and weapons to the log file.
void writeCharacter(GameCharacter characters[], int characterCounter) {

    characterLog << "Character Name: " << characters[characterCounter].characterName;

    characterLog << endl;

    characterLog << "Age: " << characters[characterCounter].age;

    characterLog << endl;

    characterLog << "height: " << characters[characterCounter].height;

    characterLog << endl;

    characterLog << "Strength: " << characters[characterCounter].strength;

    characterLog << endl;

    characterLog << "Intelligence: " << characters[characterCounter].intelligence;

    characterLog << endl;

    characterLog << "Faction: " << characters[characterCounter].faction;

    characterLog << endl;

    characterLog << "----------------------------------------";

    characterLog << endl;

        writeWeapons(characters, characterCounter);
    }

    //This is used to ignore the input that isn't an integer or float for the questions that need an integer or float input. Without this the program
    //would create an infinite loop.
    void incorrectInput(){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }