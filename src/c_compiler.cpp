#include "ast.hpp"



int main (int argc, char *argv[])
{
    
    const node *ast = parseAST(argv[2]);

    std::string o(argv[3]);
    std::ofstream ofs;
    if (o == "-o")
    {
        ofs.open(argv[4]);
        //ofs is output stream i think, the file to put assembly into
    }
    std::cout << "before context" << std::endl;

    context Context;

    std::cout << ast << std::endl;
    std::cout << ast << std::endl;
    ast->gen_mips(ofs, Context); //idk what arguments we'll need just yet
    
    std::cout << "Before print" << std::endl;
    std::cout << ast << std::endl;
    
    // std::cout << "check 2" << std::endl;
    // std::cout << "[" << std::endl;

    

    // std::cout << "]" << std::endl;

}

// Here is a list of basic features that you might like to implement first.

// * a file containing just a single function with no arguments
// * variables of `int` type
// * local variables
// * arithmetic and logical expressions
// * if-then-else statements
// * while loops