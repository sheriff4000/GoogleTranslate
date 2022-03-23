#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include "ast/ast_node.hpp"
//#include "node_vector_parser.hpp"

class statement_list : public node
{
    private:
        //std::vector<node_ptr> branches = {};
    public:
        
        statement_list(std::vector<node_ptr>* _statements){
            for (uint32_t i =0; i < _statements->size(); i++)
            {
                branches.push_back(     (*_statements)[i]    );
            }
        }
        statement_list(){
            branches = {};
        }



    void gen_mips(std::ostream &dst, context &Context, int destReg) const override {

        for(uint32_t i = 0; i < branches.size(); i++){
            branches[i]->gen_mips(dst, Context, destReg);
        }

    }

    void print(){
        std::cout << "statements" << std::endl;
    }
};

#endif