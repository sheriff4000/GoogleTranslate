#ifndef ast_ident
#define ast_ident

#include "ast_node.hpp"

class identifier : public node {
    protected:
        std::string id;

    public:
        identifier(std::string *_id){
            id = *_id;

        }
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {}

        std::string get_val() const override{
            return id;
        }

        std::string get_type() const override{
            return "ident";
        }

        void print() const override {
            std::cout << id << std::endl;
        }

        int get_size() const override{
            return 4;
        }

};





#endif