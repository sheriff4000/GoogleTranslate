
#include "ast/ast_node.hpp"

class float_literal : public node
{
private:
    float value;
public:
    float_literal(float val)
    {
        value = val;
    }

    //need visualising

    //need codegen
};