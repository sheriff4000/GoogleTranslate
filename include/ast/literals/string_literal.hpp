#include<string>

class string_literal : public node
{
    private:
        std::string value;
    public:
        string_literal(std::string val)
        {
            value = val;
        }

};