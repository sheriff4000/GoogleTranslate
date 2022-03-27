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
            type = _type->get_id();
            //need to deal with declarator list

        }
        declaration(node_ptr _type, node_ptr _declarator)
        {
            type = _type->get_id();
            declarator = _declarator;

        }
        
        void gen_mips(std::ostream &dst, context &Context) const override
        {
            std::cout << "inside basic declaration" << std::endl;

            Context.set_type(ident, type);
           
        }
        int get_size()
        {
            return 0;
        }

};  