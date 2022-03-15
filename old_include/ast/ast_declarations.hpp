#ifndef ast_declarations
#define ast_declarations

#include "ast_node.hpp"


#include <string>
#include <iostream>
#include <map>

#include <memory>

class declaration : public node

{
    public:
        declaration(nodePtr type, nodePtr id);
        declaration(nodePtr type);

        virtual ~declaration();
        

};


#endif



