/* 
In this game there are three numbers in a code
The code multiplies to give --
The code adds-up to give --
The user must guess the three digit code
*/

#include <iostream> 


void PrintIntroduction(){
    std::cout << "\n Upon boarding the abondoned alien vessel, you see a computer terminal...\n";
    std::cout << "You need to enter the corret code to access the ship's log...\n";
}
void PlayGame(){
    PrintIntroduction();

    const int CodeA = 4; 
    const int CodeB = 16;
    const int CodeC = 32;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\nThere are three numbers in the code\n";
    std::cout << "\n The codes add-up to: " << CodeSum;
    std::cout << "\n The codes multiply to give: " << CodeProduct;

    int GuessA, GuessB, GuessC; 
    std::cout << "\n\n Guess the three-number code. Insert a space between each number:\n";
    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA *  GuessB * GuessC;

    //Check if the player's guess is correct 
    if (CodeSum == GuessSum && CodeProduct == GuessProduct){
        std::cout << "Access Granted.\n";
        std::cout << "The terminal unlocks.\n";
    } else{
        std::cout << "Access Denied.\n";
        std::cout << "The terminal remains locked. The number '2' appears on the side of the terminal.\n" <<
        "You interpret this as having two remaining attempts to unlock the terminal until a security protocal is initiated...whatever that may mean.\n" <<
        "Would you like to continue?";
    }
}

int main(){
    PlayGame();
/*RETURN STATEMENT*/
    return 0; 
}