#ifndef ast_float
#define ast_float

#include "ast/ast_node.hpp"

class float_literal : public node {
    protected:
        float val;

    public:
        float_literal(float _val){
            val = _val;
        }
        void gen_mips(std::ostream &dst, context &Context, int destReg) const override{};

        int get_size() const override{
            return 8;
        }
};

#endif