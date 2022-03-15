#include <unordered_map>
#include <string>

class bindings
{
private:

std::unordered_map<std::string, nodePtr> bindings;

public:

    nodePtr evaluate(std::string ident) //returns binding if it exists
    {
        if (bindings.find(ident) == bindings.end())
        {
            return bindings[ident];
        }
        else
        {
            return 0;
        }
    }

};