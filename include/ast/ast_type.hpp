#ifndef ast_type_hpp
#define ast_type_hpp

#include "ast/ast_node.hpp"
class specifier_type: public node
{
    private:
        std::string type;
        int size;
    public:
        specifier_type(std::string _type)
        {
            type = _type;
        }
        specifier_type(node_ptr _node){
            type = _node->get_type();
        }
        std::string get_type() const override{
            return type;
        }
        virtual ~specifier_type(){};
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {};

        void print(){
            std::cout << type << std::endl;
        };

        std::string get_id() const override{
            return "type";
        }
        int get_size() const override{
            if (type == "int") {
                return 4;
            }else if (type == "char") {
                return 1;
            }

        }
};      


#endif