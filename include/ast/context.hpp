#ifndef context_hpp
#define context_hpp

#include<unordered_map>
#include <vector>
#include "ast_node.hpp"


class registers
{
private:
    std::vector <int> register_list;
public:

    int get_reg()
    {
        for (int i = 2; i< 26; i++)
        {
            if (register_list[i] == 0) //0 means not in use
            {
                register_list[i] = 1;
                return i;
            }
        }
        return 0;
    }
};

class context
{
private:
    //variables storing register configuration, function names mapped to pointers, idk other context stuff
    registers reg;
    std::unordered_map <std::string, node_ptr> function_defs;//not 100% sure about what maps to what, but it's ok for now

public:
    //functions to check context should be here
    int get_reg() //return free reg (in assembly?, rn its just integers) if false then into memory?
    {
        return reg.get_reg();
    }
    node_ptr get_function(std::string name)
    {
        return function_defs[name];
    }


};




#endif