#include "ast_node.hpp"

class size_of : public node {
    private:
        std::string type;
        //int size;
        node_ptr arg;
    public: 
        size_of(node_ptr _node){
            type = _node->get_type();
            
            arg = _node;
        }

        void gen_mips(std::ostream &dst, context &Context, int destReg) const override{
            //we have type
            //which is ident, or int etc.
            int size;
            //load immediate into destreg
            if (type == "ident")
            {
                size = Context.get_size(Context.get_type(arg->get_id()));
            }
            else{
                size = arg->get_size();
            }
            dst << "li $" << destReg << "," << size << std::endl;
        }

        std::string get_type() const override{
            return "sizeof";
        }
};