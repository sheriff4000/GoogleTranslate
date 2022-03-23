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
            //std::cout << "progress!" << std::endl;
            for (uint32_t i = 0; i < branches.size(); i++){

                std::cout << "printing branches" << std::endl;
                branches[i]->gen_mips(dst, Context);
            }
            
        }

        void print() const override{
            std::cout << "progress!" << std::endl;
        }
};