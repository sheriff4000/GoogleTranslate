#ifndef ast_int
#define ast_int

#include "ast/ast_node.hpp"

class int_literal : public node {
    protected:
        int val;

    public:
        int_literal(int _val) {
            val = _val;
        }

        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {
            dst << "li $" << destReg << "," << val << std::endl;
        };

        void print(){
            std::cout << "integer" << std::endl;
        }

        int get_size() const override{
            return 4;
        }

        std::string get_val() const override{
            return std::to_string(val);
        }
};

#endif