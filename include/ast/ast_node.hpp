#ifndef ast_node_hpp
#define ast_node_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

class node;
typedef node *node_ptr;
#include "ast/context.hpp"

class node{

    
    public:
        virtual ~node();
        virtual void gen_mips(std::ostream &dst, context &Context, int destReg) const;
};


#endif