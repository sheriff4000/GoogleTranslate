#ifndef ast_string
#define ast_string

#include "ast/ast_node.hpp"

class string_literal : public node {
    protected:
        std::string value;

    public:
        string_literal(std::string _string){
            value = _string;
        }
};

#endif