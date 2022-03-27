#include "ast_node.hpp"

class declarator : public node
{
    private:
        std::vector<node_ptr> args;
        
    public:
        declarator(node_ptr _type, node_vector_ptr _args)
        {
            args = *_args;
        }
};