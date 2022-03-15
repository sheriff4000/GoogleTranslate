#include<unordered_map>

#include "ast_node.hpp"
#include "registers.hpp"
#include "ast.hpp"



class context
{
private:
    //variables storing register configuration, function names mapped to pointers, idk other context stuff
    registers reg;
    std::unordered_map <std::string, function_def*> function_defs;//not 100% sure about what maps to what, but it's ok for now

public:
    //functions to check context should be here
    int get_reg()
    {
        return reg.get_reg();
    }
    nodePtr get_function(std::string name)
    {
        return function_defs[name];
    }


};