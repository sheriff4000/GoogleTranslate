#ifndef ast_if_statement
#define ast_if_statement

#include "ast_node.hpp"

class if_statement : public node {
    protected:
        node_ptr if_condition;
        node_ptr statements;
        node_ptr else_statements;
    public:
        //BOTH STATEMENTS ARE OF TYPE STATEMENT LIST (i HOPE)
        if_statement(node_ptr condition, node_ptr _statements) {
            //basically I could make a class for conditionals?
            //for now just eval in here 
            //condition is an expression. idek. it could be a single literal or var.
            //
            if_condition = condition;
            statements = _statements;

        }
        if_statement(node_ptr condition, node_ptr _statements, node_ptr _else_statements) {
            if_condition = condition;
            statements = _statements;
            else_statements = _else_statements;
        }

        void gen_mips(std::ostream &dst, context &Context, int destReg) const override {
            
        }

        void gen_mips(std::ostream &dst, context &Context) const override {
            if_condition->gen_mips(dst, Context, 2);
            //now we check if register 2
            dst << "nop" << std::endl;
            //basically if reg2 is false, we branch to rest of the program
            std::string first_label = Context.get_label();
            dst << "beq     $2,$0," << first_label <<std::endl;
            dst << "nop" << std::endl;
            dst << std::endl;
    
            Context.incr_label();

            //then the statement code followed by the label
            //we might need to insert a label after exiting any given statement. gonna need context for that
            statements->gen_mips(dst, Context);

            std::string second_label = Context.get_label();
            Context.store_label(second_label);

            dst << "b    " << second_label <<std::endl;
            dst << "nop" << std::endl;
            dst << std::endl;
  
            dst <<  first_label << ":" << std::endl;

        };


        int get_size() const override{
            return 8 * branches.size();
        }

        std::string get_type() const override{
            return "if";
        }

        std::string get_val() const override{
            return "if";
        }
};

#endif