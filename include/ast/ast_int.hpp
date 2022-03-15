#ifndef ast_int
#define ast_int

#include "ast_node.hpp"

class int_number : public node {
    protected:
        int val

    public:
        int_number(int _val);
}

#endif