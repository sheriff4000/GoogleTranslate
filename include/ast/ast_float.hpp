#ifndef ast_float
#define ast_float

#include "ast_node.hpp"

class float_literal : public node {
    protected:
        float val;

    public:
        f_number(float _val);
};

#endif