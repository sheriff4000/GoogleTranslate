#include "ast/ast_node.hpp"

class statement : public node {
    private:
        std::string type;
        node_ptr val_ptr;
        int val;

    public:
        statement(std::string _type, node_ptr _node){
            val_ptr = _node;

        }

        gen_mips(std::ostream &dst, context &Context) const override{
            
        }
};