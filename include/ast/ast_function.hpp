#include<iostream>
#include <vector>

class function_def : public node
{
    //we have inherited branches, wbout arguments
private:
    std::vector<nodePtr> args;
public:
    function_def(std::vector<nodePtr> _args)
    {
        args = _args; //I think it copies instead of reference
    }
    



};