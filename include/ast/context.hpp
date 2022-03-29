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
    std::vector<int> register_list;
    std::unordered_map <std::string, node_ptr> function_defs;//not 100% sure about what maps to what, but it's ok for now
    std::unordered_map<std::string, int> memory;
    std::unordered_map<std::string, std::string> types;
    int offset; //stack fram pointer shit i don't fucking know
    bool stopped = false;

public:
    void init_regs()
    {
        register_list = {};
        for (int i = 2; i< 26; i++)
        {
            register_list.push_back(0);
        }        
    }
    int get_reg()
    {
        for (int i = 2; i< 26; i++)
        {
            if (register_list[i-2] == 0) //0 means not in use
            {
                register_list[i-2] = 1;
                return i;
            }
        }
        return 0;
    }

    node_ptr get_function(std::string name)
    {
        return function_defs[name];
    }
    void clean()
    {
        init_regs();
        memory = {};
    }
    std::string get_type(std::string ident){
        return types[ident];
    }
    void set_type(std::string ident, std::string type1)
    {
        types[ident] = type1;
    }
    void set_memory(std::string ident, int mem)
    {
        memory[ident] = mem;
    }
    int get_mem(std::string ident)
    {
        return memory[ident];
    }
    void set_offset(int _offset)
    {
        offset = _offset;
    }
    void shift_offset(int shift)
    {
        offset += shift;
    }
    int get_offset()
    {
        return offset;
    }
    void stop()
    {
        stopped = true;
    }
    bool get_stop()
    {
        return stopped;
    }

};




#endif