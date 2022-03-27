#ifndef ast_def_function_hpp
#define ast_def_function_hpp


#include "ast/ast_node.hpp"

class function_def : public node
{
    private:
        // vector <node_ptr> branches is inherited
        std::string id;
        std::vector<node_ptr> args = {};
        node_ptr statements;
        std::string type;
    public:

        function_def(node_ptr _type, node_ptr _id, std::vector<node_ptr>* _args, node_ptr _statements){
            args =  *_args;
            statements = _statements;
            id = _id->get_val();
        }
        function_def(node_ptr _type, node_ptr _id, node_ptr _statements){
            statements = _statements;
            id = _id->get_val();
        } //no args in this one

        void print(){
            std::cout << "cool function def bro" << std::endl;
        }

        std::string get_id() const override{
            return id;
        }


        void gen_mips(std::ostream &dst, context &Context) const override
        {    
            
            int arg_size = args.size();
            int statement_size = 12 + 4*arg_size;
            statement_size += statements->get_size();
            //PROLOGUE
            dst << ".globl " << id << std::endl;
            dst << id << ":" << std::endl;
            dst << "addiu       $sp,$sp," << -statement_size <<std::endl;
            dst <<"sw       $31,"<<statement_size-4<<"($sp)"<< std::endl;
            dst << "sw      $fp,"<< statement_size-8 << "($sp)" << std::endl;
            dst << "move        $fp,$sp" << std::endl;

            for(int i = 0; i < arg_size; i++){
                dst << "sw      $" << i+4 << "," << statement_size + i*4 << "($sp)" << std::endl;
            }


            //ASSIGN ARGS TO REGISTERS (4 bytes each) (sequence of sw for each arg)
            // for (uint32_t i = 0; i < args.size(); i++)
            // {

            //     dst 
            // }
            //or do we call gen_mips on each of the parameters? and they store themselves.

            //MIDDLE BIT
            statements->gen_mips(dst, Context); //called on type statement_list
            //this is a statement node, generating the code for it.

            //EPILOGUE
            dst << "move        $sp,$fp" << std::endl;
            dst << "lw      $31,"<<statement_size-4<<"($sp)" << std::endl;
            dst << "lw      $fp, "<<statement_size-8 <<"($sp)" << std::endl;
            dst << "addiu       $sp,$sp," << statement_size << std::endl;
            dst << "j       $31" << std::endl;
            dst << "nop" << std::endl;
            dst << std::endl;
        }
};


#endif