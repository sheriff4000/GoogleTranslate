#ifndef ast_int
#define ast_int

#include "ast/ast_node.hpp"

class int_literal : public node {
    protected:
        int val;

    public:
        int_literal(int _val);
};

#endif