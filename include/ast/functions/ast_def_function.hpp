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

        function_def(node_ptr _type, node_ptr _id, std::vector<node_ptr> _args, node_ptr _statements){
            //args = _args;
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


        void gen_mips(std::ostream &dst, context &Context) const override
        {     
            //PROLOGUE
            dst << id << ":" << std::endl;
            dst << "addiu   $sp,$sp,-8" << std::endl;
            dst << "sw      $fp,4($sp)" << std::endl;
            dst << "move    $fp,$sp" << std::endl;

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
            dst << "move    $sp,$fp" << std::endl;
            dst << "lw      $fp,4($sp)" << std::endl;
            dst << "addiu   $sp,$sp,8" << std::endl;
            dst << "j       $31" << std::endl;
            dst << "nop" << std::endl;
        }
};


#endif