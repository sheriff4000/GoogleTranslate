#include "ast_node.hpp"

class size_of : public node {
    private:
        std::string type;
        int size;
    public: 
        size_of(node_ptr _node){
            type = _node->get_type();
            size = _node->get_size();
        }

        void gen_mips(std::ostream &dst, context &Context) const override{

        }

        int get_size(){
            return size;
        }

        std::string get_type() const override{
            return "sizeof";
        }
};