#include "ast_node.hpp"

class declaration :public node
{
    private:
        std::string type;
        std::string ident;
        std::vector<std::string> variables;
        std::string value;
    public:
        declaration(node_ptr _type, std::vector<node_ptr>* declarator_list)
        {
            type = _type->get_id();

            // for (int i = 0; i < declarator_list->size(); i++){
            //     variables.push_back((declarator_list[i])->get_id());
            // }
        }
        
        void gen_mips(std::ostream &dst, context &Context) const override
        {
            std::cout << "inside basic declaration" << std::endl;
            //idefk
            //int reg = Context.get_reg();
            //get a reg, then quick instruction to put it into reg?
            //dst << "li  $" <<reg << value << std::endl;
            
           
        }

        int get_size() const override {
            if(type == "int"){
                return 4;
            }
        }

};  