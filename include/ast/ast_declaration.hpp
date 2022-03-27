#include "ast_node.hpp"

class declaration :public node
{
    private:
        std::string type;
        std::string ident;
        std::vector<std::string> variables;
        std::string value;
        node_ptr declarator;
        
    public:
        declaration(node_ptr _type, std::vector<node_ptr>* declarator_list)
        {
            //declarator list is a list of types init declarator and normal declarations.
            // this occurs in normal function, not function def afaik
            type = _type->get_id();
            for (uint32_t i = 0; i< declarator_list->size(); i++)
            {
                branches.push_back( (*declarator_list)[i] );
            }
            //need to deal with declarator list

        }

        //This occurs for parameter declaration at least, or not
        declaration(node_ptr _type, node_ptr _declarator)
        {
            type = _type->get_id(); //Type is ident class
            declarator = _declarator;//declarator is declarator class (not init_declarator)

        }
        
        void gen_mips(std::ostream &dst, context &Context) const override
        {
            std::cout << "inside declaration" << std::endl;
            uint32_t size = branches.size();

            //Iterate through all declarations to idek
            for (uint32_t i = 0; i< size; i++)
            {
                Context.set_type(type, branches[i]->get_id()); //branches[i] is declarators and we need their ids
            }


            //Context.set_type(ident, type);
           
        }
        int get_size()
        {
            return 0;
        }


};  