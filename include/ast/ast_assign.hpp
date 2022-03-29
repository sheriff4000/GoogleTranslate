#include "ast/ast_node.hpp"

class assignment : public node {
    private:
        int dest_reg;
        std::string value;
        node_ptr ident;

        std::string id;
        node_ptr expression;

    public:
        assignment(node_ptr unary_ident, node_ptr _value){
            ident = unary_ident;
            expression = _value;
            std::cout << "assignment checking the ident" << ident->get_type() << std::endl;
            id = unary_ident->get_id();
        }

        void gen_mips(std::ostream &dst, context &Context) const override{

            std::cout << "assignment" << std::endl;
            int reg1;
            reg1 = Context.get_reg();
            std::cout << "result of get_reg " << reg1 << std::endl;
            //Evaluate the expression into destination register
            expression->gen_mips(dst, Context, reg1);
            //Now load this value into memory and record that this memory location corresponds to this variable.
            //Don't know where we can load it into? need to check context
            //idek just call get_offset()
            int off = Context.get_offset();
            Context.shift_offset(-4);
            std::cout << "offset" <<off << std::endl;
            
            dst << "sw $" << reg1 << "," << off << "($fp)" << std::endl;
            std::cout << "setting memory of ident: " << ident->get_id() << std::endl;
            Context.set_memory(id, off);
        }

        int get_size() const override
        {
            return expression->get_size();
        }
};