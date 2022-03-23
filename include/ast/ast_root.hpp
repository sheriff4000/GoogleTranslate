#include "ast_node.hpp"

class root : public node
{
    private:
    public:
        root(std::vector<node_ptr>* exprlist)
        {
            branches = *exprlist;
        }
        void gen_mips(std::ostream &dst, context &Context) const override
        {
            branches[0]->print();
        }
};