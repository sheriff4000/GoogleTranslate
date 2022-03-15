
#include "ast/ast_node.hpp"

#include<iostream>
#include <vector>

class function_def : public node
{
    //we have inherited branches, wbout arguments
private:
    std::vector<nodePtr> args;
    nodePtr _actual_func
public:
    function_def(std::vector<nodePtr> _args, nodePtr actual_func)
    {
        args = _args; //I think it copies instead of reference
        _actual_func = actual_func
    }
    function_def(nodePtr actual_func) { // no parameters
        _actual_func = actual_func
    }

    //visualise
    void print(std::ostream &dst, std::string indent) const override;

    virtual ~function_def();
    



};