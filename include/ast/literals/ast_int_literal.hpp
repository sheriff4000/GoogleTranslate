#include "ast/ast_node.hpp"

class int_literal : public node
{
    private:
        int value;
    public:
        int_literal(int val)
        {
            value = val;
        }

        //visualise

        //codegen

};