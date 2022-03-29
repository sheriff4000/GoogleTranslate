#ifndef ast_ident
#define ast_ident

#include "ast_node.hpp"

class identifier : public node {
    protected:
        std::string id;

    public:
        identifier(std::string *_id){
            id = *_id;
            std::cout << "constructing identifier " << id << std::endl;

        }
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override 
        {
            //CHECK MEMORY
            int offset = Context.get_mem(id);
            std::cout << "in ident with offset: " << offset << " id: " << id << std::endl;
            
            //lw now
            dst << "lw    " <<"$" << destReg << "," << offset << "($fp)" << std::endl;
        }

        std::string get_id() const override{
            return id;
        }

        std::string get_type() const override{
            return "iden1t";
        }

        void print() const override {
            std::cout << id << std::endl;
        }


        int get_size() const override{
            return 8;
        }

};





#endif