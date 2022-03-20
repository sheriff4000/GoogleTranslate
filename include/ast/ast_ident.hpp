#ifndef ast_ident
#define ast_ident

#include "ast_node.hpp"

class identifier : public node {
    protected:
        std::string id;

    public:
        identifier(std::string _id){
            id = _id;
            
        };

};





#endif