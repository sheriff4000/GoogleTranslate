#include<unordered_map>
#include "ast_node.hpp"
class context
{
private:
    //variables storing register configuration, function names mapped to pointers, idk other context stuff
    registers reg;
    std::unordered_map <std::string name, function_def* def> function_defs;//not 100% sure about what maps to what, but it's ok for now

public:
    //functions to check context should be here
    int get_reg(int a)
    {
        return reg.get_reg(a);
    }
    nodePtr get_function(std::string name)
    {
        return function_defs[name];
    }


};