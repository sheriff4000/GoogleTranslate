#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include "ast/ast_node.hpp"
#include "node_vector_parser.hpp"

class statement_list : public node
{
    public:
        node_vector statements {};
        statement_list();
    private:
       // statement_list();
};

#endif