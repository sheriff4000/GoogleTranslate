#ifndef ast_node_hpp
#define ast_node_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "ast/context.hpp"


class node{
    protected:
        std::vector<node*> branches = {};
    
    public:
        node(){}
        virtual ~node(){}
        virtual void gen_mips(std::ostream &dst, context &Context, int destReg) const{};
        virtual void gen_mips(std::ostream &dst, context &Context) const{};

        virtual std::string get_id() const{
            return "no id here";
        };

        virtual int get_val() const{
            return 0;
        }

        virtual void print() const {
        };
};
typedef node *node_ptr;

#endif