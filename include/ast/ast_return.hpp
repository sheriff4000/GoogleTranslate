#ifndef ast_return
#define ast_return

#include "ast_node.hpp"

class return_stmt : public node {
    private:
        std::string val;
        int dest_reg;
    public:
        return_stmt(node_ptr _val){
            val = _val->get_val();
            dest_reg = 2;
        }

        void gen_mips(std::ostream &dst, context &Context) const override{
            std::cout << "mips for return statement" << std::endl;
            dst << "li $" << dest_reg << "," << val << std::endl;
        }
};

#endif