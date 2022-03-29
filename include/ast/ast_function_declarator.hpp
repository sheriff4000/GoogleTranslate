#ifndef ast_function_declarator
#define ast_function_declarator

#include "ast_node.hpp"

class function_declarator : public node
{   
    private:
        node_ptr id;
        std::vector<node_ptr> declarators;
    public:
        function_declarator(node_ptr direct_decl, std::vector<node_ptr>* param_list)
        {   
            id = direct_decl;
            declarators = *param_list; //vector of type declaration
        }
        function_declarator(node_ptr direct_decl)
        {   
            id = direct_decl;
            declarators = {};
        }
        std::string get_id() const override
        {
            //std::cout << "function declarator get_id()" << std::endl;
            return id->get_id();//declarator object, should return string

        }
        std::vector<node_ptr> get_params() override
        {
            //std::cout << "printing declarators (list of func params) inside function declarator object" << (*declarators)[0]->get_id() << std::endl;
            return declarators;
        }
};

#endif