#ifndef ast_if_statement
#define ast_if_statement

#include "ast_node.hpp"

class if_statement : public node {
    protected:


    public:
        if_statement(node_ptr condition, node_ptr statements) {
            
        }
        if_statement(node_ptr condition, node_ptr statements, node_ptr else_statements) {

        }

        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {

        };


        int get_size() const override{
            return 8 * branches.size();
        }

        std::string get_type() const override{
            return "if";
        }

        std::string get_val() const override{
            return "if";
        }
};

#endif