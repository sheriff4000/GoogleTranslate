#ifndef ast_int
#define ast_int

#include "ast/ast_node.hpp"

class int_literal : public node {
    protected:
        int val;

    public:
        int_literal(int _val) {
            val = _val;
        }

        void gen_mips(std::ostream &dst, context &Context, int destReg) const override;
};

#endif