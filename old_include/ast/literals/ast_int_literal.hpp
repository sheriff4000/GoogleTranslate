#include "ast/ast_node.hpp"
#include <string>
#include <fstream>
#include <iostream>

class int_literal : public node
{
    private:
        int value;
    public:
        int_literal(int val)
        {
            value = val;
        }

        //codegen
        //possible way of doing it?
        void gen_mips(std::ofstream ofs, std::string reg)
        {
            //ofs << "addi " + reg + "" <<std::endl; //unfinished
        }

};