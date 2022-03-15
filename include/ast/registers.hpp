#include <vector>
#ifndef registers_hpp
#define registers_hpp
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
#endif