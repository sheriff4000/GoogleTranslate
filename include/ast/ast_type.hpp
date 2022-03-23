#ifndef ast_type_hpp
#define ast_type_hpp

#include "ast/ast_node.hpp"
class specifier_type: public node
{
    private:
        std::string type;
    public:
        specifier_type(std::string _type)
        {
            type = _type;
        }
        std::string get_id() const override{
            return type;
        }
        virtual ~specifier_type(){};
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {};

        void print(){
            std::cout << type << std::endl;
        };
};      


#endif