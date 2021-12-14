/*PREPROCESSOR DIRECTIVE*/
#include <iostream> //#include is a Preprocessor Directive - Instructions to the compiler before compiling the remainder of the code
                    //<iostream> is the library that we want to "include" - This is also known as a Header File - a file that includes code

// In this game there are three numbers in the code
// The codes multiply to give --
// The codes add-up to --
// "Enter the three code numbers followed by x"

void PrintIntroduction(){
    /*EXPRESSION STATEMENTS*/

    // Print welcome messages to the terminal
    //std::cout << std::endl;
    std::cout << "\n Upon boarding the abondoned alien vessel, you see a computer terminal...\n";
    // std::cout << std::endl; //endl = End Line - creates a new line
    std::cout << "You need to enter the corret code to access the ship's log...\n";
    //std::cout << std::endl;
}
void PlayGame()
{
    //std::cout << "Hello, World!"; //expression to output messages to terminal
    // std (meaning standard) is a Namespace - used to prevent name conflicts in the code
    // :: (used to define the Namespace) - Scope Operator - telling the compiler to check the code inside the Namespace
    // cout- Cout defined in std namespace - allows us to write to the terminal
    // << directing towards the desired output the "Hello World" string
    // A String is a sequence of characters

    PrintIntroduction();

/*DECLARATION STATEMENTS*/ // An expresion followed by a ';' is an Expression Statment.

    //Declare 3 number code
    const int CodeA = 4; //initialized variable, int = datatype "a" = variable name, 4 = value
    const int CodeB = 16; // 'const' makes the variable a constant so that the value cannot be changed after declaration

    const int CodeC = 32; //


    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;

/*EXPRESSION STATEMENT*/

    //Print CodeSum  and CodeProduct into terminal
    std::cout << std::endl;
    std::cout << "There are three numbers in the code\n";
    std::cout << "\n The codes add-up to: " << CodeSum;
    std::cout << "\n The codes multiply to give: " << CodeProduct;

    int GuessA, GuessB, GuessC; 
    std::cout << "\n\n Guess the three-number code. Insert a space between each number.\n";
    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;

    //std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA *  GuessB * GuessC;
    //std::cout << "Your guess adds-up to: " << GuessSum << std::endl;
   // std::cout << "Your guess multiply to give: " << GuessProduct <<std::endl;

    //Check if the player's guess is correct 
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "Access Granted.\n";
        std::cout << "The terminal unlocks.\n";
    }
    else{
        std::cout << "Access Denied.\n";
        std::cout << "The terminal remains locked. The number '2' appears on the side of the terminal.\n" <<
        "You interpret this as having two remaining attempts to unlock the terminal until a security protocal is initiated...whatever that may mean.\n" <<
        "Would you like to continue?";
    }
}


/*MAIN FUNCTION*/
int main()
{
    PlayGame();
/*RETURN STATEMENT*/
    return 0; 
}