#ifndef ast_type_hpp
#define ast_type_hpp

#include "ast/ast_node.hpp"
class specifier_type: public node
{
    private:
        std::string type;
    public:
        specifier_type(std::string _type)
        {
            type = _type;
        }
        virtual ~specifier_type();
};

#endif