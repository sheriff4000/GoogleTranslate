#ifndef ast_return
#define ast_return

#include "ast_node.hpp"

class return_stmt : public node {
    private:
        std::string val;
        std::string type;
        int dest_reg;
    public:
        return_stmt(node_ptr _val){
            type = _val->get_type();
            val = _val->get_val();
            
            dest_reg = 2;
        }

        void gen_mips(std::ostream &dst, context &Context) const override{
            std::cout << "mips for return statement" << std::endl;
            std::cout << type << std::endl;
            if (type == "int") { 
                dst << "li $" << dest_reg << "," << val << std::endl;
            } else if  (type == "func"){
                dst << "jal " << val << std::endl; //
                dst << "nop" << std::endl;
            }
        }
};

#endif