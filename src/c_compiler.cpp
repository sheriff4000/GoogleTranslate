#include "ast.hpp"



int main (int argc, char *argv[])
{
    nodePtr ast = parseAST(argv[2]);

    if argc[3] == "-o"
    {
        std::ofstream ofs(argc[4])
        //ofs is output stream i think, the file to put assembly into
    }
    
    //make context now - dynamically
    context* Context = new context;


    //ast->gen_mips(ofs, context,  ) //idk what arguments we'll need just yet

    /*
    Simon did it (and suggests to do) with OOP. The generate mips function is a member of the class. 
    And everything is within classes.
    */

    delete Context

}

// Here is a list of basic features that you might like to implement first.

// * a file containing just a single function with no arguments
// * variables of `int` type
// * local variables
// * arithmetic and logical expressions
// * if-then-else statements
// * while loops