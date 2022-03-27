#include "ast/ast_node.hpp"

class func_call : public node{
    private:
        std::string val;
    public:
        func_call(node_ptr _val_node){
            val = _val_node->get_val();
        };

        std::string get_val() const override{
            return val;
        }

        std::string get_type() const override{
            return "func";
        }

};