#ifndef context_hpp
#define context_hpp

#include "ast_node.hpp"

class node;
typedef node* node_ptr;


class context
{
private:
    //variables storing register configuration, function names mapped to pointers, idk other context stuff
    std::vector<int> register_list;
    std::unordered_map <std::string, node_ptr> function_defs;//not 100% sure about what maps to what, but it's ok for now
    std::unordered_map<std::string, int> memory;
    std::unordered_map<std::string, std::string> types;
    std::unordered_map<std::string, int> sizes;

    int offset; //stack fram pointer shit i don't fucking know
    bool stopped = false;
    int label = 2;
    bool is_label_stored = false;
    std::string stored_label;
    bool is_label_stored2 = false;

public:
    context()
    {
        sizes["int"] = sizes["float"] = sizes["unsigned"]  = 4;
        sizes["double"] = 8;
    }
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
    std::string get_label()
    {

        return "$L" + std::to_string(label);

    }
    void incr_label()
    {
        label++;
    }
    bool bool_label()
    {
        if (is_label_stored)
        {
            is_label_stored = false;
            return true;
        }
        else{
            return false;
        }
    }
    std::string get_stored_label()
    {
        is_label_stored = false;
        return stored_label;
    }
    void store_label(std::string lab)
    {
        stored_label = lab;
        is_label_stored = true;
    }
    void set_bool_label2(bool a)
    {
        is_label_stored2 = a;
    }
    bool bool_label2()
    {
        return is_label_stored2;
    }
    int get_size(std::string id)
    {
        return sizes[id];
    }
};




#endif