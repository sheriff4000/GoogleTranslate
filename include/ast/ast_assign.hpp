#include "ast/ast_node.hpp"

class assignment : public node {
    private:
        int dest_reg;
        std::string value;
        node_ptr ident;
        node_ptr value_node;

    public:
        assignment(node_ptr unary_ident, node_ptr _value){
            ident = unary_ident;
            value_node = _value;
        }

        void gen_mips(std::ostream &dst, context &Context) const override{
            std::cout << "assignment" << std::endl;
            int reg1;
            reg1 = Context.get_reg();
            dst << "li $" << reg1 << "," << value << std::endl;
            dst << "sw $" << reg1 << ",8($fp)" << std::endl;
            
        }

        int get_size() override
        {
            return value_node->get_size();
        }
};