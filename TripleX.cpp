#include <iostream> 
#include <ctime> // accesses computer's time

/* 
In this game there are three numbers in a code
The code multiplies to give --
The code adds-up to give --
The user must guess the three digit code
*/

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nUpon boarding the abondoned alien vessel, you see a level " << Difficulty;
    std::cout << " computer terminal. \n\nYou need to enter the corret code to access the ship's log...\n";
}
bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty; //Add '1' to the modular to remove '0' from the randomization range
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    std::cout << CodeA << CodeB << CodeC;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\nThere are three numbers in the code\n";
    std::cout << "\nThe codes add-up to: " << CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct;

    int GuessA, GuessB, GuessC; 
    std::cout << "\n\nGuess the three-number code. Insert a space between each number:\n";
    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA *  GuessB * GuessC;

    //Check if the player's guess is correct 
    if (CodeSum == GuessSum && CodeProduct == GuessProduct){
        std::cout << "Access Granted.\n";
        std::cout << "The terminal unlocks.\n";

        return true;
    } else{
        std::cout << "Access Denied.\n";
        std::cout << "The terminal remains locked. The number '2' appears on the side of the terminal.\n" <<
        "You interpret this as having two remaining attempts to unlock the terminal until a security protocal is initiated...whatever that may mean.\n" <<
        "Would you like to continue?";

        return false;
    }
}

int main(){
    srand(time(NULL)); //Creates new random sequences based on the time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;

    //Loop game until all levels completed
    while (LevelDifficulty <= MaxDifficulty){ 
        bool bLevelComplete = PlayGame(LevelDifficulty); //All boolean variables must start with lowercase 'b' in Unreal Engine

        // notice if input letter for GuessCode creates endless loop --> this causes an error
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards buffer

        if (bLevelComplete){
            //increase level difficulty
            LevelDifficulty ++;
            if(((MaxDifficulty + 1)- LevelDifficulty) == 1){
                std::cout << "There is " << ((MaxDifficulty + 1)- LevelDifficulty) << " lock remaining.";

            } else{
                std::cout << "There are " << ((MaxDifficulty + 1)- LevelDifficulty) << " locks remaining.";
            }

        }
    }

    std::cout << "You have access to the terminal";
    return 0; 
}