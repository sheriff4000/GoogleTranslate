#ifndef context_hpp
#define context_hpp

#include<unordered_map>
#include <vector>



struct function;

struct function{
    int size;
};

class registers
{
private:
    std::vector <int> register_list;
public:

    int get_reg()
    {
        for (int i = 2; i< 26; i++)
        {
            if (register_list[i] != 0)
            {
                return i;
            }
        }
        return -1;
    }
};

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




#endif