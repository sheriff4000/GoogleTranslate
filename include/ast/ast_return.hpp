#ifndef ast_return
#define ast_return

#include "ast_node.hpp"

class return_stmt : public node {
    private:
        std::string val;
        std::string type;
        int dest_reg;
        node_ptr return_val;
        bool stop = true;
    public:
        return_stmt(node_ptr _val){
            type = _val->get_type();
            val = _val->get_val();
            return_val = _val;
            
            dest_reg = 2;
        }
        return_stmt(){

        }
        void gen_mips(std::ostream &dst, context &Context) const override{

            std::cout << "In return node" << std::endl;

            //std::cout << type << std::endl;
            //std::cout << return_val->get_id() << std::endl;





            if  (type == "func"){
                std::cout << "return function call" << std::endl;
                return_val->gen_mips(dst, Context );
            }
            // else if (type == "sizeof") {
            //     dst << "li $" << dest_reg << "," << return_val->get_size() << std::endl;
            // }
            else
            {
                return_val->gen_mips(dst, Context, dest_reg);
                Context.stop();
            }
        }
};

#endif