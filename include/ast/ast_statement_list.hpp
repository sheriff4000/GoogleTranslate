#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include "ast/ast_node.hpp"
//#include "node_vector_parser.hpp"

class statement_list : public node
{
    private:
        node_vector statements {};
    public:
        
        statement_list(){};

};

#endif