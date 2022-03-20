#ifndef ast_node_hpp
#define ast_node_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

// class node;

#include "ast/context.hpp"

class node{
    private:
        std::vector<node*> branches;
    
    public:
        node();
        virtual ~node();
        virtual void gen_mips(std::ostream &dst, context &Context, int destReg) const;
        virtual void gen_mips(std::ostream &dst, context &Context) const;
};

typedef node *node_ptr;
#endif