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
        void append(std::vector<node_ptr>* _statements) override
        {
            for (uint32_t i =0; i < _statements->size(); i++)
            {
                branches.push_back(     (*_statements)[i]    );
            } 
        }

        statement_list(){
            branches = {};
        }

    int get_size()
    {
        int out = 0;
        for(uint32_t i = 0; i < branches.size(); i++){

            out += branches[i]->get_size();
        }
        return out;
    }

    void gen_mips(std::ostream &dst, context &Context) const override {
        std::cout << "in statement list" << std::endl;
        std::cout << branches.size() << std::endl;

        for(uint32_t i = 0; i < branches.size(); i++){
            std::cout << "printing statment: " << i+1 << std::endl;
            branches[i]->gen_mips(dst, Context);
        }

    }

    void print(){
        std::cout << "statements" << std::endl;
    }
};

#endif