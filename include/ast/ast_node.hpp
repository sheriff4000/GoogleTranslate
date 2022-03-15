#ifndef ast_node
#define ast_node

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include<unordered_map>

#include "context.hpp"

class node;

typedef node* nodePtr;

class node
{
protected:
    std::vector<nodePtr> branches;

   
public:
//public functions to be inherited
    //std::unordered_map<std::string, nodePtr> global_map; //variable name maps to pointer on the stack, not b important for basic functoinality tbh, also needs to be global
    node(std::vector<nodePtr> _branches): branches(_branches)
    {}
    node(): branches({})
    {}
    virtual ~node()
    {}

    virtual void visualise() const;

    virtual void gen_mips(std::ostream &dst, context &Context, int destReg) const;
    virtual void gen_mips(std::ostream &dst, context &Context) const;
    // virtual void gen_mips(std::ostream &dst, context &Context, std::vector<nodePtr> args) const;
    //virtual void generateTypeMIPS(std::ostream &dst, Context &context, int destReg, enum Specifier type) const;




    

};

#endif