#include "ast/ast_node.hpp"

class assignment : public node {
    private:
        int dest_reg;
        int value;

    public:
        assignment(node_ptr _dest_reg, node_ptr _value){
            dest_reg = 2;
            value = _value->get_val();
        }

        void gen_mips(std::ostream &dst, context &Context) const override{
            dst << "li $" << dest_reg << "," << value << std::endl;
            dst << "sw $" << dest_reg << ",8($fp)" << std::endl;
            
        }
};