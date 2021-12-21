#include <iostream> 
#include <ctime> // accesses computer's time
#include <windows.h>

/* 
In this game there are three numbers in a code
The code multiplies to give --
The code adds-up to give --
The user must guess the three digit code
*/

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nA distress signal has brought you aboard an abondoned alien vessel. You see a computer terminal. " <<
    "There are three unilluminated lights above the terminal." << 
    "\nYou need to enter the corret code to unlock the terminal, access the ship's log, and find out what happened...\n";
}

int PlayAttempts (int Attempts){
    int Attempts = 3;
    Attempts--;
    return Attempts;
    std::cout << Attempts;
   
}

bool PlayGame(int Difficulty, int Attempts){

    const int CodeA = rand() % Difficulty + Difficulty; //Add '1' to the modular to remove '0' from the randomization range
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //std::cout << CodeA << CodeB << CodeC;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\nThe \"Level " << Difficulty;
    std::cout << "\" terminal is locked by a three-digit code.";
    std::cout << "\nA message on the side of the terminal reads:";
    std::cout << "\n\n\tThe code adds-up to: " << CodeSum;
    std::cout << "\n\tThe code multiplies to give: " << CodeProduct;

    static bool initialized; // Executes once upon initialization
    if (!initialized) {
        initialized = true;
        std::cout << "\n\nApparently, mathematics is a pillar of this species' civilization.";
    }
   
    
    int GuessA, GuessB, GuessC; 
    std::cout << "\n\n\tGuess the three-digit code. Insert a space between each digit:\n";
    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA *  GuessB * GuessC;

    //Check if the player's guess is correct 
    if (CodeSum == GuessSum && CodeProduct == GuessProduct){
        Beep(1000,500);
        std::cout << "\nYou hear a tone. One of the lights illuminate.";
        std::cout << "\nYou have input the correct code."; 

        return true;
    } else{
        Beep(100,500);
        Beep(100,500);
        std::cout << "\nYou hear a tone. No lights illuminate.";
        std::cout << "\nYou have input the incorrect code.";

        PlayAttempts(Attempts);
        std::cout << "\n\nThe number " << Attempts << " appears on the terminal. You interpret this as having two more attempts to guess the correct code."; 
        std::cout << "\nBe Careful. Who knows what will happen when all atempts are gone...\n";

        return false;
    }
}

int main(){
    srand(time(NULL)); //Creates new random sequences based on the time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;
    int Attempts = 3;

    PrintIntroduction(LevelDifficulty);

    //Loop game until all levels completed
    while (LevelDifficulty <= MaxDifficulty){ 
        bool bLevelComplete = PlayGame(LevelDifficulty, Attempts); //All boolean variables must start with lowercase 'b' in Unreal Engine

        // notice if input letter for GuessCode creates endless loop --> this causes an error
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards buffer

        if (bLevelComplete){
            //increase level difficulty
            LevelDifficulty ++;
            if(((MaxDifficulty + 1)- LevelDifficulty) == 1){
                std::cout << "\n" << ((MaxDifficulty + 1)- LevelDifficulty) << " lock remains.\n";
                std::cout << "_________\n";

            } else{
                std::cout << "\n" << ((MaxDifficulty + 1)- LevelDifficulty) << " locks remain.\n";
                std::cout << "_________\n";
            }

        }
    }

    std::cout << "\nYou have access to the terminal.";
    return 0; 
}