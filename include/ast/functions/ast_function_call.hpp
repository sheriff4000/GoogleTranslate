#include "ast/ast_node.hpp"

#include "node_vector_parser.hpp"
class func_call : public node{
    private:
        std::string val;
        std::vector<node_ptr> args;
    public:
        func_call(node_ptr _val_node){
            val = _val_node->get_id();
        };

        func_call(node_ptr _val_node, node_vector_ptr _args){
            val = _val_node->get_id();
            args = *_args;
        }

        void gen_mips(std::ostream &dst, context &Context) const override {
            std::cout << "function call" << std::endl;
            // for(uint32_t i = 0; i < args.size(); i++){
            //     dst << "li      $" << i+4 << "," << args[i]->get_val() << std::endl;
            // }
            //Think above is putting params into mem

            dst << "jal     " << val << std::endl; //
            dst << "nop" << std::endl;
        }

        std::string get_val() const override{
            return val;
        }

        std::string get_type() const override{
            return "func";
        }

};