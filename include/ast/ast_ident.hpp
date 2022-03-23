#ifndef ast_ident
#define ast_ident

#include "ast_node.hpp"

class identifier : public node {
    protected:
        std::string id;

    public:
        identifier(std::string *_id){
            id = *_id;

        };
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {};

        std::string get_id(){
            return id;
        };

        void print(){
            std::cout << id << std::endl;
        }

};





#endif