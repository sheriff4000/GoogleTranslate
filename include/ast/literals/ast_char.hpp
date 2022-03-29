#ifndef ast_char
#define ast_char

#include "ast/ast_node.hpp"

class char_literal : public node {
    protected:
        char value;
        int ascii;

    public:
        char_literal(char _string){
            value = _string;
            ascii = int(_string);
            
        }
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {
            dst << "li $" << destReg << "," << ascii << std::endl;
        };

        std::string get_type() const override{
            return "char";
        }
};

#endif