#include "ast.hpp"



int main (int argc, char *argc[])
{
    node* ast = parseAST(argv[2]);
    if argc[3] == "-o"
    {
        std::ofstream ofs(argc[4])
        //ofs is stream from input file
    }
    

    //ast->gen_mips(ast, ofs, )

    /*
    Simon did it (and suggests to do) with OOP. The generate mips function is a member of the class. 
    And everything is within classes.
    */


}

// Here is a list of basic features that you might like to implement first.

// * a file containing just a single function with no arguments
// * variables of `int` type
// * local variables
// * arithmetic and logical expressions
// * if-then-else statements
// * while loops