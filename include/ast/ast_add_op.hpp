#include "ast_node.hpp"

class add_op :public node
{
    private:
        //Inherited branches, we'll make 0 and 1 indices the operands
        
    public:
        add_op(node_ptr id_or_literal, node_ptr id_or_literal2)
        {
            //we want their values?
            //or we want to load them into memory and add them
            //if ident we load word, else we load immediate
            //we can use dest_reg so that whatever type, they do the right load into whichever reg we specify and we're good
            std::cout << "making add node" << std::endl;
            branches.push_back(id_or_literal);
            branches.push_back(id_or_literal2);
            //THESE CAN ACTUALLY BE ADDITIONS THEMSELVES, LIKE A CHAIN OF EM, OR MULTIPLICATIVE EXPRESSIONS ETC. BIDMAS, 
            //CHECK PARSER then you'll know what they can be
        }

        void gen_mips(std::ostream &dst, context &Context) const override
        {
            std::cout << "Incorrect add gen_mips()" << std::endl;
        }
        void gen_mips(std::ostream &dst, context &Context, int dest_reg) const override
        {
            //So for a return statement we might have dest_reg = 2
            std::cout << "In add_op" << std::endl;
            // int reg1 = Context.get_reg();
            // int reg2 = Context.get_reg();
            int reg1 = 4;
            int reg2 = 5;
            std::cout << "gotten regs in add_op" << reg1 << reg2 << std::endl;
            branches[0]->gen_mips(dst, Context, reg1);
            std::cout << "first branch loaded" << std::endl;;
            branches[1]->gen_mips(dst, Context, reg2);
            std::cout << "second" << std::endl;
            dst << "nop" << std::endl;
            dst << "addu    $" << dest_reg << ",$" << reg1 << ",$" << reg2 << std::endl;    
        }

};  