#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include "ast/ast_node.hpp"
//#include "node_vector_parser.hpp"

class statement_list : public node
{
    private:
        std::vector<node_ptr> statements {};
    public:
        
        statement_list(){};
    void gen_mips(std::ostream &dst, context &Context, int destReg) const override;
};

#endif