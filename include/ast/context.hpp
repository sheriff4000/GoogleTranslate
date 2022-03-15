#ifndef context_hpp
#define context_hpp
#include<unordered_map>

#include "registers.hpp"

#include<unordered_map>

#include "ast/ast_node.hpp"
#include "ast/registers.hpp"
#include "ast/functions/ast_function_def.hpp"
struct function;

class context
{
private:
    //variables storing register configuration, function names mapped to pointers, idk other context stuff
    registers reg;
    std::unordered_map <std::string, function> function_size;//not 100% sure about what maps to what, but it's ok for now

public:
    //functions to check context should be here
    // int get_reg()
    // {
    //     return reg.get_reg();
    // }
    // nodePtr get_function(std::string name)
    // {
    //     return function_defs[name];
    // }


};


struct function{
    int size;
};
#endif