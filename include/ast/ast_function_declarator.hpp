#ifndef ast_function_declarator
#define ast_function_declarator

#include "ast_node.hpp"
class function_declarator : public node
{   
    private:
        node_ptr id;
        std::vector<node_ptr>* params = {};
    public:
        function_declarator(node_ptr direct_decl, std::vector<node_ptr>* param_list)
        {   
            id = direct_decl;
            params = param_list;
        }
        function_declarator(node_ptr direct_decl)
        {   
            id = direct_decl;
        }
        std::string get_id()
        {
            return id->get_id();
        }
};

#endif