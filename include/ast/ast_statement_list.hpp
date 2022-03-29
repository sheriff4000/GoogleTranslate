#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include "ast/ast_node.hpp"
//#include "node_vector_parser.hpp"

class statement_list : public node
{
    private:
        int cont_1 = 0;

    public:
        
        statement_list(std::vector<node_ptr>* _statements){
            for (uint32_t i =0; i < _statements->size(); i++)
            {
                branches.push_back(     (*_statements)[i]    );
            }
        }
        void append(std::vector<node_ptr>* _statements) override
        {
            for (uint32_t i =0; i < _statements->size(); i++)
            {
                branches.push_back(     (*_statements)[i]    );
            } 
        }

        statement_list(){
            branches = {};
        }

        int get_size()
        {
            int out = 0;
            for(uint32_t i = 0; i < branches.size(); i++){

                out += branches[i]->get_size();
            }
            return out;
        }

        void gen_mips(std::ostream &dst, context &Context) const override {
            std::cout << "In statement list" << std::endl;
            std::cout << branches.size() << "branches" << std::endl;

            for(uint32_t i = 0; i < branches.size(); i++){



                std::cout << "printing statment: " << i+1 << std::endl;
                branches[i]->gen_mips(dst, Context);

                //stopping
                // if (Context.get_stop() == false){
                //     break;
                // }
                //DONT TURN THIS ON IT LOSES A BUNCH OF TESTS
                //THIS IS A THREAT
                if ((Context.bool_label()) || (Context.bool_label2()))
                {
                    

                    if (Context.bool_label2())
                    {
                        dst << Context.get_stored_label() << ":" << std::endl;

                    }
                    Context.set_bool_label2(!Context.bool_label2());
                }

            }


        }

        void print(){
            std::cout << "statements" << std::endl;
        }
};

#endif