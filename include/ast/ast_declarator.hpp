#include "ast_node.hpp"

class declarator : public node
{
    private:
        std::vector<node_ptr> args;
        
        std::string id;
    public:
        declarator(node_ptr _type, node_vector_ptr _args)
        {
            args = *_args;
            id = (*_args)[0]->get_id();
        }
        declarator(std::string ident)
        {
            id = ident;
        }
        std::string get_id() const override
        {
            return id;
        }
};