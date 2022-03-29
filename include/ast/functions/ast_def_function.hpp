#ifndef ast_def_function_hpp
#define ast_def_function_hpp


#include "ast/ast_node.hpp"

class function_def : public node
{
    private:
        // vector <node_ptr> branches is inherited
        std::string id;
        //std::vector<node_ptr> args = {};
        node_ptr func_decl;
        node_ptr statements;
        std::string type;
    public:

        function_def(node_ptr _type, node_ptr _id, node_ptr _statements){
            //type = _type->
            statements = _statements;
            id = _id->get_id();
            func_decl = _id;
            //id is of type declarator

        } //no args in this one

        void print(){
            std::cout << "cool function def bro" << std::endl;
        }

        std::string get_id() const override{
            return id;
        }


        void gen_mips(std::ostream &dst, context &Context) const override
        {
            std::cout << "In function def " << std::endl;

            std::vector<node_ptr> args = func_decl->get_params(); //list of declaration objects
            std::cout << "after get params from function decl" << std::endl;
            //PARAMS ARE PRIVATE AND WE'RE POINTING TO THEM - WE'RE NOT ALLOWED TO ACCESS THEM HENCE SEG?
            int arg_size = args.size(); //args is a vector pointer now
            std::cout << "after size of params from function decl" << std::endl;
            int statement_size = 32 + 4*arg_size;

            statement_size += statements->get_size();
            std::cout << "Done accessing params of function" << std::endl;
            //PROLOGUE
            dst << ".globl " << id << std::endl;
            dst << id << ":" << std::endl;
            dst << "addiu       $sp,$sp," << -statement_size <<std::endl;
            dst <<"sw       $31,"<<statement_size-4<<"($sp)"<< std::endl;
            dst << "sw      $fp,"<< statement_size-8 << "($sp)" << std::endl;
            dst << "move        $fp,$sp" << std::endl;

            Context.set_offset(statement_size - 12);
            //Putting args into memory relative to fp
            std::cout << arg_size << std::endl;

            for(int i = 0; i < arg_size; i++){
                dst << "sw      $" << i+4 << "," << statement_size + i*4 << "($fp)" << std::endl;
                std::cout << "processing function args "<< args[i]->get_id() << "oh no" << std::endl;
                Context.set_memory(args[i]->get_id(), statement_size + i*4  );
            }
            //Should we take note where they are stored and put them into context?
            //We assume it's in memory, look up where in the memory context, and then pull them into registers and add. This is part of return as we must eval the expression in return.
            //PUTTING ARGS INTO CONTEXT


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
            Context.clean();
        }
};


#endif