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
        virtual void gen_mips(std::ostream &dst, context &Context, int destReg) const{std::cout << "node mips destreg" << std::endl;};
        virtual void gen_mips(std::ostream &dst, context &Context) const{
            std::cout << "node mips" << std::endl;
        };

        virtual int get_size() const{
            std::cout << "Node get_size()" << std::endl;
            return 0; //shouldn't be in here 
        }

        virtual std::string get_id() const{
            return "no id here";
        }

        virtual std::string get_type() const{
            return "normal node";
        }

        virtual std::string get_val() const{
            return "0";
        }
        virtual std::vector<node_ptr> get_params() {}

        virtual void print() const {
        };
        virtual void append(std::vector<node_ptr>* list){};
};
typedef node *node_ptr;

#endif