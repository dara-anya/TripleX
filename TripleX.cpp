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
    "\nYou need to enter the correct code to unlock the terminal, access the ship's log, and find out what happened...\n";
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

        if (Attempts != 0) {
            std::cout << "\n\nThe number " << Attempts << " appears on the terminal. You interpret this as the number of attempts remaining to guess the correct code."; 
            std::cout << "\nBe Careful. Who knows what will happen when there are no more attempts...\n";
        } else{
            std::cout << "\n\nThe number " << Attempts << " appears on the terminal. \nYou have no attempts remaining.\n";
        }        

        return false;
    }
}

int main(){
    srand(time(NULL)); //Creates new random sequences based on the time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;

    int Attempts = 2;

    PrintIntroduction(LevelDifficulty);

    //Loop game until all levels completed
    while (LevelDifficulty <= MaxDifficulty && Attempts > -1){ 
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

        } else{
            //decrease number of attempts
            Attempts --;
        }

    }

    if (Attempts < 0){
        std::cout << "\nYou hear several tones proliferate throughout the ship...";
        Beep(100,500);
        Beep(200,500);
        Beep(300,500);
        Beep(400,500);
        Beep(500,500);
        Beep(600,500);
        Beep(700,500);
        Beep(800,500);
        Beep(900,500);
        std::cout << "\n\nThen silence...";
        Sleep (5000);
        std::cout << "\n\nYou hear explosions grow closer and closer to you. The ship explodes. The alien vessel, your crew and you are lost in the emptiness of space.";
        std::cout << "\n\nThe number of attempts reached zero, which triggered the self-destruct sequence.";
        std::cout << "\n\nGAME OVER!";
        std::cout << "\n\nThanks for playing.";
        return 0;
    }
    std::cout << "\nYou have successfully unlocked the terminal";
    std::cout << "\n\nThanks for playing.";
    return 0; 
}