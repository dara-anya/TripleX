/*PREPROCESSOR DIRECTIVE*/
#include <iostream> //#include is a Preprocessor Directive - Instructions to the compiler before compiling the remainder of the code
                    //<iostream> is the library that we want to "include" - This is also known as a Header File - a file that includes code

// In this game there are three numbers in the code
// The codes multiply to give --
// The codes add-up to --
// "Enter the three code numbers followed by x"

/*MAIN FUNCTION*/
int main()
{
    //std::cout << "Hello, World!"; //expression to output messages to terminal
    // std (meaning standard) is a Namespace - used to prevent name conflicts in the code
    // :: (used to define the Namespace) - Scope Operator - telling the compiler to check the code inside the Namespace
    // cout- Cout defined in std namespace - allows us to write to the terminal
    // << directing towards the desired output the "Hello World" string
    // A String is a sequence of characters

/*EXPRESSION STATEMENTS*/

    // Print welcome messages to the terminal
    std::cout << std::endl;
    std::cout << "Upon boarding the abondoned alien vessel, you see a computer terminal...";
    std::cout << std::endl; //endl = End Line - creates a new line
    std::cout << "You need to enter the corret code to access the ship's log...";
    std::cout << std::endl;

/*DECLARATION STATEMENTS*/ // An expresion followed by a ';' is an Expression Statment.

    //Declare 3 number code
    const int a = 4; //initialized variable, int = datatype "a" = variable name, 4 = value
    const int b = 16; // 'const' makes the variable a constant so that the value cannot be changed after declaration

    const int c = 32; //


    const int sum = a + b + c; 
    const int product = a * b * c;

/*EXPRESSION STATEMENT*/

    //Print sume and product into terminal
    std::cout << std::endl;
    std::cout << sum << std::endl;
    std::cout << product <<std::endl;

/*RETURN STATEMENT*/
    return 0.0; 
}