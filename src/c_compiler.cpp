#include "ast.hpp"



int main (int argc, char *argv[])
{
    
    const node *ast = parseAST(argv[2]);

    //std::string o(argv[3]);
    std::ofstream ofs;
    ofs.open(argv[4]);
    // if (o == "-o")
    // {
        
    //     //ofs is output stream i think, the file to put assembly into
    // }
    //std::cout << "before context" << std::endl;

    context Context;
    Context.init_regs();
    ast->gen_mips(ofs, Context);
    //ast->print(); //idk what arguments we'll need just yet
    

    

}

// Here is a list of basic features that you might like to implement first.

// * a file containing just a single function with no arguments
// * variables of `int` type
// * local variables
// * arithmetic and logical expressions
// * if-then-else statements
// * while loops