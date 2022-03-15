#include "ast.hpp"



int main (int argc, char *argv[])
{
    nodePtr ast = parseAST(argv[2]);

    if (argv[3] == "-o")
    {
        std::ofstream ofs(argv[4]);
        //ofs is output stream i think, the file to put assembly into
    }
    
    //make context now - dynamically
    context Context;

    ast->gen_mips(std::cout, Context); //idk what arguments we'll need just yet

    //delete Context;

}

// Here is a list of basic features that you might like to implement first.

// * a file containing just a single function with no arguments
// * variables of `int` type
// * local variables
// * arithmetic and logical expressions
// * if-then-else statements
// * while loops