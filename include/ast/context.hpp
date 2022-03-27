#ifndef context_hpp
#define context_hpp

#include "ast_node.hpp"

class node;
typedef node* node_ptr;

class registers
{
private:
    std::vector <int> register_list;
public:
    registers()
    {
        register_list = {};
    }

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
    void zero()
    {
        register_list = {};
    }
};



class context
{
private:
    //variables storing register configuration, function names mapped to pointers, idk other context stuff
    registers reg;
    std::unordered_map <std::string, node_ptr> function_defs;//not 100% sure about what maps to what, but it's ok for now
    std::unordered_map<std::string, std::string> memory;
    std::unordered_map<std::string, int> types;

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
    void clean()
    {
        reg.zero();
        memory = {};
    }
    int get_type(std::string ident){
        return types[ident];
    }
    void set_type(std::string ident, std::string type1)
    {
        int size;

        types[ident] = size;
    }


};




#endif