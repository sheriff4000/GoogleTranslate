#include "ast_node.hpp"

class declaration :public node
{
    private:
        std::string type;
        std::string ident;
    public:
        declaration(node_ptr _type, std::vector<node_ptr> declarator_list )
        {
            type = _type->get_id();
            
        }
        void gen_mips(std::ostream &dst, context &Context) const override
        {
            //idefk
            int reg = Context.get_reg();
            //get a reg, then quick instruction to put it into reg?
            dst << "li";
           
        }

};  