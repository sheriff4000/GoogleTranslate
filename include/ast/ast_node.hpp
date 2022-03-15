#ifndef ast_node
#define ast_node

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include<unordered_map>

#include "ast.hpp"


typedef node* nodePtr;

class node
{
    
public:
//public functions to be inherited
    //std::unordered_map<std::string, nodePtr> global_map; //variable name maps to pointer on the stack, not b important for basic functoinality tbh, also needs to be global


    virtual void visualise() const;

    virtual void gen_mips(std::ostream &dst, Context &context, int destReg) const;
    //virtual void generateTypeMIPS(std::ostream &dst, Context &context, int destReg, enum Specifier type) const;



protected:
    std::vector<nodePtr> branches;


    

};

#endif